//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_array_bounds_check.h"
#include "my_color.h"
#include "my_depth.h"
#include "my_dmap.h"
#include "my_game.h"
#include "my_log.h"
#include "my_ptrcheck.h"
#include "my_python.h"
#include "my_random.h"
#include "my_sprintf.h"
#include "my_string.h"
#include "my_sys.h"
#include "my_thing.h"
#include "my_thing_template.h"

//
// Lower level function than dead. Adds the thing to gc.
//
void Thing::defeat(Thingp defeater, const char *reason)
{
  //
  // Check we're not in a death loop
  //
  if (is_dying) {
    return;
  }
  is_dying = true;

  dbg("Destroy");
  TRACE_AND_INDENT();
  ///////////////////////////////////////////////////////////////
  // WARNING: defeater can be nullptr
  ///////////////////////////////////////////////////////////////
  auto is_corpse_currently = is_corpse();

  //
  // If already dead, do nothing
  //
  if (is_dead) {
    //
    // Unless it is already a corpse. In such a case, if a corpse is
    // eaten we want to remove it.
    //
    if (! is_corpse_currently) {
      return;
    }

    //
    // You only die once
    //
    if (is_player()) {
      return;
    }
  }

  if (! level->is_being_destroyed) {
    auto on_death = on_death_do();
    if (! std::empty(on_death)) {
      auto t = split_tokens(on_death, '.');
      if (t.size() == 2) {
        auto        mod   = t[ 0 ];
        auto        fn    = t[ 1 ];
        std::size_t found = fn.find("()");
        if (found != std::string::npos) {
          fn = fn.replace(found, 2, "");
        }

        dbg("Call %s.%s(%s)", mod.c_str(), fn.c_str(), to_string().c_str());

        py_call_void_fn(mod.c_str(), fn.c_str(), id.id, (unsigned int) mid_at.x, (unsigned int) mid_at.y);
      } else {
        ERR("Bad on_death call [%s] expected mod:function, got %d elems", on_death.c_str(), (int) on_death.size());
      }
    }
  }

  //
  // Unwield weapons
  //
  unwield("owner is dead");

  //
  // If in a bag, get out of there!
  //
  auto immediate_owner = get_immediate_owner();
  if (immediate_owner) {
    immediate_owner->bag_remove(this);
  }

  //
  // If a minion generator dies, kill all minions
  //
  if (defeater && is_minion_generator()) {
    destroy_minions(defeater);
  }

  if (defeater && is_spawner()) {
    destroy_spawned(defeater);
  }

  //
  // Set is_dead after the log message or we print it as dead
  //
  auto The = text_The();
  is_dead  = true;

  //
  // Resurrect unless say this was a minion and its manifestor died
  //
  if (! is_resurrection_blocked) {
    if (is_resurrectable()) {
      set_tick_resurrect_when(game->tick_current + get_resurrect());
    }
  }

  if (monst_infop) {
    //
    // So that slimes don't keep moving when dead
    //
    move_finish();

    //
    // Drop everything!
    //
    if (on_death_drop_all_items()) {
      dbg("Drop all items on death");
      drop_all();
      dbg("Dropped all items");
    }

    skill_remove_all();
  }

  if (on_death_is_open()) {
    dbg("Defeated, now open");
    level_pop();
    is_open = true;
    level_push();
    auto p = level->player;
    if (p) {
      int distance = distance_to_player();
      if (defeater && defeater->is_fire()) {
        if ((distance < 5) || (distance == DMAP_IS_WALL)) {
          TOPCON("The door burns through.");
        } else if (distance < DMAP_IS_PASSABLE) {
          TOPCON("The hear the crackling of burning wood.");
        } else {
          TOPCON("You smell smoke in the air.");
        }
      } else {
        if ((distance < 5) || (distance == DMAP_IS_WALL)) {
          TOPCON("The door crashes open.");
        } else if (distance < DMAP_IS_PASSABLE) {
          TOPCON("The hear the noise of a door crashing open.");
        } else {
          TOPCON("You hear a muffled crash. %d", distance);
        }
      }
      p->update_light();
    }
  }

  if (is_bleeder()) {
    int splatters = pcg_random_range(2, 10);
    for (int splatter = 0; splatter < splatters; splatter++) {
      auto tpp = tp_random_blood();
      (void) level->thing_new(tpp, mid_at, fpoint(0.25, 0.25));
      if (! tpp) {
        err("Could not place blood");
        break;
      }
    }
  }

  //
  // Add to the hiscore table?
  //
  if (is_player()) {
    //
    // Poor player
    //
    if (! get_score()) {
      incr_score(1);
    }

    if (game->config.hiscores.is_new_hiscore(this)) {
      if (game->robot_mode) {
        TOPCON("%%fg=yellow$New robo high score, %s place!%%fg=reset$", game->config.hiscores.place_str(this));
        TOPCON("RIP: Robot is defeated %s.", reason);
      } else {
        TOPCON("%%fg=yellow$New high score, %s place!%%fg=reset$", game->config.hiscores.place_str(this));
        TOPCON("RIP: You are defeated %s.", reason);
      }
      game->config.hiscores.add_new_hiscore(this, title(), reason);
    }

    TOPCON("%%fg=red$Congratulations, you are dead!%%fg=reset$");
    level->map_follow_player = false;
    game->dead_select(reason);
  } else if (is_loggable()) {
    dbg("%s defeated dead, %s", The.c_str(), reason);
    if (defeater && (defeater != this)) {
      if (defeater->is_player()) {
        if (is_monst()) {
          if (is_undead()) {
            TOPCON("%%fg=white$%s is vanquished, %s.%%fg=reset$", The.c_str(), reason);
          } else {
            TOPCON("%%fg=white$%s is defeated, %s.%%fg=reset$", The.c_str(), reason);
          }
        } else {
          TOPCON("%s is destroyed %s.", The.c_str(), reason);
        }

        defeater->score_add(this);
      } else if (is_monst() && (distance_to_player() >= DMAP_IS_PASSABLE)) {
        if (is_undead()) {
          TOPCON("You hear a distant moan...");
        } else if (is_jelly()) {
          TOPCON("You hear a distant splat...");
        } else if (is_humanoid()) {
          TOPCON("You hear distant cursing...");
        } else if (is_meat()) {
          TOPCON("You hear the distant crunching of bones...");
        } else {
          TOPCON("You hear a distant shriek...");
        }
      }
    }
  }

  if (is_corpse_currently) {
    //
    // Already a corpse
    //
    if (is_loggable()) {
      dbg("Already a corpse, clean it up");
    }
    auto tpp = tp_random_bones();
    if (! tpp) {
      err("Could not place bones");
    }
    (void) level->thing_new(tpp, mid_at);
  } else if (is_corpse_on_death()) {
    //
    // Leaves a corpse
    //
    if (is_loggable()) {
      dbg("Defeated, leaves corpse");
    }

    level->set_is_corpse(mid_at.x, mid_at.y);

    if (i_set_is_monst) {
      i_set_is_monst = false;
      level->unset_is_monst(mid_at.x, mid_at.y);
    }
    return;
  }

  //
  // If this was blocking the way to the player, update that now
  //
  if (! level->is_being_destroyed) {
    if (is_obs_wall_or_door()) {
      level->request_dmap_to_player_update = true;
    }
  }

  level_pop();

  if (is_loggable()) {
    dbg("Defeated, need to garbage collect");
  }

  gc();
}

void Thing::defeat(Thingp defeater, const std::string &reason)
{
  TRACE_AND_INDENT();
  defeat(defeater, reason.c_str());
}

bool Thing::if_matches_then_kill(const std::string &what, const point &p)
{
  TRACE_AND_INDENT();
  //
  // Don't destroy the floor under critical items
  //
  if ((what == "is_floor") || (what == "is_corridor")) {
    FOR_ALL_THINGS(level, t, p.x, p.y)
    {
      if (t->is_critical_to_level()) {
        return true;
      }
    }
    FOR_ALL_THINGS_END()
  }

  FOR_ALL_THINGS(level, t, p.x, p.y)
  {
    if (t->is_indestructible()) {
      continue;
    }

    if (t->matches(what)) {
      t->dead(this, "defeated ");

      //
      // Check if we are newly spawned over a chasm
      // Or if something we spawned at needs to react to us
      //
      location_check_forced_all_things_at();
    }
  }
  FOR_ALL_THINGS_END()

  return true;
}