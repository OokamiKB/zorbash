import zx
import tp


def tp_init(name, tiles=[]):
    
    x = tp.Tp(name)

    x.set_gfx_animated(True)
    x.set_gfx_is_floor_deco(True)
    x.set_gfx_outlined(True)
    x.set_gfx_oversized_but_sitting_on_the_ground(True)
    x.set_gfx_small_shadow_caster(True)
    x.set_is_interesting(False)
    x.set_is_light_strength(5)
    x.set_is_loggable(False)
    x.set_is_movement_blocking(True)
    x.set_str_light_color("cyan")
    x.set_z_depth(zx.MAP_DEPTH_FLOOR_DECO)
    
    delay=50
    for t in tiles:
        x.set_tile(tile=t, delay_ms=delay)

    x.update()
    
def init():
    tp_init(name="brazier1",
            tiles=[ 
                "brazier1.1", 
                "brazier1.2", 
                "brazier1.3", 
                "brazier1.4", 
                "brazier1.5", 
                "brazier1.6", 
                "brazier1.7", 
                "brazier1.8", 
                "brazier1.9", 
                "brazier1.10", 
                "brazier1.11", 
                "brazier1.12", 
                "brazier1.13", 
                "brazier1.14", 
                "brazier1.15", 
                "brazier1.16", 
                "brazier1.17", 
                "brazier1.18", 
                "brazier1.19", 
                "brazier1.20", 
                "brazier1.21", 
                "brazier1.22", 
                "brazier1.23", 
                "brazier1.24", 
                "brazier1.25", 
                "brazier1.26", 
                "brazier1.27", 
                "brazier1.28", 
                "brazier1.29", 
                "brazier1.30", 
                "brazier1.31", 
                "brazier1.32", 
                ])
init()
