//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#pragma once
#ifndef _MY_THING_TEMPLATE_H
#define _MY_THING_TEMPLATE_H

// REMOVED #include <unordered_map>
// REMOVED #include <memory>

#include "my_dice.h"
#include "my_tile.h"
#include "my_size.h"

enum {
    THING_RARITY_COMMON,
    THING_RARITY_UNCOMMON,
    THING_RARITY_RARE,
    THING_RARITY_VERY_RARE,
    THING_RARITY_UNIQUE,
};

class Tp {
public:
    //
    // Used a lot, so avoid the cost of an accessor.
    //
    uint16_t id {};
    uint8_t z_depth {};
    uint8_t z_prio {};
    //
    // Modified on tile loading; easier to leave public
    //
    Tilemap bl1_tiles;
    Tilemap bl2_tiles;
    Tilemap bot1_tiles;
    Tilemap bot2_tiles;
    Tilemap bot3_tiles;
    Tilemap br1_tiles;
    Tilemap br2_tiles;
    Tilemap left1_tiles;
    Tilemap left2_tiles;
    Tilemap right1_tiles;
    Tilemap right2_tiles;
    Tilemap tiles;
    Tilemap tl1_tiles;
    Tilemap tl2_tiles;
    Tilemap top1_tiles;
    Tilemap top2_tiles;
    Tilemap tr1_tiles;
    Tilemap tr2_tiles;
private:
    //
    // Dice
    //
    Dice _on_idle_dice_do {};
    std::string _on_idle_dice_do_str;

    Dice _lifespan_dice {};
    std::string _lifespan_dice_str;

    Dice _nutrition_dice {};
    std::string _nutrition_dice_str;

    Dice _damage_melee_dice {};
    std::string _damage_melee_dice_str;

    Dice _damage_poison_dice {};
    std::string _damage_poison_dice_str;

    Dice _health_initial_dice {};
    std::string _health_initial_dice_str;

    Dice _gold_value_dice {};
    std::string _gold_value_dice_str;

    Dice _resurrect_dice {};
    std::string _resurrect_dice_str;

