//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_array_bounds_check.hpp"
#include "my_game.hpp"
#include "my_monst.hpp"
#include "my_ptrcheck.hpp"
#include "my_thing.hpp"

void Thing::temperature_tick(void)
{
  TRACE_NO_INDENT();

  if (! is_temperature_sensitive()) {
    return;
  }

  //
  // Add in the temperature of the location
  //
  int location_t = 0;

  FOR_ALL_THINGS(level, t, curr_at.x, curr_at.y)
  {
    if (t->is_hidden) {
      continue;
    }

    if (t == this) {
      continue;
    }

    location_t += t->temperature_get();
  }
  FOR_ALL_THINGS_END()

  auto t = temperature_get();
  if (! location_t && ! t) {
    return;
  }

  dbg("Temperature tick");
  TRACE_AND_INDENT();

  temperature_incr(location_t);

  t = temperature_get() + location_t;
  if (! t) {
    return;
  }

  t = (int) ((float) t * 0.5);
  topcon("T%d", t);
  temperature_set(t);

  if (is_temperature_sensitive()) {
    if (game->tick_current != tick_last_i_was_attacked()) {
      if (t <= -100) {
        if (! is_immune_to_cold() || is_player()) {
          auto damage = abs(t) / 20;
          if (is_stone()) {
            popup("Crack!");
            if (is_player()) {
              msg("%%fg=cyan$%s fractures from the extreme cold.%%fg=reset$", text_The().c_str());
            } else {
              msg("%s fractures from the extreme cold.", text_The().c_str());
            }
          } else {
            if (is_player()) {
              msg("%%fg=cyan$%s suffers from the extreme cold.%%fg=reset$", text_The().c_str());
            } else {
              msg("%s suffers from the extreme cold.", text_The().c_str());
            }
          }
          is_attacked_with_damage_cold(this, damage);
        }
      } else if (t >= 100) {
        if (! is_immune_to_fire()) {
          auto damage = abs(t) / 20;
          if (is_stone()) {
            popup("Crack!");
            if (is_player()) {
              msg("%%fg=orange$%s fractures from the extreme heat.%%fg=reset$", text_The().c_str());
            } else {
              msg("%s fractures from the extreme heat.", text_The().c_str());
            }
          } else {
            if (is_player()) {
              msg("%%fg=orange$%s suffers from the extreme heat.%%fg=reset$", text_The().c_str());
            } else if (is_monst()) {
              msg("%s suffers from the extreme heat.", text_The().c_str());
            }
          }
          if (fire_tick()) {
            is_attacked_with_damage_fire(this, damage);
          }
        }
      }
    }
  }
}

int Thing::temperature_get(void)
{
  TRACE_NO_INDENT();
  if (maybe_infop()) {
    return (infop()->temperature);
  } else {
    return 0;
  }
}

int Thing::temperature_set(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->request_update_rightbar = true;
  }
  new_infop();
  auto n = (infop()->temperature = v);
  return (n);
}

int Thing::temperature_decr(int v) { return temperature_incr(-v); }

int Thing::temperature_incr(int v)
{
  TRACE_NO_INDENT();

  if (! v) {
    return v;
  }

  if (is_flying()) {
    return v;
  }
  if (is_floating()) {
    return v;
  }
  if (is_dead) {
    return v;
  }
  if (is_undead()) {
    return v;
  }

  log("Increment temp %d", v);
  TRACE_AND_INDENT();

  auto T = temperature_get();

  if (is_temperature_change_sensitive()) {
    if (v > 0) {
      if (T < 0) {
        auto damage = (v - T) / 10;
        if (is_stone()) {
          popup("Crack!");
          if (is_player()) {
            msg("%%fg=orange$%s cracks from the change in temperature.%%fg=reset$", text_The().c_str());
          } else {
            msg("%s cracks from the change in temperature.%%fg=reset$", text_The().c_str());
          }
        } else {
          if (is_player()) {
            msg("%%fg=orange$%s suffers from the change in temperature.%%fg=reset$", text_The().c_str());
          } else {
            msg("%s suffers from the change in temperature.%%fg=reset$", text_The().c_str());
          }
        }
        is_attacked_with_damage_fire(this, damage);
      }
    } else if (v < 0) {
      if (T > 0) {
        auto damage = (T - v) / 10;
        if (is_stone()) {
          popup("Crack!");
          if (is_player()) {
            msg("%%fg=cyan$%s cracks from the change in temperature.%%fg=reset$", text_The().c_str());
          } else {
            msg("%s cracks from the change in temperature.", text_The().c_str());
          }
        } else {
          if (is_player()) {
            msg("%%fg=cyan$%s suffers from the change in temperature.%%fg=reset$", text_The().c_str());
          } else {
            msg("%s suffers from the change in temperature.", text_The().c_str());
          }
        }
        is_attacked_with_damage_cold(this, damage);
      }
    }
  }

  if (is_player()) {
    game->request_update_rightbar = true;
  }

  new_infop();
  auto n = (infop()->temperature += v);

  if (n > 1000) {
    n                    = 1000;
    infop()->temperature = v;
  } else if (n < -1000) {
    n                    = -1000;
    infop()->temperature = v;
  }

  return (n);
}

int Thing::temperature_decr(void) { return temperature_incr(-1); }

int Thing::temperature_incr(void) { return temperature_incr(1); }
