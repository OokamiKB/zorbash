//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#pragma once
#ifndef _MY_PY_THING_HPP_
#define _MY_PY_THING_HPP_
#include <Python.h>

PyObject *thing_set_health(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_incr_health(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_health(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_health(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_set_health_max(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_incr_health_max(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_health_max(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_health_max(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_set_poisoned_amount(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_incr_poisoned_amount(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_poisoned_amount(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_poisoned_amount(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_set_necrotized_amount(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_incr_necrotized_amount(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_necrotized_amount(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_necrotized_amount(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_set_stamina(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_incr_stamina(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_stamina(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_stamina(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_set_stamina_max(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_incr_stamina_max(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_stamina_max(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_stamina_max(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_set_enchant(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_incr_enchant(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_enchant(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_enchant(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_set_enchant_max(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_incr_enchant_max(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_enchant_max(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_enchant_max(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_set_current_damage(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_incr_current_damage(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_current_damage(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_current_damage(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_incr_charge_count(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_charge_count(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_charge_count(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_initial_charge_count(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_incr_idle_count(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_idle_count(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_idle_count(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_incr_stuck_count(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_decr_stuck_count(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_stuck_count(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_get_name(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_skill_activate(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_skill_deactivate(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_msg(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *level_is_able_to_fire_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_ai_resent_count(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_ai_aggression_level_pct(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_ai_detect_secret_doors(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_ai_wanderer(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_attack_blood(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_attack_engulf_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_attack_undead(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_buff_add(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_buff_remove(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_necrosis_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_poison_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_future1_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_future2_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_future3_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_future4_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_future5_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_future6_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_lightning_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_energy_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_acid_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_damage_digest_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_debuff_add(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_debuff_remove(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_defeated_by(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_defeated(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_enchant_level(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_enchant_max(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_avoids_acid(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_avoids_fire(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_avoids_necrosis(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_avoids_poison(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_avoids_water(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_prefers_acid(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_prefers_fire(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_prefers_necrosis(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_prefers_poison(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_prefers_spiderwebs(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_environ_prefers_water(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_fire_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_coords(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_immediate_minion_owner_id(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_immediate_owner_id(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_immediate_spawned_owner_id(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_top_owner_id(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_gfx_flickers(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_gfx_long_shadow_caster(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_gfx_solid_shadow(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_gfx_very_short_shadow_caster(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_gfx_water(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_hit(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_attack_generators(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_break_down_doors(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_break_out_of_webs(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_change_levels(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_collect_keys(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_enchant_weapons(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_fall(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_attack(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_onto(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_distance(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_on_low_hp_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_randomly_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_attack_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_onto_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_randomly(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_attack(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_onto(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_learn_skills(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_open_doors(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_see_in_the_dark(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_see_through_doors(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_tire(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_walk_through_walls(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_acid(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_alive_monst(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_alive_on_end_of_anim(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_always_hit(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_ascend_dungeon(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_ascend_sewer(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_auto_collect_item(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_auto_equipped(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_auto_throw(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_auto_use(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_bag_item_container(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_bag_item_not_stackable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_bag_item(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_bag(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_barrel(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_bleeder(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_blood_eater(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_bloodied(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_blood(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_blood_splatter(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_bones(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_brazier(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_bridge(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_buff(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_burnable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_carrier_of_treasure_class_a(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_carrier_of_treasure_class_b(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_carrier_of_treasure_class_c(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_carrying_item(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_carrying_treasure(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_chasm(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_collectable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_collect_as_keys(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_collected_as_gold(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_combustible(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_corpse_on_death(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_corpse(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_corridor(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_critical_to_level(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_cursor_can_hover_over(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_cursor_can_hover_over_x2_click(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_cursor_path_hazard_for_player(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_cursor_path(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_cursor(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dead_on_end_of_anim(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dead_or_dying_on_shove(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dead_or_dying(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_debuff(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_debug_path(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_debug_type(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_deep_water(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_descend_dungeon(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_descend_sewer(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_described_when_hovering_over(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_destroyed_on_hit_or_miss(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_destroyed_on_hitting(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dir_bl(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dir_br(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dir_down(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dir_left(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dir_none(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dir_right(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dir_tl(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dirt(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dir_tr(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dir_up(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_door(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_droppable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_dry_grass(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_enchantable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_enchantstone(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_engulfer(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_ethereal_minion_generator(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_ethereal(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_exit_finder(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_explosion(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_fearless(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_fire(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_floating(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_floor_deco(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_floor(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_foilage(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_food_eater(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_food(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_gfx_anim_synced_with_owner(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_glass(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_gold(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_hazard(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_health_booster(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_hittable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_humanoid(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_hunger_insatiable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_indestructible(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_intelligent(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_interesting(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_item_carrier(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_item_collector(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_item_eater(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_item_magical_eater(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_item_magical(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_item_organic(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_item(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_jelly_baby_eater(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_jelly_baby(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_jelly_eater(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_jelly_parent(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_jelly(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_key(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_laser(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_lava(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_level_explorer(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_light_blocker(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_living(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_loggable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_meat_eater(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_meat(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_metal(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_minion_generator(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_minion(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_monst(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_moveable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_msg(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_necrotic_danger_level(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_no_tile(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_obs_destructable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_obs_wall_or_door(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_on_fire(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_openable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_organic(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_player(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_poisonous_danger_level(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_potion_eater(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_potion(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_projectile(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_removeable_if_out_of_slots(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_resurrectable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_ring(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_ripple(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_rock(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_rusty(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_secret_door(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_sewer_wall(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_shallow_water(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_shovable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_skill(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_skillstone(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_smoke(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_soft_body(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_spawner(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_spiderweb(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_steal_item_chance_d1000(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_sticky(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_stone(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_sword(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_target_auto_select(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_throwable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_tickable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_tmp_thing(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_torch(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_treasure_class_a(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_treasure_class_b(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_treasure_class_c(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_treasure_type_chest(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_treasure_type_eater(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_treasure_type(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_undead(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_usable(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_used_when_thrown(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_very_combustible(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_visible(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_wall_dungeon(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_wall(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_wand(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_water(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_weapon_equiper(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_weapon(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_wooden(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_set_minion_owner(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag10(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag11(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag12(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag13(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag14(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag15(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag16(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag17(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag18(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag19(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag1(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag20(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag21(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_able_to_jump_without_tiring(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_is_spider(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag25(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag2(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag30(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag3(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag4(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag5(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag6(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag7(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag8(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_unused_flag9(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_possible_to_attack(PyObject *obj, PyObject *args, PyObject *keywds);

PyObject *thing_get_damage_energy(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_bite(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_crush(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_melee(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_necrosis(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_poison(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_future1(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_future2(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_future3(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_future4(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_future5(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_future6(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_lightning(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_energy(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_acid(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_get_damage_digest(PyObject *obj, PyObject *args, PyObject *keywds);

#endif
