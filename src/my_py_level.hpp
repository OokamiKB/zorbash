//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#pragma once
#ifndef _MY_PY_LEVEL_HPP_
#define _MY_PY_LEVEL_HPP_
#include <Python.h>

PyObject *level_add_(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_ai_detect_secret_doors_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_ai_resent_count_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_ai_wanderer_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_attack_engulf_chance_d1000_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_attack_undead_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_collision_hit_180_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_collision_hit_360_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_collision_hit_adj_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_damage_received_doubled_from_cold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_enchant_level_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_enchant_max_current_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_environ_avoids_acid_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_environ_avoids_fire_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_environ_avoids_cold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_environ_avoids_necrosis_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_environ_avoids_poison_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_environ_avoids_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_flood_fill_get_all_things(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_get_all(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_gfx_flickers_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_gfx_health_bar_shown_when_awake_only_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_gfx_long_shadow_caster_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_gfx_show_asleep_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_gfx_solid_shadow_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_gfx_very_short_shadow_caster_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_gfx_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_hunger_clock_tick_freq_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_hunger_is_insatiable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_attack_mobs_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_break_down_doors_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_break_out_of_webs_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_change_levels_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_collect_keys_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_enchant_items_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_fall_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_fire_at_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_follow_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_jump_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_jump_attack_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_jump_attack_chance_d1000_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_jump_escape_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_jump_on_low_hp_chance_d1000_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_jump_onto_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_jump_onto_chance_d1000_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_jump_randomly_chance_d1000_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_jump_without_tiring_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_learn_skills_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_move_diagonally_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_open_doors_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_see_in_the_dark_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_see_through_doors_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_sleep_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_tire_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_use_amulet_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_use_armor_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_use_boots_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_use_cloak_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_use_gauntlet_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_use_helmet_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_use_rings_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_use_shield_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_use_wands_or_staffs_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_use_weapons_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_walk_through_walls_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_acid_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_alive_monst_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_alive_on_end_of_anim_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_always_hit_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_amulet_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_aquatic_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_armor_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ascend_dungeon_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ascend_sewer_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_asleep_initially_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_attackable_by_monst_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_attackable_by_player_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_auto_collect_item_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_auto_equipped_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_auto_throw_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_auto_use_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bag_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bag_item_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bag_item_container_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bag_item_not_stackable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_barrel_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_biome_dungeon_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_biome_swamp_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bleeder_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bloodied_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bones_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_corpse_with_bones_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_boots_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_brazier_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_breather_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bridge_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_buff_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_burnable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_carrying_item_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_carrying_treasure_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_chasm_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cloak_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_collectable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_collect_as_keys_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_collected_as_gold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_combustible_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_corpse_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_corpse_on_death_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_corridor_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_critical_to_level_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_crushable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_can_hover_over_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_can_hover_over_x2_click_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_path_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_path_hazard_for_player_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_combustible_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dead_on_end_of_anim_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dead_on_falling_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dead_on_shove_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_debuff_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_debug_path_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_debug_type_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_deep_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_descend_dungeon_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_descend_sewer_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_described_when_hovering_over_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_destroyed_on_hit_or_miss_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_destroyed_on_hitting_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_bl_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_br_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_down_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_left_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_none_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_right_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dirt_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_tl_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_tr_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_up_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_door_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_droppable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dry_grass_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_enchantable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_enchantstone_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_engulfer_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ethereal_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ethereal_mob_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_exit_finder_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_explorer_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_explosion_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_fearless_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_fire_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_floating_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_floor_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_floor_deco_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_flying_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_foilage_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_food_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_food_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_gas_blocker_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_gauntlet_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_gfx_anim_synced_with_owner_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_glass_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_gold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_green_blood_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_green_blood_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_green_blooded_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_green_splatter_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_hazard_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_health_booster_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_heavy_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_helmet_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_hittable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_humanoid_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_acid_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_cold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_fire_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_necrosis_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_poison_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_spiderwebs_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_intelligent_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_interesting_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_carrier_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_collector_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_magical_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_magical_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_organic_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_jelly_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_jelly_baby_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_jelly_baby_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_jelly_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_jelly_parent_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_key_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_lava_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_light_blocker_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_light_blocker_for_monst_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_light_blocker_for_monst_for_monst_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_living_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_loggable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_meat_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_meat_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_meltable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_metal_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_minion_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_mob_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_mob_challenge_class_a_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_mob_challenge_class_b_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_class_a_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_class_b_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_class_c_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_class_d_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_class_e_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_moveable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_msg_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_necrotic_danger_level_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_no_tile_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_obs_destructable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_obstacle_when_dead_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_obs_wall_or_door_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_on_firing_at_something(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_openable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_organic_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_pink_blood_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_pink_blood_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_pink_blooded_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_pink_splatter_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_player_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_poisonous_danger_level_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_potion_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_potion_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_red_blood_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_red_blood_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_red_blooded_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_red_splatter_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_removeable_if_out_of_slots_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_resurrectable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ring_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ripple_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_rock_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_rusty_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_secret_door_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_sewer_wall_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_shallow_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_shield_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_shovable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_skill_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_skillstone_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_slippery_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_smoke_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_spawner_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_spider_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_spiderweb_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_steal_item_chance_d1000_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_sticky_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_stone_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_sword_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_temperature_change_sensitive_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_temperature_sensitive_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_throwable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_tickable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_tmp_thing_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_torch_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_toughness_hard_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_toughness_soft_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_toughness_very_hard_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_treasure_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_treasure_chest_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_treasure_eater_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_treasure_type_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_undead_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_usable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_used_when_thrown_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_very_is_combustible_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_very_heavy_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_target_select_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_visible_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_wall_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_wall_dungeon_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_wand_or_staff_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_weapon_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_wet_grass_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_wooden_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_move_speed_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_noise_blocker_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_noise_decibels_hearing_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_noise_on_born_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_noise_additional_on_jump_end_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_noise_on_dropping_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_noise_on_open_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_noise_on_you_are_hit_and_now_dead_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_noise_on_you_are_hit_but_still_alive_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stamina_drain_on_swinging(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stamina_drain_on_using(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_att_penalty_when_idle_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_att_penalty_when_idle_max_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_att_penalty_when_in_deep_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_att_penalty_when_in_shallow_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_att_penalty_when_stuck_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_att_penalty_when_stuck_max_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_def_penalty_when_idle_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_def_penalty_when_idle_max_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_def_penalty_when_in_deep_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_def_penalty_when_in_shallow_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_def_penalty_when_stuck_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_stat_def_penalty_when_stuck_max_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_temperature_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag100_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag101_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag102_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag103_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag104_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag105_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag106_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag107_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag108_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_key_special_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag10_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_crystal_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_noise_on_moving_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_tireless_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_shove_strength_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_gfx_wobbles_when_hit_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_snake_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_targetted_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_noise_additional_on_teleporting_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_teleport_attack_chance_d1000_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_teleport_distance_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag11_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_teleport_attack_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_teleport_without_tiring_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_teleport_escape_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag123_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_pack_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_pillar_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_walk_through_walls_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_collision_hit_two_tiles_ahead_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_flat_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_target_radial_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag12_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_staff_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag13_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag14_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag15_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag16_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag17_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag18_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag19_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag1_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag20_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag21_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag22_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag23_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag24_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag25_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag26_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag27_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag28_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag29_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag2_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag30_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag31_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag32_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag33_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag34_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag35_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag36_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag37_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag38_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag39_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag3_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag40_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag41_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag42_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag43_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag44_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag45_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag46_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag47_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag48_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag49_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag4_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag50_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag51_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag52_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag53_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag54_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag55_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag56_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag57_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag58_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag59_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag5_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag60_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag61_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag62_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag63_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag64_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag65_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag66_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag67_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag68_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag69_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag6_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag70_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag71_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag72_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag73_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag74_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag75_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag76_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag77_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag78_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag79_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag7_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag80_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag81_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag82_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag83_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag84_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag85_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag86_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag87_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag88_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag89_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag8_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag90_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag91_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag92_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag93_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag94_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag95_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag96_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag97_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag98_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag99_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_unused_flag9_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_all_followers_get(PyObject *obj, PyObject *args, PyObject *keywds);
#endif
