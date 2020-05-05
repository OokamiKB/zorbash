//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include "my_game.h"
#include "my_thing.h"
#include "my_sprintf.h"
#include "my_gl.h"

void Thing::bounce (double bounce_height,
                    double bounce_fade,
                    timestamp_t ms,
                    int bounce_count)
{
    auto t = set_timestamp_bounce_begin(time_get_time_ms_cached());
    set_timestamp_bounce_end(t + ms);

    set_bounce_height(bounce_height);
    set_bounce_fade(bounce_fade);
    set_bounce_count(bounce_count);
    is_bouncing = true;
}

double Thing::get_bounce (void)
{
    if (!is_bouncing) {
        return (0.0);
    }

    auto t = time_get_time_ms_cached();

    if (t >= get_timestamp_bounce_end()) {
        is_bouncing = false;

        if (get_bounce_count()) {
            bounce(
                get_bounce_height() * get_bounce_fade(),
                get_bounce_fade(),
                (double)(get_timestamp_bounce_end() -
                         get_timestamp_bounce_begin()) * get_bounce_fade(),
                get_bounce_count() - 1);
        }

        return (0);
    }

    double time_step =
        (double)(t - get_timestamp_bounce_begin()) /
        (double)(get_timestamp_bounce_end() - get_timestamp_bounce_begin());

    double height = 1.0;

    height *= sin(time_step * RAD_180);
    height *= get_bounce_height();

    return (height);
}
