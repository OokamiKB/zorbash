//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_tile.h"
#include "my_thing.h"

void Thing::rest (void)
{_
    log("Resting");
    stamina_boost(1);
}
