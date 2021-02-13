//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_game.h"
#include "my_dungeon.h"
#include "my_thing.h"
#include "my_thing_template.h"
#include "my_random.h"
#include "my_globals.h"
#include "my_array_bounds_check.h"
#include "my_vector_bounds_check.h"
#include "my_ptrcheck.h"

bool Level::create_dungeon (point3d at, int seed)
{_
    log("Create dungeon at (%d,%d,%d)", at.x, at.y, at.z);

    is_dungeon_level = true;

    while (true) {
        auto dungeon = new Dungeon(MAP_WIDTH, MAP_HEIGHT, MAP_GRID_WIDTH,
                                   MAP_GRID_HEIGHT, seed);
        if (dungeon->failed) {
            seed++;
            delete dungeon;
            continue;
        }

        //
        // The grid is the basis of all reality.
        //
        place_the_grid();
        if (g_errored) { return false; }
#if 0
        //
        // Static level
        //
        auto dungeon = new Dungeon(0);
        if (g_errored) { return false; }
#endif
        auto tries = 10000;

        create_dungeon_place_walls(dungeon, 1, 6, 6, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 2, 6, 6, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 1, 6, 3, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 1, 3, 6, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 1, 3, 3, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 2, 3, 3, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 1, 2, 2, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 2, 2, 2, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 3, 2, 2, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 1, 2, 1, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 2, 2, 1, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 1, 1, 2, tries);
        if (g_errored) { return false; }
        create_dungeon_place_walls(dungeon, 2, 1, 2, tries);
        if (g_errored) { return false; }

        for (auto d = 1; d < 3; d++) {
            int nloops = 10;
            while (nloops--) {
                auto s = "floor";

                int tries = 100;
                switch (random_range(0, 5)) {
                    case 0: create_dungeon_place_floors(dungeon, s, d, 1, 3, 3, tries); break;
                    case 1: create_dungeon_place_floors(dungeon, s, d, 2, 3, 3, tries); break;
                    case 2: create_dungeon_place_floors(dungeon, s, d, 1, 2, 2, tries); break;
                    case 3: create_dungeon_place_floors(dungeon, s, d, 2, 2, 2, tries); break;
                    case 4: create_dungeon_place_floors(dungeon, s, d, 3, 2, 2, tries); break;
                }
            }
        }

        create_dungeon_place_floor_under_objects(dungeon, "floor1", 1);
        if (g_errored) { return false; }
        create_dungeon_place_floor_under_objects(dungeon, "floor2", 2);
        if (g_errored) { return false; }
        create_dungeon_place_floor_under_objects(dungeon, "floor3", 3);
        if (g_errored) { return false; }
        create_dungeon_place_floor_under_objects(dungeon, "floor4", 4);
        if (g_errored) { return false; }
        create_dungeon_place_floor_under_objects(dungeon, "floor5", 5);
        if (g_errored) { return false; }
        create_dungeon_place_floor_under_objects(dungeon, "floor6", 6);
        if (g_errored) { return false; }
        create_dungeon_place_floor_under_objects(dungeon, "floor7", 7);
        if (g_errored) { return false; }
        create_dungeon_place_floor_under_objects(dungeon, "floor8", 8);
        if (g_errored) { return false; }
        create_dungeon_place_floor_under_objects(dungeon, "floor9", 9);
        if (g_errored) { return false; }
        create_dungeon_place_remaining_floor(dungeon, "floor1");
        if (g_errored) { return false; }
        create_dungeon_place_corridor(dungeon, "corridor1", 0);
        if (g_errored) { return false; }

        create_dungeon_place_rocks(dungeon, 1, 6, 6, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 1, 6, 3, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 1, 3, 6, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 1, 3, 3, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 2, 3, 3, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 1, 2, 2, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 2, 2, 2, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 3, 2, 2, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 1, 2, 1, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 2, 2, 1, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 1, 1, 2, tries);
        if (g_errored) { return false; }
        create_dungeon_place_rocks(dungeon, 2, 1, 2, tries);
        if (g_errored) { return false; }

        create_dungeon_place_remaining_walls(dungeon, "dungeon_wall");
        if (g_errored) { return false; }
        create_dungeon_place_remaining_rocks(dungeon, "rock1");
        if (g_errored) { return false; }
        place_dirt(dungeon);
        if (g_errored) { return false; }
        create_dungeon_place_lava(dungeon, "lava1");
        if (g_errored) { return false; }
        create_dungeon_place_chasm(dungeon, "chasm1");
        if (g_errored) { return false; }
        create_dungeon_place_deep_water(dungeon, "deep_water1");
        if (g_errored) { return false; }
        create_dungeon_place_place_shallow_water(dungeon, "water1");
        if (g_errored) { return false; }

        //
        // Items that have no special placement rules
        //
        create_dungeon_place_objects_with_normal_placement_rules(dungeon);
        if (g_errored) { return false; }

        //
        // Place the player if we do not have one.
        //
        if (!game->level) {
            for (auto x = 0; x < MAP_WIDTH; x++) {
                for (auto y = 0; y < MAP_HEIGHT; y++) {
                    if (dungeon->is_ascend_dungeon(x, y)) {
                        auto t = thing_new("player2", fpoint(x, y));

#if 0
                        auto w = thing_new("scythe", fpoint(x, y));
                        t->carry(w);

                        auto w3 = thing_new("axe_basic", fpoint(x, y));
                        t->carry(w3);
#endif
                        auto w2 = thing_new("sword_basic", fpoint(x, y));
                        t->carry(w2);

                        auto b = thing_new("bag_small", fpoint(x, y));
                        t->carry(b);

                        auto f = thing_new("food_frog", fpoint(x, y));
                        t->carry(f);

                        for (auto x = 0; x < 1; x++) {
                            auto p = thing_new("potion_descent", fpoint(x, y));
                            t->carry(p);
                        }

                        auto s = thing_new("skill_devoted_thrust", fpoint(x, y));
                        t->skill_add(s);

                        goto placed_player;
                    }
                }
            }
        }

placed_player:
        if (g_errored) { return false; }

        //
        // Scary non essential stuff
        //
        create_dungeon_place_random_blood(dungeon);
        if (g_errored) { return false; }

        //
        // Less important stuff
        //
        place_floor_deco(dungeon);
        if (g_errored) { return false; }
        create_dungeon_place_random_floor_deco(dungeon);
        if (g_errored) { return false; }
        create_dungeon_place_sewer_pipes(dungeon);
        if (g_errored) { return false; }
        create_dungeon_game_mark_dungeon_tiles(dungeon);
        if (g_errored) { return false; }
        scroll_map_to_player();
        if (g_errored) { return false; }

        break;
    }

    return true;
}