    float _collision_attack_radius {};
    float _collision_radius {};
    fsize _sz;
    int _ai_delay_after_moving_ms {};
    int _ai_obstacle {};
    int _ai_scent_distance {};
    int _blit_bot_off {};
    int _blit_left_off {};
    int _blit_off {};
    int _blit_right_off {};
    int _blit_top_off {};
    int _collision_attack {};
    int _collision_box {};
    int _collision_check {};
    int _collision_circle {};
    int _collision_hit_priority {};
    int _gfx_an_animation_only {};
    int _gfx_animated {};
    int _gfx_animated_can_hflip {};
    int _gfx_animated_can_vflip {};
    int _gfx_animated_no_dir {};
    int _gfx_attack_anim {};
    int _gfx_bounce_always {};
    int _gfx_bounce_on_move {};
    int _gfx_dead_anim {};
    int _gfx_health_bar_shown {};
    int _gfx_health_bar_shown_only_when_injured {};
    int _gfx_is_rrr99 {};
    int _gfx_moves_ahead_shown {};
    int _gfx_on_fire_anim {};
    int _gfx_oversized_but_sitting_on_the_ground {};
    int _gfx_show_outlined {};
    int _gfx_shown_in_bg {};
    int _gfx_small_shadow_caster {};
    int _gfx_weapon_carry_anim {};
    int _is_chasm {};
    int _hunger_clock_freq_ms {};
    int _internal_has_dir_anim {};
    int _internal_has_hp_anim {};
    int _is_able_to_change_levels {};
    int _is_acid {};
    int _is_acid_lover {};
    int _avoider_of_acid {};
    int _is_active {}; // e.g. a monst or player or something movable
    int _attack_eater {};
    int _attack_lunge {};
    int _attack_shove {};
    int _attack_shove_chance_d1000 {};
    int _attackable_by_monst {};
    int _attackable_by_player {};
    int _is_bag {};
    int _is_bleeder {};
    int _is_blood {};
    int _is_blood_splatter {};
    int _is_collect_as_keys {};
    int _is_collectable {};
    int _is_combustible {};
    int _is_corridor {};
    int _is_cursor {};
    int _is_cursor_can_hover_over {};
    int _is_cursor_can_hover_over_but_needs_double_click {};
    int _is_cursor_path {};
    int _is_dead_on_shove {};
    int _is_deep_water {};
    int _is_dirt {};
    int _is_door {};
    int _damage_doubled_from_acid {};
    int _damage_doubled_from_fire {};
    int _damage_doubled_from_water {};
    int _is_droppable {};
    int _is_entrance {};
    int _is_ethereal {};
    int _is_exit {};
    int _is_explosion {};
    int _is_fire {};
    int _avoider_of_fire {};
    int _is_flammable {};
    int _is_floating {};
    int _is_floor {};
    int _is_floor_deco {};
    int _is_food {};
    int _is_generator {};
    int _is_gold {};
    int _is_hazard {};
    int _is_hunger_insatiable {};
    int _is_intelligent {};
    int _is_interesting {}; // e.g. something edible or a monst or lava
    int _is_item {};
    int _is_treasure_class_a {};
    int _is_treasure_class_b {};
    int _is_item_collected_as_gold {};
    int _is_item_eater {};
    int _is_item_not_stackable {};
    int _is_jelly {};
    int _is_jelly_baby {};
    int _is_jelly_baby_eater {};
    int _is_jelly_eater {};
    int _is_jelly_parent {};
    int _is_jumper {};
    int _is_jumper_chance_d1000 {};
    int _is_jumper_distance {};
    int _is_jumper_on_low_hp_chance_d1000 {};
    int _is_key {};
    int _is_killed_on_hit_or_miss {};
    int _is_killed_on_hitting {};
    int _is_lava {};
    int _is_light_blocker {};
    int _is_light_strength {};
    int _is_loggable_for_important_stuff {};
    int _is_loggable_for_unimportant_stuff {};
    int _is_meat {};
    int _is_meat_eater {};
    int _is_monst {};
    int _is_movable {};
    int _is_movement_blocking_hard {};
    int _is_movement_blocking_soft {};
    int _is_msg {};
    int _is_no_tile {};
    int _is_player {};
    int _is_potion {};
    int _is_potion_eater {};
    int _is_projectile {};
    int _is_removable_if_out_of_slots {};
    int _is_resurrectable {};
    int _is_ripple {};
    int _is_rock {};
    int _is_rrr1 {};
    int _is_rrr10 {};
    int _is_rrr100 {};
    int _is_rrr11 {};
    int _is_rrr12 {};
    int _is_rrr13 {};
    int _is_rrr14 {};
    int _is_rrr15 {};
    int _is_rrr16 {};
    int _is_rrr17 {};
    int _is_rrr18 {};
    int _is_rrr19 {};
    int _is_rrr2 {};
    int _is_rrr20 {};
    int _is_rrr21 {};
    int _is_rrr22 {};
    int _is_rrr23 {};
    int _is_rrr24 {};
    int _is_rrr25 {};
    int _is_rrr26 {};
    int _is_rrr27 {};
    int _is_rrr28 {};
    int _is_rrr29 {};
    int _is_rrr3 {};
    int _is_rrr30 {};
    int _is_rrr31 {};
    int _is_rrr32 {};
    int _is_rrr33 {};
    int _is_rrr34 {};
    int _is_rrr35 {};
    int _is_rrr36 {};
    int _is_poison_lover {};
    int _damage_doubled_from_poison {};
    int _avoider_of_poison {};
    int _is_rrr4 {};
    int _is_rrr40 {};
    int _is_poison {};
    int _is_used_when_thrown {};
    int _is_used_automatically_when_selected {};
    int _is_thrown_automatically_when_selected {};
    int _is_extreme_hazard {};
    int _is_auto_collect_item {};
    int _attack_meat {};
    int _is_food_eater {};
    int _is_item_effect_max_radius {};
    int _is_rrr5 {};
    int _is_item_effect_min_radius {};
    int _is_critical_to_level {};
    int _is_able_to_fall {};
    int _is_temporary_bag {};
    int _is_treasure_class_c {};
    int _bag_item_height {};
    int _bag_item_width {};
    int _bag_height {};
    int _bag_width {};
    int _rrr58 {};
    int _is_rrr6 {};
    int _is_rrr7 {};
    int _is_rrr8 {};
    int _is_rrr9 {};
    int _rarity {};
    int _is_secret_door {};
    int _is_shovable {};
    int _is_shown_on_leftbar {};
    int _is_shown_uniquely_on_leftbar {};
    int _is_smoke {};
    int _is_stamina_check {};
    int _is_steal_item_chance_d1000 {};
    int _is_the_grid {};
    int _is_throwable {};
    int _is_torch {};
    int _is_treasure {};
    int _is_treasure_eater {};
    int _is_undead {};
    int _is_usable {};
    int _is_wall {};
    int _is_wall_deco {};
    int _is_water {};
    int _is_water_lover {};
    int _avoider_of_water {};
    int _is_weapon {};
    int _is_weapon_wielder {};
    int _normal_placement_rules {};
    int _on_death_drop_all_items {};
    int _on_death_is_corpse {};
    int _on_death_is_open {};
    int _stats01 {};
    int _stats02 {};
    int _stats03 {};
    int _stats04 {};
    int _stats05 {};
    int _stats06 {};
    int _stats07 {};
    int _stats08 {};
    int _stats09 {};
    int _stats10 {};
    int _stats11 {};
    int _stats12 {};
    int _modifier_constitution {};
    int _modifier_attack {};
    int _modifier_defence {};
    int _modifier_strength {};
    int _stats17 {};
    int _throw_distance {};
    int _health_hunger_pct {};
    int _health_starving_pct {};
    int _move_speed_ms {};
    int _stamina {};
    int _tick_catches_up_on_attack {};
    int _tick_rate_tenths {};
    int _weapon_damage {};
    int _weapon_use_delay_hundredths {};
    int _weapon_use_distance {};
    std::string _gfx_anim_attack;
    std::string _light_color;
    std::string _name;
    std::string _on_birth_do;
    std::string _on_use_do;
    std::string _on_death_do;
    std::string _spawn_on_shoved;
    std::string _str1;
    std::string _str2;
    std::string _str3;
    std::string _str4;
    std::string _str5;
    std::string _str6;
    std::string _str7;
    std::string _long_text_description;
    std::string _text_a_or_an;
    std::string _text_description;
    std::string _text_hits;
    std::string _text_name;
    std::string _short_text_name;
    std::string _text_title;
    std::string _weapon_carry_anim;
public:
    Tp (void) {
        newptr(this, "Tp");
    }

