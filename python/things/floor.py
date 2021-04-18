import zx
import tp


#
# NOTE: chasm tiles are not blitted explicitly. Instead a floor tile
# will check for the presence of a chasm beneath it and blit the chasm
#
def tp_init(name, tiles=[], bot3_tiles=[]):
    x = tp.Tp(name)
    x.set_gfx_shown_in_bg(True)
    x.set_is_able_to_fall(False)
    x.set_is_cursor_can_hover_over(True)
    x.set_is_floor(True)
    x.set_is_interesting(False)
    x.set_is_loggable_for_important_stuff(False)
    x.set_is_loggable_for_unimportant_stuff(False)
    x.set_text_a_or_an("the");
    x.set_text_description("The unwashed dungeon floor.")
    x.set_z_depth(zx.MAP_DEPTH_FLOOR)
    x.set_z_prio(zx.MAP_PRIO_BEHIND)

    for t in tiles:
        x.set_tile(t)

    if bot3_tiles is not None:
        for t in bot3_tiles:
            x.set_bot3_tile(t)
    else:
        x.set_bot3_tile(bot3_tile=name)

    x.update()

def init():
    tp_init(name="floor1",
            tiles=[
                        "floor1.1", "floor1.2", "floor1.3", "floor1.4",
                        "floor1.5", "floor1.6", "floor1.7", "floor1.8",
                        "floor1.9", "floor1.10", "floor1.11", "floor1.12",
                        "floor1.13", "floor1.14", "floor1.15", "floor1.16",
                        "floor1.17", "floor1.18", "floor1.19", "floor1.20",
                        "floor1.21", "floor1.22", "floor1.23", "floor1.24",
                        "floor1.25", "floor1.26", "floor1.27", "floor1.28",
                        "floor1.29", "floor1.30", "floor1.31", "floor1.32",
                        "floor1.33", "floor1.34", "floor1.35", "floor1.36",
                        "floor1.37", "floor1.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
    tp_init(name="floor2",
            tiles=[
                        "floor2.1", "floor2.2", "floor2.3", "floor2.4",
                        "floor2.5", "floor2.6", "floor2.7", "floor2.8",
                        "floor2.9", "floor2.10", "floor2.11", "floor2.12",
                        "floor2.13", "floor2.14", "floor2.15", "floor2.16",
                        "floor2.17", "floor2.18", "floor2.19", "floor2.20",
                        "floor2.21", "floor2.22", "floor2.23", "floor2.24",
                        "floor2.25", "floor2.26", "floor2.27", "floor2.28",
                        "floor2.29", "floor2.30", "floor2.31", "floor2.32",
                        "floor2.33", "floor2.34", "floor2.35", "floor2.36",
                        "floor2.37", "floor2.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
    tp_init(name="floor3",
            tiles=[
                        "floor3.1", "floor3.2", "floor3.3", "floor3.4",
                        "floor3.5", "floor3.6", "floor3.7", "floor3.8",
                        "floor3.9", "floor3.10", "floor3.11", "floor3.12",
                        "floor3.13", "floor3.14", "floor3.15", "floor3.16",
                        "floor3.17", "floor3.18", "floor3.19", "floor3.20",
                        "floor3.21", "floor3.22", "floor3.23", "floor3.24",
                        "floor3.25", "floor3.26", "floor3.27", "floor3.28",
                        "floor3.29", "floor3.30", "floor3.31", "floor3.32",
                        "floor3.33", "floor3.34", "floor3.35", "floor3.36",
                        "floor3.37", "floor3.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
    tp_init(name="floor4",
            tiles=[
                        "floor4.1", "floor4.2", "floor4.3", "floor4.4",
                        "floor4.5", "floor4.6", "floor4.7", "floor4.8",
                        "floor4.9", "floor4.10", "floor4.11", "floor4.12",
                        "floor4.13", "floor4.14", "floor4.15", "floor4.16",
                        "floor4.17", "floor4.18", "floor4.19", "floor4.20",
                        "floor4.21", "floor4.22", "floor4.23", "floor4.24",
                        "floor4.25", "floor4.26", "floor4.27", "floor4.28",
                        "floor4.29", "floor4.30", "floor4.31", "floor4.32",
                        "floor4.33", "floor4.34", "floor4.35", "floor4.36",
                        "floor4.37", "floor4.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
    tp_init(name="floor5",
            tiles=[
                        "floor5.1", "floor5.2", "floor5.3", "floor5.4",
                        "floor5.5", "floor5.6", "floor5.7", "floor5.8",
                        "floor5.9", "floor5.10", "floor5.11", "floor5.12",
                        "floor5.13", "floor5.14", "floor5.15", "floor5.16",
                        "floor5.17", "floor5.18", "floor5.19", "floor5.20",
                        "floor5.21", "floor5.22", "floor5.23", "floor5.24",
                        "floor5.25", "floor5.26", "floor5.27", "floor5.28",
                        "floor5.29", "floor5.30", "floor5.31", "floor5.32",
                        "floor5.33", "floor5.34", "floor5.35", "floor5.36",
                        "floor5.37", "floor5.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
    tp_init(name="floor6",
            tiles=[
                        "floor6.1", "floor6.2", "floor6.3", "floor6.4",
                        "floor6.5", "floor6.6", "floor6.7", "floor6.8",
                        "floor6.9", "floor6.10", "floor6.11", "floor6.12",
                        "floor6.13", "floor6.14", "floor6.15", "floor6.16",
                        "floor6.17", "floor6.18", "floor6.19", "floor6.20",
                        "floor6.21", "floor6.22", "floor6.23", "floor6.24",
                        "floor6.25", "floor6.26", "floor6.27", "floor6.28",
                        "floor6.29", "floor6.30", "floor6.31", "floor6.32",
                        "floor6.33", "floor6.34", "floor6.35", "floor6.36",
                        "floor6.37", "floor6.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
    tp_init(name="floor7",
            tiles=[
                        "floor7.1", "floor7.2", "floor7.3", "floor7.4",
                        "floor7.5", "floor7.6", "floor7.7", "floor7.8",
                        "floor7.9", "floor7.10", "floor7.11", "floor7.12",
                        "floor7.13", "floor7.14", "floor7.15", "floor7.16",
                        "floor7.17", "floor7.18", "floor7.19", "floor7.20",
                        "floor7.21", "floor7.22", "floor7.23", "floor7.24",
                        "floor7.25", "floor7.26", "floor7.27", "floor7.28",
                        "floor7.29", "floor7.30", "floor7.31", "floor7.32",
                        "floor7.33", "floor7.34", "floor7.35", "floor7.36",
                        "floor7.37", "floor7.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
    tp_init(name="floor8",
            tiles=[
                        "floor8.1", "floor8.2", "floor8.3", "floor8.4",
                        "floor8.5", "floor8.6", "floor8.7", "floor8.8",
                        "floor8.9", "floor8.10", "floor8.11", "floor8.12",
                        "floor8.13", "floor8.14", "floor8.15", "floor8.16",
                        "floor8.17", "floor8.18", "floor8.19", "floor8.20",
                        "floor8.21", "floor8.22", "floor8.23", "floor8.24",
                        "floor8.25", "floor8.26", "floor8.27", "floor8.28",
                        "floor8.29", "floor8.30", "floor8.31", "floor8.32",
                        "floor8.33", "floor8.34", "floor8.35", "floor8.36",
                        "floor8.37", "floor8.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
    tp_init(name="floor9",
            tiles=[
                        "floor9.1", "floor9.2", "floor9.3", "floor9.4",
                        "floor9.5", "floor9.6", "floor9.7", "floor9.8",
                        "floor9.9", "floor9.10", "floor9.11", "floor9.12",
                        "floor9.13", "floor9.14", "floor9.15", "floor9.16",
                        "floor9.17", "floor9.18", "floor9.19", "floor9.20",
                        "floor9.21", "floor9.22", "floor9.23", "floor9.24",
                        "floor9.25", "floor9.26", "floor9.27", "floor9.28",
                        "floor9.29", "floor9.30", "floor9.31", "floor9.32",
                        "floor9.33", "floor9.34", "floor9.35", "floor9.36",
                        "floor9.37", "floor9.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
    tp_init(name="floor10",
            tiles=[
                        "floor10.1", "floor10.2", "floor10.3", "floor10.4",
                        "floor10.5", "floor10.6", "floor10.7", "floor10.8",
                        "floor10.9", "floor10.10", "floor10.11", "floor10.12",
                        "floor10.13", "floor10.14", "floor10.15", "floor10.16",
                        "floor10.17", "floor10.18", "floor10.19", "floor10.20",
                        "floor10.21", "floor10.22", "floor10.23", "floor10.24",
                        "floor10.25", "floor10.26", "floor10.27", "floor10.28",
                        "floor10.29", "floor10.30", "floor10.31", "floor10.32",
                        "floor10.33", "floor10.34", "floor10.35", "floor10.36",
                        "floor10.37", "floor10.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
    tp_init(name="floor11",
            tiles=[
                        "floor11.1", "floor11.2", "floor11.3", "floor11.4",
                        "floor11.5", "floor11.6", "floor11.7", "floor11.8",
                        "floor11.9", "floor11.10", "floor11.11", "floor11.12",
                        "floor11.13", "floor11.14", "floor11.15", "floor11.16",
                        "floor11.17", "floor11.18", "floor11.19", "floor11.20",
                        "floor11.21", "floor11.22", "floor11.23", "floor11.24",
                        "floor11.25", "floor11.26", "floor11.27", "floor11.28",
                        "floor11.29", "floor11.30", "floor11.31", "floor11.32",
                        "floor11.33", "floor11.34", "floor11.35", "floor11.36",
                        "floor11.37", "floor11.38",
                  ],
            bot3_tiles=[ 
                        "chasm1.1", "chasm1.2", "chasm1.3", "chasm1.4", "chasm1.5",
                        "chasm1.6", "chasm1.7", "chasm1.8", "chasm1.9", "chasm1.10",
                        "chasm1.11", "chasm1.12", "chasm1.13", "chasm1.14", "chasm1.15",
                        "chasm1.16", "chasm1.17", "chasm1.18", "chasm1.19",
                ])
init()