void Level::create_dungeon_place_walls (Dungeonp d, int variant, 
                                        int block_width, int block_height, int tries)
{_
    auto tp = tp_random_dungeon_wall();
    if (!tp) {
        ERR("Place walls failed");
        return;
    }
    auto what = tp->name();

    while (tries--) {
        auto x = random_range(0, MAP_WIDTH - block_width + 1);
        auto y = random_range(0, MAP_HEIGHT - block_height + 1);

        auto can_place_here = true;
        for (auto dx = 0; dx < block_width; dx++) {
            auto X = x + dx;
            for (auto dy = 0; dy < block_height; dy++) {
                auto Y = y + dy;

                if (d->is_oob(X, Y)) {
                    continue;
                }

                if (!d->is_wall_no_check(X, Y)) {
                    can_place_here = false;
                    break;
                }

                //
                // We place large blocks and avoid splatting them with
                // smaller ones here.
                //
                if (is_wall(X, Y)) {
                    can_place_here = false;
                    continue;
                }
            }

            if (!can_place_here) {
                break;
            }
        }

        if (!can_place_here) {
            continue;
        }

        auto cnt = 1;
        for (auto dy = 0; dy < block_height; dy++) {
            auto Y = y + dy;
            for (auto dx = 0; dx < block_width; dx++) {
                auto X = x + dx;
                set_is_wall(X, Y);

                auto tilename = what + ".";
                tilename += std::to_string(variant);
                if (!((block_width == 1) && (block_height == 1))) {
                    tilename += ".";
                    tilename += std::to_string(block_width);
                    tilename += "x";
                    tilename += std::to_string(block_height);
                    tilename += ".";
                    tilename += std::to_string(cnt);
                    cnt++;
                }

                auto t = thing_new(what, fpoint(X, Y));
                auto tile = tile_find(tilename);
                if (!tile) {
                    ERR("Wall tile %s not found", tilename.c_str());
                    return;
                }

                t->tile_curr = tile->global_index;

                //
                // Need this so we can display chasms under walls
                //
                (void) thing_new("wall_floor1", fpoint(X, Y));
            }
        }
    }
}

