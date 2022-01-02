//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_array_bounds_check.hpp"
#include "my_depth.hpp"
#include "my_game.hpp"
#include "my_globals.hpp"
#include "my_level.hpp"
#include "my_ptrcheck.hpp"
#include "my_random.hpp"
#include "my_sprintf.hpp"
#include "my_sys.hpp"
#include "my_thing.hpp"
#include "my_thing_template.hpp"

void Thing::lava_tick(void)
{
  TRACE_NO_INDENT();

  if (! environ_avoids_fire()) {
    return;
  }

  point at = curr_at;
  if (! level->is_lava(at.x, at.y)) {
    return;
  }

  dbg("Lava tick");
  TRACE_NO_INDENT();

  bool hit = false;

  //
  // Give the player a chance
  //
  if (! level->is_smoke(at.x, at.y)) {
    hit = (d100() < 80);
  } else {
    hit = true;
  }

  if (is_on_fire()) {
    hit = true;
  }

  if (hit) {
    FOR_ALL_THINGS_AT_DEPTH(level, t, at.x, at.y, MAP_DEPTH_LAVA)
    {
      if (! t->is_lava()) {
        continue;
      }

      is_attacked_with_damage_fire(t, t->get_damage_fire());
      break;
    }
    FOR_ALL_THINGS_END()
  } else {
    if (is_player()) {
      TOPCON("You stand on a sightly cooler rock in the lava!");
      TOPCON("Your feet are warm and toasty!");
    }
  }

  if (! level->is_smoke(at.x, at.y)) {
    auto smoke = level->thing_new("smoke", at);
    smoke->set_lifespan(pcg_random_range(1, 10));
  }
}
