import zx


class Tp:
    """thing template"""

    def __init__(self, name, text_name=None):
        self.name = name

        if text_name is None:
            self.text_name = name
        else:
            self.text_name = text_name

        #
        # Load it into the game engine
        #
        zx.tp_load(self)

    def update(self):
        zx.tp_update(self)

    def set_tile(self, tile=None, **kw):
        zx.tp_set_tile(self, tile, **kw)

    def set_left1_tile(self, left1_tile=None, **kw):
        zx.tp_set_left1_tile(self, left1_tile, **kw)

    def set_right1_tile(self, right1_tile=None, **kw):
        zx.tp_set_right1_tile(self, right1_tile, **kw)

    def set_bot1_tile(self, bot1_tile=None, **kw):
        zx.tp_set_bot1_tile(self, bot1_tile, **kw)

    def set_top1_tile(self, top1_tile=None, **kw):
        zx.tp_set_top1_tile(self, top1_tile, **kw)

    def set_tl1_tile(self, tl1_tile=None, **kw):
        zx.tp_set_tl1_tile(self, tl1_tile, **kw)

    def set_tr1_tile(self, tr1_tile=None, **kw):
        zx.tp_set_tr1_tile(self, tr1_tile, **kw)

    def set_br1_tile(self, br1_tile=None, **kw):
        zx.tp_set_br1_tile(self, br1_tile, **kw)

    def set_bl1_tile(self, bl1_tile=None, **kw):
        zx.tp_set_bl1_tile(self, bl1_tile, **kw)

    def set_left2_tile(self, left2_tile=None, **kw):
        zx.tp_set_left2_tile(self, left2_tile, **kw)

    def set_right2_tile(self, right2_tile=None, **kw):
        zx.tp_set_right2_tile(self, right2_tile, **kw)

    def set_bot2_tile(self, bot2_tile=None, **kw):
        zx.tp_set_bot2_tile(self, bot2_tile, **kw)

    def set_bot3_tile(self, bot3_tile=None, **kw):
        zx.tp_set_bot3_tile(self, bot3_tile, **kw)

    def set_top2_tile(self, top2_tile=None, **kw):
        zx.tp_set_top2_tile(self, top2_tile, **kw)

    def set_tl2_tile(self, tl2_tile=None, **kw):
        zx.tp_set_tl2_tile(self, tl2_tile, **kw)

    def set_tr2_tile(self, tr2_tile=None, **kw):
        zx.tp_set_tr2_tile(self, tr2_tile, **kw)

    def set_br2_tile(self, br2_tile=None, **kw):
        zx.tp_set_br2_tile(self, br2_tile, **kw)

    def set_bl2_tile(self, bl2_tile=None, **kw):
        zx.tp_set_bl2_tile(self, bl2_tile, **kw)

    def set_name(self, value):
        zx.tp_set_name(self, value)

    def set_short_name(self, value):
        zx.tp_set_short_name(self, value)

    def set_blit_top_off(self, value):
        zx.tp_set_blit_top_off(self, value)

    def set_blit_bot_off(self, value):
        zx.tp_set_blit_bot_off(self, value)

    def set_blit_left_off(self, value):
        zx.tp_set_blit_left_off(self, value)

    def set_blit_right_off(self, value):
        zx.tp_set_blit_right_off(self, value)

    def set_gfx_animated(self, value):
        zx.tp_set_gfx_animated(self, value)

    def set_gfx_animated_no_dir(self, value):
        zx.tp_set_gfx_animated_no_dir(self, value)

    def set_gfx_an_animation_only(self, value):
        zx.tp_set_gfx_an_animation_only(self, value)

    def set_gfx_on_fire_anim(self, value):
        zx.tp_set_gfx_on_fire_anim(self, value)

    def set_is_monst(self, value):
        zx.tp_set_is_monst(self, value)

    def set_is_key(self, value):
        zx.tp_set_is_key(self, value)

    def set_is_floor_deco(self, value):
        zx.tp_set_is_floor_deco(self, value)

    def set_is_wall_deco(self, value):
        zx.tp_set_is_wall_deco(self, value)

    def set_is_player(self, value):
        zx.tp_set_is_player(self, value)

    def set_str1(self, value):
        zx.tp_set_str1(self, value)

    def set_str_str2(self, value):
        zx.tp_set_str_str2(self, value)

    def set_str_str3(self, value):
        zx.tp_set_str_str3(self, value)

    def set_str_str4(self, value):
        zx.tp_set_str_str4(self, value)

    def set_str_str5(self, value):
        zx.tp_set_str_str5(self, value)

    def set_str_str6(self, value):
        zx.tp_set_str_str6(self, value)

    def set_str_str7(self, value):
        zx.tp_set_str_str7(self, value)

    def set_long_text_description(self, value):
        zx.tp_set_long_text_description(self, value)

    def set_text_description(self, value):
        zx.tp_set_text_description(self, value)

    def set_on_birth_do(self, value):
        zx.tp_set_on_birth_do(self, value)

    def set_on_death_do(self, value):
        zx.tp_set_on_death_do(self, value)

    def set_text_title(self, value):
        zx.tp_set_text_title(self, value)

    def set_on_idle_dice_do(self, value):
        zx.tp_set_on_idle_dice_do(self, value)

    def set_text_hits(self, value):
        zx.tp_set_text_hits(self, value)

    def set_spawn_on_shoved(self, value):
        zx.tp_set_spawn_on_shoved(self, value)

    def set_text_a_or_an(self, value):
        zx.tp_set_text_a_or_an(self, value)

    def set_text_name(self, value):
        zx.tp_set_text_name(self, value)

    def set_light_color(self, value):
        zx.tp_set_light_color(self, value)

    def set_weapon_carry_anim(self, value):
        zx.tp_set_weapon_carry_anim(self, value)

    def set_gfx_anim_attack(self, value):
        zx.tp_set_gfx_anim_attack(self, value)

    def set_is_rrr1(self, value):
        zx.tp_set_is_rrr1(self, value)

    def set_is_rrr2(self, value):
        zx.tp_set_is_rrr2(self, value)

    def set_is_rrr3(self, value):
        zx.tp_set_is_rrr3(self, value)

    def set_is_rrr4(self, value):
        zx.tp_set_is_rrr4(self, value)

    def set_is_rrr5(self, value):
        zx.tp_set_is_rrr5(self, value)

    def set_is_rrr6(self, value):
        zx.tp_set_is_rrr6(self, value)

    def set_is_rrr7(self, value):
        zx.tp_set_is_rrr7(self, value)

    def set_is_rrr8(self, value):
        zx.tp_set_is_rrr8(self, value)

    def set_is_rrr9(self, value):
        zx.tp_set_is_rrr9(self, value)

    def set_is_rrr10(self, value):
        zx.tp_set_is_rrr10(self, value)

    def set_is_rrr11(self, value):
        zx.tp_set_is_rrr11(self, value)

    def set_is_rrr12(self, value):
        zx.tp_set_is_rrr12(self, value)

    def set_is_rrr13(self, value):
        zx.tp_set_is_rrr13(self, value)

    def set_is_rrr14(self, value):
        zx.tp_set_is_rrr14(self, value)

    def set_is_rrr15(self, value):
        zx.tp_set_is_rrr15(self, value)

    def set_is_rrr16(self, value):
        zx.tp_set_is_rrr16(self, value)

    def set_is_rrr17(self, value):
        zx.tp_set_is_rrr17(self, value)

    def set_is_rrr18(self, value):
        zx.tp_set_is_rrr18(self, value)

    def set_is_rrr19(self, value):
        zx.tp_set_is_rrr19(self, value)

    def set_is_rrr20(self, value):
        zx.tp_set_is_rrr20(self, value)

    def set_is_rrr21(self, value):
        zx.tp_set_is_rrr21(self, value)

    def set_is_rrr22(self, value):
        zx.tp_set_is_rrr22(self, value)

    def set_is_rrr23(self, value):
        zx.tp_set_is_rrr23(self, value)

    def set_is_rrr24(self, value):
        zx.tp_set_is_rrr24(self, value)

    def set_is_rrr25(self, value):
        zx.tp_set_is_rrr25(self, value)

    def set_is_rrr26(self, value):
        zx.tp_set_is_rrr26(self, value)

    def set_is_rrr27(self, value):
        zx.tp_set_is_rrr27(self, value)

    def set_is_rrr28(self, value):
        zx.tp_set_is_rrr28(self, value)

    def set_is_rrr29(self, value):
        zx.tp_set_is_rrr29(self, value)

    def set_is_rrr30(self, value):
        zx.tp_set_is_rrr30(self, value)

    def set_is_rrr31(self, value):
        zx.tp_set_is_rrr31(self, value)

    def set_is_rrr32(self, value):
        zx.tp_set_is_rrr32(self, value)

    def set_is_rrr33(self, value):
        zx.tp_set_is_rrr33(self, value)

    def set_is_rrr34(self, value):
        zx.tp_set_is_rrr34(self, value)

    def set_is_rrr35(self, value):
        zx.tp_set_is_rrr35(self, value)

    def set_is_rrr36(self, value):
        zx.tp_set_is_rrr36(self, value)

    def set_is_rrr37(self, value):
        zx.tp_set_is_rrr37(self, value)

    def set_is_rrr38(self, value):
        zx.tp_set_is_rrr38(self, value)

    def set_is_rrr39(self, value):
        zx.tp_set_is_rrr39(self, value)

    def set_is_rrr40(self, value):
        zx.tp_set_is_rrr40(self, value)

    def set_is_rrr41(self, value):
        zx.tp_set_is_rrr41(self, value)

    def set_is_rrr42(self, value):
        zx.tp_set_is_rrr42(self, value)

    def set_is_rrr43(self, value):
        zx.tp_set_is_rrr43(self, value)

    def set_is_rrr44(self, value):
        zx.tp_set_is_rrr44(self, value)

    def set_is_rrr45(self, value):
        zx.tp_set_is_rrr45(self, value)

    def set_is_rrr46(self, value):
        zx.tp_set_is_rrr46(self, value)

    def set_is_rrr47(self, value):
        zx.tp_set_is_rrr47(self, value)

    def set_is_rrr48(self, value):
        zx.tp_set_is_rrr48(self, value)

    def set_is_rrr49(self, value):
        zx.tp_set_is_rrr49(self, value)

    def set_is_rrr50(self, value):
        zx.tp_set_is_rrr50(self, value)

    def set_is_rrr51(self, value):
        zx.tp_set_is_rrr51(self, value)

    def set_is_rrr52(self, value):
        zx.tp_set_is_rrr52(self, value)

    def set_is_rrr53(self, value):
        zx.tp_set_is_rrr53(self, value)

    def set_is_rrr54(self, value):
        zx.tp_set_is_rrr54(self, value)

    def set_bag_item_height(self, value):
        zx.tp_set_bag_item_height(self, value)

    def set_bag_item_width(self, value):
        zx.tp_set_bag_item_width(self, value)

    def set_bag_height(self, value):
        zx.tp_set_bag_height(self, value)

    def set_bag_width(self, value):
        zx.tp_set_bag_width(self, value)

    def set_rrr58(self, value):
        zx.tp_set_rrr58(self, value)

    def set_rarity(self, value):
        zx.tp_set_rarity(self, value)

    def set_gfx_is_rrr99(self, value):
        zx.tp_set_gfx_is_rrr99(self, value)

    def set_is_shown_uniquely_on_leftbar(self, value):
        zx.tp_set_is_shown_uniquely_on_leftbar(self, value)

    def set_is_stamina_check(self, value):
        zx.tp_set_is_stamina_check(self, value)

    def set_gfx_shown_in_bg(self, value):
        zx.tp_set_gfx_shown_in_bg(self, value)

    def set_on_death_drop_all_items(self, value):
        zx.tp_set_on_death_drop_all_items(self, value)

    def set_is_steal_item_chance_d1000(self, value):
        zx.tp_set_is_steal_item_chance_d1000(self, value)

    def set_is_weapon_wielder(self, value):
        zx.tp_set_is_weapon_wielder(self, value)

    def set_is_item(self, value):
        zx.tp_set_is_item(self, value)

    def set_is_attackable_by_player(self, value):
        zx.tp_set_is_attackable_by_player(self, value)

    def set_is_item_class_b(self, value):
        zx.tp_set_is_item_class_b(self, value)

    def set_is_item_eater(self, value):
        zx.tp_set_is_item_eater(self, value)

    def set_is_movement_blocking_soft(self, value):
        zx.tp_set_is_movement_blocking_soft(self, value)

    def set_is_the_grid(self, value):
        zx.tp_set_is_the_grid(self, value)

    def set_is_cursor_can_hover_over_but_needs_double_click(self, value):
        zx.tp_set_is_cursor_can_hover_over_but_needs_double_click(self, value)

    def set_gfx_moves_ahead_shown(self, value):
        zx.tp_set_gfx_moves_ahead_shown(self, value)

    def set_gfx_health_bar_shown_only_when_injured(self, value):
        zx.tp_set_gfx_health_bar_shown_only_when_injured(self, value)

    def set_gfx_health_bar_shown(self, value):
        zx.tp_set_gfx_health_bar_shown(self, value)

    def set_on_death_is_open(self, value):
        zx.tp_set_on_death_is_open(self, value)

    def set_is_killed_on_hit_or_miss(self, value):
        zx.tp_set_is_killed_on_hit_or_miss(self, value)

    def set_is_killed_on_hitting(self, value):
        zx.tp_set_is_killed_on_hitting(self, value)

    def set_is_collect_as_keys(self, value):
        zx.tp_set_is_collect_as_keys(self, value)

    def set_is_ethereal(self, value):
        zx.tp_set_is_ethereal(self, value)

    def set_is_potion_eater(self, value):
        zx.tp_set_is_potion_eater(self, value)

    def set_is_throwable(self, value):
        zx.tp_set_is_throwable(self, value)

    def set_is_usable(self, value):
        zx.tp_set_is_usable(self, value)

    def set_is_droppable(self, value):
        zx.tp_set_is_droppable(self, value)

    def set_is_item_not_stackable(self, value):
        zx.tp_set_is_item_not_stackable(self, value)

    def set_is_item_class_a(self, value):
        zx.tp_set_is_item_class_a(self, value)

    def set_is_bag(self, value):
        zx.tp_set_is_bag(self, value)

    def set_is_rrr59(self, value):
        zx.tp_set_is_rrr59(self, value)

    def set_is_potion(self, value):
        zx.tp_set_is_potion(self, value)

    def set_is_shown_on_leftbar(self, value):
        zx.tp_set_is_shown_on_leftbar(self, value)

    def set_is_floating(self, value):
        zx.tp_set_is_floating(self, value)

    def set_is_double_damage_from_acid(self, value):
        zx.tp_set_is_double_damage_from_acid(self, value)

    def set_is_double_damage_from_water(self, value):
        zx.tp_set_is_double_damage_from_water(self, value)

    def set_is_generator(self, value):
        zx.tp_set_is_generator(self, value)

    def set_is_treasure_eater(self, value):
        zx.tp_set_is_treasure_eater(self, value)

    def set_is_double_damage_from_acid(self, value):
        zx.tp_set_is_double_damage_from_acid(self, value)

    def set_is_acid_dweller(self, value):
        zx.tp_set_is_acid_dweller(self, value)

    def set_is_acid_hater(self, value):
        zx.tp_set_is_acid_hater(self, value)

    def set_is_jelly_parent(self, value):
        zx.tp_set_is_jelly_parent(self, value)

    def set_is_jelly_eater(self, value):
        zx.tp_set_is_jelly_eater(self, value)

    def set_is_jelly(self, value):
        zx.tp_set_is_jelly(self, value)

    def set_is_attack_eater(self, value):
        zx.tp_set_is_attack_eater(self, value)

    def set_is_jumper_distance(self, value):
        zx.tp_set_is_jumper_distance(self, value)

    def set_is_jumper(self, value):
        zx.tp_set_is_jumper(self, value)

    def set_is_acid(self, value):
        zx.tp_set_is_acid(self, value)

    def set_is_jelly_baby_eater(self, value):
        zx.tp_set_is_jelly_baby_eater(self, value)

    def set_is_jelly_baby(self, value):
        zx.tp_set_is_jelly_baby(self, value)

    def set_is_able_to_change_levels(self, value):
        zx.tp_set_is_able_to_change_levels(self, value)

    def set_is_item_collected_as_gold(self, value):
        zx.tp_set_is_item_collected_as_gold(self, value)

    def set_is_gold(self, value):
        zx.tp_set_is_gold(self, value)

    def set_is_loggable_for_important_stuff(self, value):
        zx.tp_set_is_loggable_for_important_stuff(self, value)

    def set_tick_catches_up_on_attack(self, value):
        zx.tp_set_tick_catches_up_on_attack(self, value)

    def set_is_removable_if_out_of_slots(self, value):
        zx.tp_set_is_removable_if_out_of_slots(self, value)

    def set_is_smoke(self, value):
        zx.tp_set_is_smoke(self, value)

    def set_is_fire_hater(self, value):
        zx.tp_set_is_fire_hater(self, value)

    def set_is_treasure(self, value):
        zx.tp_set_is_treasure(self, value)

    def set_is_collectable(self, value):
        zx.tp_set_is_collectable(self, value)

    def set_is_resurrectable(self, value):
        zx.tp_set_is_resurrectable(self, value)

    def set_is_intelligent(self, value):
        zx.tp_set_is_intelligent(self, value)

    def set_is_double_damage_from_fire(self, value):
        zx.tp_set_is_double_damage_from_fire(self, value)

    def set_is_fire(self, value):
        zx.tp_set_is_fire(self, value)

    def set_is_dead_on_shove(self, value):
        zx.tp_set_is_dead_on_shove(self, value)

    def set_is_loggable_for_unimportant_stuff(self, value):
        zx.tp_set_is_loggable_for_unimportant_stuff(self, value)

    def set_is_torch(self, value):
        zx.tp_set_is_torch(self, value)

    def set_gfx_bounce_always(self, value):
        zx.tp_set_gfx_bounce_always(self, value)

    def set_normal_placement_rules(self, value):
        zx.tp_set_normal_placement_rules(self, value)

    def set_is_flammable(self, value):
        zx.tp_set_is_flammable(self, value)

    def set_is_combustible(self, value):
        zx.tp_set_is_combustible(self, value)

    def set_gfx_attack_anim(self, value):
        zx.tp_set_gfx_attack_anim(self, value)

    def set_is_attack_shove_chance_d1000(self, value):
        zx.tp_set_is_attack_shove_chance_d1000(self, value)

    def set_is_jumper_chance_d1000(self, value):
        zx.tp_set_is_jumper_chance_d1000(self, value)

    def set_is_jumper_on_low_hp_chance_d1000(self, value):
        zx.tp_set_is_jumper_on_low_hp_chance_d1000(self, value)

    def set_is_chasm(self, value):
        zx.tp_set_is_chasm(self, value)

    def set_is_hazard(self, value):
        zx.tp_set_is_hazard(self, value)

    def set_is_attack_shove(self, value):
        zx.tp_set_is_attack_shove(self, value)

    def set_is_shovable(self, value):
        zx.tp_set_is_shovable(self, value)

    def set_is_cursor_path(self, value):
        zx.tp_set_is_cursor_path(self, value)

    def set_is_blood_splatter(self, value):
        zx.tp_set_is_blood_splatter(self, value)

    def set_is_no_tile(self, value):
        zx.tp_set_is_no_tile(self, value)

    def set_is_msg(self, value):
        zx.tp_set_is_msg(self, value)

    def set_is_attack_lunge(self, value):
        zx.tp_set_is_attack_lunge(self, value)

    def set_stats_strength(self, value):
        zx.tp_set_stats_strength(self, value)

    def set_stats_stamina(self, value):
        zx.tp_set_stats_stamina(self, value)

    def set_stats_defence(self, value):
        zx.tp_set_stats_defence(self, value)

    def set_stats_attack(self, value):
        zx.tp_set_stats_attack(self, value)

    def set_tick_rate_tenths(self, value):
        zx.tp_set_tick_rate_tenths(self, value)

    def set_lifespan_dice(self, value):
        zx.tp_set_lifespan_dice(self, value)

    def set_is_secret_door(self, value):
        zx.tp_set_is_secret_door(self, value)

    def set_is_cursor_can_hover_over(self, value):
        zx.tp_set_is_cursor_can_hover_over(self, value)

    def set_is_cursor(self, value):
        zx.tp_set_is_cursor(self, value)

    def set_gfx_dead_anim(self, value):
        zx.tp_set_gfx_dead_anim(self, value)

    def set_ai_obstacle(self, value):
        zx.tp_set_ai_obstacle(self, value)

    def set_is_attackable_by_monst(self, value):
        zx.tp_set_is_attackable_by_monst(self, value)

    def set_is_food(self, value):
        zx.tp_set_is_food(self, value)

    def set_is_water_hater(self, value):
        zx.tp_set_is_water_hater(self, value)

    def set_is_hunger_insatiable(self, value):
        zx.tp_set_is_hunger_insatiable(self, value)

    def set_is_undead(self, value):
        zx.tp_set_is_undead(self, value)

    def set_tick_catches_up_on_attack(self, value):
        zx.tp_set_tick_catches_up_on_attack(self, value)

    def set_nutrition_dice(self, value):
        zx.tp_set_nutrition_dice(self, value)

    def set_stats_attack_dice(self, value):
        zx.tp_set_stats_attack_dice(self, value)

    def set_gold_value_dice(self, value):
        zx.tp_set_gold_value_dice(self, value)

    def set_resurrect_dice(self, value):
        zx.tp_set_resurrect_dice(self, value)

    def set_collision_check(self, value):
        zx.tp_set_collision_check(self, value)

    def set_collision_attack(self, value):
        zx.tp_set_collision_attack(self, value)

    def set_is_water_dweller(self, value):
        zx.tp_set_is_water_dweller(self, value)

    def set_collision_hit_priority(self, value):
        zx.tp_set_collision_hit_priority(self, value)

    def set_collision_radius(self, value):
        zx.tp_set_collision_radius(self, value)

    def set_collision_attack_radius(self, value):
        zx.tp_set_collision_attack_radius(self, value)

    def set_ai_delay_after_moving_ms(self, value):
        zx.tp_set_ai_delay_after_moving_ms(self, value)

    def set_gfx_bounce_on_move(self, value):
        zx.tp_set_gfx_bounce_on_move(self, value)

    def set_is_loggable_for_unimportant_stuff(self, value):
        zx.tp_set_is_loggable_for_unimportant_stuff(self, value)

    def set_is_bleeder(self, value):
        zx.tp_set_is_bleeder(self, value)

    def set_on_death_is_corpse(self, value):
        zx.tp_set_on_death_is_corpse(self, value)

    def set_is_meat_eater(self, value):
        zx.tp_set_is_meat_eater(self, value)

    def set_is_meat(self, value):
        zx.tp_set_is_meat(self, value)

    def set_is_active(self, value):
        zx.tp_set_is_active(self, value)

    def set_stats_health_starving_pct(self, value):
        zx.tp_set_stats_health_starving_pct(self, value)

    def set_stats_health_initial(self, value):
        zx.tp_set_stats_health_initial(self, value)

    def set_stats_health_hunger_pct(self, value):
        zx.tp_set_stats_health_hunger_pct(self, value)

    def set_stats_attack(self, value):
        zx.tp_set_stats_attack(self, value)

    def set_stats_defence(self, value):
        zx.tp_set_stats_defence(self, value)

    def set_hunger_clock_freq_ms(self, value):
        zx.tp_set_hunger_clock_freq_ms(self, value)

    def set_ai_scent_distance(self, value):
        zx.tp_set_ai_scent_distance(self, value)

    def set_is_ripple(self, value):
        zx.tp_set_is_ripple(self, value)

    def set_is_light_strength(self, value):
        zx.tp_set_is_light_strength(self, value)

    def set_is_blood(self, value):
        zx.tp_set_is_blood(self, value)

    def set_gfx_animated_can_vflip(self, value):
        zx.tp_set_gfx_animated_can_vflip(self, value)

    def set_is_corridor(self, value):
        zx.tp_set_is_corridor(self, value)

    def set_gfx_oversized_but_sitting_on_the_ground(self, value):
        zx.tp_set_gfx_oversized_but_sitting_on_the_ground(self, value)

    def set_is_interesting(self, value):
        zx.tp_set_is_interesting(self, value)

    def set_is_exit(self, value):
        zx.tp_set_is_exit(self, value)

    def set_is_door(self, value):
        zx.tp_set_is_door(self, value)

    def set_is_entrance(self, value):
        zx.tp_set_is_entrance(self, value)

    def set_stats_move_speed_ms(self, value):
        zx.tp_set_stats_move_speed_ms(self, value)

    def set_weapon_use_delay_hundredths(self, value):
        zx.tp_set_weapon_use_delay_hundredths(self, value)

    def set_collision_box(self, value):
        zx.tp_set_collision_box(self, value)

    def set_collision_circle(self, value):
        zx.tp_set_collision_circle(self, value)

    def set_weapon_damage(self, value):
        zx.tp_set_weapon_damage(self, value)

    def set_is_projectile(self, value):
        zx.tp_set_is_projectile(self, value)

    def set_is_explosion(self, value):
        zx.tp_set_is_explosion(self, value)

    def set_is_combustible(self, value):
        zx.tp_set_is_combustible(self, value)

    def set_weapon_use_distance(self, value):
        zx.tp_set_weapon_use_distance(self, value)

    def set_gfx_weapon_carry_anim(self, value):
        zx.tp_set_gfx_weapon_carry_anim(self, value)

    def set_gfx_attack_anim(self, value):
        zx.tp_set_gfx_attack_anim(self, value)

    def set_is_weapon(self, value):
        zx.tp_set_is_weapon(self, value)

    def set_gfx_show_outlined(self, value):
        zx.tp_set_gfx_show_outlined(self, value)

    def set_is_light_blocker(self, value):
        zx.tp_set_is_light_blocker(self, value)

    def set_z_depth(self, value):
        zx.tp_set_z_depth(self, value)

    def set_ascii_z_depth(self, value):
        zx.tp_set_ascii_z_depth(self, value)

    def set_z_prio(self, value):
        zx.tp_set_z_prio(self, value)

    def set_is_movable(self, value):
        zx.tp_set_is_movable(self, value)

    def set_gfx_animated_can_hflip(self, value):
        zx.tp_set_gfx_animated_can_hflip(self, value)

    def set_gfx_animated_can_vflip(self, value):
        zx.tp_set_gfx_animated_can_vflip(self, value)

    def set_is_movement_blocking_hard(self, value):
        zx.tp_set_is_movement_blocking_hard(self, value)

    def set_is_treasure(self, value):
        zx.tp_set_is_treasure(self, value)

    def set_is_wall(self, value):
        zx.tp_set_is_wall(self, value)

    def set_is_rock(self, value):
        zx.tp_set_is_rock(self, value)

    def set_is_floor(self, value):
        zx.tp_set_is_floor(self, value)

    def set_is_dirt(self, value):
        zx.tp_set_is_dirt(self, value)

    def set_is_lava(self, value):
        zx.tp_set_is_lava(self, value)

    def set_is_chasm(self, value):
        zx.tp_set_is_chasm(self, value)

    def set_is_water(self, value):
        zx.tp_set_is_water(self, value)

    def set_is_deep_water(self, value):
        zx.tp_set_is_deep_water(self, value)

    def set_gfx_small_shadow_caster(self, value):
        zx.tp_set_gfx_small_shadow_caster(self, value)
