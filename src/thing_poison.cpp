//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_random.hpp"
#include "my_sys.hpp"
#include "my_thing.hpp"
#include "my_thing_template.hpp"
#include "my_tile.hpp"
#include "my_ui.hpp"
#include "my_wid_topcon.hpp"

void Thing::poison_tick(void)
{
  if (! is_monst() && ! is_player()) {
    return;
  }

  auto old_poison = get_poison();
  if (! old_poison) {
    return;
  }

  TRACE_AND_INDENT();
  dbg("Poison tick");
  TRACE_AND_INDENT();

  debuff_add(tp_find("debuff_poisoned"));

  Thingp hitter = this;
  bool   crit   = false;
  bool   bite   = false;
  int    poison = old_poison;
  int    damage = 0;

  if (poison) {
    if ((int) pcg_random_range(0, 20) < get_stat_constitution()) {
      if (is_player()) {
        TOPCON("You take half damage fron poison due to your sturdy constitution.");
      }
      poison /= 2;
    }

    if (poison) {
      is_hit_by(hitter, crit, bite, poison, damage);
    }
  }

  set_poison(old_poison / 2);
}
