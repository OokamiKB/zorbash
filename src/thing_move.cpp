//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_game.h"
#include "my_thing.h"
#include "my_sprintf.h"
#include "my_gl.h"
#include "my_wid_thing_collect.h"
#include "my_array_bounds_check.h"
#include "my_vector_bounds_check.h"
#include "my_thing_template.h"
#include "my_ptrcheck.h"

void Thing::move_completed (void)
{_
    if (is_player()) {
        if (check_anything_to_carry()) {
            BOTCON("Press %%fg=yellow$%s%%fg=reset$ to collect items",
                   SDL_GetScancodeName(
                        (SDL_Scancode)game->config.key_wait_or_collect));
        }

#if 0
        if (THING_TICK_MAX_MOVES_AHEAD == 1) {
            for (auto i : level->all_active_things) {
                auto t = i.second;
                if (t->is_monst()) {
                    t->set_tick(game->tick_current);
                }
            }
        }
#endif
    }
    set_timestamp_move_begin(0);
    set_timestamp_move_end(0);
}

void Thing::move_finish (void)
{_
    if (get_timestamp_move_begin() == 0) {
        return;
    }

    //
    // Set this so that we can pick up items again at the last location.
    //
    set_where_i_dropped_an_item_last(point(-1, -1));
    move_completed();

    log("Move finish");
    set_timestamp_move_begin(0);
    set_timestamp_move_end(0);
    update_interpolated_position();
}

bool Thing::move (fpoint future_pos)
{_
    log("Move to %f,%f", future_pos.x, future_pos.y);
    bool up     = future_pos.y < mid_at.y;
    bool down   = future_pos.y > mid_at.y;
    bool left   = future_pos.x < mid_at.x;
    bool right  = future_pos.x > mid_at.x;
    bool attack = false;
    bool wait_or_collect   = false;

    verify(this);
    return (move(future_pos, up, down, left, right, attack, wait_or_collect, true));
}

bool Thing::move_no_shove (fpoint future_pos)
{
    log("Move, without shoving to %f,%f", future_pos.x, future_pos.y);
    bool up     = future_pos.y < mid_at.y;
    bool down   = future_pos.y > mid_at.y;
    bool left   = future_pos.x < mid_at.x;
    bool right  = future_pos.x > mid_at.x;
    bool attack = false;
    bool wait_or_collect   = false;

    verify(this);
    return (move(future_pos, up, down, left, right, attack, wait_or_collect, false));
}

bool Thing::move (fpoint future_pos,
                  uint8_t up,
                  uint8_t down,
                  uint8_t left,
                  uint8_t right,
                  uint8_t attack,
                  uint8_t wait_or_collect,
                  bool shove_allowed)
{_
    log("Moved");

    if (is_dead) {
        return false;
    }

    if (is_changing_level ||
        is_hidden || 
        is_falling || 
        is_waiting_to_ascend_dungeon || 
        is_waiting_to_descend_sewer || 
        is_waiting_to_descend_dungeon || 
        is_waiting_to_ascend_sewer || 
        is_jumping) { 
        return false;
    }

    if (!attack) {
        rest();
    }

    if (wait_or_collect) {
        if (is_player()) {
            game->tick_begin("player idled");
        }

        auto items = anything_to_carry();
        if (!items.empty()) {
            if (items.size() > 1) {
                game->wid_thing_collect_create(items);
            } else {
                try_to_carry(items);
            }
        } else {
            MINICON("You wait...");
        }

        location_check();
        return false;
    }

    auto x = future_pos.x;
    auto y = future_pos.y;
    auto delta = fpoint(x, y) - mid_at;

    if (tp()->gfx_bounce_on_move()) {
        if (get_bounce() == 0) {
            bounce(0.2 /* height */, 0.1 /* fade */, 200, 3);
        }
    }

    move_set_dir_from_delta(delta);

    if (attack) {
        use_weapon();

        if (is_player()) {
            game->tick_begin("player attacked");
        }

        return false;
    }

    if ((x == mid_at.x) && (y == mid_at.y)) {
        return false;
    }

    if (is_player()) {
        game->tick_begin("player moved");
        log("Player move");
        _

        if (mid_at != future_pos) {
            log("Try to move; collision check");
            if (collision_check_only(future_pos)) {
                log("Cannot move; try to shove");
                if (shove_allowed) {
                    try_to_shove(future_pos);
                }
                lunge(future_pos);
                log("Move failed");
                return false;
            }
        }

        set_where_i_failed_to_collect_last(point(-1, -1));

        if (!level->map_follow_player) {
            level->map_follow_player = true;
            level->cursor_needs_update = true;
        }
    }
_
    auto t = nearby_most_dangerous_thing_get();
    if (t) {
        auto free_attack =
             (t->get_tick() < game->tick_current) &&
             (((t->mid_at.x >= mid_at.x) && left) ||
              ((t->mid_at.x <= mid_at.x) && right) ||
              ((t->mid_at.y >= mid_at.y) && up) ||
              ((t->mid_at.y <= mid_at.y) && down));

        if (free_attack) {_
            log("Free attack by %s", t->to_string().c_str());
            if (t->attack(this)) {
                //
                // Too noisy?
                //
                if ((0)) {
                    if (is_player()) {
                        std::string s = t->text_The() + " attacks as you run";
                        MINICON("%s", s.c_str());
                    }
                }
            }

            //
            // Even if it misses, it counts
            //
            t->update_tick();
        }
    }

    if (tp()->gfx_animated_can_hflip()) {
        if (future_pos.x > mid_at.x) {
            if (is_facing_left && !get_timestamp_flip_start()) {
                set_timestamp_flip_start(time_get_time_ms_cached());
            }
        } else if (future_pos.x < mid_at.x) {
            if (!is_facing_left && !get_timestamp_flip_start()) {
                set_timestamp_flip_start(time_get_time_ms_cached());
            }
        }
    }

    if (up || down || left || right) {
        move_delta(delta);
    }

    return true;
}

