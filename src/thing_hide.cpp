//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_color.h"
#include "my_depth.h"
#include "my_dmap.h"
#include "my_globals.h"
#include "my_level.h"
#include "my_main.h"
#include "my_sprintf.h"
#include "my_sys.h"
#include "my_thing.h"

void Thing::hide(void)
{
  TRACE_AND_INDENT();
  if (is_hidden) {
    return;
  }

  is_hidden = true;

  //
  // Hide the weapon too or it just floats in the air.
  //
  if (get_weapon_id_carry_anim().ok()) {
    auto w = level->thing_find(get_weapon_id_carry_anim());
    if (w) {
      w->hide();
    }
  }

  if (get_weapon_id_use_anim().ok()) {
    auto w = level->thing_find(get_weapon_id_use_anim());
    if (w) {
      w->hide();
    }
  }

  auto on_fire_anim_id = get_on_fire_anim_id();
  if (on_fire_anim_id.ok()) {
    TRACE_AND_INDENT();
    auto w = level->thing_find(on_fire_anim_id);
    if (w) {
      w->hide();
    }
  }
}
