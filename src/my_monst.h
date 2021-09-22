//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
// Please use spaces indent of 2, no tabs and column width of 120 to view.
//

#pragma once
#ifndef _MY_MONST_H_
#define _MY_MONST_H_

#include <list>
#include "my_time.h"
#include "my_light.h"
#include "my_thing_ai.h"
#include "my_thing_id.h"

constexpr uint32_t THING_MAGIC_BEGIN = 11221122;
constexpr uint32_t THING_MAGIC_END   = 22112211;
constexpr uint32_t THING_MAGIC_FINAL = 33333333;

enum {
  MONST_SIZE_TINY,
  MONST_SIZE_SMALL,
  MONST_SIZE_NORMAL,
  MONST_SIZE_LARGE,
  MONST_SIZE_GIANT,
  MONST_SIZE_GARGANTUAN,
};

enum {
  ROBOT_STATE_IDLE,
  ROBOT_STATE_MOVING,
  ROBOT_STATE_RESTING,
  ROBOT_STATE_OPEN_INVENTORY,
  ROBOT_STATE_ENCHANTING,
};

typedef struct Monst_ {
public:
  AgeMap       *_age_map = {};             // How old a cell is
  AgeMap       *_seen_map = {};            // If we've ever seen this tile and when
  Dmap         *_dmap_can_see = {};        // What the monster can reach during AI
  Dmap         *_dmap_unused = {};         // As above, but allows jumping
  std::vector<Lightp> light = {};          // Has light sources?

  /////////////////////////////////////////////////////////////////////////
  // Keep these sorted alphabetically to make it easier to see additions
  // and always update game_load.cpp and game_save.cpp
  //
  // | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
  // v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v
  /////////////////////////////////////////////////////////////////////////
  ThingId      on_fire_id_anim {};
  ThingId      owner_id {};                // Who carries this thing?
  ThingId      minion_owner_id {};         // Who generated this thing?
  ThingId      spawner_owner_id {};        // Who spawned this thing?
  ThingId      weapon_id {};               // Current weapon
  ThingId      weapon_id_carry_anim {};
  ThingId      weapon_id_use_anim {};
  color        light_col {};
  float        bounce_fade = {};           // 0.1; rapid, 0.9 slow
  float        bounce_height = {};         // Percentage of tile height.
  float        fadeup_fade = {};           // 0.1; rapid, 0.9 slow
  float        fadeup_height = {};         // Percentage of tile height.
  float        fall_height = {};           // y offset for falling
  float        wobble = {};                // Fades when set
  fpoint       lunge_to;                   // When a monst attacks something
  int          bounce_count = {};
  int          capacity_height {};
  int          capacity_width {};
  int          charge_count = {};          // How many things this thing spawned.
  int          enchant = {};
  int          enchant_max = {};
  int          gold = {};
  int          health = {};
  int          health_max = {};
  int          keys = {};
  int          lifespan = {};              // How many things this thing owns.
  int          light_quality {};
  int          light_strength {};          // Current strength, including torches
  int          minion_count = {};          // How many things this thing spawned.
  int          owned_count = {};           // How many things this thing owns.
  int          poison = {};
  int          robot_state {};
  int          score = {};
  int          spawned_count = {};         // How many things this thing owns.
  int          stamina = {};
  int          stamina_max = {};
  int          stat_attack = {};
  int          stat_constitution = {};
  int          stat_defence = {};
  int          stats01 = {};
  int          stats02 = {};
  int          stats03 = {};
  int          stats04 = {};
  int          stats05 = {};
  int          stats06 = {};
  int          stats07 = {};
  int          stats08 = {};
  int          stats09 = {};
  int          stats10 = {};
  int          stats11 = {};
  int          stats12 = {};
  int          stats17 = {};
  int          stats19 = {};
  int          stat_strength = {};
  int          submerged_offset = {};      // Pixels
  int          throw_distance = {};
  int          tick_resurrect_when = {};
  point        bag_position{-1, -1};
  point        wander_target{-1, -1};
  point        where_i_dropped_an_item_last{-1, -1};
  point        where_i_failed_to_collect_last{-1, -1};
  std::array<std::array<ThingId, MAX_BAG_WIDTH>, MAX_BAG_HEIGHT> bag {};
  std::list<ThingId>    carrying;
  std::list<ThingId>    skills;
  std::string           msg;               // Text that floats on screen
  std::string           dead_reason;       // What killed me
  std::map<ThingId, int> enemies {};       // List of things that wronged us
  std::vector<point>    move_path;
  std::vector<uint16_t> inventory_id;      // Vector of tp_id
  std::vector<uint16_t> skillbox_id;       // Vector of tp_id
  ts_t  ts_bounce_begin {};
  ts_t  ts_bounce_end {};
  ts_t  ts_fadeup_begin {};
  ts_t  ts_fadeup_end {};
  ts_t  ts_fall_begin {};
  ts_t  ts_fall_end {};
  ts_t  ts_flip_start {};    // Used for animating the steps.
  ts_t  ts_lunge_begin {};
  ts_t  ts_lunge_end {};
  ts_t  ts_anim_delay_end {};
  //
  // Used for calling on_idle()
  //
  uint32_t     tick_last_did_something {};
  //
  // When this thing was dropped
  //
  uint32_t     tick_last_dropped {};
  //
  // If things have stopped moving, perform location checks on where theuy
  // are now. This handles things like shoving a monst into a chasm. We do
  // location checks on the ends of moves, but this is a backup and will
  // also handle things that do not move, like a wand that is now on fire.
  //
  uint32_t     tick_last_location_check {};
  //
  // Don't try and escape too often else the player can never kill the monst!
  //
  uint32_t     tick_last_escape {};
  uint32_t     tick_last_level_change {};
  /////////////////////////////////////////////////////////////////////////
  // ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^
  // | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
  //
  // Keep these sorted alphabetically to make it easier to see additions
  // and always update game_load.cpp and game_save.cpp
  /////////////////////////////////////////////////////////////////////////

  //
  // Things not worth saving
  //
  point        preferred_bag_position{-1, -1};
  int          current_damage {};          // Current damage; so it can be modified by python
} Monst;
std::ostream& operator<<(std::ostream &out, Bits<const Monstp & > const my);
std::istream& operator>>(std::istream &in, Bits<Monstp &> my);

#endif // _MY_THING_H_
