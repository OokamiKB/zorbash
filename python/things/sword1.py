import zx
import tp


def init1(name):
    x = tp.Tp(name)

    x.set_collision_attack(True)
    x.set_collision_check(True)
    x.set_collision_circle(True)
    x.set_collision_hit_priority(10)
    x.set_collision_radius(0.5)
    x.set_gfx_animated(True)
    x.set_gfx_animated_can_vflip(True)
    x.set_gfx_can_hflip(True)
    x.set_gfx_is_weapon_use_anim(True)
    x.set_gfx_outlined(True)
    x.set_gfx_small_shadow_caster(True)
    x.set_is_active(True)
    x.set_is_interesting(True)
    x.set_is_loggable(True)
    x.set_is_movable(True)
    x.set_z_depth(zx.MAP_DEPTH_WEAPON)

    delay = 20
    x.set_tile(tile=name + "_left.1", delay_ms=delay, is_dir_left=True)
    x.set_tile(tile=name + "_left.2", delay_ms=delay, is_dir_left=True)
    x.set_tile(tile=name + "_left.3", delay_ms=delay, is_dir_left=True)
    x.set_tile(tile=name + "_left.4", delay_ms=delay, is_dir_left=True)
    x.set_tile(tile=name + "_left.5", delay_ms=delay, is_dir_left=True)
    x.set_tile(tile=name + "_left.6", delay_ms=delay, is_dir_left=True,
               is_end_of_anim = True, is_dead_on_end_of_anim=True)
    x.set_tile(tile=name + "_left.1", delay_ms=delay, is_dir_right=True)
    x.set_tile(tile=name + "_left.2", delay_ms=delay, is_dir_right=True)
    x.set_tile(tile=name + "_left.3", delay_ms=delay, is_dir_right=True)
    x.set_tile(tile=name + "_left.4", delay_ms=delay, is_dir_right=True)
    x.set_tile(tile=name + "_left.5", delay_ms=delay, is_dir_right=True)
    x.set_tile(tile=name + "_left.6", delay_ms=delay, is_dir_right=True,
               is_end_of_anim = True, is_dead_on_end_of_anim=True)
    x.set_tile(tile=name + "_up.1", delay_ms=delay, is_dir_up=True)
    x.set_tile(tile=name + "_up.2", delay_ms=delay, is_dir_up=True)
    x.set_tile(tile=name + "_up.3", delay_ms=delay, is_dir_up=True)
    x.set_tile(tile=name + "_up.4", delay_ms=delay, is_dir_up=True)
    x.set_tile(tile=name + "_up.5", delay_ms=delay, is_dir_up=True)
    x.set_tile(tile=name + "_up.6", delay_ms=delay, is_dir_up=True,
               is_end_of_anim = True, is_dead_on_end_of_anim=True)
    x.set_tile(tile=name + "_up.1", delay_ms=delay, is_dir_down=True)
    x.set_tile(tile=name + "_up.2", delay_ms=delay, is_dir_down=True)
    x.set_tile(tile=name + "_up.3", delay_ms=delay, is_dir_down=True)
    x.set_tile(tile=name + "_up.4", delay_ms=delay, is_dir_down=True)
    x.set_tile(tile=name + "_up.5", delay_ms=delay, is_dir_down=True)
    x.set_tile(tile=name + "_up.6", delay_ms=delay, is_dir_down=True,
               is_end_of_anim = True, is_dead_on_end_of_anim=True)
   
    x.update()
    
def init2(name):
    x = tp.Tp(name)

    x.set_gfx_animated(True)
    x.set_gfx_can_hflip(True)
    x.set_gfx_is_weapon_carry_anim(True)
    x.set_gfx_outlined(True)
    x.set_gfx_small_shadow_caster(True)
    x.set_is_active(True)
    x.set_is_movable(True)
    x.set_z_depth(zx.MAP_DEPTH_WEAPON)

    delay = 550
    x.set_tile(tile=name + ".1", delay_ms=delay)
    x.set_tile(tile=name + ".2", delay_ms=delay)

    x.update()
    
def init3(name):
    x = tp.Tp(name)

    x.set_gfx_animated(True)
    x.set_gfx_can_hflip(True)
    x.set_is_movable(True)
    x.set_gfx_outlined(True)
    x.set_is_weapon(True)
    x.set_weapon_carry_anim("sword1_carry_anim")
    x.set_weapon_use_anim("sword1_swing_anim")
    x.set_weapon_use_delay_hundredths(5)
    x.set_weapon_use_distance(5)
    x.set_z_depth(zx.MAP_DEPTH_WEAPON)
    x.set_gfx_small_shadow_caster(True)

    x.set_tile(tile=name + ".1")

    x.update()
    
def init():
    init1(name="sword1_swing_anim")
    init2(name="sword1_carry_anim")
    init3(name="sword1")

init()