    ~Tp (void) {
        oldptr(this);
    }

    //
    // Dice
    //
    const Dice& on_idle_dice_do(void) const;
    const int idle_tick(void) const;
    const std::string& on_idle_dice_do_str(void) const;
    void set_on_idle_dice_do(const std::string &);

    const Dice& lifespan_dice(void) const;
    const int lifespan(void) const;
    const std::string& lifespan_dice_str(void) const;
    void set_lifespan_dice(const std::string &);

    const Dice& nutrition_dice(void) const;
    const int nutrition(void) const;
    const std::string& nutrition_dice_str(void) const;
    void set_nutrition_dice(const std::string &);

    const Dice& get_damage_melee_dice(void) const;
    const int get_damage_melee(void) const;
    const std::string& get_damage_melee_dice_str(void) const;
    void set_damage_melee_dice(const std::string &);

    const Dice& get_damage_poison_dice(void) const;
    const int get_damage_poison(void) const;
    const std::string& get_damage_poison_dice_str(void) const;
    void set_damage_poison_dice(const std::string &);

    const Dice& get_health_initial_dice(void) const;
    const int get_health_initial(void) const;
    const std::string& get_health_initial_dice_str(void) const;
    void set_health_initial_dice(const std::string &);

    const Dice& gold_value_dice(void) const;
    const int cash(void) const;
    const std::string& gold_value_dice_str(void) const;
    void set_gold_value_dice(const std::string &);

    const Dice& resurrect_dice(void) const;
    const int resurrect(void) const;
    const std::string& resurrect_dice_str(void) const;
    void set_resurrect_dice(const std::string &);

