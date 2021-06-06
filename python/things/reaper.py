import zx
import tp

def tp_init(name, text_name):
    mytp = tp.Tp(name, text_name)
    mytp.set_ai_scent_distance(40)
    mytp.set_attack_living(False)
    mytp.set_attack_lunge(True)
    mytp.set_hates_water(100)
    mytp.set_collision_attack(True)
    mytp.set_collision_check(True)
    mytp.set_collision_circle(True)
    mytp.set_collision_hit_priority(10)
    mytp.set_collision_radius(0.40)
    mytp.set_damage_doubled_from_water(True)
    mytp.set_damage_melee_dice("1d6+6")
    mytp.set_gfx_anim_attack("scythe_swing")
    mytp.set_gfx_animated(True)
    mytp.set_gfx_animated_can_hflip(True)
    mytp.set_gfx_bounce_on_move(True)
    mytp.set_gfx_health_bar_shown(True)
    mytp.set_gfx_oversized_but_sitting_on_the_ground(True)
    mytp.set_gfx_show_outlined(False)
    mytp.set_gfx_short_shadow_caster(True)
    mytp.set_health_hunger_pct(95)
    mytp.set_health_initial_dice("2d20+200")
    mytp.set_is_able_to_change_levels(True)
    mytp.set_is_able_to_fall(True)
    mytp.set_is_active(True)
    mytp.set_is_attackable_by_player(True)
    mytp.set_is_attackable_by_monst(True)
    mytp.set_is_corpse_on_death(True)
    mytp.set_is_described_when_hovering_over(True)
    mytp.set_is_ethereal(True)
    mytp.set_is_fearless(True)
    mytp.set_is_floating(True)
    mytp.set_is_hunger_insatiable(True)
    mytp.set_loves_poison(True)
    mytp.set_is_intelligent(True)
    mytp.set_is_loggable_for_important_stuff(True)
    mytp.set_is_loggable_for_unimportant_stuff(True)
    mytp.set_is_monst(True)
    mytp.set_is_moveable(True)
    mytp.set_is_resurrectable(True)
    mytp.set_is_shown_on_leftbar(True)
    mytp.set_is_undead(True)
    mytp.set_attack_humanoid(True)
    mytp.set_attack_living(False)
    mytp.set_long_text_description("A lesser reaper. You cannot kill what does not live!")
    mytp.set_monst_size(zx.MONST_SIZE_NORMAL)
    mytp.set_move_speed_ms(150)
    mytp.set_normal_placement_rules(True)
    mytp.set_rarity(zx.RARITY_VERY_RARE)
    mytp.set_resurrect_dice("1d10+30")
    mytp.set_stat_attack(18) # 10, means no bonus
    mytp.set_stat_constitution(25)
    mytp.set_stat_defence(25)
    mytp.set_stat_strength(25)
    mytp.set_text_a_or_an("a")
    mytp.set_text_description("A lesser reaper. Death incarnate.")
    mytp.set_text_hits("claws")
    mytp.set_tick_rate_tenths(3)
    mytp.set_z_depth(zx.MAP_DEPTH_OBJ)
    mytp.set_z_prio(zx.MAP_PRIO_NORMAL)

    delay = 1000
    mytp.set_tile(tile=name + ".1.100", is_hp_100_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".2.100", is_hp_100_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".1.100", is_hp_75_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".2.100", is_hp_75_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".1.100", is_hp_50_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".2.100", is_hp_50_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".1.100", is_hp_25_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".2.100", is_hp_25_percent=True, delay_ms=delay)

    delay = 200
    mytp.set_tile(tile=name + ".1.dead", is_dead=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".2.dead", is_dead=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".3.dead", is_dead=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".4.dead", is_dead=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".5.dead", is_dead=True, is_end_of_anim=True)

    mytp.set_tile(tile=name + ".5.dead", is_resurrecting=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".4.dead", is_resurrecting=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".3.dead", is_resurrecting=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".2.dead", is_resurrecting=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".1.dead", is_resurrecting=True, is_end_of_anim=True, is_alive_on_end_of_anim=True)

    mytp.update()

def init():
    tp_init(name="reaper", text_name="reaper")

init()

