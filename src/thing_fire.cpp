//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_main.h"
#include "my_game.h"
#include "my_level.h"
#include "my_depth.h"
#include "my_thing.h"
#include "my_sprintf.h"

void Thing::fire_tick (void)
{_
    if (g_opt_debug3) {
        log("Fire tick");
    }

    if (is_changing_level ||
        is_hidden || 
        is_falling || 
        is_waiting_to_ascend || 
        is_waiting_to_descend || 
        is_waiting_to_fall || 
        is_the_grid || 
        is_jumping) { 
        if (g_opt_debug3) {
            log("No, not relevent");
        }
        return;
    }

    if (!avoider_of_fire()) {
        if (g_opt_debug3) {
            log("No, is not fire avoider");
        }
        return;
    }

    fpoint at = get_interpolated_mid_at();
    if (!level->is_fire(at.x, at.y) && !is_on_fire()) {
        if (g_opt_debug3) {
            log("No, no fire at");
        }
        return;
    }

    bool hit = false;

    if (is_on_fire()) {
        //
        // Give the player a chance
        //
        if (!level->is_smoke(at.x, at.y)) {
            hit = ((int)random_range(0, 100) < 90);
            if (!hit) {
                if (is_player()) {
                    MINICON("%%fg=green$You feel a brief cool breeze and reprieve from the flames!%%fg=reset$");

                    //
                    // Smoke ensures a reprieve.
                    //
                    if (!level->is_smoke(at.x, at.y)) {
                        auto smoke = level->thing_new("smoke1", at);
                        smoke->set_lifespan(random_range(1, 10));
                    }
                }
            }
        } else {
            hit = false;
        }
    } else if (level->is_fire(at.x, at.y)) {
        //
        // Give the player a chance
        //
        if (!level->is_smoke(at.x, at.y)) {
            auto smoke = level->thing_new("smoke1", at);
            smoke->set_lifespan(random_range(1, 10));

            hit = ((int)random_range(0, 100) < 90);
            if (!hit) {
                if (is_player()) {
                    MINICON("%%fg=red$You dodge the flames");
                }
            } else if ((int)random_range(0, 100) < 20) {
                if (set_on_fire("stepped into fire")) {
                    MINICON("%%fg=red$The flames wrap around you!%%fg=reset$");
                }
            }
        } else {
            hit = false;
        }
    }

    if (hit) {
        auto fire = tp_find("fire");
        auto damage = fire->get_damage_melee();

        if (avoider_of_fire()) {
            damage *= 2;
        }

        auto h = decr_health(damage);
        if (is_player()) {
            MINICON("%%fg=red$You take %u burn damage!%%fg=reset$", damage);
        }

        if (h <= 0) {
            h = set_health(0);
            dead("Burned to death");
        }

        if (!level->is_smoke(at.x, at.y)) {
            auto smoke = level->thing_new("smoke1", at);
            smoke->set_lifespan(random_range(1, 10));
        }
    }
}
