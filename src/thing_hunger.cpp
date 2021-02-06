//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_tile.h"
#include "my_thing.h"
#include "my_thing_template.h"

void Thing::hunger_clock (void)
{_
    auto tpp = tp();

    //
    // Does this thing hunger?
    //
    if (!tpp->hunger_clock_freq_ms()) {
        return;
    }

    //
    // Update the hunger clock.
    //
    if (!time_have_x_ms_passed_since(tpp->hunger_clock_freq_ms(),
                                     get_timestamp_hunger_tick())) {
        return;
    }

    set_timestamp_hunger_tick(time_get_time_ms_cached());

    if (get_health() > 1) {
        decr_health();
    } else {
        //
        // starvation is just annoying for players
        //
        // dead("starved to death");
    }

    int hungry_at =
      (int) ((double) get_health_max() *
             ((double) tpp->health_hunger_pct() / 100.0));

    auto old_is_hungry = is_hungry;
    is_hungry = get_health() < hungry_at;

    int starving_at =
      (int) ((double) get_health_max() *
             ((double) tpp->health_starving_pct() / 100.0));

    auto old_is_starving = is_starving;
    is_starving = get_health() < starving_at;

    if (old_is_starving != is_starving) {
        if (is_starving) {
            log("Is starving");
        } else {
            log("Is no longer starving");
        }
    } else if (old_is_hungry != is_hungry) {
        if (is_hungry) {
            log("Is hungry");
        } else {
            log("Is no longer hungry");
        }
    }
}
