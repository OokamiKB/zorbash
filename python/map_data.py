import zx


def map_data_init():

    data = [
    ]

    zx.map_load_room(
        floor=[
                "......",
                "......",
                "......",
                "......",
                "......",
              ],
        walls=[
                "xxDxxx",
                "x    D",
                "D    x",
                "x    x",
                "xxxDxx",
              ],
        items=[
                "      ",
                "   o  ",
                "      ",
                "      ",
                "      ",
              ])

    zx.map_load_room(
        floor=[
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
              ],
        walls=[
                "xxDxxxxxxx",
                "x  x     D",
                "x  x   xxx",
                "x        x",
                "x        x",
                "x        x",
                "xxxxxxxxxx",
              ],
        items=[
                "          ",
                "   o      ",
                "          ",
                "          ",
                "          ",
                "          ",
                "          ",
              ])

    zx.map_load_room(
        floor=[
                "   .......",
                "   .......",
                "..........",
                "..........",
                "..........",
                ".......   ",
                ".......   ",

              ],
        walls=[
                "   xxxxxxx",
                "   x     D",
                "xxxx     x",
                "D        x",
                "x     xxxx",
                "x     x   ",
                "xxxxxxx   ",
              ],
        items=[
                "          ",
                "          ",
                "          ",
                "          ",
                "          ",
                "          ",
                "          ",
              ])

    zx.map_load_room(
        floor=[
                    "  ....  ",
                    " ...... ",
                    "........",
                    "........",
                    "........",
                    " .......",
                    "  ......",
              ],
        walls=[
                    "  xxDx  ",
                    " xx  xx ",
                    "xx    xx",
                    "D      D",
                    "xx     x",
                    " xx    x",
                    "  xDxxxx",
              ],
        items=[
                    "        ",
                    "        ",
                    "        ",
                    "        ",
                    "        ",
                    "        ",
                    "        ",
              ])

    zx.map_load_room(
        floor=[
                    "....  ....   ",
                    ".............",
                    ".............",
                    " ............",
                    " ............",
                    ".............",
                    ".............",
                    "............ ",
                    "............ ",
                    "....   ..... ",
              ],
        walls=[
                    "xxDx  xxxx   ",
                    "x  xxxx  xxxx",
                    "xx          D",
                    " x          x",
                    " x          x",
                    "xx          x",
                    "D          xx",
                    "x          x ",
                    "x  xxxxx   x ",
                    "xxxx   xxxDx ",
              ],
        items=[
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
              ])

    zx.map_load_room(
        floor=[
                    ".....   .....",
                    ".............",
                    ".............",
                    ".............",
                    "   .......   ",
                    "   .......   ",
                    "   .......   ",
                    ".............",
                    ".............",
                    ".............",
                    ".....   .....",
              ],
        walls=[
                    "xxxxx   xxxxx",
                    "x   xxDxx   x",
                    "x           x",
                    "xxxx     xxxx",
                    "   x     x   ",
                    "   D     D   ",
                    "   x     x   ",
                    "xxxx     xxxx",
                    "x           x",
                    "x   xxDxx   x",
                    "xxxxx   xxxxx",
              ],
        items=[
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
                    "             ",
              ])

map_data_init()
