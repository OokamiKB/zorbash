//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_main.h"
#include "my_game.h"
#include "my_thing.h"
#include "my_sprintf.h"
#include "my_gl.h"

void Thing::fall (float fall_height, timestamp_t ms)
{_
    log("Can fall?");
_
    if (is_changing_level ||
        is_hidden || 
        is_falling || 
        is_waiting_to_ascend || 
        is_waiting_to_descend_to_next_level || 
        is_waiting_to_fall || 
        is_jumping) { 
        log("No");
        return;
    }

    if (is_critical_to_level()) {
        log("No, critical");
        return;
    }

    if (!is_able_to_fall()) {
        log("No, unable to fall");
        return;
    }

    if (is_floating()) {
        log("No, floating");
        return;
    }

    auto t = set_timestamp_fall_begin(time_get_time_ms_cached());
    set_timestamp_fall_end(t + ms);

    set_fall_height(fall_height);

    log("Begin falling");
    level_pop();
    is_falling = true;
    level_push();

    if (is_on_fire()) {
        if (is_player()) {
            MINICON("%%fg=green$The fall puts out the flames!%%fg=reset$");
        }
        unset_on_fire();
    }

    if (is_player() || is_monst() || is_item()) {
        wobble(360);
    }
}

float Thing::get_fall (void)
{
    if (!is_falling) {
        return (0.0);
    }

    auto t = time_get_time_ms_cached();

    if (t >= get_timestamp_fall_end()) {
        is_falling = false;
        log("End of falling");
        level_push();
        fall_to_next_level();
        return (0);
    }

    float time_step =
        (float)(t - get_timestamp_fall_begin()) /
        (float)(get_timestamp_fall_end() - get_timestamp_fall_begin());

    //
    // This hide things like the sword
    //
    if (time_step > 0.95) {
        is_changing_level = true;

        if (is_player()) {
            log("Player is waiting to complete the fall");
            level->timestamp_fade_out_begin = time_get_time_ms_cached();
            is_waiting_to_fall = true;
        }
    }

    float height = get_fall_height() * time_step;

    return (height);
}