void Thing::update_interpolated_position (void)
{_
    bool update_pos = false;
    fpoint new_pos;
    auto tpp = tp();

    auto p = get_top_owner();
    if ((p && p->is_falling) || is_falling) {
        z_depth = MAP_DEPTH_FLOOR;
    } else {
        z_depth = tpp->z_depth;
    }

    //
    // We don't want to hit lava twice as we move onto it, so only do the location
    // check if we really move.
    //
    bool do_location_check = false;

    if (is_jumping) {
        float t = get_timestamp_jump_end() - get_timestamp_jump_begin();
        float dt = time_get_time_ms_cached() - get_timestamp_jump_begin();
        float step = dt / t;
        float dx = mid_at.x - last_mid_at.x;
        float dy = mid_at.y - last_mid_at.y;

        update_pos = true;
        new_pos.x = last_mid_at.x + dx * step;
        new_pos.y = last_mid_at.y + dy * step;
        do_location_check = false;
    } else if (!get_timestamp_move_end()) {
        if (mid_at != last_mid_at) {
            do_location_check = true;
            log("Changed position (new %f, %f, old %f,%f); do location check",
                mid_at.x, mid_at.y, last_mid_at.x, last_mid_at.y);

            update_pos = true;
            new_pos = mid_at;
            last_mid_at = mid_at;
            set_timestamp_move_end(time_get_time_ms_cached());
        }
    } else if (time_get_time_ms_cached() >= get_timestamp_move_end()) {
        if (mid_at != last_mid_at) {
            do_location_check = true;
            log("End of move position (new %f, %f, old %f,%f); do location check",
                mid_at.x, mid_at.y, last_mid_at.x, last_mid_at.y);

            update_pos = true;
            new_pos = mid_at;
            last_mid_at = mid_at;

            //
            // In case we changed level, update these
            //
            new_pos = mid_at;
            last_mid_at = mid_at;

            move_completed();
        }

        //
        // If the dead widget popped up, it waited for our move to end
        //
        if (is_player() && is_dead) {
            game->soft_pause();
        }
    } else {
        float t = get_timestamp_move_end() - get_timestamp_move_begin();
        float dt = time_get_time_ms_cached() - get_timestamp_move_begin();
        float step = dt / t;
        float dx = mid_at.x - last_mid_at.x;
        float dy = mid_at.y - last_mid_at.y;

        new_pos.x = last_mid_at.x + dx * step;
        new_pos.y = last_mid_at.y + dy * step;
        update_pos = true;
    }

    if (update_pos) {
        if (g_opt_debug3) {
            log("Update interpolated pos");
        }

        level_pop();
        set_interpolated_mid_at(new_pos);
        level_push();

        //
        // For now only the player has a calculated light
        //
        update_light();

        if (do_location_check) {
            location_check();
        }
    }
}

void Thing::update_pos (fpoint to, bool immediately, uint32_t speed)
{_
    log("Update pos to %f,%f", to.x, to.y);

    auto tpp = tp();
    point new_at((int)to.x, (int)to.y);
    if (level->is_oob(new_at)) {
        return;
    }

    point old_at((int)mid_at.x, (int)mid_at.y);

    if (!has_ever_moved) {
        last_mid_at = to;
    }

    has_ever_moved = true;

    //
    // Keep track of where this thing is on the grid
    //
    if (old_at != new_at) {
        if (is_player()) {
            if (((int)old_at.x != (int)new_at.x) ||
                ((int)old_at.y != (int)new_at.y)) {
                level->minimap_valid = false;
            }
        }
    }

    int move_speed;
    if (speed) {
        move_speed = speed;
    } else {
        auto owner = get_top_owner();
        if (owner) {
            move_speed = owner->tp()->move_speed_ms();
        } else{
            move_speed = tpp->move_speed_ms();
        }
    }

    //
    // Moves are immediate, but we render the move in steps, hence keep
    // track of when we moved.
    //
    if (to == mid_at) {
        return;
    }

    log("Move to %f,%f", to.x, to.y);
    level_pop();
    mid_at = to;
    level_push();

    if (!immediately) {
        set_timestamp_move_begin(time_get_time_ms_cached());
        set_timestamp_move_end(get_timestamp_move_begin() + move_speed);
    }

    move_carried_items();

    if (!is_hidden) {
        if (tpp->is_loggable_for_unimportant_stuff()) {
            log("Moved");
        }
    }
}

