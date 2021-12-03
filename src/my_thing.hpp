//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#pragma once
#ifndef _MY_THING_HPP_
#define _MY_THING_HPP_

#include <array>
#include <functional>
#include <list>

#include "my_color.hpp"
#include "my_dice.hpp"
#include "my_fwd.hpp"
#include "my_point.hpp"
#include "my_thing_ai.hpp"
#include "my_thing_defs.hpp"
#include "my_thing_id.hpp"
#include "my_time.hpp"

typedef enum {
  THING_SHOVE_TRIED_AND_FAILED,
  THING_SHOVE_TRIED_AND_PASSED,
  THING_SHOVE_NEVER_TRIED,
} ThingShoved;

typedef struct {
  uint16_t tile_outline;
  uint16_t bl1_tile;
  uint16_t bot1_tile;
  uint16_t br1_tile;
  uint16_t left1_tile;
  uint16_t right1_tile;
  uint16_t tl1_tile;
  uint16_t top1_tile;
  uint16_t tr1_tile;
  uint16_t bl2_tile;
  uint16_t bot2_tile;
  uint16_t bot3_tile;
  uint16_t br2_tile;
  uint16_t left2_tile;
  uint16_t right2_tile;
  uint16_t tl2_tile;
  uint16_t top2_tile;
  uint16_t tr2_tile;
} ThingTiles;

