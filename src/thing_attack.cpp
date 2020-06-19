//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include <algorithm>
#include <set>
#include "my_main.h"
#include "my_level.h"
#include "my_dmap.h"
#include "my_math.h"
#include "my_thing.h"

bool Thing::possible_to_attack (const Thingp itp)
{_
    auto me = tp();
    auto it = itp->tp();

    if (!it->is_attackable()) {
        return (false);
    }

    if (is_alive_monst()) {
        if (me->is_meat_eater()) {
            if (it->is_made_of_meat() || it->is_blood()) {
                log("can attack %s", itp->to_string().c_str());
                return (true);
            }
        }
    }

    if (is_player()) {
        log("can attack %s", itp->to_string().c_str());
        return (true);
    }

    if (is_weapon()) {
        log("can attack %s", itp->to_string().c_str());
        return (true);
    }

    if (me->is_fire() || me->is_lava()) {
        if (it->is_combustible()) {
            if (!it->is_fire() && !it->is_lava()) {
                log("can attack %s", itp->to_string().c_str());
                return (true);
            }
        }
    }

    log("ignore attack %s", itp->to_string().c_str());
    return (false);
}