void Level::create_dungeon_place_rocks (Dungeonp d, int variant, 
                                        int block_width, int block_height, int tries)
{_
    auto tp = tp_random_rock();
    if (!tp) {
        ERR("Place rocks failed");
        return;
    }
    auto what = tp->name();

    while (tries--) {
        auto x = random_range(0, MAP_WIDTH - block_width + 1);
        auto y = random_range(0, MAP_HEIGHT - block_height + 1);

        auto can_place_here = true;
        for (auto dx = 0; dx < block_width; dx++) {
            auto X = x + dx;
            for (auto dy = 0; dy < block_height; dy++) {
                auto Y = y + dy;

                if (d->is_oob(X, Y)) {
                    continue;
                }

                if (!d->is_rock(X, Y)) {
                    can_place_here = false;
                    break;
                }

                //
                // We place large blocks and avoid splatting them with
                // smaller ones here.
                //
                if (is_wall(X, Y)) {
                    can_place_here = false;
                    continue;
                }
            }

            if (!can_place_here) {
                break;
            }
        }

        if (!can_place_here) {
            continue;
        }

        auto cnt = 1;
        for (auto dy = 0; dy < block_height; dy++) {
            auto Y = y + dy;
            for (auto dx = 0; dx < block_width; dx++) {
                auto X = x + dx;
                set_is_rock(X, Y);

                auto tilename = what + ".";
                tilename += std::to_string(variant);
                if (!((block_width == 1) && (block_height == 1))) {
                    tilename += ".";
                    tilename += std::to_string(block_width);
                    tilename += "x";
                    tilename += std::to_string(block_height);
                    tilename += ".";
                    tilename += std::to_string(cnt);
                    cnt++;
                }

                auto t = thing_new(what, fpoint(X, Y));
                auto tile = tile_find(tilename);
                if (!tile) {
                    ERR("Rock tile %s not found", tilename.c_str());
                    return;
                }
                t->tile_curr = tile->global_index;

                //
                // Need this so we can display chasms under walls
                //
                (void) thing_new("wall_floor1", fpoint(X, Y));
            }
        }
    }
}

