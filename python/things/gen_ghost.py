import zx
import tp

def spawn(me, x, y):
    zx.tp_spawn_next_to(me, "ghost1")

def tp_init(name, text_name):
    x = tp.Tp(name, text_name)
    x.set_collision_attack(True)
    x.set_collision_check(True)
    x.set_collision_circle(True)
    x.set_collision_hit_priority(10)
    x.set_collision_radius(0.40)
    x.set_gfx_animated(True)
    x.set_gfx_oversized_but_sitting_on_the_ground(True)
    x.set_gfx_show_outlined(True)
    x.set_gfx_small_shadow_caster(True)
    x.set_is_able_to_fall(True)
    x.set_avoider_of_acid(True)
    x.set_is_active(True)
    x.set_attack_shove_chance_d1000(200)
    x.set_attackable_by_monst(True)
    x.set_attackable_by_player(True)
    x.set_is_combustible(True)
    x.set_damage_doubled_from_fire(True)
    x.set_damage_doubled_from_water(True)
    x.set_avoider_of_fire(100)
    x.set_is_generator(True)
    x.set_is_interesting(True)
    x.set_is_light_strength(1)
    x.set_is_loggable_for_important_stuff(True)
    x.set_is_loggable_for_unimportant_stuff(True)
    x.set_is_movement_blocking_soft(True)
    x.set_is_resurrectable(True)
    x.set_is_shovable(True)
    x.set_is_shown_on_leftbar(True)
    x.set_avoider_of_water(100)
    x.set_light_color("cyan")
    x.set_normal_placement_rules(True)
    x.set_on_idle_dice_do("1d30+20:gen_ghost.spawn()")
    x.set_modifier_defence(1)
    x.set_health_initial_dice("6d6")
    x.set_modifier_strength(15)
    x.set_text_a_or_an("a");
    x.set_text_description("A cursed pile of bones, spawning spirits")
    x.set_tick_rate_tenths(3)
    x.set_z_depth(zx.MAP_DEPTH_OBJ)
    x.set_z_prio(zx.MAP_PRIO_NORMAL)

    delay = 200
    x.set_tile(tile=name + ".1.100", is_hp_100_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".2.100", is_hp_100_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".3.100", is_hp_100_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".4.100", is_hp_100_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".1.75", is_hp_75_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".2.75", is_hp_75_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".3.75", is_hp_75_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".4.75", is_hp_75_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".1.50", is_hp_50_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".2.50", is_hp_50_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".3.50", is_hp_50_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".4.50", is_hp_50_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".1.25", is_hp_25_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".2.25", is_hp_25_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".3.25", is_hp_25_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".4.25", is_hp_25_percent=True, delay_ms=delay)

    x.update()

def init():
    tp_init(name="gen_ghost", text_name="pile of bones")

init()