void Thing::move_set_dir_from_delta (fpoint delta)
{
    //
    // If not moving and this is the first move then break out of the
    // idle animation.
    //
    if (is_dir_none()) {
        timestamp_next_frame = time_get_time_ms_cached();
    }

    if (delta.x < 0) {
        if (delta.y > 0) {
            dir_set_bl();
        } else if (delta.y < 0) {
            dir_set_tl();
        } else {
            dir_set_left();
        }
        is_moving = true;
        has_ever_moved = true;
        return;
    }

    if (delta.x > 0) {
        if (delta.y > 0) {
            dir_set_br();
        } else if (delta.y < 0) {
            dir_set_tr();
        } else {
            dir_set_right();
        }
        is_moving = true;
        has_ever_moved = true;
        return;
    }

    if (delta.y > 0) {
        if (delta.x > 0) {
            dir_set_br();
        } else if (delta.x < 0) {
            dir_set_bl();
        } else {
            dir_set_down();
        }
        is_moving = true;
        has_ever_moved = true;
        return;
    }

    if (delta.y < 0) {
        if (delta.x > 0) {
            dir_set_tr();
        } else if (delta.x < 0) {
            dir_set_tl();
        } else {
            dir_set_up();
        }
        is_moving = true;
        has_ever_moved = true;
        return;
    }
}

void Thing::move_to (fpoint to)
{_
    move_finish();
    auto delta = to - mid_at;
    move_set_dir_from_delta(delta);
    update_pos(to, false);
}

void Thing::move_to (fpoint to, uint32_t speed)
{_
    move_finish();
    auto delta = to - mid_at;
    move_set_dir_from_delta(delta);
    update_pos(to, false, speed);
}

void Thing::move_delta (fpoint delta)
{_
    move_finish();
    move_set_dir_from_delta(delta);
    update_pos(mid_at + delta, false);
}

void Thing::move_to_immediately (fpoint to)
{_
    move_finish();
    auto delta = to - mid_at;
    move_set_dir_from_delta(delta);
    update_pos(to, true);
    move_finish();

    //
    // End of jump handles this
    //
    if (!is_jumping) {
        location_check();
    }

    if (is_player()) {
        if (!level->map_follow_player) {
            level->map_follow_player = true;
            level->cursor_needs_update = true;
        }
    }
}

void Thing::move_to_immediately_delta (fpoint delta)
{_
    move_finish();
    move_set_dir_from_delta(delta);
    update_pos(mid_at + delta, true);
    move_finish();

    //
    // End of jump handles this
    //
    if (!is_jumping) {
        location_check();
    }

    if (is_player()) {
        if (!level->map_follow_player) {
            level->map_follow_player = true;
            level->cursor_needs_update = true;
        }
    }
}

bool Thing::move_to_check (const point& nh, const bool escaping)
{_
    if (escaping) {
        log("Escape to check %d,%d", nh.x, nh.y);
    } else {
        log("Move to check %d,%d", nh.x, nh.y);
    }

    //
    // Check to see if moving to this new location will hit something
    //
    // We need to look at the next-hop at the current time which may
    // be vacant, but also to the future if a thing is moving to that
    // spot; in which case we get an attack of opportunity.
    //
    auto fnh = fpoint(nh.x, nh.y);
    if (collision_check_only(fnh)) {
        //
        // We would hit something and cannot do this move. However,
        // see if we can hit the thing that is in the way.
        //
        log("Cannot move to %d,%d will hit obstacle or monst", nh.x, nh.y);
_
        bool target_attacked = false;
        bool target_overlaps = false;
        collision_check_and_handle_nearby(fnh,
                                          &target_attacked,
                                          &target_overlaps);
        if (target_attacked) {
            is_tick_done = true;
            log("Cannot move to %d,%d, must attack", nh.x, nh.y);
            return true;
        } else {
            log("Cannot move to %d,%d, obstacle", nh.x, nh.y);
            return false;
        }
    } else {
        log("Move to %d,%d is ok", nh.x, nh.y);

        if (!escaping) {
            if (is_less_preferred_terrain(nh)) {_
                log("But %d,%d is less preferred terrain, avoid", nh.x, nh.y);
                return false;
            }
        }

        is_tick_done = true;
        move(fnh);
        return true;
    }
}

bool Thing::move_to_or_attack (const point& nh)
{_
    log("Move to or attack");
    return move_to_check(nh, false);
}

bool Thing::move_to_or_escape (const point& nh)
{_
    log("Move to or escape");
    return move_to_check(nh, true);
}
