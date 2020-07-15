//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_main.h"
#include "my_level.h"
#include "my_depth.h"
#include "my_thing.h"
#include "my_sprintf.h"

void Thing::acid_tick (void)
{_
    if (is_acid_hater()) {
        if (level->is_acid(mid_at.x, mid_at.y)) {
            bool hit;

            //
            // Give the player a chance
            //
            if (!level->is_smoke(mid_at.x, mid_at.y)) {
                auto smoke = level->thing_new("smoke1", mid_at);
                smoke->set_lifespan(4);

                hit = ((int)random_range(0, 100) < 50);
            } else {
                hit = true;
            }

            if (hit) {
                FOR_ALL_THINGS_AT_DEPTH(level, t, mid_at.x, mid_at.y, MAP_DEPTH_FLOOR2) {
                    auto tpp = t->tp();
                    if (!tpp->is_acid()) {
                        continue;
                    }
                    is_hit_by(t, t->get_stats_attack());
                    break;
                } FOR_ALL_THINGS_END()
            } else {
                if (is_player()) {
                    MINICON("Your shoes are dissolving!");
                }
            }
        }
    }
}