bool Thing::fall_to_next_level (void)
{_
    if (!monstp) {
        return false;
    }

    log("Try to fall");
_
    auto where_to = level->world_at + point3d(0, 0, 1);
    game->init_level(where_to);
    if (is_player()) {
        game->current_level = where_to;
    }

    auto next_level = get(game->world.levels, where_to.x, where_to.y, where_to.z);
    if (!next_level) {
        if (is_player()) {
            MINICON("The chasm is permanently blocked!");
        }
        log("No, no next level");
        return false;
    }

    auto tries = 0;
    for (;;) {
        int x;
        int y;

        //
        // Try close to where we are first; failing that anywhere will do.
        //
        if (tries < 1) {
            x = mid_at.x;
            y = mid_at.y;
        } else if (tries < 10) {
            x = mid_at.x + random_range(-MAP_BORDER_TOTAL, MAP_BORDER_TOTAL);
            y = mid_at.y + random_range(-MAP_BORDER_TOTAL, MAP_BORDER_TOTAL);
        } else if (tries < 100) {
            x = mid_at.x + random_range(-MAP_BORDER_TOTAL * 2, MAP_BORDER_TOTAL * 2);
            y = mid_at.y + random_range(-MAP_BORDER_TOTAL * 2, MAP_BORDER_TOTAL * 2);
        } else if (tries < 1000) {
            x = mid_at.x + random_range(-MAP_BORDER_TOTAL * 4, MAP_BORDER_TOTAL * 4);
            y = mid_at.y + random_range(-MAP_BORDER_TOTAL * 4, MAP_BORDER_TOTAL * 4);
        } else {
            x = random_range(MAP_BORDER_TOTAL, MAP_WIDTH - MAP_BORDER_TOTAL);
            y = random_range(MAP_BORDER_TOTAL, MAP_HEIGHT - MAP_BORDER_TOTAL);
        }
        tries++;

        if (next_level->is_oob(x, y)) {_
            continue;
        }

        log("Try to fall to %d,%d", x, y);
        if (!next_level->is_dungeon(x, y)) {_
            log("No, out of dungeon");
            continue;
        }

        if (next_level->is_entrance(x, y)         ||
            next_level->is_monst(x, y)            ||
            next_level->is_rock(x, y)             ||
            next_level->is_door(x, y)             ||
            next_level->is_secret_door(x, y)      ||
            next_level->is_minion_generator(x, y) ||
            next_level->is_chasm(x, y)            ||
            next_level->is_wall(x, y)             ||
            next_level->is_sewer(x, y)            ||
            next_level->is_exit(x, y)) {_
            log("No, special tile");
            continue;
        }

        if (next_level->is_floor(x, y) ||
            next_level->is_fire(x, y) ||
            next_level->is_lava(x, y)) {

            if (is_player()) {
                game->level = next_level;
                MINICON("%%fg=red$You tumble into the void!%%fg=reset$");
            } else if (is_monst() || is_item()) {
                MINICON("%s tumbles into the void!", text_The().c_str());
            }

            log("Land on the next level, change level then move to %d,%d", x, y);
            level_change(next_level);

            log("Land on the next level, move to %d,%d", x, y);
            move_to_immediately(fpoint(x, y));

            if (is_player()) {
                next_level->player = this;
                next_level->scroll_map_to_player();
                next_level->update();
                //
                // Make sure all monsts on the new level are at the
                // same tick or they will get lots of free attacks
                //
                next_level->update_all_ticks();
            }

            set_fall_height(0);
            if (is_player() || is_monst() || is_item()) {
                wobble(90);
            }
            visible();

            //
            // Allow generators to fall without damage
            //
            int fall_damage = 0;
            if (is_player()) {
                fall_damage = random_range(20, 50);
            }

            if (is_potion() || is_minion_generator() || is_monst()) {
                fall_damage = get_health() / 2;
            }

            auto new_pos = make_point(mid_at);
            if (next_level->is_lava(new_pos)) {
                if (is_player()) {
                    MINICON("%%fg=orange$You plunge into lava! This must be the end for you!%%fg=reset$");
                }
                fall_damage *= 3;
            } else if (next_level->is_fire(new_pos)) {
                if (is_player()) {
                    MINICON("%%fg=orange$You plunge into flames! Not a good move!%%fg=reset$");
                }
                fall_damage *= 2;
            } else if (next_level->is_deep_water(new_pos)) {
                if (is_player()) {
                    MINICON("%%fg=yellow$The deep water lessens the fall!%%fg=reset$");
                }
                fall_damage /= 4;
            } else if (next_level->is_shallow_water(new_pos)) {
                if (is_player()) {
                    MINICON("%%fg=yellow$The water lessens the fall!%%fg=reset$");
                }
                fall_damage /= 2;
            }

            if (is_player()) {
                MINICON("%%fg=red$You take %u fall damage!%%fg=reset$", fall_damage);
            }

            bounce(2.0 /* height */, 0.5 /* fade */, 100, 3);
            next_level->thing_new(tp_random_blood_splatter()->name(), mid_at);

            next_level->scroll_map_to_player();
            update_light();

            //
            // Update the z depth when falling
            // 
            log("End of falling");
            level_pop();
            is_falling = false;
            update_interpolated_position();
            level_push();

            if (is_player()) {
                game->tick_begin("finished fall to next level");
                level->timestamp_fade_in_begin = time_get_time_ms_cached();
                level->update();
            }

            if (tp()->get_health_initial_dice_str() != "") {
                auto h = decr_health(fall_damage);
                if (h <= 0) {
                    h = set_health(0);
                    dead("Flying without wings");
                }
            }
            return true;
        }

        log("No, not floor or lava");
    }
}
