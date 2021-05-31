//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_game.h"
#include "my_level.h"
#include "my_depth.h"
#include "my_thing.h"
#include "my_sprintf.h"
#include "my_ptrcheck.h"
#include "my_array_bounds_check.h"

//
// This is called if we move onto or fall onto a new location
//
// It is also called at the end of all moves for the current tick
// to handle things that do not move but something has happened to
// like they caught on fire
//
void Thing::location_check_forced (void)
{_
    //
    // Prevent interactions that might generate things like smoke.
    //
    if (level->is_being_destroyed) {
        if (is_player()) {
            log("Location check, skip, level is being destroyed");
        }
        return;
    }

    if (is_being_destroyed) {
        if (is_player()) {
            log("Location check, skip, being destroyed");
        }
        return;
    }

    if (is_hidden) {
        if (is_player()) {
            log("Location check, skip, is hidden");
        }
        return;
    }

    if (is_player()) {
        log("Location check, do");
    }

    //
    // Put chasm checks first as you can still fall when dead!
    //
    if (is_changing_level ||
        is_the_grid || 
        is_hidden || 
        is_falling || 
        is_waiting_to_ascend_dungeon || 
        is_waiting_to_descend_sewer || 
        is_waiting_to_descend_dungeon || 
        is_waiting_to_ascend_sewer || 
        is_waiting_to_fall || 
        get_immediate_owner() ||
        is_jumping) { 
        //
        // Skip interactions
        //
        return;
    }

    chasm_tick();
    if (is_dead) {
        return;
    }
    barrel_tick();
    if (is_dead) {
        return;
    }
    brazier_tick();
    if (is_dead) {
        return;
    }
    water_tick();
    if (is_dead) {
        return;
    }
    lava_tick();
    if (is_dead) {
        return;
    }
    acid_tick();
    if (is_dead) {
        return;
    }
    fire_tick();
    if (is_dead) {
        return;
    }
    grass_tick();
    if (is_dead) {
        return;
    }

    if (!is_able_to_change_levels()) {
        return;
    }

    if (descend_dungeon_tick()) {
        if (is_player()) {
            log("Location check, descending dungeon");
        }
        return;
    }
    if (ascend_dungeon_tick()) {
        if (is_player()) {
            log("Location check, ascending dungeon");
        }
        return;
    }
    if (descend_sewer_tick()) {
        if (is_player()) {
            log("Location check, descending sewer");
        }
        return;
    }
    if (ascend_sewer_tick()) {
        if (is_player()) {
            log("Location check, ascending sewer");
        }
        return;
    }
}

void Thing::location_check (void)
{_
    if (get_tick_last_location_check() == game->tick_current) {
        if (is_player()) {
            log("Skip location check, already done. Last check %d, game tick %d",
                get_tick_last_location_check(), game->tick_current);
        }
        return;
    }

    if (is_player()) {
        log("Do location check. Last check %d, game tick %d",
            get_tick_last_location_check(), game->tick_current);
    }

    set_tick_last_location_check(game->tick_current);

    location_check_forced();
}

//
// Check all things at this location. In this case we check it
// already performed, so we don't for example do a lava check
// again initiated by being set on fire by lava.
//
void Thing::location_check_all_things_at (void)
{_
    log("Do location checks");
    FOR_ALL_INTERESTING_THINGS(level, t, mid_at.x, mid_at.y) {_
        t->log("Do location check");
        t->location_check();
    } FOR_ALL_THINGS_END()
}

//
// Check all things at this location
//
void Thing::location_check_forced_all_things_at (void)
{_
    log("Do location checks");
    FOR_ALL_INTERESTING_THINGS(level, t, mid_at.x, mid_at.y) {_
        t->log("Do location check");
        t->location_check_forced();
    } FOR_ALL_THINGS_END()
}
