//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_array_bounds_check.hpp"
#include "my_backtrace.hpp"
#include "my_game.hpp"
#include "my_math.hpp"
#include "my_monst.hpp"
#include "my_ptrcheck.hpp"
#include "my_python.hpp"
#include "my_random.hpp"
#include "my_sprintf.hpp"
#include "my_sys.hpp"
#include "my_thing.hpp"
#include "my_thing_template.hpp"

void Thing::temperature_tick(void)
{
  TRACE_NO_INDENT();

  auto t = get_temperature();
  if (! t) {
    return;
  }

  dbg("Temperature tick");
  TRACE_AND_INDENT();

  t = (int) ((float) t * 0.95);
  set_temperature(t);
}

int Thing::get_temperature(void)
{
  TRACE_NO_INDENT();
  if (maybe_infop()) {
    return (get_infop()->temperature);
  } else {
    return 0;
  }
}

int Thing::set_temperature(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->request_update_rightbar = true;
  }
  new_infop();
  auto n = (get_infop()->temperature = v);
  return (n);
}

int Thing::decr_temperature(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->request_update_rightbar = true;
  }
  new_infop();
  auto n = (get_infop()->temperature -= v);
  return (n);
}

int Thing::incr_temperature(int v)
{
  TRACE_NO_INDENT();

  if (! v) {
    return v;
  }

  auto T = get_temperature();

  if (v > 0) {
    if (T < 0) {
      if (is_alive_monst()) {
        if (temperature_change_sensitive()) {
          if (is_stone()) {
            msg("%s cracks from the change in temperature.", text_The().c_str());
          } else {
            msg("%s suffers from the change in temperature.", text_The().c_str());
          }
          is_attacked_with_damage_fire(this, (v - T) / 10);
        }
      }
    }
  } else if (v < 0) {
    if (T > 0) {
      if (is_alive_monst()) {
        if (temperature_change_sensitive()) {
          if (is_stone()) {
            msg("%s cracks from the change in temperature.", text_The().c_str());
          } else {
            msg("%s suffers from the change in temperature.", text_The().c_str());
          }
          is_attacked_with_damage_cold(this, (T - v) / 10);
        }
      }
    }
  } else if (v < -100) {
    if (is_alive_monst()) {
      if (temperature_change_sensitive()) {
        if (is_stone()) {
          msg("%s fractures from the extreme cold.", text_The().c_str());
        } else {
          msg("%s suffers from the extreme cold.", text_The().c_str());
        }
        is_attacked_with_damage_fire(this, abs(v) / 10);
      }
    }
  } else if (v > 100) {
    if (is_alive_monst()) {
      if (temperature_change_sensitive()) {
        if (is_stone()) {
          msg("%s fractures from the extreme heat.", text_The().c_str());
        } else {
          msg("%s suffers from the extreme heat.", text_The().c_str());
        }
        is_attacked_with_damage_cold(this, abs(v) / 10);
      }
    }
  }

  if (is_player()) {
    game->request_update_rightbar = true;
  }
  new_infop();
  auto n = (get_infop()->temperature += v);
  return (n);
}

int Thing::decr_temperature(void)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->request_update_rightbar = true;
  }
  new_infop();
  auto n = (get_infop()->temperature--);
  return (n);
}

int Thing::incr_temperature(void)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->request_update_rightbar = true;
  }
  new_infop();
  auto n = (get_infop()->temperature++);
  return (n);
}
