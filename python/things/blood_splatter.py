import zx
import tp

def tp_init(name, real_name):
    x = tp.Tp(name, real_name)

    x.set_a_or_an("a");
    x.set_gfx_animated(True)
    x.set_gfx_oversized_but_sitting_on_the_ground(True)
    x.set_gfx_show_outlined(True)
    x.set_is_blood_splatter(True)
    x.set_is_interesting(False)
    x.set_is_loggable(False)
    x.set_is_combustible(False)
    x.set_z_depth(zx.MAP_DEPTH_ITEM)

    delay = 20
    x.set_tile(tile=name + ".1", delay_ms=delay)
    x.set_tile(tile=name + ".2", delay_ms=delay)
    x.set_tile(tile=name + ".3", delay_ms=delay)
    x.set_tile(tile=name + ".4", delay_ms=delay)
    x.set_tile(tile=name + ".5", delay_ms=delay)
    x.set_tile(tile=name + ".6", delay_ms=delay)
    x.set_tile(tile=name + ".7", delay_ms=delay)
    x.set_tile(tile=name + ".8", delay_ms=delay)
    x.set_tile(tile=name + ".9", delay_ms=delay)
    x.set_tile(tile=name + ".10", delay_ms=delay)
    x.set_tile(tile=name + ".11", delay_ms=delay)
    x.set_tile(tile=name + ".12", delay_ms=delay)
    x.set_tile(tile=name + ".13", delay_ms=delay)
    x.set_tile(tile=name + ".14", delay_ms=delay, is_end_of_anim=True, is_dead_on_end_of_anim=True)

    x.update()

def init():
    tp_init(name="blood_splatter1", real_name="blood splatter")

init()
