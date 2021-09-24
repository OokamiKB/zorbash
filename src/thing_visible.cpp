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

void Thing::visible(void)
{
  TRACE_AND_INDENT();
  if (! is_hidden) {
    return;
  }

  //
  // If this thing has an owner, should the thing stay hidden?
  //
  auto owner = get_top_owner();
  if (owner) {
    if (this == owner->weapon_get_carry_anim()) {
      if (owner->weapon_get_use_anim()) {
        //
        // Stay hidden until the weapon use is done.
        //
        dbg("Stay hidden until weapon use is done");
        return;
      }
    }
  }

  is_hidden = false;

  //
  // Reveal the weapon again too.
  //
  if (get_weapon_id_carry_anim().ok()) {
    auto w = level->thing_find(get_weapon_id_carry_anim());
    if (w) {
      w->visible();
    }
  }

  if (get_weapon_id_use_anim().ok()) {
    auto w = level->thing_find(get_weapon_id_use_anim());
    if (w) {
      w->visible();
    }
  }

  auto on_fire_anim_id = get_on_fire_anim_id();
  if (on_fire_anim_id.ok()) {
    TRACE_AND_INDENT();
    auto w = level->thing_find(on_fire_anim_id);
    if (w) {
      w->visible();
    }
  }

  move_finish();
}

uint8_t Thing::is_visible(void) const
{
  TRACE_AND_INDENT();
  return (! is_hidden);
}
