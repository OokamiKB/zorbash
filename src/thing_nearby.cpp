//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include <algorithm>
#include <set>
#include "my_sys.h"
#include "my_level.h"
#include "my_dmap.h"
#include "my_math.h"
#include "my_thing.h"
#include "my_array_bounds_check.h"
#include "my_thing_template.h"
#include "my_ptrcheck.h"

Thingp Thing::nearby_most_dangerous_thing_get (void)
{
    std::vector<std::pair<Thingp, int> > possible;

    static const std::vector<point> all_deltas = {
        point(-1, -1),
        point( 1, -1),
        point(-1,  1),
        point( 1,  1),
        point(0, -1),
        point(-1, 0),
        point(1, 0),
        point(0, 1),
        point(0, 0), // For spiderwebs
    };

    for (const auto& d : all_deltas) {
        auto x = mid_at.x + d.x;
        auto y = mid_at.y + d.y;

        FOR_ALL_THINGS(level, t, x, y) {
            if (t == this) {
                continue;
            }

            if (t->is_dead) {
                continue;
            }

            //
            // Treat as a threat so they attack
            //
            if (t->is_spiderweb()) {
                if (t->mid_at == mid_at) {
                    possible.push_back(std::make_pair(t, 666));
                    continue;
                }
            }

            if (!t->is_monst()) {
                continue;
            }

            auto score = t->get_health();
            if (will_avoid_threat(point(x, y))) {
                score += t->get_health_max();
            }

            possible.push_back(std::make_pair(t, score));
        } FOR_ALL_THINGS_END()
    }

    if (!possible.size()) {
        return nullptr;
    }

    sort(possible.begin(),
         possible.end(),
         [](const std::pair<Thingp, int> &a,
            const std::pair<Thingp, int> &b) -> bool {
             return a.second > b.second;
         });

    return possible[0].first;
}
