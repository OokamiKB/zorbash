import zx
import tp


def tp_init(name, text_name):
    x = tp.Tp(name, text_name)
    x.set_gfx_shown_in_bg(True)
    x.set_gfx_small_shadow_caster(True)
    x.set_is_able_to_fall(False)
    x.set_is_cursor_can_hover_over(True)
    x.set_is_interesting(True)
    x.set_is_light_blocker(True)
    x.set_is_secret_door(True)
    x.set_normal_placement_rules(True)
    x.set_text_a_or_an("a");
    x.set_text_description("A hidden door.")
    x.set_z_depth(zx.MAP_DEPTH_OBJ)
    x.set_z_prio(zx.MAP_PRIO_NORMAL)

    x.set_tile(tile=name + ".1")
    x.set_tile(tile=name + ".2")
    x.set_tile(tile=name + ".3")
    x.set_tile(tile=name + ".4")
    x.set_tile(tile=name + ".5")
    x.set_tile(tile=name + ".6")
    x.set_tile(tile=name + ".7")
    x.set_tile(tile=name + ".8")
    x.set_tile(tile=name + ".9")
    x.set_tile(tile=name + ".10")
    x.set_tile(tile=name + ".11")
    x.set_tile(tile=name + ".12")
    x.set_tile(tile=name + ".13")
    x.set_tile(tile=name + ".14")
    x.set_tile(tile=name + ".15")
    x.set_tile(tile=name + ".16")

    x.update()

def init():
    tp_init(name="door_secret", text_name="secret door")

init()
