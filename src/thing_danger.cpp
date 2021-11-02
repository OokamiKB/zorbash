//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_globals.hpp"
#include "my_level.hpp"
#include "my_main.hpp"
#include "my_sys.hpp"
#include "my_thing.hpp"
#include "my_thing_template.hpp"

int Tp::get_danger_level(void)
{
  TRACE_AND_INDENT();
  int danger_level = 0;

  danger_level = get_health_initial() / 10;

  if (is_undead()) {
    danger_level += 1;
  }
  if (is_sticky()) {
    danger_level += 1;
  }
  if (is_spiderweb()) {
    danger_level += 5;
  }
  if (is_resurrectable()) {
    danger_level *= 2;
  }
  if (ai_is_able_to_shove()) {
    danger_level++;
  }
  if (is_acid()) {
    danger_level++;
  }
  if (is_hunger_insatiable()) {
    danger_level++;
  }
  if (is_fire()) {
    danger_level++;
  }
  if (is_lava()) {
    danger_level++;
  }
  if (is_poison()) {
    danger_level += is_poison();
  }
  if (is_floating()) {
    danger_level += 2;
  }
  if (ai_is_able_to_jump()) {
    danger_level += 5;
  }
  if (is_item_eater()) {
    danger_level += 20;
  }
  if (is_able_to_fire_at()) {
    danger_level += 20;
  }

  danger_level +=
      std::max(get_damage_melee_dice().max_roll(),
               std::max(get_damage_poison_dice().max_roll(),
                        std::max(get_damage_swallow_dice().max_roll(), get_damage_bite_dice().max_roll())));

  //
  // Don't include crush damage as it is non typical
  //

  // CON("level %d", danger_level);
  return danger_level;
}

int Thing::get_danger_initial_level(void)
{
  TRACE_AND_INDENT();
  int danger_level = 0;

  danger_level = get_health_initial() / 10;

  if (is_undead()) {
    danger_level += 1;
  }
  if (is_sticky()) {
    danger_level += 1;
  }
  if (is_spiderweb()) {
    danger_level += 5;
  }
  if (is_resurrectable()) {
    danger_level *= 2;
  }
  if (ai_is_able_to_shove()) {
    danger_level++;
  }
  if (is_carrying_item()) {
    danger_level++;
  }
  if (is_acid()) {
    danger_level++;
  }
  if (is_hunger_insatiable()) {
    danger_level++;
  }
  if (is_poison()) {
    danger_level++;
  }
  if (is_fire()) {
    danger_level++;
  }
  if (is_lava()) {
    danger_level++;
  }
  if (is_poison()) {
    danger_level += is_poison();
  }
  if (is_floating()) {
    danger_level += 2;
  }
  if (ai_is_able_to_jump()) {
    danger_level += 5;
  }
  if (is_item_eater()) {
    danger_level += 20;
  }
  if (is_able_to_fire_at()) {
    danger_level += 20;
  }

  danger_level += get_damage_max();

  //
  // Low on health, reduce the level
  //
  if (get_health() < get_health_max() / 5) {
    danger_level /= 5;
  }

  if (get_health() < get_health_max() / 10) {
    danger_level /= 10;
  }

  //
  // Don't include crush damage as it is non typical
  //

  return danger_level;
}

int Thing::get_danger_current_level(void)
{
  TRACE_AND_INDENT();
  int danger_level = 0;

  danger_level = get_health() / 10;

  if (is_undead()) {
    danger_level += 1;
  }
  if (is_sticky()) {
    danger_level += 1;
  }
  if (is_spiderweb()) {
    danger_level += 5;
  }
  if (is_resurrectable()) {
    danger_level *= 2;
  }
  if (ai_is_able_to_shove()) {
    danger_level++;
  }
  if (is_carrying_item()) {
    danger_level++;
  }
  if (is_acid()) {
    danger_level++;
  }
  if (is_hunger_insatiable()) {
    danger_level++;
  }
  if (is_poison()) {
    danger_level++;
  }
  if (is_fire()) {
    danger_level++;
  }
  if (is_lava()) {
    danger_level++;
  }
  if (is_poison()) {
    danger_level += is_poison();
  }
  if (is_floating()) {
    danger_level += 2;
  }
  if (ai_is_able_to_jump()) {
    danger_level += 5;
  }
  if (is_item_eater()) {
    danger_level += 20;
  }
  if (is_able_to_fire_at()) {
    danger_level += 20;
  }

  danger_level += get_damage_max();

  //
  // Low on health, reduce the level
  //
  if (get_health() < get_health_max() / 5) {
    danger_level /= 2;
  }

  if (get_health() < get_health_max() / 10) {
    danger_level /= 10;
  }

  return danger_level;
}

int Thing::is_dangerous(Thingp it)
{
  if (! it->is_monst() && ! it->is_player()) {
    return false;
  }

  if (is_fearless()) {
    return false;
  }

  int a = get_danger_current_level();
  int b = it->get_danger_current_level();

  //
  // If it's really close, then it's more dangerous
  //
  if (distance(mid_at, it->mid_at) < 2) {
    b += 10;
  }

  if (distance(mid_at, it->mid_at) == 0) {
    b += 20;
  }

  //
  // If I'm low on health then consider it more dangereous
  //
  if (get_health() < get_health_max() / 5) {
    b++;
  } else if (get_health() < get_health_max() / 10) {
    b += 2;
  }

  // log("My danger level %d, its %d, %s", a, b, it->to_string().c_str());

  //
  // So giant rats will attack each other if at the same danger level
  //
  return b > a;
}

const std::string Thing::get_danger_level_str(Thingp it)
{
  auto a     = get_danger_current_level();
  auto b     = it->get_danger_current_level();
  auto delta = b - a;

  if (delta > 20) {
    return "%%fg=red$Deadly. Avoid!";
  } else if (delta > 10) {
    return "%%fg=red$Dangerous";
  } else if (delta >= 0) {
    return "%%fg=orange$Caution advised";
  } else if (delta >= -10) {
    return "%%fg=green$Slight caution needed";
  } else if (delta >= -20) {
    return "%%fg=green$Mostly harmless";
  } else if (delta >= -30) {
    return "%%fg=green$Harmless";
  } else {
    return "%%fg=green$Walkover";
  }
}

int Thing::get_danger_current_level(Thingp it)
{
  int a = get_danger_current_level();
  int b = it->get_danger_current_level();
  return b - a;
}

int Thing::get_danger_initial_level(Thingp it)
{
  int a = get_danger_initial_level();
  int b = it->get_danger_initial_level();
  // con("danger level %d vs %s %d", a, it->to_string().c_str(), b);
  return b - a;
}
