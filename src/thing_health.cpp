//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include "my_main.h"
#include "my_tile.h"
#include "my_thing.h"

void Thing::health_boost (int v)
{
    auto old_health = health;
    health += v;
    health = std::min(health, max_health);
    log("health boost %d, %d -> %d", v, old_health, health);
}