void Level::create_dungeon_place_floors (Dungeonp d, std::string what, int depth,
                                         int variant, int block_width,
                                         int block_height, int tries)
{_
    while (tries--) {
        auto x = random_range(0, MAP_WIDTH - block_width + 1);
        auto y = random_range(0, MAP_HEIGHT - block_height + 1);

        auto can_place_here = true;
        for (auto dx = 0; dx < block_width; dx++) {
            auto X = x + dx;
            for (auto dy = 0; dy < block_height; dy++) {
                auto Y = y + dy;

                if (d->is_oob(X, Y)) {
                    continue;
                }

                if (depth) {
                    if (depth != d->get_grid_depth_at(X, Y)) {
                        can_place_here = false;
                        continue;
                    }
                }

                if (!d->is_floor(X, Y)) {
                    can_place_here = false;
                    break;
                }

                if (is_floor(x, y)) {
                    can_place_here = false;
                    continue;
                }

                //
                // We place large blocks and avoid splatting them with
                // smaller ones here.
                //
                if (is_floor(X, Y)) {
                    can_place_here = false;
                    continue;
                }
            }

            if (!can_place_here) {
                break;
            }
        }

        if (!can_place_here) {
            continue;
        }

        auto cnt = 1;
        for (auto dy = 0; dy < block_height; dy++) {
            auto Y = y + dy;
            for (auto dx = 0; dx < block_width; dx++) {
                auto X = x + dx;
                set_is_floor(X, Y);

                auto new_thing = what + std::to_string(depth);
                auto tilename = new_thing + ".";

                tilename += std::to_string(variant);
                if (!((block_width == 1) && (block_height == 1))) {
                    tilename += ".";
                    tilename += std::to_string(block_width);
                    tilename += "x";
                    tilename += std::to_string(block_height);
                    tilename += ".";
                    tilename += std::to_string(cnt);
                    cnt++;
                }

                auto t = thing_new(new_thing, fpoint(X, Y));
                auto tile = tile_find(tilename);
                if (!tile) {
                    ERR("Floor tile %s not found", tilename.c_str());
                    return;
                }
                t->tile_curr = tile->global_index;
            }
        }
    }
}

void Level::create_dungeon_place_floor_under_objects (Dungeonp d, std::string what, int depth)
{_
    for (auto x = MAP_BORDER_TOTAL; x < MAP_WIDTH - MAP_BORDER_TOTAL; x++) {
        for (auto y = MAP_BORDER_TOTAL; y < MAP_HEIGHT - MAP_BORDER_TOTAL; y++) {
            if (!d->is_floor_no_check(x, y)) {
                continue;
            }

            if (is_floor(x, y)) {
                continue;
            }

            if (depth) {
                if (depth != d->get_grid_depth_at(x, y)) {
                    continue;
                }
            }

            (void) thing_new(what, fpoint(x, y));

            if (d->is_monst(x, y + 1) ||
                d->is_food(x, y + 1) ||
                d->is_treasure(x, y + 1) ||
                d->is_treasure_class_a(x, y + 1) ||
                d->is_treasure_class_b(x, y + 1) ||
                d->is_treasure_class_c(x, y + 1) ||
                d->is_potion(x, y + 1) ||
                d->is_key(x, y + 1)) {
                if (!is_floor(x, y + 1)) {
                    thing_new(what, fpoint(x, y + 1));
                }
            }
            if (d->is_monst(x, y - 1) ||
                d->is_food(x, y - 1) ||
                d->is_treasure(x, y - 1) ||
                d->is_treasure_class_a(x, y - 1) ||
                d->is_treasure_class_b(x, y - 1) ||
                d->is_treasure_class_c(x, y - 1) ||
                d->is_potion(x, y - 1) ||
                d->is_key(x, y - 1)) {
                if (!is_floor(x, y - 1)) {
                    thing_new(what, fpoint(x, y - 1));
                }
            }
            if (d->is_monst(x + 1, y) ||
                d->is_food(x + 1, y) ||
                d->is_treasure(x + 1, y) ||
                d->is_treasure_class_a(x + 1, y) ||
                d->is_treasure_class_b(x + 1, y) ||
                d->is_treasure_class_c(x + 1, y) ||
                d->is_potion(x + 1, y) ||
                d->is_key(x + 1, y)) {
                if (!is_floor(x + 1, y)) {
                    thing_new(what, fpoint(x + 1, y));
                }
            }
            if (d->is_monst(x - 1, y) ||
                d->is_food(x - 1, y) ||
                d->is_treasure(x - 1, y) ||
                d->is_treasure_class_a(x - 1, y) ||
                d->is_treasure_class_b(x - 1, y) ||
                d->is_treasure_class_c(x - 1, y) ||
                d->is_potion(x - 1, y) ||
                d->is_key(x - 1, y)) {
                if (!is_floor(x - 1, y)) {
                    thing_new(what, fpoint(x - 1, y));
                }
            }
        }
    }
}