typedef class Thing_
{
public:
  Thing_(void);
  ~Thing_(void);

  ThingInfop _infop {};
  ThingItemp _itemp {};
  ThingAip   _aip {};

  Levelp level {};

  ThingId    id {}; // Unique per thing.
  ThingTiles tiles {};

  fpoint interpolated_mid_at;

  ts_t ts_next_frame {};

  point last_mid_at; // Previous hop where we were.
  point mid_at;      // Grid coordinates.
  point last_attached;
  point last_blit_br; // Last blit coords
  point last_blit_tl; // Offset from top left of map
  point last_blit_at; // Center of the above

  uint16_t tile_curr {};
  uint16_t frame_count {};
  int16_t  tp_id {-1}; // Common settings

  uint8_t alpha {255}; // For fading
  uint8_t z_depth {};

  uint64_t dir : 4 {}; // Direction

  /////////////////////////////////////////////////////////////////////////
  // Keep these sorted alphabetically to make it easier to see additions
  // and always update game_load.cpp and game_save.cpp
  //
  // | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
  // v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v
  /////////////////////////////////////////////////////////////////////////
  uint64_t has_ever_moved                               : 1 {};
  uint64_t has_laser                                    : 1 {}; // current laser being fired
  uint64_t has_light                                    : 1 {};
  uint64_t has_projectile                               : 1 {}; // current projectile being fired
  uint64_t is_activated                                 : 1 {}; // this skill is activated
  uint64_t is_attached                                  : 1 {}; // is attached to the level
  uint64_t is_being_destroyed                           : 1 {};
  uint64_t is_bouncing                                  : 1 {};
  uint64_t is_changing_level                            : 1 {}; // is in the process of changing level
  uint64_t is_dead                                      : 1 {};
  uint64_t is_dying                                     : 1 {}; // is currently in the throes of death
  uint64_t is_facing_left                               : 1 {};
  uint64_t is_fadeup                                    : 1 {}; // for text that fades upwards
  uint64_t is_falling                                   : 1 {};
  uint64_t is_ring2                                     : 1 {}; // for 2nd rings
  uint64_t is_hidden                                    : 1 {};
  uint64_t is_hungry                                    : 1 {};
  uint64_t is_in_lava                                   : 1 {};
  uint64_t is_in_water                                  : 1 {};
  uint64_t is_jumping                                   : 1 {};
  uint64_t is_moving                                    : 1 {}; // is currently moving tiles
  uint64_t is_offscreen                                 : 1 {};
  uint64_t is_open                                      : 1 {};
  uint64_t is_resurrected                               : 1 {}; // has finished resurrecting
  uint64_t is_resurrecting                              : 1 {}; // is currently resurrecing
  uint64_t is_resurrection_blocked                      : 1 {}; // blocked from resurrection
  uint64_t is_scheduled_for_death                       : 1 {}; // will die in next game loop
  uint64_t is_scheduled_for_jump_end                    : 1 {};
  uint64_t is_sleeping                                  : 1 {};
  uint64_t is_starving                                  : 1 {};
  uint64_t is_the_grid                                  : 1 {}; // is the backbone of the level
  uint64_t is_waiting_to_ascend_dungeon                 : 1 {};
  uint64_t is_waiting_to_ascend_sewer                   : 1 {};
  uint64_t is_waiting_to_descend_dungeon                : 1 {};
  uint64_t is_waiting_to_descend_sewer                  : 1 {};
  uint64_t is_waiting_to_leave_level_has_completed_fall : 1 {};

  //
  // These are flags used to make sure we set or unset flags onto
  // the level only once.
  //
  uint64_t i_set_water                            : 1 {};
  uint64_t i_set_is_acid                          : 1 {};
  uint64_t i_set_is_ascend_dungeon                : 1 {};
  uint64_t i_set_is_ascend_sewer                  : 1 {};
  uint64_t i_set_is_barrel                        : 1 {};
  uint64_t i_set_is_blood                         : 1 {};
  uint64_t i_set_is_brazier                       : 1 {};
  uint64_t i_set_is_bridge                        : 1 {};
  uint64_t i_set_is_chasm                         : 1 {};
  uint64_t i_set_is_corpse                        : 1 {};
  uint64_t i_set_is_corridor                      : 1 {};
  uint64_t i_set_is_deep_water                    : 1 {};
  uint64_t i_set_is_descend_dungeon               : 1 {};
  uint64_t i_set_is_descend_sewer                 : 1 {};
  uint64_t i_set_is_dirt                          : 1 {};
  uint64_t i_set_is_door                          : 1 {};
  uint64_t i_set_is_dry_grass                     : 1 {};
  uint64_t i_set_is_enchantstone                  : 1 {};
  uint64_t i_set_is_cursor_path_hazard_for_player : 1 {};
  uint64_t i_set_is_fire                          : 1 {};
  uint64_t i_set_is_floor                         : 1 {};
  uint64_t i_set_is_foilage                       : 1 {};
  uint64_t i_set_is_food                          : 1 {};
  uint64_t i_set_is_gold                          : 1 {};
  uint64_t i_set_is_hazard                        : 1 {};
  uint64_t i_set_is_key                           : 1 {};
  uint64_t i_set_is_lava                          : 1 {};
  uint64_t i_set_is_light_blocker                 : 1 {};
  uint64_t i_set_is_minion_generator              : 1 {};
  uint64_t i_set_is_monst                         : 1 {};
  uint64_t i_set_is_obs_wall_or_door              : 1 {};
  uint64_t i_set_is_obs_destructable              : 1 {};
  uint64_t i_set_is_poisonous_danger_level        : 1 {};
  uint64_t i_set_is_necrotic_danger_level         : 1 {};
  uint64_t i_set_is_potion                        : 1 {};
  uint64_t i_set_is_ripple                        : 1 {};
  uint64_t i_set_is_rock                          : 1 {};
  uint64_t i_set_is_secret_door                   : 1 {};
  uint64_t i_set_is_shallow_water                 : 1 {};
  uint64_t i_set_is_skillstone                    : 1 {};
  uint64_t i_set_is_smoke                         : 1 {};
  uint64_t i_set_is_spiderweb                     : 1 {};
  uint64_t i_set_is_sticky                        : 1 {};
  uint64_t i_set_is_shovable                      : 1 {};
  uint64_t i_set_is_treasure_class_a              : 1 {};
  uint64_t i_set_is_treasure_class_b              : 1 {};
  uint64_t i_set_is_treasure_class_c              : 1 {};
  uint64_t i_set_is_treasure_type                 : 1 {};
  uint64_t i_set_is_wall                          : 1 {};
  uint64_t i_set_is_wand                          : 1 {};
  uint64_t i_set_is_ring                          : 1 {};

  /////////////////////////////////////////////////////////////////////////
  // ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^
  // | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
  //
  // Keep these sorted alphabetically to make it easier to see additions
  // and always update game_load.cpp and game_save.cpp
  /////////////////////////////////////////////////////////////////////////
  // Fields not worth saving
  uint64_t debug                 : 1 {};
  uint64_t is_being_dropped      : 1 {};
  uint64_t is_blitted            : 1 {};
  uint64_t inited_tiles          : 1 {};
  uint64_t has_external_particle : 1 {}; // current in motion particle
  uint64_t has_internal_particle : 1 {}; // current in motion particle
#ifdef ENABLE_DEBUG_THING_SER
  std::string debug_str;
#endif
private:
  //
  // As this is called a lot, probably worth the memory
  //
  Tpp mytp {};

public:
  //
  // Walk all items and bags to get the items
  //
  std::list< Thingp > get_item_list(void);
  std::list< Thingp > get_treasure_list(void);
  std::list< Thingp > get_wand_list(void);
  std::list< Thingp > get_ring_list(void);
  std::list< Thingp > get_food_list(void);
  std::list< Thingp > get_weapon_list(void);

  std::vector< Thingp > get_item_vector(void);
  std::vector< Thingp > get_treasure_vector(void);
  std::vector< Thingp > get_wand_vector(void);
  std::vector< Thingp > get_ring_vector(void);
  std::vector< Thingp > get_food_vector(void);
  std::vector< Thingp > get_weapon_vector(void);

  ThingShoved try_to_shove(Thingp it, point delta);
  ThingShoved try_to_shove(point future_pos);
  ThingShoved try_to_shove_into_hazard(Thingp it, point delta);

  ThingId get_on_fire_anim_id(void);
  ThingId set_on_fire_anim_id(ThingId);

  ThingId get_equip_id(int equip);
  ThingId get_equip_id_carry_anim(int equip);
  ThingId get_equip_id_use_anim(int equip);

  ThingId set_equip_id(ThingId, int equip);
  ThingId set_equip_id_carry_anim(ThingId, int equip);
  ThingId set_equip_id_use_anim(ThingId, int equip);

  int  get_distance_from_minion_owner(void);
  int  get_distance_from_minion_owner(point p);
  bool too_far_from_minion_owner(void);
  bool too_far_from_minion_owner(point p);
  bool too_far_from_minion_owner(point p, int delta);

  Thingp get_equip(int equip);
  Thingp get_equip_carry_anim(int equip);
  Thingp get_equip_use_anim(int equip);

  void dump_equip(void);

  Thingp get_immediate_minion_owner();
  Thingp get_top_minion_owner();

  Thingp get_immediate_spawned_owner();
  Thingp get_top_spawned_owner();

  Thingp get_immediate_owner();
  Thingp get_top_owner();

  Thingp get_most_dangerous_adjacent_thing(void);
  Thingp get_most_dangerous_visible_thing(void);

  Thingp get_best_fire_at_target(void);
  Thingp laser_fire_at(const std::string &item, Thingp target);
  Thingp projectile_fire_at(const std::string &item, Thingp target);

  Thingp spawn_at(const std::string &what);
  Thingp spawn_at_if_possible(const std::string &what);

  bool ai_blocked(void);
  bool ai_blocked_completely(void);
  bool ai_choose_avoid_goals(std::multiset< Goal > &avoid_goals, const Goal &goal);
  bool ai_choose_immediately_adjacent_goal(void);
  bool ai_choose_wander(point &nh);
  bool ai_create_on_fire_path(point &nh, const point start, const point end);
  bool ai_create_path(point &nh, const point start, const point end);
  bool ai_create_path_to_goal(int minx, int miny, int maxx, int maxy, int search_type = 0);
  bool ai_create_path_to_single_goal(int, int, int, int, const Goal &goal, const struct Dmap_ *saved_dmap);
  bool ai_escape(void);
  bool ai_obstacle(Thingp);
  bool ai_obstacle(fpoint);
  bool ai_obstacle_for_me(const point &);
  bool ai_on_fire(void);
  bool ai_on_fire_choose_target(point &nh);
  bool ai_tick(bool recursing = false);
  bool ai_wander(void);
  bool any_adjacent_monst(void);
  bool any_unfriendly_monst_visible(void);
  bool ascend(int z);
  bool ascend_dungeon(void);
  bool ascend_dungeon_tick();
  bool ascend_sewer(void);
  bool ascend_sewer_tick();
  bool attack(Thingp it);
  bool attack(point future_pos);
  bool bag_add(Thingp);
  bool bag_add_test(Thingp);
  bool bag_can_place_anywhere(Thingp item, point &pos);
  bool bag_can_place_at(Thingp item, point pos);
  bool bag_compress(void);
  bool bag_contains(Thingp item);
  bool bag_place_at(Thingp item, point pos);
  bool bag_remove(Thingp);
  bool bag_remove_at(Thingp item, point pos);
  bool buff_add(Thingp it);
  bool buff_add(Tpp what);
  bool buff_remove(Tpp what);
  bool buff_remove(Thingp it);
  bool buff_use(Thingp it);
  bool buffbox_id_insert(Thingp what);
  bool buffbox_id_remove(Thingp what);
  bool can_eat(const Thingp it);
  bool can_eat_something(void);
  bool can_enchant_something(void);
  bool can_learn_something(void);
  bool cannot_avoid(Thingp attacker);
  bool carry(Thingp w, bool can_equip = true);
  bool change_owner(Thingp new_owner);
  bool check_anything_to_carry(bool auto_collect_allowed);
  bool close_door(Thingp door);
  bool collision_add_candidates(Thingp it, point future_pos, int x, int y, int dx, int dy);
  bool collision_check_and_handle(Thingp it, point future_pos, int x, int y, int dx, int dy);
  bool collision_check_and_handle(point future_pos, bool *, bool *, float radius);
  bool collision_check_and_handle_at(bool *, bool *);
  bool collision_check_and_handle_at(point future_pos, bool *, bool *);
  bool collision_check_and_handle_nearby(point future_pos, bool *, bool *);
  bool collision_check_do();
  bool collision_check_only(Thingp it, int x, int y, int dx, int dy);
  bool collision_check_only(Thingp it, point future_pos, int x, int y);
  bool collision_check_only(point future_pos);
  bool collision_check_only(void);
  bool collision_find_best_target(bool *, bool *);
  bool collision_obstacle(Thingp);
  bool collision_obstacle(point);
  bool cursor_path_pop_first_move(void);
  bool debuff_add(Thingp it);
  bool debuff_add_if_not_found(Tpp what);
  bool debuff_add(Tpp what);
  bool debuff_remove(Tpp what);
  bool debuff_remove(Thingp it);
  bool debuff_use(Thingp it);
  bool debuffbox_id_insert(Thingp what);
  bool debuffbox_id_remove(Thingp what);
  bool descend_dungeon(void);
  bool descend_dungeon_tick();
  bool descend_sewer(void);
  bool descend_sewer_tick();
  bool describe_when_hovered_over_in_rightbar(void);
  bool describe_when_hovering_over(void);
  bool drop(Thingp w);
  bool drop(Thingp w, Thingp target, bool stolen = false);
  void check_all_carried();
  bool drop_from_ether(Thingp w);
  bool drop_into_ether(Thingp w);
  bool eat(Thingp it);
  bool consume(Thingp it);
  bool eat_something(void);
  bool enchant(Thingp);
  bool enchant_random_item(void);
  bool equip(Thingp w, int equip);
  bool equip_use(bool forced, int equip);
  bool equip_use_may_attack(int equip);
  bool equip_use_must_attack(int equip);
  bool equip_use_try(int equip);
  bool fall(void);
  bool fall_to_next_level(void);
  bool fire_at_and_choose_target(Thingp);
  bool fire_at_target(void);
  bool fire_choose_target(Thingp item);
  bool get_coords(point &blit_tl, point &blit_br, point &pre_blit_tl, point &pre_blit_br, Tilep &tile, bool refl);
  bool get_map_offset_coords(point &blit_tl, point &blit_br, Tilep &tile, bool reflection);
  bool health_boost_would_occur(int v);
  bool idle_check(void);
  bool if_matches_then_kill(const std::string &what, const point &p);
  bool inventory_shortcuts_insert(Thingp what);
  bool inventory_shortcuts_remove(Thingp what);
  bool inventory_shortcuts_remove(Thingp what, Thingp target);
  bool is_blocking_terrain(const Thingp it);
  bool is_bloodied(void);
  bool is_carrying_item(void);
  bool is_carrying_treasure(void);
  bool is_disliked_by_me(const Thingp it);
  bool is_disliked_by_me(const point &p);
  bool is_enemy(Thingp attacker);
  bool is_equipped(Thingp item);
  bool is_hated_by_me(const Thingp it);
  bool is_hated_by_me(const point &p);
  bool is_on_fire(void);
  bool is_to_be_avoided(Thingp attacker);
  bool laser_anim_exists(void);
  bool laser_choose_target(Thingp item);
  bool learn_random_skill(void);
  bool matches(const std::string &what);
  bool move(point to);
  bool move(point to, uint8_t u, uint8_t d, uint8_t l, uint8_t r, uint8_t att, uint8_t idl, bool shoveok, bool attok);
  bool move_no_shove_attack_allowed(point future_pos);
  bool move_no_shove_no_attack(point future_pos);
  bool move_to_or_attack(const point &);
  bool move_to_or_attack_check_only(const point &nh);
  bool move_to_or_escape(const point &);
  bool move_to_or_escape_check_only(const point &nh);
  bool move_to_try(const point &, const bool escaping, bool check_only);
  bool on_firing_at_something(Thingp hitter);
  bool on_tick(void);
  bool open(Thingp it);
  bool open_door(Thingp door);
  bool particle_anim_exists(void);
  bool path_pop_next_move(void);
  bool place(const std::string &what, const point &p);
  bool possible_to_attack(const Thingp it);
  bool possible_to_attack_at(point at);
  bool projectile_anim_exists(void);
  bool projectile_choose_target(Thingp item);
  bool set_on_fire(const std::string &why);
  bool skill_add(Thingp it);
  bool skill_add(Tpp what);
  bool skill_remove(Thingp it);
  bool skill_use(Thingp it);
  bool skillbox_id_insert(Thingp what);
  bool skillbox_id_remove(Thingp what);
  bool spawn_fire(const std::string &what);
  bool spawn_next_to(const std::string &what);
  bool spawn_next_to_or_on_monst(const std::string &what);
  bool spawn_radius_range(Thingp parent, Thingp target, const std::string &what, uint32_t rad_min, uint32_t rad_max);
  bool steal_item_from(Thingp);
  bool steal_treasure_from(Thingp);
  bool target_select(Thingp item);
  bool thing_sound_play(const std::string &alias);
  bool thing_sound_play_channel(int chan, const std::string &alias);
  bool throw_item_choose_target(Thingp item);
  bool try_harder_to_jump(void);
  bool try_to_carry(Thingp w);
  bool try_to_carry_if_worthwhile_dropping_items_if_needed(Thingp it);
  bool try_to_escape(void);
  bool try_to_jump(point to, bool carefully, bool *too_far);
  bool try_to_jump(void);
  bool try_to_jump_away_from_player(void);
  bool try_to_jump_carefree(point to);
  bool try_to_jump_carefree(point to, bool *too_far);
  bool try_to_jump_carefully(point to);
  bool try_to_jump_carefully(point to, bool *too_far);
  bool try_to_jump_towards_player(void);
  bool use(Thingp w, int equip = -1);
  bool will_avoid_monst(const Thingp it);
  bool will_avoid_monst(const point &p);
  bool will_prefer_terrain(const Thingp it);
  bool worth_eating(const Thingp it);
  bool unequip(const char *why, int equip, bool allowed_to_recarry);
  bool unequip_me_from_owner(const char *why, bool allowed_to_recarry);

  void reset_goal_penalty(Thingp attacker);
  void buff_tick();
  void debuff_tick();

  int buff_on_damage_poison(Thingp hitter, int damage);
  int buff_on_damage_bite(Thingp hitter, int damage);
  int buff_on_damage_melee(Thingp hitter, int damage);
  int buff_on_damage_necrosis(Thingp hitter, int damage);
  int buff_on_damage_strength(Thingp hitter, int damage);
  int buff_on_damage_constitution(Thingp hitter, int damage);

  const Dice &get_damage_bite_dice(void);
  const Dice &get_damage_crush_dice(void);
  const Dice &get_damage_melee_dice(void);
  const Dice &get_damage_poison_dice(void);
  const Dice &get_damage_necrosis_dice(void);
  const Dice &get_damage_digest_dice(void);

  const Dice &get_gold_value_dice(void);
  const Dice &get_health_initial_dice(void);
  const Dice &get_lifespan_dice(void);
  const Dice &get_nutrition_dice(void);
  const Dice &get_on_idle_dice(void);
  const Dice &get_resurrect_dice(void);

  const ThingId &get_immediate_minion_owner_id(void);
  const ThingId &get_immediate_owner_id(void);
  const ThingId &get_immediate_spawned_owner_id(void);
  const ThingId &get_top_owner_id(void);
  const ThingId &set_minion_owner_id(const ThingId &v);
  const ThingId &set_owner_id(const ThingId &v);
  const ThingId &set_spawned_owner_id(const ThingId &v);

  const Tpp tp(void);
  const Tpp tp_or_update(void);

  const fpoint &get_interpolated_mid_at(void);

  const std::string  get_danger_level_str(Thingp); // Cannot return reference
  const std::string &get_damage_bite_dice_str(void);
  const std::string &get_damage_crush_dice_str(void);
  const std::string &get_damage_melee_dice_str(void);
  const std::string &get_damage_poison_dice_str(void);
  const std::string &get_damage_necrosis_dice_str(void);
  const std::string &get_damage_digest_dice_str(void);
  const std::string &get_dead_reason(void);
  const std::string &get_gold_value_dice_str(void);
  const std::string &get_health_initial_dice_str(void);
  const std::string &get_lifespan_dice_str(void);
  const std::string &get_msg(void);
  const std::string &get_nutrition_dice_str(void);
  const std::string &get_on_idle_dice_str(void);
  const std::string &get_resurrect_dice_str(void);
  const std::string &gfx_anim_use(void);
  const std::string &laser_name(void);
  const std::string &light_color(void);
  const std::string &long_text_description(void);
  const std::string &name(void);
  const std::string &on_birth_do(void);
  const std::string &on_you_bite_attack_do(void);
  const std::string &on_born_do(void);
  const std::string &on_death_do(void);
  const std::string &on_enchant_do(void);
  const std::string &on_fall_do(void);
  const std::string &on_you_are_on_fire_do(void);
  const std::string &on_firing_at_something_do(void);
  const std::string &on_you_are_hit_do(void);
  const std::string &on_lifespan_do(void);
  const std::string &on_you_miss_do(void);
  const std::string &on_move_do(void);
  const std::string &on_open_do(void);
  const std::string &on_tick_do(void);
  const std::string &on_use_do(void);
  const std::string &on_final_use_do(void);
  const std::string &on_equip_do(void);
  const std::string &on_unequip_do(void);
  const std::string &on_owner_set_do(void);
  const std::string &on_owner_unset_do(void);
  const std::string &on_owner_damage_poison_do(void);
  const std::string &on_owner_damage_constitution_do(void);
  const std::string &on_owner_damage_strength_do(void);
  const std::string &on_owner_damage_melee_do(void);
  const std::string &on_owner_damage_necrosis_do(void);
  const std::string &on_owner_damage_bite_do(void);
  const std::string &projectile_name(void);
  const std::string &short_text_name(void);
  const std::string &spawn_on_shoved(void);
  const std::string &str1(void);
  const std::string &str2(void);
  const std::string &str4(void);
  const std::string &str5(void);
  const std::string &text_buff(void);
  const std::string &text_debuff(void);
  const std::string &text_description(void);
  const std::string &text_enchant(void);
  const std::string &text_hits(void);
  const std::string &text_name(void);
  const std::string &text_skill(void);
  const std::string &text_title(void);
  const std::string &text_unused(void);
  const std::string &title(void);
  const std::string &equip_carry_anim(void);

  float get_bounce_fade(void);
  float get_bounce_height(void);
  float get_bounce(void);
  float get_fadeup_fade(void);
  float get_fadeup_height(void);
  float get_fadeup(void);
  float get_fall_height(void);
  float get_fall(void);
  float get_health_pct(void);
  float get_lunge(void);
  float get_wobble(void);
  float how_far_i_can_jump_max(void);
  float how_far_i_can_jump(void);
  float update_wobble(void);

  int ai_aggression_level_pct(void);
  int ai_avoid_distance(void);
  int ai_choose_goal(void);
  int ai_detect_secret_doors(void);
  int ai_dmap_can_see_init(int minx, int miny, int maxx, int maxy, int type, bool check);
  int ai_hit_actual(Thingp hitter, Thingp real_hitter, bool crit, bool bite, bool poison, bool necrosis, int dmg);
  int ai_obstacle(void);
  int ai_resent_count(void);
  int ai_shove_chance_d1000(void);
  int ai_vision_distance(void);
  int ai_wanderer(void);
  int attack_blood(void);
  int attack_eater(void);
  int attack_engulf_chance_d1000(void);
  int attack_humanoid(void);
  int attack_living(void);
  int attack_lunge(void);
  int attack_meat(void);
  int attack_undead(void);
  int attack(void);
  int blast_max_radius(void);
  int blast_min_radius(void);
  int capacity_height(void);
  int capacity_width(void);
  int collision_check(void);
  int collision_hit_priority(void);
  int damage_bite_chance_d1000(void);
  int damage_melee_chance_d1000(void);
  int damage_necrosis_chance_d1000(void);
  int damage_poison_chance_d1000(void);
  int damage_received_doubled_from_acid(void);
  int damage_received_doubled_from_fire(void);
  int damage_received_doubled_from_necrosis(void);
  int damage_received_doubled_from_poison(void);
  int damage_received_doubled_from_water(void);
  int decr_charge_count(int);
  int decr_charge_count(void);
  int decr_current_damage(int);
  int decr_current_damage(void);
  int decr_enchant(int);
  int decr_enchant_max(int);
  int decr_enchant_max(void);
  int decr_enchant(void);
  int decr_gold(int);
  int decr_gold(void);
  int decr_health(int);
  int decr_health_max(int);
  int decr_health_max(void);
  int decr_health(void);
  int decr_idle_count(int);
  int decr_idle_count(void);
  int decr_keys(int);
  int decr_keys(void);
  int decr_lifespan(int);
  int decr_lifespan(void);
  int decr_light_strength(int);
  int decr_light_strength(void);
  int decr_minion_count(int);
  int decr_minion_count(void);
  int decr_necrotized_amount(int);
  int decr_necrotized_amount(void);
  int decr_owned_count(int);
  int decr_owned_count(void);
  int decr_poisoned_amount(int);
  int decr_poisoned_amount(void);
  int decr_spawned_count(int);
  int decr_spawned_count(void);
  int decr_stamina(int);
  int decr_stamina_max(int);
  int decr_stamina_max(void);
  int decr_stamina(void);
  int decr_stat_armor_class(int);
  int decr_stat_armor_class(void);
  int decr_stat_attack_bonus(int);
  int decr_stat_attack_bonus(void);
  int decr_stat_constitution(int);
  int decr_stat_constitution(void);
  int decr_stat_dexterity(int);
  int decr_stat_dexterity(void);
  int decr_stats02(int);
  int decr_stats02(void);
  int decr_stats03(int);
  int decr_stats03(void);
  int decr_stats04(int);
  int decr_stats04(void);
  int decr_stats05(int);
  int decr_stats05(void);
  int decr_stats06(int);
  int decr_stats06(void);
  int decr_stats07(int);
  int decr_stats07(void);
  int decr_stats08(int);
  int decr_stats08(void);
  int decr_stats09(int);
  int decr_stats09(void);
  int decr_stats10(int);
  int decr_stats10(void);
  int decr_stats11(int);
  int decr_stats11(void);
  int decr_stats12(int);
  int decr_stats12(void);
  int decr_stats17(int);
  int decr_stats17(void);
  int decr_stats19(int);
  int decr_stats19(void);
  int decr_stat_strength(int);
  int decr_stat_strength(void);
  int decr_stuck_count(int);
  int decr_stuck_count(void);
  int decr_throw_distance(int);
  int decr_throw_distance(void);
  int defence(void);
  int distance_to_player(void);
  int enchant_level(void);
  int enchant_max(void);
  int environ_avoids_acid(void);
  int environ_avoids_fire(void);
  int environ_avoids_necrosis(void);
  int environ_avoids_poison(void);
  int environ_avoids_water(void);
  int environ_prefers_acid(void);
  int environ_prefers_fire(void);
  int environ_prefers_necrosis(void);
  int environ_prefers_poison(void);
  int environ_prefers_spiderwebs(void);
  int environ_prefers_water(void);
  int get_bounce_count(void);
  int get_carried_food_count(void);
  int get_carried_food_highest_value(Thingp *out);
  int get_carried_food_least_value(Thingp *out);
  int get_carried_ring_count(void);
  int get_carried_ring_highest_value(Thingp *out);
  int get_carried_ring_least_value(Thingp *out);
  int get_carried_wand_count(void);
  int get_carried_wand_highest_value(Thingp *out);
  int get_carried_wand_least_value(Thingp *out);
  int get_carried_weapon_count(void);
  int get_carried_weapon_highest_value(Thingp *out);
  int get_carried_weapon_least_value(Thingp *out);
  int get_charge_count(void);
  int get_current_damage(void);
  int get_damage_bite(void);
  int get_damage_crush(void);
  int get_damage_max(void);
  int get_damage_melee(void);
  int get_damage_min(void);
  int get_damage_necrosis(void);
  int get_damage_poison(void);
  int get_damage_digest(void);
  int get_danger_current_level(Thingp);
  int get_danger_current_level(void);
  int get_danger_initial_level(Thingp);
  int get_danger_initial_level(void);
  int get_enchant_max(void);
  int get_enchantstone_count(void);
  int get_enchant(void);
  int get_goal_penalty(Thingp attacker);
  int get_gold_value(void);
  int get_gold(void);
  int get_group(void);
  int get_health_initial(void);
  int get_health_max(void);
  int get_health(void);
  int get_idle_count(void);
  int get_idle_tick(void);
  int get_initial_charge_count(void);
  int get_initial_light_strength(void);
  int get_keys(void);
  int get_lifespan_initial(void);
  int get_lifespan(void);
  int get_light_strength_initial(void);
  int get_light_strength(void);
  int get_minion_count(void);
  int get_necrotized_amount(void);
  int get_nutrition(void);
  int get_owned_count(void);
  int get_poisoned_amount(void);
  int get_resurrect(void);
  int get_score(void);
  int get_skillstone_count(void);
  int get_spawned_count(void);
  int get_stamina_max(void);
  int get_stamina(void);
  int get_stat_armor_class(void);
  int get_stat_attack_bonus(void);
  int get_stat_constitution(void);
  int get_stat_dexterity(void);
  int get_stats02(void);
  int get_stats03(void);
  int get_stats04(void);
  int get_stats05(void);
  int get_stats06(void);
  int get_stats07(void);
  int get_stats08(void);
  int get_stats09(void);
  int get_stats10(void);
  int get_stats11(void);
  int get_stats12(void);
  int get_stats17(void);
  int get_stats19(void);
  int get_stat_strength(void);
  int get_stuck_count(void);
  int get_submerged_offset(void);
  int get_throw_distance(void);
  int get_torch_count(void);
  int gfx_an_animation_only(void);
  int gfx_animated_can_hflip(void);
  int gfx_animated_can_vflip(void);
  int gfx_animated_no_dir(void);
  int gfx_animated(void);
  int gfx_attack_anim(void);
  int gfx_bounce_always(void);
  int gfx_bounce_on_move(void);
  int gfx_dead_anim(void);
  int gfx_equip_carry_anim(void);
  int gfx_flickers(void);
  int gfx_glows(void);
  int gfx_health_bar_autohide(void);
  int gfx_health_bar_shown(void);
  int gfx_long_shadow_caster(void);
  int gfx_on_fire_anim(void);
  int gfx_oversized_and_on_floor(void);
  int gfx_short_shadow_caster(void);
  int gfx_shown_in_bg(void);
  int gfx_show_outlined(void);
  int gfx_solid_shadow(void);
  int gfx_very_short_shadow_caster(void);
  int gfx_water(void);
  int health_boost(int v);
  int health_hunger_pct(void);
  int health_starving_pct(void);
  int incr_charge_count(int);
  int incr_charge_count(void);
  int incr_current_damage(int);
  int incr_current_damage(void);
  int incr_enchant(int);
  int incr_enchant_max(int);
  int incr_enchant_max(void);
  int incr_enchant(void);
  int incr_gold(int);
  int incr_gold(void);
  int incr_health(int);
  int incr_health_max(int);
  int incr_health_max(void);
  int incr_health(void);
  int incr_idle_count(int);
  int incr_idle_count(void);
  int incr_keys(int);
  int incr_keys(void);
  int incr_lifespan(int);
  int incr_lifespan(void);
  int incr_light_strength(int);
  int incr_light_strength(void);
  int incr_minion_count(int);
  int incr_minion_count(void);
  int incr_necrotized_amount(int);
  int incr_necrotized_amount(void);
  int incr_owned_count(int);
  int incr_owned_count(void);
  int incr_poisoned_amount(int);
  int incr_poisoned_amount(void);
  int incr_spawned_count(int);
  int incr_spawned_count(void);
  int incr_stamina(int);
  int incr_stamina_max(int);
  int incr_stamina_max(void);
  int incr_stamina(void);
  int incr_stat_armor_class(int);
  int incr_stat_armor_class(void);
  int incr_stat_attack_bonus(int);
  int incr_stat_attack_bonus(void);
  int incr_stat_constitution(int);
  int incr_stat_constitution(void);
  int incr_stat_dexterity(int);
  int incr_stat_dexterity(void);
  int incr_stats02(int);
  int incr_stats02(void);
  int incr_stats03(int);
  int incr_stats03(void);
  int incr_stats04(int);
  int incr_stats04(void);
  int incr_stats05(int);
  int incr_stats05(void);
  int incr_stats06(int);
  int incr_stats06(void);
  int incr_stats07(int);
  int incr_stats07(void);
  int incr_stats08(int);
  int incr_stats08(void);
  int incr_stats09(int);
  int incr_stats09(void);
  int incr_stats10(int);
  int incr_stats10(void);
  int incr_stats11(int);
  int incr_stats11(void);
  int incr_stats12(int);
  int incr_stats12(void);
  int incr_stats17(int);
  int incr_stats17(void);
  int incr_stats19(int);
  int incr_stats19(void);
  int incr_stat_strength(int);
  int incr_stat_strength(void);
  int incr_stuck_count(int);
  int incr_stuck_count(void);
  int incr_throw_distance(int);
  int incr_throw_distance(void);
  int is_able_to_attack_generators(void);
  int is_able_to_break_down_doors(void);
  int is_able_to_break_out_of_webs(void);
  int is_able_to_change_levels(void);
  int is_able_to_collect_keys(void);
  int is_able_to_enchant_weapons(void);
  int is_able_to_fall(void);
  int is_able_to_fire_at(void);
  int is_able_to_jump_attack(void);
  int is_able_to_jump_onto(void);
  int is_able_to_jump_distance(void);
  int is_able_to_jump_on_low_hp_chance_d1000(void);
  int is_able_to_jump_randomly_chance_d1000(void);
  int is_able_to_jump_attack_chance_d1000(void);
  int is_able_to_jump_onto_chance_d1000(void);
  int is_able_to_jump(void);
  int is_able_to_learn_skills(void);
  int is_able_to_open_doors(void);
  int is_able_to_see_in_the_dark(void);
  int is_able_to_see_through_doors(void);
  int is_able_to_shove(void);
  int is_able_to_tire(void);
  int is_able_to_walk_through_walls(void);
  int is_acid(void);
  int is_alive_monst(void);
  int is_alive_on_end_of_anim(void);
  int is_always_hit(void);
  int is_ascend_dungeon(void);
  int is_ascend_sewer(void);
  int is_attackable_by_monst(void);
  int is_attackable_by_player(void);
  int is_melee_attacked_by(Thingp hitter, int damage);
  int is_auto_collect_item(void);
  int is_auto_equipped(void);
  int is_auto_throw(void);
  int is_auto_use(void);
  int is_bag_item_container(void);
  int is_bag_item_not_stackable(void);
  int is_bag_item(void);
  int is_bag(void);
  int is_barrel(void);
  int is_bitten_by(Thingp hitter, int damage);
  int is_bleeder(void);
  int is_blood_eater(void);
  int is_blood_splatter(void);
  int is_blood(void);
  int is_bones(void);
  int is_brazier(void);
  int is_bridge(void);
  int is_buff(void);
  int is_burnable(void);
  int is_carrier_of_treasure_class_a(void);
  int is_carrier_of_treasure_class_b(void);
  int is_carrier_of_treasure_class_c(void);
  int is_chasm(void);
  int is_collectable(void);
  int is_collect_as_keys(void);
  int is_collected_as_gold(void);
  int is_combustible(void);
  int is_corpse_on_death(void);
  int is_corpse(void);
  int is_corridor(void);
  int is_critical_to_level(void);
  int is_cursor_can_hover_over(void);
  int is_cursor_can_hover_over_x2_click(void);
  int is_cursor_path_hazard_for_player(void);
  int is_cursor_path(void);
  int is_cursor(void);
  int is_dangerous(Thingp);
  int is_dead_on_end_of_anim(void);
  int is_dead_on_shove(void);
  int is_dead_or_dying(void);
  int is_debuff(void);
  int is_debug_path(void);
  int is_debug_type(void);
  int is_deep_water(void);
  int is_descend_dungeon(void);
  int is_descend_sewer(void);
  int is_described_when_hovering_over(void);
  int is_destroyed_on_hit_or_miss(void);
  int is_destroyed_on_hitting(void);
  int is_dirt(void);
  int is_door(void);
  int is_droppable(void);
  int is_dry_grass(void);
  int is_enchantable(void);
  int is_enchantstone(void);
  int is_engulfer(void);
  int is_ethereal_minion_generator(void);
  int is_ethereal(void);
  int is_exit_finder(void);
  int is_explosion(void);
  int is_fearless(void);
  int is_fire(void);
  int is_floating(void);
  int is_floor_deco(void);
  int is_floor(void);
  int is_foilage(void);
  int is_food_eater(void);
  int is_food(void);
  int is_gfx_anim_synced_with_owner(void);
  int is_glass(void);
  int is_gold(void);
  int is_hazard(void);
  int is_health_booster(void);
  int is_hittable(void);
  int is_hit(Thingp hitter, bool crit, bool bite, bool poison, bool necrosis, int damage);
  int is_humanoid(void);
  int is_hunger_insatiable(void);
  int is_indestructible(void);
  int is_intelligent(void);
  int is_interesting(void);
  int is_item_carrier(void);
  int is_item_collector(void);
  int is_item_eater(void);
  int is_item_magical_eater(void);
  int is_item_magical(void);
  int is_item_organic(void);
  int is_item(void);
  int is_jelly_baby_eater(void);
  int is_jelly_baby(void);
  int is_jelly_eater(void);
  int is_jelly_parent(void);
  int is_jelly(void);
  int is_key(void);
  int is_laser(void);
  int is_lava(void);
  int is_level_explorer(void);
  int is_light_blocker(void);
  int is_living(void);
  int is_loggable(void);
  int is_meat_eater(void);
  int is_meat(void);
  int is_metal(void);
  int is_minion_generator(void);
  int is_minion(void);
  int is_monst(void);
  int is_moveable(void);
  int is_msg(void);
  int is_necrotic_danger_level(void);
  int is_necrotized_by(Thingp hitter, int damage);
  int is_no_tile(void);
  int is_obs_destructable(void);
  int is_obs_wall_or_door(void);
  int is_openable(void);
  int is_organic(void);
  int is_player(void);
  int is_poisoned_by(Thingp hitter, int damage);
  int is_poisonous_danger_level(void);
  int is_potion_eater(void);
  int is_potion(void);
  int is_projectile(void);
  int is_removeable_if_out_of_slots(void);
  int is_resurrectable(void);
  int is_ring(void);
  int is_ripple(void);
  int is_rock(void);
  int is_rusty(void);
  int is_secret_door(void);
  int is_sewer_wall(void);
  int is_shallow_water(void);
  int is_shovable(void);
  int is_skillstone(void);
  int is_skill(void);
  int is_smoke(void);
  int is_soft_body(void);
  int is_spawner(void);
  int is_spiderweb(void);
  int is_steal_item_chance_d1000(void);
  int is_sticky(void);
  int is_stone(void);
  int is_sword(void);
  int is_target_auto_select(void);
  int is_throwable(void);
  int is_tickable(void);
  int is_tmp_thing(void);
  int is_torch(void);
  int is_treasure_class_a(void);
  int is_treasure_class_b(void);
  int is_treasure_class_c(void);
  int is_treasure_type_chest(void);
  int is_treasure_type_eater(void);
  int is_treasure_type(void);
  int is_undead(void);
  int is_usable(void);
  int is_used_when_thrown(void);
  int is_very_combustible(void);
  int is_wall_dungeon(void);
  int is_wall(void);
  int is_wand(void);
  int is_water(void);
  int is_weapon_equiper(void);
  int is_weapon(void);
  int is_wooden(void);
  int item_count_excluding_charges(Tpp item);
  int item_count_including_charges(Tpp item);
  int item_enchant_count(const uint32_t slot);
  int item_height(void);
  int item_slot_charge_count(const uint32_t slot);
  int item_width(void);
  int light_strength(void);
  int maybe_itemp_value(const Thingp it);
  int minion_leash_distance(void);
  int minion_limit(void);
  int monst_size(void);
  int normal_placement_rules(void);
  int on_death_drop_all_items(void);
  int on_death_is_open(void);
  int range_max(void);
  int rarity(void);
  int set_charge_count(int);
  int set_current_damage(int);
  int set_enchant(int);
  int set_enchant_max(int);
  int set_gold(int);
  int set_health(int);
  int set_health_max(int);
  int set_idle_count(int);
  int set_keys(int);
  int set_lifespan(int);
  int set_light_strength(int);
  int set_minion_count(int);
  int set_necrotized_amount(int);
  int set_owned_count(int);
  int set_poisoned_amount(int);
  int set_spawned_count(int);
  int set_stamina(int);
  int set_stamina_max(int);
  int set_stat_armor_class(int);
  int set_stat_attack_bonus(int);
  int set_stat_constitution(int);
  int set_stat_dexterity(int);
  int set_stats02(int);
  int set_stats03(int);
  int set_stats04(int);
  int set_stats05(int);
  int set_stats06(int);
  int set_stats07(int);
  int set_stats08(int);
  int set_stats09(int);
  int set_stats10(int);
  int set_stats11(int);
  int set_stats12(int);
  int set_stats17(int);
  int set_stats19(int);
  int set_stat_strength(int);
  int set_stuck_count(int);
  int set_throw_distance(int);
  int skill_enchant_count(const uint32_t slot);
  int unused_chance1_d1000(void);
  int unused_chance2_d1000(void);
  int unused_chance3_d1000(void);
  int unused_chance4_d1000(void);
  int unused_chance5_d1000(void);
  int unused_chance6_d1000(void);
  int unused_chance7_d1000(void);
  int unused_chance8_d1000(void);
  int unused_flag10(void);
  int unused_flag11(void);
  int unused_flag12(void);
  int unused_flag13(void);
  int unused_flag14(void);
  int unused_flag15(void);
  int unused_flag16(void);
  int unused_flag17(void);
  int unused_flag18(void);
  int unused_flag19(void);
  int unused_flag1(void);
  int unused_flag20(void);
  int unused_flag21(void);
  int is_able_to_jump_without_tiring(void);
  int is_spider(void);
  int unused_flag25(void);
  int unused_flag2(void);
  int unused_flag30(void);
  int unused_flag3(void);
  int unused_flag4(void);
  int unused_flag5(void);
  int unused_flag6(void);
  int unused_flag7(void);
  int unused_flag8(void);
  int unused_flag9(void);
  int update_light_strength(void);
  int weapon_damage(void);
  int worth_collecting(const Thingp it);
  int worth_collecting(const Thingp it, Thingp *would_need_to_drop);
  int on_owner_damage_poison(Thingp owner, Thingp hitter, int damage);
  int on_owner_damage_constitution(Thingp owner, Thingp hitter, int damage);
  int on_owner_damage_strength(Thingp owner, Thingp hitter, int damage);
  int on_owner_damage_melee(Thingp owner, Thingp hitter, int damage);
  int on_owner_damage_necrosis(Thingp owner, Thingp hitter, int damage);
  int on_owner_damage_bite(Thingp owner, Thingp hitter, int damage);

  point dir_to_direction();
  point get_random_target(void);
  point get_where_i_dropped_an_item_last(void);
  point get_lunge_to(void);

  point get_where_i_failed_to_collect_last(void);
  point set_where_i_dropped_an_item_last(point);
  point set_where_i_failed_to_collect_last(point);

  std::list< Thingp > anything_to_carry(void);
  std::list< Thingp > anything_to_carry_at(point);

  std::size_t get_light_count(void);

  std::string short_text_The(void);
  std::string short_text_a_or_an(void);
  std::string short_text_capitalized(void);
  std::string short_text_the(void);
  std::string text_The(void);
  std::string text_a_or_an(void);
  std::string text_the(bool include_owner = false);
  std::string to_dbg_saved_string(void);
  std::string to_dbg_string(void);
  std::string to_short_string(void);
  std::string to_string(void);

  std::vector< Lightp > &get_light(void);

  struct AgeMap_ *get_age_map(void);
  struct AgeMap_ *get_seen_map(void);
  struct AgeMap_ *get_interrupt_map(void);

  struct Dmap_ *get_dmap_can_see(void);

  struct FovMap_ *get_can_see_currently(void);
  struct FovMap_ *get_can_see_ever(void);

  ts_t decr_ts_anim_delay_end(ts_t);
  ts_t decr_ts_anim_delay_end(void);
  ts_t decr_ts_bounce_begin(ts_t);
  ts_t decr_ts_bounce_begin(void);
  ts_t decr_ts_bounce_end(ts_t);
  ts_t decr_ts_bounce_end(void);
  ts_t decr_ts_fadeup_begin(ts_t);
  ts_t decr_ts_fadeup_begin(void);
  ts_t decr_ts_fadeup_end(ts_t);
  ts_t decr_ts_fadeup_end(void);
  ts_t decr_ts_fall_begin(ts_t);
  ts_t decr_ts_fall_begin(void);
  ts_t decr_ts_fall_end(ts_t);
  ts_t decr_ts_fall_end(void);
  ts_t decr_ts_flip_start(ts_t);
  ts_t decr_ts_flip_start(void);
  ts_t decr_ts_lunge_begin(ts_t);
  ts_t decr_ts_lunge_begin(void);
  ts_t decr_ts_lunge_end(ts_t);
  ts_t decr_ts_lunge_end(void);
  ts_t get_ts_anim_delay_end(void);
  ts_t get_ts_bounce_begin(void);
  ts_t get_ts_bounce_end(void);
  ts_t get_ts_fadeup_begin(void);
  ts_t get_ts_fadeup_end(void);
  ts_t get_ts_fall_begin(void);
  ts_t get_ts_fall_end(void);
  ts_t get_ts_flip_start(void);
  ts_t get_ts_lunge_begin(void);
  ts_t get_ts_lunge_end(void);
  ts_t incr_ts_anim_delay_end(ts_t);
  ts_t incr_ts_anim_delay_end(void);
  ts_t incr_ts_bounce_begin(ts_t);
  ts_t incr_ts_bounce_begin(void);
  ts_t incr_ts_bounce_end(ts_t);
  ts_t incr_ts_bounce_end(void);
  ts_t incr_ts_fadeup_begin(ts_t);
  ts_t incr_ts_fadeup_begin(void);
  ts_t incr_ts_fadeup_end(ts_t);
  ts_t incr_ts_fadeup_end(void);
  ts_t incr_ts_fall_begin(ts_t);
  ts_t incr_ts_fall_begin(void);
  ts_t incr_ts_fall_end(ts_t);
  ts_t incr_ts_fall_end(void);
  ts_t incr_ts_flip_start(ts_t);
  ts_t incr_ts_flip_start(void);
  ts_t incr_ts_lunge_begin(ts_t);
  ts_t incr_ts_lunge_begin(void);
  ts_t incr_ts_lunge_end(ts_t);
  ts_t incr_ts_lunge_end(void);
  ts_t set_ts_anim_delay_end(ts_t);
  ts_t set_ts_bounce_begin(ts_t);
  ts_t set_ts_bounce_end(ts_t);
  ts_t set_ts_fadeup_begin(ts_t);
  ts_t set_ts_fadeup_end(ts_t);
  ts_t set_ts_fall_begin(ts_t);
  ts_t set_ts_fall_end(ts_t);
  ts_t set_ts_flip_start(ts_t);
  ts_t set_ts_lunge_begin(ts_t);
  ts_t set_ts_lunge_end(ts_t);

  uint32_t decr_tick_last_did_something(uint32_t);
  uint32_t decr_tick_last_did_something(void);
  uint32_t decr_tick_last_dropped(uint32_t);
  uint32_t decr_tick_last_dropped(void);
  uint32_t decr_tick_last_escape(uint32_t);
  uint32_t decr_tick_last_escape(void);
  uint32_t decr_tick_last_level_change(uint32_t);
  uint32_t decr_tick_last_level_change(void);
  uint32_t decr_tick_last_location_check(uint32_t);
  uint32_t decr_tick_last_location_check(void);
  uint32_t decr_tick_resurrect_when(int);
  uint32_t decr_tick_resurrect_when(void);
  uint32_t get_tick_last_did_something(void);
  uint32_t get_tick_last_dropped(void);
  uint32_t get_tick_last_escape(void);
  uint32_t get_tick_last_level_change(void);
  uint32_t get_tick_last_location_check(void);
  uint32_t get_tick_resurrect_when(void);
  uint32_t incr_tick_last_did_something(uint32_t);
  uint32_t incr_tick_last_did_something(void);
  uint32_t incr_tick_last_dropped(uint32_t);
  uint32_t incr_tick_last_dropped(void);
  uint32_t incr_tick_last_escape(uint32_t);
  uint32_t incr_tick_last_escape(void);
  uint32_t incr_tick_last_level_change(uint32_t);
  uint32_t incr_tick_last_level_change(void);
  uint32_t incr_tick_last_location_check(uint32_t);
  uint32_t incr_tick_last_location_check(void);
  uint32_t incr_tick_resurrect_when(int);
  uint32_t incr_tick_resurrect_when(void);
  uint32_t set_tick_last_did_something(uint32_t);
  uint32_t set_tick_last_dropped(uint32_t);
  uint32_t set_tick_last_escape(uint32_t);
  uint32_t set_tick_last_level_change(uint32_t);
  uint32_t set_tick_last_location_check(uint32_t);
  uint32_t set_tick_resurrect_when(int);

  uint8_t blit_begin_reflection_submerged(void);
  uint8_t blit_begin_submerged(void);
  uint8_t get_terrain_cost(point p);
  uint8_t is_dir_bl(void);
  uint8_t is_dir_br(void);
  uint8_t is_dir_down(void);
  uint8_t is_dir_left(void);
  uint8_t is_dir_none(void);
  uint8_t is_dir_right(void);
  uint8_t is_dir_tl(void);
  uint8_t is_dir_tr(void);
  uint8_t is_dir_up(void);
  uint8_t is_visible();
  uint8_t z_prio(void);

  bool jump_attack(Thingp it = nullptr);
  void achieve_goals_in_death();
  void achieve_goals_in_life();
  void acid_tick();
  void add_avoid(Thingp attacker);
  void add_enemy(Thingp attacker);
  void add_goal_penalty(Thingp attacker);
  void ai_change_state(int new_state, const std::string &why);
  void ai_choose_can_see_goals(std::multiset< Goal > &goals, int minx, int miny, int maxx, int maxy);
  void ai_choose_search_goals(std::multiset< Goal > &goals, int search_type);
  void ai_get_next_hop(void);
  void ai_log(const std::string &short_msg);
  void ai_log(const std::string &short_msg, const std::string &long_msg);
  void ai_log(const std::string &short_msg, const std::string &long_msg, Thingp it);
  void ai_log(const std::string &short_msg, Thingp it);
  void animate();
  void avoid_tick(void);
  void barrel_tick();
  void blit_end_reflection_submerged(uint8_t submerged);
  void blit_end_submerged(uint8_t submerged);
  void blit_floor_chasm(point &tl, point &br, const ThingTiles *tiles);
  void blit_internal(int fbo, point &blit_tl, point &blit_br, const Tilep tile, color c, const bool reflection);
  void blit(int fbo);
  void blit_non_player_owned_shadow(const Tpp &tp, const Tilep &tile, const point &tl, const point &br);
  void blit_player_owned_shadow(const Tpp &tp, const Tilep &tile, const point &tl, const point &br);
  void blit_shadow(const Tpp &tp, const Tilep &tile, const point &tl, const point &br);
  void blit_text(std::string const &, color c, point tl, point br);
  void blit_upside_down(int fbo);
  void blit_wall_cladding(point &tl, point &br, const ThingTiles *tiles);
  void blit_wall_shadow(point &tl, point &br, const ThingTiles *tiles);
  void botcon(const char *fmt, ...) __attribute__((format(printf, 2, 3)));
  void botcon_(const char *fmt, va_list args); // compile error without
  void bounce(float bounce_height, float bounce_fade, ts_t ms, int bounce_count);
  void brazier_tick();
  void buff_activate(Thingp what);
  void buff_deactivate(Thingp what);
  void buff_remove_all(void);
  void chasm_tick();
  void clear_age_map(void);
  void clear_can_see_currently(void);
  void clear_can_see_ever(void);
  void clear_dmap_can_see(void);
  void clear_interrupt_map(void);
  void clear_move_path(const std::string &why);
  void clear_seen_map(void);
  void con(const char *fmt, ...) __attribute__((format(printf, 2, 3)));
  void con_(const char *fmt, va_list args); // compile error without
  void corrode_tick();
  void cursor_hover_over_check(void);
  void dead(const char *fmt, ...) __attribute__((format(printf, 2, 3)));
  void dead_(const char *fmt, va_list args); // compile error without
  void dead(const std::string &);
  void dead_scheduled(const char *fmt, ...) __attribute__((format(printf, 2, 3)));
  void dead_scheduled_(const char *fmt, va_list args); // compile error without
  void dead_scheduled(const std::string &);
  void dead(Thingp defeater, const char *fmt, ...) __attribute__((format(printf, 3, 4)));
  void dead_(Thingp defeater, const char *fmt, va_list args); // compile error without
  void dead(Thingp defeater, std::string &);
  void debuff_activate(Thingp what);
  void debuff_deactivate(Thingp what);
  void debuff_remove_all(void);
  void defeat(Thingp defeater, const char *reason);
  void defeat(Thingp defeater, const std::string &reason);
  void delete_laser();
  void delete_lights(void);
  void delete_particle();
  void delete_projectile();
  void destroy();
  void destroyed(void);
  void destroy_minions(Thingp defeater);
  void destroy_spawned(Thingp defeater);
  void die(const char *fmt, ...) __attribute__((format(printf, 2, 3)));
  void die_(const char *fmt, va_list args); // compile error without
  void dir_set_bl(void);
  void dir_set_br(void);
  void dir_set_down(void);
  void dir_set_left(void);
  void dir_set_none(void);
  void dir_set_right(void);
  void dir_set_tl(void);
  void dir_set_tr(void);
  void dir_set_up(void);
  void dmap_modify_terrain_cost(point p, uint8_t *d);
  void drop_all(void);
  void dump(std::string prefix, std::ostream &out);
  void enchant_randomly(void);
  void enemies_tick(void);
  void equip_remove_anim(int equip);
  void err(const char *fmt, ...) __attribute__((format(printf, 2, 3)));
  void err_(const char *fmt, va_list args); // compile error without
  void fadeup(float fadeup_height, float fadeup_fade, ts_t ms);
  void fall(float fall_height, ts_t ms);
  void fire_tick();
  void gc(void);
  void get_equip_use_offset(int *dx, int *dy, int equip);
  void get_light_strength_including_torch_effect(uint8_t &light_strength);
  void get_tiles(void);
  void goal_penalty_tick(void);
  void grass_tick();
  void hide();
  void hooks_remove();
  void hunger_clock();
  void incr_score(int);
  void inherit_from(Thingp it);
  void init(Levelp, const std::string &name, point at);
  void init_lights(void);
  void inventory_particle(Thingp what, uint32_t slot);
  void inventory_particle(Thingp what, uint32_t slot, Thingp particle_target);
  void jump_end(void);
  void lava_tick();
  void level_change(Levelp);
  void level_enter(void);
  void level_leave(void);
  void level_pop(void);
  void level_push(void);
  void lifespan_tick();
  void light_update_strength(void);
  void location_check();
  void location_check_all_things_at();
  void location_check_forced();
  void location_check_forced_all_things_at();
  void log(const char *fmt, ...) __attribute__((format(printf, 2, 3)));
  void log_(const char *fmt, va_list args); // compile error without
  void lunge(point tt);
  void move_carried_items_immediately(void);
  void move_carried_items(void);
  void move_delta(point);
  void move_finish(void);
  void move_set_dir_from_delta(point);
  void move_to_immediately(point to);
  void move_to(point to);
  void msg(const std::string &);
  void necrosis_tick(void);
  void new_aip(void);
  void new_infop(void);
  void new_itemp(void);
  void new_light(point offset, int strength);
  void new_light(point offset, int strength, color col, int fbo);
  void on_born(void);
  void on_enchant(void);
  void on_equip(Thingp what);
  void on_fall(void);
  void on_final_use(Thingp what);
  void on_final_use(Thingp what, Thingp target);
  void on_fire(void);
  void on_lifespan(Thingp hitter);
  void on_move(void);
  void on_open(void);
  void on_owner_set(Thingp owner);
  void on_owner_unset(Thingp owner);
  void on_unequip(Thingp what);
  void on_use(Thingp what);
  void on_use(Thingp what, Thingp target);
  void on_you_are_hit(Thingp hitter, Thingp real_hitter, bool crit, int dmg);
  void on_you_bite_attack(void);
  void on_you_miss_do(Thingp hitter);
  void poisoned(void);
  void poison_tick(void);
  void reinit(void);
  void remove_all_references();
  void remove_minion_owner(void);
  void remove_owner(void);
  void remove_spawner_owner(void);
  void rest();
  void resurrect_tick();
  void rotting(void);
  void score_add(Thingp victim);
  void secret_door_tick();
  void set_bounce_count(int);
  void set_bounce_fade(float);
  void set_bounce_height(float);
  void set_dead_reason(const std::string &);
  void set_equip_carry_anim_id(ThingId equip_carry_anim_id, int equip);
  void set_equip_carry_anim(Thingp equip_carry_anim, int equip);
  void set_equip_use_anim_id(ThingId gfx_anim_use_id, int equip);
  void set_equip_use_anim(Thingp gfx_anim_use, int equip);
  void set_fadeup_fade(float);
  void set_fadeup_height(float);
  void set_fall_height(float);
  void set_interpolated_mid_at(fpoint v);
  void set_lunge_to(point);
  void set_minion_owner(Thingp minion_owner);
  void set_msg(const std::string &);
  void set_owner(Thingp owner);
  void set_score(int);
  void set_spawned_owner(Thingp spawner_owner);
  void set_submerged_offset(int);
  void set_wobble(float);
  void show_botcon_description(void);
  void skill_activate(Thingp what);
  void skill_deactivate(Thingp what);
  void skill_remove_all(void);
  void stamina_boost(int v);
  void stats_tick();
  void throw_at(Thingp w, Thingp target);
  void tick();
  void topcon(const char *fmt, ...) __attribute__((format(printf, 2, 3)));
  void topcon_(const char *fmt, va_list args); // compile error without
  void try_to_carry(const std::list< Thingp > &items);
  void unleash_minions(void);
  void unleash_spawners_things(void);
  void unset_on_fire(void);
  void update_all(void);
  void update_interpolated_position(void);
  void update_light_strength_including_torch_effect(uint8_t &light_strength);
  void update_light(void);
  void update_pos(point, bool immediately);
  void update_tick(void);
  void used(Thingp w, Thingp target, bool remove_after_use);
  void visible();
  void water_tick();
  void weapon_sheath(void);
  void wobble(float wobble);

  const std::array< std::array< ThingId, MAX_BAG_WIDTH >, MAX_BAG_HEIGHT > *get_const_bag(void);
  std::array< std::array< ThingId, MAX_BAG_WIDTH >, MAX_BAG_HEIGHT >       *get_bag(void);
  static std::function< int(Thingp) >                                       matches_to_func(const std::string &what);

  ThingInfop get_or_alloc_infop(void);
  ThingItemp get_or_alloc_itemp(void);
  ThingAip   get_or_alloc_aip(void);

  ThingInfop maybe_infop(void) { return _infop; }
  ThingItemp maybe_itemp(void) { return _itemp; }
  ThingAip   maybe_aip(void) { return _aip; }

  ThingInfop get_infop(void);
  ThingItemp get_itemp(void);
  ThingAip   get_aip(void);

} Thing;

std::ostream &operator<<(std::ostream &out, Bits< const Thingp & > const my);
std::istream &operator>>(std::istream &in, Bits< Thingp & > my);

bool things_overlap(Thingp t, Thingp o);
bool things_overlap(Thingp t, fpoint t_at, Thingp o);
int  bag_estimate_volume(const std::list< Thingp > &items);

extern Thingp g_debug_thing;

#endif // _MY_THING_HPP_