    bool will_avoid(Levelp, point p) const;
    const Tilemap *tp_bl1_tiles(void) const;
    const Tilemap *tp_bl2_tiles(void) const;
    const Tilemap *tp_bot1_tiles(void) const;
    const Tilemap *tp_bot2_tiles(void) const;
    const Tilemap *tp_bot3_tiles(void) const;
    const Tilemap *tp_br1_tiles(void) const;
    const Tilemap *tp_br2_tiles(void) const;
    const Tilemap *tp_horiz_tiles(void) const;
    const Tilemap *tp_l180_tiles(void) const;
    const Tilemap *tp_l270_tiles(void) const;
    const Tilemap *tp_l90_tiles(void) const;
    const Tilemap *tp_l_tiles(void) const;
    const Tilemap *tp_left1_tiles(void) const;
    const Tilemap *tp_left2_tiles(void) const;
    const Tilemap *tp_outline_tiles(void) const;
    const Tilemap *tp_right1_tiles(void) const;
    const Tilemap *tp_right2_tiles(void) const;
    const Tilemap *tp_t180_tiles(void) const;
    const Tilemap *tp_t270_tiles(void) const;
    const Tilemap *tp_t90_tiles(void) const;
    const Tilemap *tp_t_tiles(void) const;
    const Tilemap *tp_tiles(void) const;
    const Tilemap *tp_tl1_tiles(void) const;
    const Tilemap *tp_tl2_tiles(void) const;
    const Tilemap *tp_top1_tiles(void) const;
    const Tilemap *tp_top2_tiles(void) const;
    const Tilemap *tp_tr1_tiles(void) const;
    const Tilemap *tp_tr2_tiles(void) const;
    const Tilemap *tp_vert_tiles(void) const;
    const Tilemap *tp_x_tiles(void) const;
    const std::string& light_color(void) const;
    const std::string& name(void) const;
    const std::string& on_birth_do(void) const;
    const std::string& on_use_do(void) const;
    const std::string& on_death_do(void) const;
    const std::string& spawn_on_shoved(void) const;
    const std::string& str1(void) const;
    const std::string& str2(void) const;
    const std::string& str3(void) const;
    const std::string& str4(void) const;
    const std::string& str5(void) const;
    const std::string& str6(void) const;
    const std::string& str7(void) const;
    const std::string& long_text_description(void) const;
    const std::string& text_description(void) const;
    const std::string& text_hits(void) const;
    const std::string& text_name(void) const;
    const std::string& short_text_name(void) const;
    const std::string& text_title(void) const;
    const std::string& weapon_carry_anim(void) const;
    const std::string& gfx_anim_attack(void) const;
    float collision_attack_radius(void) const;
    float collision_radius(void) const;
    int ai_delay_after_moving_ms(void) const;
    int ai_obstacle(void) const;
    int ai_scent_distance(void) const;
    int blit_bot_off(void) const;
    int blit_left_off(void) const;
    int blit_right_off(void) const;
    int blit_top_off(void) const;
    int collision_attack(void) const;
    int collision_box(void) const;
    int collision_check(void) const;
    int collision_circle(void) const;
    int collision_hit_priority(void) const;
    int gfx_an_animation_only(void) const;
    int gfx_animated(void) const;
    int gfx_animated_can_hflip(void) const;
    int gfx_animated_can_vflip(void) const;
    int gfx_animated_no_dir(void) const;
    int gfx_attack_anim(void) const;
    int gfx_bounce_always(void) const;
    int gfx_bounce_on_move(void) const;
    int gfx_dead_anim(void) const;
    int gfx_on_fire_anim(void) const;
    int gfx_oversized_but_sitting_on_the_ground(void) const;
    int gfx_show_outlined(void) const;
    int gfx_small_shadow_caster(void) const;
    int gfx_weapon_carry_anim(void) const;
    int is_chasm(void) const;
    int hunger_clock_freq_ms(void) const;
    int internal_has_dir_anim(void) const;
    int internal_has_hp_anim(void) const;
    int is_able_to_change_levels(void) const;
    int is_acid(void) const;
    int is_acid_lover(void) const;
    int avoider_of_acid(void) const;
    int is_active(void) const;
    int attack_eater(void) const;
    int attack_lunge(void) const;
    int attack_shove(void) const;
    int attack_shove_chance_d1000(void) const;
    int attackable_by_monst(void) const;
    int attackable_by_player(void) const;
    int is_bag(void) const;
    int is_bleeder(void) const;
    int is_blood(void) const;
    int is_blood_splatter(void) const;
    int is_collect_as_keys(void) const;
    int is_collectable(void) const;
    int is_item_collected_as_gold(void) const;
    int is_combustible(void) const;
    int on_death_is_corpse(void) const;
    int is_corridor(void) const;
    int is_cursor(void) const;
    int is_cursor_can_hover_over(void) const;
    int is_cursor_can_hover_over_but_needs_double_click(void) const;
    int is_cursor_path(void) const;
    int is_dead_on_shove(void) const;
    int is_deep_water(void) const;
    int is_dirt(void) const;
    int is_door(void) const;
    int damage_doubled_from_acid(void) const;
    int damage_doubled_from_fire(void) const;
    int damage_doubled_from_water(void) const;
    int is_droppable(void) const;
    int is_entrance(void) const;
    int is_ethereal(void) const;
    int is_exit(void) const;
    int is_explosion(void) const;
    int is_fire(void) const;
    int avoider_of_fire(void) const;
    int is_flammable(void) const;
    int is_floating(void) const;
    int is_floor(void) const;
    int is_floor_deco(void) const;
    int is_food(void) const;
    int is_generator(void) const;
    int gfx_health_bar_shown(void) const;
    int gfx_health_bar_shown_only_when_injured(void) const;
    int gfx_moves_ahead_shown(void) const;
    int is_gold(void) const;
    int is_hazard(void) const;
    int is_hunger_insatiable(void) const;
    int is_intelligent(void) const;
    int is_interesting(void) const;
    int is_treasure_class_a(void) const;
    int is_treasure_class_b(void) const;
    int is_item_eater(void) const;
    int is_shown_on_leftbar(void) const;
    int is_jumper(void) const;
    int is_jumper_chance_d1000(void) const;
    int is_jumper_distance(void) const;
    int is_jumper_on_low_hp_chance_d1000(void) const;
    int is_key(void) const;
    int is_killed_on_hit_or_miss(void) const;
    int is_killed_on_hitting(void) const;
    int is_lava(void) const;
    int is_light_blocker(void) const;
    int is_light_strength(void) const;
    int is_loggable_for_important_stuff(void) const;
    int is_loggable_for_unimportant_stuff(void) const;
    int is_meat(void) const;
    int is_meat_eater(void) const;
    int is_monst(void) const;
    int is_movable(void) const;
    int is_movement_blocking_hard(void) const;
    int is_movement_blocking_soft(void) const;
    int is_msg(void) const;
    int is_no_tile(void) const;
    int is_item_not_stackable(void) const;
    int on_death_is_open(void) const;
    int is_player(void) const;
    int is_potion(void) const;
    int is_potion_eater(void) const;
    int is_projectile(void) const;
    int is_removable_if_out_of_slots(void) const;
    int is_resurrectable(void) const;
    int is_ripple(void) const;
    int is_rock(void) const;
    int is_rrr1(void) const;
    int is_rrr10(void) const;
    int is_rrr11(void) const;
    int is_rrr12(void) const;
    int is_rrr13(void) const;
    int is_rrr14(void) const;
    int is_rrr15(void) const;
    int is_rrr16(void) const;
    int is_rrr17(void) const;
    int is_rrr18(void) const;
    int is_rrr19(void) const;
    int is_rrr2(void) const;
    int is_rrr20(void) const;
    int is_rrr21(void) const;
    int is_rrr22(void) const;
    int is_rrr23(void) const;
    int is_rrr24(void) const;
    int is_rrr25(void) const;
    int is_rrr26(void) const;
    int is_rrr27(void) const;
    int is_rrr28(void) const;
    int is_rrr29(void) const;
    int is_rrr3(void) const;
    int is_rrr30(void) const;
    int is_rrr31(void) const;
    int is_rrr32(void) const;
    int is_rrr33(void) const;
    int is_rrr34(void) const;
    int is_rrr35(void) const;
    int is_rrr36(void) const;
    int is_poison_lover(void) const;
    int damage_doubled_from_poison(void) const;
    int avoider_of_poison(void) const;
    int is_rrr4(void) const;
    int is_rrr40(void) const;
    int is_poison(void) const;
    int is_used_when_thrown(void) const;
    int is_used_automatically_when_selected(void) const;
    int is_thrown_automatically_when_selected(void) const;
    int is_extreme_hazard(void) const;
    int is_auto_collect_item(void) const;
    int attack_meat(void) const;
    int is_food_eater(void) const;
    int is_item_effect_max_radius(void) const;
    int is_rrr5(void) const;
    int is_item_effect_min_radius(void) const;
    int is_critical_to_level(void) const;
    int is_able_to_fall(void) const;
    int is_temporary_bag(void) const;
    int is_treasure_class_c(void) const;
    int bag_item_height(void) const;
    int bag_item_width(void) const;
    int bag_height(void) const;
    int bag_width(void) const;
    int rrr58(void) const;
    int is_rrr6(void) const;
    int rarity(void) const;
    int gfx_is_rrr99(void) const;
    int is_shown_uniquely_on_leftbar(void) const;
    int is_stamina_check(void) const;
    int gfx_shown_in_bg(void) const;
    int on_death_drop_all_items(void) const;
    int is_steal_item_chance_d1000(void) const;
    int is_weapon_wielder(void) const;
    int is_item(void) const;
    int is_rrr7(void) const;
    int is_rrr8(void) const;
    int is_rrr9(void) const;
    int is_secret_door(void) const;
    int is_shovable(void) const;
    int is_jelly(void) const;
    int is_jelly_baby(void) const;
    int is_jelly_baby_eater(void) const;
    int is_jelly_eater(void) const;
    int is_jelly_parent(void) const;
    int is_smoke(void) const;
    int is_the_grid(void) const;
    int is_throwable(void) const;
    int is_torch(void) const;
    int is_treasure(void) const;
    int is_treasure_eater(void) const;
    int is_undead(void) const;
    int is_usable(void) const;
    int is_wall(void) const;
    int is_wall_deco(void) const;
    int is_water(void) const;
    int is_water_lover(void) const;
    int avoider_of_water(void) const;
    int is_weapon(void) const;
    int normal_placement_rules(void) const;
    int stats01(void) const;
    int stats02(void) const;
    int stats03(void) const;
    int stats04(void) const;
    int stats05(void) const;
    int stats06(void) const;
    int stats07(void) const;
    int stats08(void) const;
    int stats09(void) const;
    int stats10(void) const;
    int stats11(void) const;
    int stats12(void) const;
    int modifier_attack(void) const;
    int modifier_constitution(void) const;
    int attack(void) const;
    int stats17(void) const;
    int throw_distance(void) const;
    int stamina(void) const;
    int modifier_defence(void) const;
    int health_hunger_pct(void) const;
    int health_starving_pct(void) const;
    int move_speed_ms(void) const;
    int modifier_strength(void) const;
    int tick_catches_up_on_attack(void) const;
    int tick_rate_tenths(void) const;
    int weapon_damage(void) const;
    int weapon_use_delay_hundredths(void) const;
    int weapon_use_distance(void) const;
    std::string text_a_or_an(void) const;
    void set_ai_delay_after_moving_ms(int);
    void set_ai_obstacle(int);
    void set_ai_scent_distance(int);
    void set_blit_bot_off(int);
    void set_blit_left_off(int);
    void set_blit_right_off(int);
    void set_blit_top_off(int);
    void set_collision_attack(int);
    void set_collision_attack_radius(float);
    void set_collision_box(int);
    void set_collision_check(int);
    void set_collision_circle(int);
    void set_collision_hit_priority(int);
    void set_collision_radius(float);
    void set_gfx_an_animation_only(int);
    void set_gfx_animated(int);
    void set_gfx_animated_can_hflip(int);
    void set_gfx_animated_can_vflip(int);
    void set_gfx_animated_no_dir(int);
    void set_gfx_attack_anim(int);
    void set_gfx_bounce_always(int);
    void set_gfx_bounce_on_move(int);
    void set_gfx_dead_anim(int);
    void set_gfx_on_fire_anim(int);
    void set_gfx_oversized_but_sitting_on_the_ground(int);
    void set_gfx_show_outlined(int);
    void set_gfx_small_shadow_caster(int);
    void set_gfx_weapon_carry_anim(int);
    void set_is_chasm(int);
    void set_hunger_clock_freq_ms(int);
    void set_internal_has_dir_anim(int);
    void set_internal_has_hp_anim(int);
    void set_is_able_to_change_levels(int);
    void set_is_acid(int);
    void set_is_acid_lover(int);
    void set_avoider_of_acid(int);
    void set_is_active(int);
    void set_attack_eater(int);
    void set_attack_lunge(int);
    void set_attack_shove(int);
    void set_attack_shove_chance_d1000(int);
    void set_attackable_by_monst(int);
    void set_attackable_by_player(int);
    void set_is_bag(int);
    void set_is_bleeder(int);
    void set_is_blood(int);
    void set_is_blood_splatter(int);
    void set_is_collect_as_keys(int);
    void set_is_collectable(int);
    void set_is_item_collected_as_gold(int);
    void set_is_combustible(int);
    void set_on_death_is_corpse(int);
    void set_is_corridor(int);
    void set_is_cursor(int);
    void set_is_cursor_can_hover_over(int);
    void set_is_cursor_can_hover_over_but_needs_double_click(int);
    void set_is_cursor_path(int);
    void set_is_dead_on_shove(int);
    void set_is_deep_water(int);
    void set_is_dirt(int);
    void set_is_door(int);
    void set_damage_doubled_from_acid(int);
    void set_damage_doubled_from_fire(int);
    void set_damage_doubled_from_water(int);
    void set_is_droppable(int);
    void set_is_entrance(int);
    void set_is_ethereal(int);
    void set_is_exit(int);
    void set_is_explosion(int);
    void set_is_fire(int);
    void set_avoider_of_fire(int);
    void set_is_flammable(int);
    void set_is_floating(int);
    void set_is_floor(int);
    void set_is_floor_deco(int);
    void set_is_food(int);
    void set_is_generator(int);
    void set_gfx_health_bar_shown(int);
    void set_gfx_health_bar_shown_only_when_injured(int);
    void set_gfx_moves_ahead_shown(int);
    void set_is_gold(int);
    void set_is_hazard(int);
    void set_is_hunger_insatiable(int);
    void set_is_intelligent(int);
    void set_is_interesting(int);
    void set_is_treasure_class_a(int);
    void set_is_treasure_class_b(int);
    void set_is_item_eater(int);
    void set_is_shown_on_leftbar(int);
    void set_is_jumper(int);
    void set_is_jumper_chance_d1000(int);
    void set_is_jumper_distance(int);
    void set_is_jumper_on_low_hp_chance_d1000(int);
    void set_is_key(int);
    void set_is_killed_on_hit_or_miss(int);
    void set_is_killed_on_hitting(int);
    void set_is_lava(int);
    void set_is_light_blocker(int);
    void set_is_light_strength(int);
    void set_is_loggable_for_important_stuff(int);
    void set_is_loggable_for_unimportant_stuff(int);
    void set_is_meat(int);
    void set_is_meat_eater(int);
    void set_is_monst(int);
    void set_is_movable(int);
    void set_is_movement_blocking_hard(int);
    void set_is_movement_blocking_soft(int);
    void set_is_msg(int);
    void set_is_no_tile(int);
    void set_is_item_not_stackable(int);
    void set_on_death_is_open(int);
    void set_is_player(int);
    void set_is_potion(int);
    void set_is_potion_eater(int);
    void set_is_projectile(int);
    void set_is_removable_if_out_of_slots(int);
    void set_is_resurrectable(int);
    void set_is_ripple(int);
    void set_is_rock(int);
    void set_is_rrr1(int);
    void set_is_rrr10(int);
    void set_is_rrr100(int);
    void set_is_rrr11(int);
    void set_is_rrr12(int);
    void set_is_rrr13(int);
    void set_is_rrr14(int);
    void set_is_rrr15(int);
    void set_is_rrr16(int);
    void set_is_rrr17(int);
    void set_is_rrr18(int);
    void set_is_rrr19(int);
    void set_is_rrr2(int);
    void set_is_rrr20(int);
    void set_is_rrr21(int);
    void set_is_rrr22(int);
    void set_is_rrr23(int);
    void set_is_rrr24(int);
    void set_is_rrr25(int);
    void set_is_rrr26(int);
    void set_is_rrr27(int);
    void set_is_rrr28(int);
    void set_is_rrr29(int);
    void set_is_rrr3(int);
    void set_is_rrr30(int);
    void set_is_rrr31(int);
    void set_is_rrr32(int);
    void set_is_rrr33(int);
    void set_is_rrr34(int);
    void set_is_rrr35(int);
    void set_is_rrr36(int);
    void set_is_poison_lover(int);
    void set_damage_doubled_from_poison(int);
    void set_avoider_of_poison(int);
    void set_is_rrr4(int);
    void set_is_rrr40(int);
    void set_is_poison(int);
    void set_is_used_when_thrown(int);
    void set_is_used_automatically_when_selected(int);
    void set_is_thrown_automatically_when_selected(int);
    void set_is_extreme_hazard(int);
    void set_is_auto_collect_item(int);
    void set_attack_meat(int);
    void set_is_food_eater(int);
    void set_is_item_effect_max_radius(int);
    void set_is_rrr5(int);
    void set_is_item_effect_min_radius(int);
    void set_is_critical_to_level(int);
    void set_is_able_to_fall(int);
    void set_is_temporary_bag(int);
    void set_is_treasure_class_c(int);
    void set_bag_item_height(int);
    void set_bag_item_width(int);
    void set_bag_height(int);
    void set_bag_width(int);
    void set_rrr58(int);
    void set_is_rrr6(int);
    void set_rarity(int);
    void set_gfx_is_rrr99(int);
    void set_is_shown_uniquely_on_leftbar(int);
    void set_is_stamina_check(int);
    void set_gfx_shown_in_bg(int);
    void set_on_death_drop_all_items(int);
    void set_is_steal_item_chance_d1000(int);
    void set_is_weapon_wielder(int);
    void set_is_item(int);
    void set_is_rrr7(int);
    void set_is_rrr8(int);
    void set_is_rrr9(int);
    void set_is_secret_door(int);
    void set_is_shovable(int);
    void set_is_jelly(int);
    void set_is_jelly_baby(int);
    void set_is_jelly_baby_eater(int);
    void set_is_jelly_eater(int);
    void set_is_jelly_parent(int);
    void set_is_smoke(int);
    void set_is_the_grid(int);
    void set_is_throwable(int);
    void set_is_torch(int);
    void set_is_treasure(int);
    void set_is_treasure_eater(int);
    void set_is_undead(int);
    void set_is_usable(int);
    void set_is_wall(int);
    void set_is_wall_deco(int);
    void set_is_water(int);
    void set_is_water_lover(int);
    void set_avoider_of_water(int);
    void set_is_weapon(int);
    void set_light_color(const std::string &);
    void set_name(const std::string &);
    void set_normal_placement_rules(int);
    void set_on_birth_do(const std::string &);
    void set_on_use_do(const std::string &);
    void set_on_death_do(const std::string &);
    void set_spawn_on_shoved(const std::string &);
    void set_stats01(int);
    void set_stats02(int);
    void set_stats03(int);
    void set_stats04(int);
    void set_stats05(int);
    void set_stats06(int);
    void set_stats07(int);
    void set_stats08(int);
    void set_stats09(int);
    void set_stats10(int);
    void set_stats11(int);
    void set_stats12(int);
    void set_modifier_attack(int);
    void set_modifier_constitution(int);
    void set_stats17(int);
    void set_throw_distance(int);
    void set_stamina(int);
    void set_modifier_defence(int);
    void set_health_hunger_pct(int);
    void set_health_starving_pct(int);
    void set_move_speed_ms(int);
    void set_modifier_strength(int);
    void set_str1(const std::string &);
    void set_str2(const std::string &);
    void set_str3(const std::string &);
    void set_str4(const std::string &);
    void set_str5(const std::string &);
    void set_str6(const std::string &);
    void set_str7(const std::string &);
    void set_long_text_description(const std::string &);
    void set_text_a_or_an(const std::string &);
    void set_text_description(const std::string &);
    void set_text_hits(const std::string &);
    void set_text_name(const std::string &);
    void set_short_text_name(const std::string &);
    void set_text_title(const std::string &);
    void set_tick_catches_up_on_attack(int);
    void set_tick_rate_tenths(int);
    void set_weapon_carry_anim(const std::string &);
    void set_weapon_damage(int);
    void set_gfx_anim_attack(const std::string &);
    void set_weapon_use_delay_hundredths(int);
    void set_weapon_use_distance(int);
    void set_z_depth(int);
    void set_z_prio(int);
};