void Level::create_dungeon_place_objects_with_normal_placement_rules (Dungeonp d)
{_
    for (auto x = 0; x < MAP_WIDTH; x++) {
        for (auto y = 0; y < MAP_HEIGHT; y++) {
            Tpp tp {};
            //
            // Reset the seed for each cell to increase the chances
            // of repeatability if other small things change in the
            // game
            //
            mysrand(seed + x + (y * MAP_WIDTH));

            if (d->is_blood(x, y))            { tp = tp_random_blood(); }
            if (d->is_door(x, y))             { tp = tp_random_door(); }
            if (d->is_ascend_dungeon(x, y))   { tp = tp_random_entrance(); }
            if (d->is_descend_dungeon(x, y))  { tp = tp_random_exit(); }
            if (d->is_food(x, y))             { tp = tp_random_food(); }
            if (d->is_gold(x, y))             { tp = tp_random_gold(); }
            if (d->is_key(x, y))              { tp = tp_random_key(); }
            if (d->is_potion(x, y))           { tp = tp_random_potion(); }
            if (d->is_monst(x, y))            { tp = tp_random_monst(); }
            if (d->is_secret_door(x, y))      { tp = tp_random_secret_door(); }
            if (d->is_minion_generator(x, y)) { tp = tp_random_generator(); }
            if (d->is_torch(x, y))            { tp = tp_random_torch(); }
            if (d->is_treasure(x, y))         { tp = tp_random_treasure(); }
            if (d->is_treasure_class_a(x, y)) { tp = tp_random_item_class_a(); }
            if (d->is_treasure_class_b(x, y)) { tp = tp_random_item_class_b(); }
            if (d->is_treasure_class_c(x, y)) { tp = tp_random_item_class_c(); }
            if (tp) {
                (void) thing_new(tp->name(), fpoint(x, y));
            }
        }
    }
}

void Level::create_dungeon_place_lava (Dungeonp d, const std::string &what)
{_
    for (auto x = 0; x < MAP_WIDTH; x++) {
        for (auto y = 0; y < MAP_HEIGHT; y++) {
            if (is_lava(x, y)) {
                continue;
            }

            if (!d->is_lava(x, y)) {
                continue;
            }

            (void) thing_new(what, fpoint(x, y));

            if (random_range(0, 100) < 20) {
                thing_new("smoke", fpoint(x, y));
            }
        }
    }
}

void Level::create_dungeon_place_chasm (Dungeonp d, const std::string &what)
{_
    for (auto x = 0; x < MAP_WIDTH; x++) {
        for (auto y = 0; y < MAP_HEIGHT; y++) {
            if (is_chasm(x, y)) {
                continue;
            }

            if (!d->is_chasm(x, y)) {
                continue;
            }

            (void) thing_new(what, fpoint(x, y));
        }
    }
}

void Level::create_dungeon_place_random_blood (Dungeonp d)
{_
    for (auto x = MAP_BORDER_TOTAL; x < MAP_WIDTH - MAP_BORDER_TOTAL; x++) {
        for (auto y = MAP_BORDER_TOTAL; y < MAP_HEIGHT - MAP_BORDER_TOTAL; y++) {
            if (is_blood(x, y)) {
                continue;
            }

            if (!d->is_floor(x, y) ||
                !d->is_floor(x - 1, y) ||
                !d->is_floor(x + 1, y) ||
                !d->is_floor(x, y - 1) ||
                !d->is_floor(x, y + 1) ||
                !d->is_floor(x - 1, y - 1) ||
                !d->is_floor(x + 1, y - 1) ||
                !d->is_floor(x - 1, y + 1) ||
                !d->is_floor(x + 1, y + 1)) {
                continue;
            }

            if (d->is_hazard(x, y) ||
                d->is_hazard(x - 1, y) ||
                d->is_hazard(x + 1, y) ||
                d->is_hazard(x, y - 1) ||
                d->is_hazard(x, y + 1) ||
                d->is_hazard(x - 1, y - 1) ||
                d->is_hazard(x + 1, y - 1) ||
                d->is_hazard(x - 1, y + 1) ||
                d->is_hazard(x + 1, y + 1)) {
                continue;
            }

            if (random_range(0, 1000) > 20) {
                continue;
            }

            auto tp = tp_random_blood();
            (void) thing_new(tp->name(), fpoint(x, y));
        }
    }
}

