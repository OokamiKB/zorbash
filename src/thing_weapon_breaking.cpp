//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_game.hpp"
#include "my_random.hpp"
#include "my_thing.hpp"

//
// See if the weapon crumbles
//
void Thing::weapon_check_for_damage(Thingp weapon, Thingp victim)
{
  auto my_owner = weapon->top_owner();
  if (! my_owner) {
    return;
  }

  bool corrode = false;
  bool shatter = false;

  //
  // Enchantment is already factored in here
  //
  auto break_chance = weapon->break_chance_d10000();
  if (victim->is_toughness_soft()) {
    break_chance /= 2;
  }

  if (victim->is_acid()) {
    if (! weapon->is_immune_to_acid()) {
      break_chance *= 2;
      if (weapon->damage_received_doubled_from_acid()) {
        break_chance *= 2;
      }
    }
  }

  if (victim->is_toughness_hard()) {
    break_chance *= 2;
    shatter = true;
  }

  if (victim->is_toughness_very_hard()) {
    break_chance *= 2;
    shatter = true;
  }

  if (d20roll_under(stat_luck_total())) {
    break_chance = 0;
  }

  //
  // See if the weapon is damaged.
  //
  auto roll = d10000();
  if (roll > break_chance) {
    return;
  }

  //
  // Decrement the items health. If it gets too damaged, it is dead.
  //
  if (weapon->health_decr(1) > 0) {
    if (shatter) {
      msg("%%fg=orange$%s is buckling.%%fg=reset$", weapon->text_The().c_str());
    } else if (corrode) {
      msg("%%fg=orange$%s is corroding.%%fg=reset$", weapon->text_The().c_str());
    } else {
      msg("%%fg=orange$%s is damaged.%%fg=reset$", weapon->text_The().c_str());
    }
    return;
  }

  if (my_owner->is_player()) {
    if (shatter) {
      msg("%%fg=red$%s shatters.%%fg=reset$", weapon->text_The().c_str());
    } else if (corrode) {
      msg("%%fg=red$%s dissolves to nothing.%%fg=reset$", weapon->text_The().c_str());
    } else {
      msg("%%fg=red$%s is broken.%%fg=reset$", weapon->text_The().c_str());
    }
  }
  weapon->dead("broken");
}