Tilep tp_first_tile(Tpp);
Tpp string2tp(const char **s);
Tpp string2tp(const std::string &s, int *len);
Tpp string2tp(const std::wstring &s, int *len);
Tpp tp_find(uint32_t id);
Tpp tp_load(int id, 
            const std::string & file, 
            const std::string & text_name,
            const std::string & text_short_name);
Tpp tp_random_blood(void);
Tpp tp_random_blood_splatter(void);
Tpp tp_random_deco(void);
Tpp tp_random_dirt(void);
Tpp tp_random_door(void);
Tpp tp_random_entrance(void);
Tpp tp_random_exit(void);
Tpp tp_random_floor(void);
Tpp tp_random_food(void);
Tpp tp_random_generator(void);
Tpp tp_random_gold(void);
Tpp tp_random_item_class_a(void);
Tpp tp_random_item_class_b(void);
Tpp tp_random_item_class_c(void);
Tpp tp_random_key(void);
Tpp tp_random_monst(void);
Tpp tp_random_potion(void);
Tpp tp_random_ripple(void);
Tpp tp_random_rock(void);
Tpp tp_random_secret_door(void);
Tpp tp_random_torch(void);
Tpp tp_random_treasure(void);
Tpp tp_random_wall(void);
Tpp tp_random_wall_deco(void);
uint8_t tp_init(void);
void tp_fini(void);
void tp_init_after_loading(void);

//
// Find an existing thing.
//
static inline Tpp tp_find (std::string name)
{_
    auto result = tp_name_map.find(name);

    if (unlikely(result == tp_name_map.end())) {
        return (0);
    }

    return (result->second);
}

enum {
    THING_DIR_NONE,
    THING_DIR_DOWN,
    THING_DIR_UP,
    THING_DIR_LEFT,
    THING_DIR_RIGHT,
    THING_DIR_TL,
    THING_DIR_BL,
    THING_DIR_TR,
    THING_DIR_BR,
};

#endif // THING_TEMPLATE_H