void Level::create_dungeon_place_place_shallow_water (Dungeonp d, const std::string &what)
{_
    for (auto x = 0; x < MAP_WIDTH; x++) {
        for (auto y = 0; y < MAP_HEIGHT; y++) {
            if (is_shallow_water(x, y)) {
                continue;
            }

            if (!d->is_shallow_water(x, y)) {
                continue;
            }

            (void) thing_new(what, fpoint(x, y));

            if (!d->is_floor(x, y)) {
                (void) thing_new("dirt2", fpoint(x, y));
            }
        }
    }
}

void Level::create_dungeon_place_deep_water (Dungeonp d, const std::string &what)
{_
    for (auto x = 0; x < MAP_WIDTH; x++) {
        for (auto y = 0; y < MAP_HEIGHT; y++) {
            if (is_deep_water(x, y)) {
                continue;
            }

            if (!d->is_deep_water(x, y)) {
                continue;
            }

            (void) thing_new(what, fpoint(x, y));

            if (!d->is_floor(x, y)) {
                (void) thing_new("dirt3", fpoint(x, y));
            }
        }
    }
}

void Level::place_floor_deco (Dungeonp d)
{_
    for (auto x = MAP_BORDER_TOTAL; x < MAP_WIDTH - MAP_BORDER_TOTAL; x++) {
        for (auto y = MAP_BORDER_TOTAL; y < MAP_HEIGHT - MAP_BORDER_TOTAL; y++) {
            if (!d->is_floor(x, y)) {
                continue;
            }

            if (!d->is_floor_deco_at(x, y)) {
                continue;
            }

            //
            // Reset the seed for each cell to increase the chances
            // of repeatability if other small things change in the
            // game
            //
            mysrand(seed + x + (y * MAP_WIDTH));

            auto tp = tp_random_deco();
            if (!tp) {
                return;
            }

            thing_new(tp->name(), fpoint(x, y));
        }
    }
}

void Level::create_dungeon_place_random_floor_deco (Dungeonp d)
{_
    for (auto x = MAP_BORDER_TOTAL; x < MAP_WIDTH - MAP_BORDER_TOTAL; x++) {
        for (auto y = MAP_BORDER_TOTAL; y < MAP_HEIGHT - MAP_BORDER_TOTAL; y++) {
            if (!d->is_floor(x, y)) {
                continue;
            }

            if (d->is_floor_deco_at(x, y)) {
                continue;
            }

            if (random_range(0, 100) < 99) {
                continue;
            }

            if (d->is_food(x, y)              ||
                d->is_blood(x, y)             ||
                d->is_door(x, y)              ||
                d->is_ascend_dungeon(x, y)    ||
                d->is_descend_dungeon(x, y)   ||
                d->is_minion_generator(x, y)  ||
                d->is_key(x, y)               ||
                d->is_potion(x, y)            ||
                d->is_secret_door(x, y)       ||
                d->is_treasure(x, y)          ||
                d->is_treasure_class_a(x, y)  ||
                d->is_treasure_class_b(x, y)  ||
                d->is_treasure_class_c(x, y)  ||
                d->is_monst(x, y)) {
                continue;
            }

            if (!d->is_floor(x - 1, y) ||
                !d->is_floor(x + 1, y) ||
                !d->is_floor(x, y - 1) ||
                !d->is_floor(x, y + 1) ||
                !d->is_floor(x - 1, y - 1) ||
                !d->is_floor(x + 1, y - 1) ||
                !d->is_floor(x - 1, y + 1) ||
                !d->is_floor(x + 1, y + 1)) {
                continue;
            }

            if (d->is_hazard(x, y) ||
                d->is_hazard(x - 1, y) ||
                d->is_hazard(x + 1, y) ||
                d->is_hazard(x, y - 1) ||
                d->is_hazard(x, y + 1) ||
                d->is_hazard(x - 1, y - 1) ||
                d->is_hazard(x + 1, y - 1) ||
                d->is_hazard(x - 1, y + 1) ||
                d->is_hazard(x + 1, y + 1)) {
                continue;
            }

            //
            // Reset the seed for each cell to increase the chances
            // of repeatability if other small things change in the
            // game
            //
            mysrand(seed + x + (y * MAP_WIDTH));

            auto tp = tp_random_deco();
            if (!tp) {
                return;
            }

            thing_new(tp->name(), fpoint(x, y));
        }
    }
}

