//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

// REMOVED #include "my_array_bounds_check.hpp"
#include "my_game.hpp"
// REMOVED #include "my_globals.hpp"
// REMOVED #include "my_math.hpp"
#include "my_monst.hpp"
// REMOVED #include "my_player.hpp"
// REMOVED #include "my_ptrcheck.hpp"
// REMOVED #include "my_random.hpp"
// REMOVED #include "my_sprintf.hpp"
// REMOVED #include "my_sys.hpp"
// REMOVED #include "my_template.hpp"
#include "my_thing.hpp"
// REMOVED #include "my_thing_ai.hpp"
// REMOVED #include "my_thing_template.hpp"

bool Thing::state_resting(bool &do_something, bool &wait)
{
  TRACE_NO_INDENT();

  //
  // If attacked, we should be kicked out of resting
  //
  // If resting, check if we are rested enough.
  //
  if ((health() >= (health_max() / 4) * 3) && (stamina_get() >= (stamina_max() / 4) * 3)) {
    AI_LOG("Rested enough. Back to work.");
    if (is_player()) {
      game->tick_begin("Robot has rested enough");
    }
    change_state(MONST_STATE_IDLE, "rested enough");
    infop()->last_failed_jump_at = point(0, 0);
    return true;
  }

  //
  // Check for food first, before abandoning resting
  //
  if (eat_something()) {
    AI_LOG("Ate an item.");
    if (is_player()) {
      game->tick_begin("Robot ate an item");
    }
    change_state(MONST_STATE_OPEN_INVENTORY, "eat something");
    return true;
  }

  AI_LOG("Wait and rest.");

  if (is_able_to_sleep()) {
    sleep_count_incr();
    if (sleep_count() > 5) {
      change_state(MONST_STATE_SLEEPING, "time to sleep");
    }
  }

  do_something = true;
  wait         = true;

  return false;
}
