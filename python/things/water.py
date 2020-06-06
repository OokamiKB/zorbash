import zx
import tp


def tp_init(name, text_name, tiles=[]):

    x = tp.Tp(name, text_name)

    x.set_ai_obstacle(True)
    x.set_gfx_animated(True)
    x.set_is_hazard(True)
    x.set_is_interesting(True)
    x.set_is_loggable_for_important_stuff(False)
    x.set_is_loggable_for_unimportant_stuff(False)
    x.set_is_water(True)
    x.set_text_a_or_an("the");
    x.set_z_depth(zx.MAP_DEPTH_WATER)
    x.set_z_prio(zx.MAP_PRIO_NORMAL)

    delay = 1250
    for t in tiles:
        x.set_tile(tile=t, delay_ms=delay)

    x.update()

def init():
    tp_init(name="water1", text_name="water",
            tiles=[
                "water1.1",
                "water1.2",
                "water1.3",
                "water1.4",
                "water1.5",
                "water1.6",
                "water1.7",
                "water1.8",
                "water1.9",
                "water1.10",
                "water1.11",
                "water1.12",
                "water1.13",
                "water1.14",
                "water1.15",
                "water1.16",
                ])
init()