void Level::create_dungeon_place_sewer_pipes (Dungeonp d)
{_
    //
    // Sometimes we have sewer pipes
    //
    if (random_range(0, 100) < 80) {
        return;
    }

    int sewer_count = 0;
    int sewer_count_target = 2 + random_range(0, 5);

    while (sewer_count < sewer_count_target) {
        auto x = random_range(MAP_BORDER_TOTAL, MAP_WIDTH - MAP_BORDER_TOTAL + 1);
        auto y = random_range(MAP_BORDER_TOTAL, MAP_HEIGHT - MAP_BORDER_TOTAL + 1);

        if (d->is_wall(x, y)) {
            continue;
        }

        if (d->is_rock(x, y)) {
            continue;
        }

        if (!d->is_floor(x, y) ||
            !d->is_floor(x - 1, y) ||
            !d->is_floor(x + 1, y) ||
            !d->is_floor(x, y - 1) ||
            !d->is_floor(x, y + 1) ||
            !d->is_floor(x - 1, y - 1) ||
            !d->is_floor(x + 1, y - 1) ||
            !d->is_floor(x - 1, y + 1) ||
            !d->is_floor(x + 1, y + 1)) {
            continue;
        }

        if (d->is_hazard(x, y) ||
            d->is_hazard(x - 1, y) ||
            d->is_hazard(x + 1, y) ||
            d->is_hazard(x, y - 1) ||
            d->is_hazard(x, y + 1) ||
            d->is_hazard(x - 1, y - 1) ||
            d->is_hazard(x + 1, y - 1) ||
            d->is_hazard(x - 1, y + 1) ||
            d->is_hazard(x + 1, y + 1)) {
            continue;
        }

        if (d->is_ascend_dungeon(x, y) ||
            d->is_ascend_dungeon(x - 1, y) ||
            d->is_ascend_dungeon(x + 1, y) ||
            d->is_ascend_dungeon(x, y - 1) ||
            d->is_ascend_dungeon(x, y + 1) ||
            d->is_ascend_dungeon(x - 1, y - 1) ||
            d->is_ascend_dungeon(x + 1, y - 1) ||
            d->is_ascend_dungeon(x - 1, y + 1) ||
            d->is_ascend_dungeon(x + 1, y + 1)) {
            continue;
        }

        if (d->is_descend_dungeon(x, y) ||
            d->is_descend_dungeon(x - 1, y) ||
            d->is_descend_dungeon(x + 1, y) ||
            d->is_descend_dungeon(x, y - 1) ||
            d->is_descend_dungeon(x, y + 1) ||
            d->is_descend_dungeon(x - 1, y - 1) ||
            d->is_descend_dungeon(x + 1, y - 1) ||
            d->is_descend_dungeon(x - 1, y + 1) ||
            d->is_descend_dungeon(x + 1, y + 1)) {
            continue;
        }

        if (d->is_descend_sewer(x, y) ||
            d->is_descend_sewer(x - 1, y) ||
            d->is_descend_sewer(x + 1, y) ||
            d->is_descend_sewer(x, y - 1) ||
            d->is_descend_sewer(x, y + 1) ||
            d->is_descend_sewer(x - 1, y - 1) ||
            d->is_descend_sewer(x + 1, y - 1) ||
            d->is_descend_sewer(x - 1, y + 1) ||
            d->is_descend_sewer(x + 1, y + 1)) {
            continue;
        }

        if (is_descend_sewer(x, y)) {
            continue;
        }

        //
        // Reset the seed for each cell to increase the chances
        // of repeatability if other small things change in the
        // game
        //
        mysrand(seed + x + (y * MAP_WIDTH));

        auto tp = tp_random_descend_sewer();
        if (!tp) {
            return;
        }

        thing_new(tp->name(), fpoint(x, y));
        sewer_count++;
    }
}

