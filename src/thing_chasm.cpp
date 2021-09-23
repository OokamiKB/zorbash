//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
// Please use spaces indent of 2, no tabs and column width of 120 to view.
//

#include "my_sys.h"
#include "my_game.h"
#include "my_depth.h"
#include "my_color.h"
#include "my_dmap.h"
#include "my_sprintf.h"
#include "my_level.h"
#include "my_thing.h"
#include "my_globals.h"

void Thing::chasm_tick(void)
{
  TRACE_AND_INDENT();
  if (is_floating() || is_ethereal()) {
    return;
  }

  if (level->is_chasm(mid_at.x, mid_at.y)) {
    dbg("Over a chasm");
    fall(1, 750);
  }
}
