//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_game.h"
#include "my_wid.h"
#include "my_wid_thing_info.h"
#include "my_array_bounds_check.h"
#include "my_thing.h"
#include "my_ptrcheck.h"
#include "my_sound.h"

uint8_t
game_mouse_down (int32_t x, int32_t y, uint32_t button)
{_
    //
    // If over the minimap allows clicks to move us
    //
    // Else, ignore clicks as they should go to a widget
    //
    if (game->minimap_over == point(-1, -1)) {
        auto w = wid_find_under_mouse();
        if (w) {
            if (w->name != "wid topcon window") {
                return false;
            }
        }

        w = wid_find_under_mouse_when_scrolling();
        if (w) {
            if (w->name != "wid topcon window") {
                return false;
            }
        }
    }

    if (!game || !game->started) {
        return false;
    }

    auto level = game->level;
    if (!level) {
        return false;
    }

    auto player = level->player;
    if (!player) {
        return false;
    }

    if (player->is_dead) {
        return true;
    }

    //
    // If mid air, we're done. Let other things move.
    //
    if (player->is_jumping) {
        return true;
    }

    if (!level->cursor) {_
        return false;
    }

    wid_thing_info_fini();

    if (game->state == Game::STATE_CHOOSING_TARGET) {
        player->log("Chosen target");
        if (game->request_to_throw_item) {
            auto item = game->request_to_throw_item;
            player->throw_at(item, level->cursor);
        }
        if (game->request_to_fire_item) {
            auto item = game->request_to_fire_item;

            player->used(item, level->cursor, true);

            //
            // The laser name is provided by the likes of wand
            //
            Thingp new_item = nullptr;
            if (!item->laser_name().empty()) {
                new_item = player->laser_fire_at(item->laser_name(), level->cursor);
            } else if (!item->projectile_name().empty()) {
                new_item = player->projectile_fire_at(item->projectile_name(), level->cursor);
            } else {
                TOPCON("Unknown beam weapon: %s.", item->text_the().c_str());
            }

            //
            // Get the damage from the enchanted wand, so the laser
            // inflicts that damage.
            //
            player->set_current_damage(item->get_current_damage());
        }
        return true;
    }

    player->log("Mouse down");

    //
    // Have we moved close enough to attack? Do this prior to checking for
    // double click so we can attack monsts sitting in lava
    //
    if ((std::abs(player->mid_at.x - level->cursor->mid_at.x) <= 1) &&
        (std::abs(player->mid_at.y - level->cursor->mid_at.y) <= 1)) {
        int x = level->cursor->mid_at.x;
        int y = level->cursor->mid_at.y;
        FOR_ALL_INTERESTING_THINGS(level, t, x, y) {
            if (t == level->player) {
                continue;
            }
            if (t->is_door() || t->is_alive_monst() || t->is_minion_generator()) {
                player->log("Close enough to attack");
                player->attack(level->cursor->mid_at);
                return true;
            }
        }
        FOR_ALL_THINGS_END()
    }

    //
    // If hovering over a double click thing then don't jump in unless
    // the user really means it.
    //
    if (!wid_mouse_double_click) {
        auto to = level->cursor->mid_at;
        FOR_ALL_THINGS(level, t, to.x, to.y) {
            if (t->is_cursor_can_hover_over_but_needs_double_click()) {
                player->log("Needs double click");
                return true;
            }
        } FOR_ALL_THINGS_END()
    }

    //
    // Have we moved close enough to collect? Do this after the double
    // click check so we do not try to collect things in lava.
    //
    if ((std::abs(player->mid_at.x - level->cursor->mid_at.x) <= 1) &&
        (std::abs(player->mid_at.y - level->cursor->mid_at.y) <= 1)) {
        int x = level->cursor->mid_at.x;
        int y = level->cursor->mid_at.y;
        FOR_ALL_INTERESTING_THINGS(level, t, x, y) {
            if (t == level->player) {
                continue;
            }
            if (t->is_food() || t->is_item()) {
                player->log("Close enough to collect");
                player->try_to_carry(t);
                return true;
            }
        }
        FOR_ALL_THINGS_END()
    }

    //
    // Grab the current move path and start walking toward it. This will
    // consume one move by the player.
    //
    if (player->cursor_path_pop_first_move()) {
        return true;
    }

    return false;
}

uint8_t
game_mouse_up (int32_t x, int32_t y, uint32_t button)
{
    return false;
}

uint8_t game_mouse_motion (int32_t x, int32_t y,
                           int32_t relx, int32_t rely,
                           int32_t wheelx, int32_t wheely)
{_
    auto level = game->level;
    if (!level) {
        return false;
    }

    auto w = wid_find_under_mouse();
    if (w) {
        if (w->name != "wid topcon window") {
            level->cursor_path_clear();
        }
    }

    if (level->timestamp_dungeon_created &&
      time_have_x_tenths_passed_since(10, level->timestamp_dungeon_created)) {
        if (level->cursor) {_
            if (level->player && !level->player->is_dead) {
                level->cursor->visible();
            }
        }
    }

#if 0
{
    g_debug_thing = nullptr;

    point p(level->cursor->mid_at.x, level->cursor->mid_at.y);
    TOPCON("monst %d corpse %d", level->is_monst(p), level->is_corpse(p));
    FOR_ALL_INTERESTING_THINGS(level, t, level->cursor->mid_at.x, level->cursor->mid_at.y) {
        if (level->cursor->mid_at != t->mid_at) {
            continue;
        }
        if (t->is_dead) {
            continue;
        }
        if (t->is_monst()) {
            t->topcon("debug");
            g_debug_thing = t;
        }
    }
    FOR_ALL_THINGS_END()
}
#endif

    return true;
}
