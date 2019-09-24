/*
 * Copyright goblinhack@gmail.com
 * See the README file for license info.
 */

#include "my_main.h"
#include "my_tile.h"
#include "my_room.h"
#include "my_range.h"
#include <bitset>

static int debug_enabled = false;

std::vector<Roomp> Room::all_rooms;

Roomp Room::room_new (void)
{_
    auto r = std::make_shared< class Room >();
    Room::all_rooms.push_back(r);
    return (r);
}

Roomp Room::create_w_flip (void)
{_
    std::vector<std::string> rot[MAP_DEPTH];

    auto r = Room::room_new();

    /*
     * Flip the room chars
     */
    for (auto z = 0; z < MAP_DEPTH; z++) {
        for (auto y = 0; y < height; y++) {
            std::string s;
            for (auto x = 0; x < width; x++) {
                set(r->data, x, y, z, get(data, width - x - 1, y, z));
            }
        }
    }

    /*
     * Flip the doors too
     */
    auto z = MAP_DEPTH_WALLS; {
        for (auto y = 0; y < height; y++) {
            std::string s;
            for (auto x = 0; x < width; x++) {
                auto c = get(r->data, x, y, z);
                switch (c) {
                    case Charmap::DOOR_UP:    c = Charmap::DOOR_UP; break;
                    case Charmap::DOOR_DOWN:  c = Charmap::DOOR_DOWN; break;
                    case Charmap::DOOR_LEFT:  c = Charmap::DOOR_RIGHT; break;
                    case Charmap::DOOR_RIGHT: c = Charmap::DOOR_LEFT; break;
                }
                set(r->data, x, y, z, c);
            }
        }
    }

    r->dir_up         = dir_up;
    r->dir_down       = dir_down;
    r->dir_left       = dir_right;
    r->dir_right      = dir_left;

    r->is_entrance    = is_entrance;
    r->is_lock        = is_lock;
    r->is_key         = is_key;
    r->is_secret      = is_secret;
    r->is_exit        = is_exit;

    r->depth          = depth;

    r->finalize();

    return (r);
}

Roomp Room::rotate_clockwise (void)
{_
    std::vector<std::string> rot[MAP_DEPTH];

    auto r = Room::room_new();

    /*
     * Rotate the room chars
     */
    for (auto z = 0; z < MAP_DEPTH; z++) {
        for (auto y = 0; y < height; y++) {
            std::string s;
            for (auto x = 0; x < width; x++) {
                set(r->data, width - y - 1, x, z, get(data, x, y, z));
            }
        }
    }

    /*
     * Rotate the doors too
     */
    auto z = MAP_DEPTH_WALLS; {
        for (auto y = 0; y < height; y++) {
            std::string s;
            for (auto x = 0; x < width; x++) {
                auto c = get(r->data, x, y, z);
                switch (c) {
                    case Charmap::DOOR_UP:    c = Charmap::DOOR_RIGHT; break;
                    case Charmap::DOOR_DOWN:  c = Charmap::DOOR_LEFT; break;
                    case Charmap::DOOR_LEFT:  c = Charmap::DOOR_UP; break;
                    case Charmap::DOOR_RIGHT: c = Charmap::DOOR_DOWN; break;
                }

                set(r->data, x, y, z, c);
            }
        }
    }

    r->dir_up         = dir_left;
    r->dir_down       = dir_right;
    r->dir_left       = dir_down;
    r->dir_right      = dir_up;

    r->is_entrance    = is_entrance;
    r->is_lock        = is_lock;
    r->is_key         = is_key;
    r->is_secret      = is_secret;
    r->is_exit        = is_exit;

    r->depth          = depth;

    r->finalize();

    return (r);
}

//
// Find all doors from a room
//
void Room::find_doors (void)
{
    int z = MAP_DEPTH_WALLS;

    for (auto x : range<int>(0, width)) {
        for (auto y : range<int>(0, height)) {
            if (get(data, x, y, z) == Charmap::DOOR_UP) {
                has_door_up = true;
                doors_up.push_back(point(x, y));
            }
            if (get(data, x, y, z) == Charmap::DOOR_DOWN) {
                has_door_down = true;
                doors_down.push_back(point(x, y));
            }
            if (get(data, x, y, z) == Charmap::DOOR_LEFT) {
                has_door_left = true;
                doors_left.push_back(point(x, y));
            }
            if (get(data, x, y, z) == Charmap::DOOR_RIGHT) {
                has_door_right = true;
                doors_right.push_back(point(x, y));
            }
        }
    }

    if (!doors_up.size() &&
        !doors_down.size() &&
        !doors_left.size() &&
        !doors_right.size()) {
        dump();
        DIE("room has no doors");
    }
}

void Room::finalize (void)
{
    find_doors();

    if (debug_enabled) {
        dump();
    }
}

void Room::dump (void)
{
    std::array<std::array<char, CHUNK_HEIGHT>, CHUNK_WIDTH> tmp {};
    for (auto y = 0; y < height; y++) {
        for (auto x = 0; x < width; x++) {
            set(tmp, x, y, ' ');
        }
    }

    for (auto y = 0; y < height; y++) {
        for (auto x = 0; x < width; x++) {
            auto c = get(data, x, y, MAP_DEPTH_WALLS);
            if (!c || (c == ' ')) {
                c = get(data, x, y, MAP_DEPTH_FLOOR);
            }
            set(tmp, x, y, c);
        }
    }

    LOG("ROOM(%d): direction: up %d down %d left %d right %d",
        roomno, dir_up, dir_down, dir_left, dir_right);
    LOG("ROOM(%d): doors:     up %d down %d left %d right %d",
        roomno, has_door_up, has_door_down, has_door_left, has_door_right);
    for (auto y = 0; y < height; y++) {
        std::string s;
        for (auto x = 0; x < width; x++) {
            s += get(tmp, x, y);
        }
        LOG("ROOM(%d): %s", roomno, s.c_str());
    }
    LOG(" ");
}
