import zx
import tp

def tp_init(name, text_name):
    x = tp.Tp(name, text_name)

    x.set_ai_delay_after_moving_ms(100)
    x.set_ai_scent_distance(20)
    x.set_collision_attack(True)
    x.set_collision_check(True)
    x.set_collision_circle(True)
    x.set_collision_hit_priority(10)
    x.set_collision_radius(0.40)
    x.set_gfx_animated(True)
    x.set_gfx_animated_can_hflip(True)
    x.set_gfx_bounce_on_move(True)
    x.set_gfx_show_outlined(True)
    x.set_gfx_small_shadow_caster(True)
    x.set_is_able_to_change_levels(True)
    x.set_is_acid_hater(True)
    x.set_is_active(True)
    x.set_is_attack_eater(True)
    x.set_is_attack_lunge(True)
    x.set_is_attack_shove(True)
    x.set_is_attack_shove_chance_d1000(200)
    x.set_is_attackable(True)
    x.set_is_combustible(True)
    x.set_is_corpse_on_death(True)
    x.set_is_double_damage_from_fire(True)
    x.set_is_double_damage_from_water(True)
    x.set_is_fire_hater(100)
    x.set_is_hunger_insatiable(True)
    x.set_is_intelligent(True)
    x.set_is_interesting(True)
    x.set_is_loggable_for_important_stuff(True)
    x.set_is_loggable_for_unimportant_stuff(True)
    x.set_is_meat_eater(True)
    x.set_is_monst(True)
    x.set_is_movable(True)
    x.set_is_movement_blocking(True)
    x.set_is_resurrectable(True)
    x.set_is_shovable(True)
    x.set_is_undead(True)
    x.set_is_water_hater(100)
    x.set_normal_placement_rules(True)
    x.set_resurrect_dice("1d10+30")
    x.set_stats_attack_dice("1d4")
    x.set_stats_defence(1)
    x.set_stats_health_hunger_pct(95)
    x.set_stats_health_initial(10)
    x.set_stats_move_speed_ms(500)
    x.set_stats_strength(9)
    x.set_text_a_or_an("a");
    x.set_text_hits("claws");
    x.set_tick_rate_tenths(3)
    x.set_weapon_use_anim("claws1")
    x.set_z_depth(zx.MAP_DEPTH_OBJ)
    x.set_z_prio(zx.MAP_PRIO_NORMAL)

    delay = 200
    x.set_tile(tile=name + ".1", is_dir_left=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".2", is_dir_left=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".3", is_dir_left=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".4", is_dir_left=True, is_moving=True, delay_ms=delay)

    x.set_tile(tile=name + ".1", is_dir_up=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".2", is_dir_up=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".3", is_dir_up=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".4", is_dir_up=True, is_moving=True, delay_ms=delay)

    x.set_tile(tile=name + ".1", is_dir_down=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".2", is_dir_down=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".3", is_dir_down=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".4", is_dir_down=True, is_moving=True, delay_ms=delay)

    x.set_tile(tile=name + ".1", is_dir_right=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".2", is_dir_right=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".3", is_dir_right=True, is_moving=True, delay_ms=delay)
    x.set_tile(tile=name + ".4", is_dir_right=True, is_moving=True, delay_ms=delay)

    x.set_tile(tile=name + ".1", is_dir_left=True, delay_ms=delay)
    x.set_tile(tile=name + ".2", is_dir_left=True, delay_ms=delay)
    x.set_tile(tile=name + ".3", is_dir_left=True, delay_ms=delay)
    x.set_tile(tile=name + ".4", is_dir_left=True, delay_ms=delay)

    x.set_tile(tile=name + ".1", is_dir_up=True, delay_ms=delay)
    x.set_tile(tile=name + ".2", is_dir_up=True, delay_ms=delay)
    x.set_tile(tile=name + ".3", is_dir_up=True, delay_ms=delay)
    x.set_tile(tile=name + ".4", is_dir_up=True, delay_ms=delay)

    x.set_tile(tile=name + ".1", is_dir_down=True, delay_ms=delay)
    x.set_tile(tile=name + ".2", is_dir_down=True, delay_ms=delay)
    x.set_tile(tile=name + ".3", is_dir_down=True, delay_ms=delay)
    x.set_tile(tile=name + ".4", is_dir_down=True, delay_ms=delay)

    x.set_tile(tile=name + ".1", is_dir_right=True, delay_ms=delay)
    x.set_tile(tile=name + ".2", is_dir_right=True, delay_ms=delay)
    x.set_tile(tile=name + ".3", is_dir_right=True, delay_ms=delay)
    x.set_tile(tile=name + ".4", is_dir_right=True, delay_ms=delay)

    x.set_tile(tile=name + ".1", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".2", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".3", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".4", is_dir_none=True, delay_ms=delay)

    x.set_tile(tile=name + ".1.dead", is_dead=True, delay_ms=delay)
    x.set_tile(tile=name + ".2.dead", is_dead=True, delay_ms=delay)
    x.set_tile(tile=name + ".3.dead", is_dead=True, delay_ms=delay)
    x.set_tile(tile=name + ".4.dead", is_dead=True, delay_ms=delay, is_end_of_anim=True)

    x.set_tile(tile=name + ".4.dead", is_resurrecting=True, delay_ms=delay)
    x.set_tile(tile=name + ".3.dead", is_resurrecting=True, delay_ms=delay)
    x.set_tile(tile=name + ".2.dead", is_resurrecting=True, delay_ms=delay)
    x.set_tile(tile=name + ".1.dead", is_resurrecting=True, is_end_of_anim=True, is_alive_on_end_of_anim=True)

    x.update()

def init():
    tp_init(name="skeleton1", text_name="skeleton")

init()