void Level::create_dungeon_place_remaining_floor (Dungeonp d, const std::string &what)
{_
    for (auto x = 1; x < MAP_WIDTH - 1; x++) {
        for (auto y = 1; y < MAP_HEIGHT - 1; y++) {
            if (!d->is_floor(x, y)) {
                continue;
            }
            if (!is_floor(x, y)) {
                thing_new(what, fpoint(x, y));
            }
        }
    }
}

void Level::create_dungeon_place_corridor (Dungeonp d, const std::string what, int depth)
{_
    for (auto x = MAP_BORDER_TOTAL; x < MAP_WIDTH - MAP_BORDER_TOTAL; x++) {
        for (auto y = MAP_BORDER_TOTAL; y < MAP_HEIGHT - MAP_BORDER_TOTAL; y++) {
            if (!d->is_corridor(x, y) &&
                !d->is_secret_corridor_at(x, y)) {
                continue;
            }

            if (depth) {
                if (depth != d->get_grid_depth_at(x, y)) {
                    continue;
                }
            }

            (void) thing_new(what, fpoint(x, y));
        }
    }
}

void Level::place_dirt (Dungeonp d)
{_
    for (auto x = 1; x < MAP_WIDTH - 1; x++) {
        for (auto y = 1; y < MAP_HEIGHT - 1; y++) {
            if (!d->is_anything_at(x, y) || d->is_dirt(x, y)) {
                auto tp = tp_random_dirt();
                if (!tp) {
                    return;
                }

                (void) thing_new(tp->name(), fpoint(x, y));
            }
        }
    }
}

void Level::create_dungeon_place_remaining_walls (Dungeonp d, const std::string &what)
{_
    for (auto x = 0; x < MAP_WIDTH; x++) {
        for (auto y = 0; y < MAP_HEIGHT; y++) {
            if (is_rock(x, y) || is_wall(x, y)) {
                continue;
            }

            if (!d->is_rock(x, y) && !d->is_wall(x, y)) {
                continue;
            }

            if (random_range(0, 100) < 50) {
                continue;
            }

            (void) thing_new(what, fpoint(x, y));

            //
            // Need this so we can display chasms under walls
            //
            (void) thing_new("wall_floor1", fpoint(x, y));
        }
    }
}

void Level::create_dungeon_place_remaining_rocks (Dungeonp d, const std::string &what)
{_
    for (auto x = 0; x < MAP_WIDTH; x++) {
        for (auto y = 0; y < MAP_HEIGHT; y++) {
            if (is_rock(x, y) || is_wall(x, y)) {
                continue;
            }

            if (!d->is_rock(x, y) && !d->is_wall(x, y)) {
                continue;
            }

            (void) thing_new(what, fpoint(x, y));

            //
            // Need this so we can display chasms under walls
            //
            (void) thing_new("wall_floor1", fpoint(x, y));
        }
    }
}

//
// Keep track of which tiles were part of the original dungeon so we can
// display things like just the walls without all the hidden stuff like rock
//
void Level::create_dungeon_game_mark_dungeon_tiles (Dungeonp d)
{_
    for (auto x = 0; x < MAP_WIDTH; x++) {
        for (auto y = 0; y < MAP_HEIGHT; y++) {
            if (d->is_floor(x, y) ||
                d->is_corridor(x, y) ||
                d->is_wall(x, y) ||
                is_floor(x, y) ||
                is_corridor(x, y)) {
                set_dungeon(x, y);
            }
        }
    }
}