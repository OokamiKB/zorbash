//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_gfx.hpp"
#include "my_tile.hpp"
#include "my_ui.hpp"

static void gfx_init_font_small(void)
{
  std::initializer_list< std::string > tiles = {
      //////////////////////////////////////////////////////////////////
      // sp     !       "       #       $       %       &       '
      //////////////////////////////////////////////////////////////////
      "1.0",
      "1.1",
      "1.2",
      "1.3",
      "1.4",
      "1.5",
      "1.6",
      "1.7",
      //////////////////////////////////////////////////////////////////
      //  (     )       *       +       ,       -       .       /
      //////////////////////////////////////////////////////////////////
      "1.8",
      "1.9",
      "1.10",
      "1.11",
      "1.12",
      "1.13",
      "1.14",
      "1.15",
      //////////////////////////////////////////////////////////////////
      //  0     1       2       3       4       5       6       7
      //////////////////////////////////////////////////////////////////
      "1.16",
      "1.17",
      "1.18",
      "1.19",
      "1.20",
      "1.21",
      "1.22",
      "1.23",
      //////////////////////////////////////////////////////////////////
      //  8     9       :       ;       <       =       >       ?
      //////////////////////////////////////////////////////////////////
      "1.24",
      "1.25",
      "1.26",
      "1.27",
      "1.28",
      "1.29",
      "1.30",
      "1.31",
      //////////////////////////////////////////////////////////////////
      //  @     A       B       C       D       E       F       G
      //////////////////////////////////////////////////////////////////
      "1.32",
      "1.33",
      "1.34",
      "1.35",
      "1.36",
      "1.37",
      "1.38",
      "1.39",
      //////////////////////////////////////////////////////////////////
      //  H     I       J       K       L       M       N       O
      //////////////////////////////////////////////////////////////////
      "1.40",
      "1.41",
      "1.42",
      "1.43",
      "1.44",
      "1.45",
      "1.46",
      "1.47",
      //////////////////////////////////////////////////////////////////
      //  P     Q       R       S       T       U       V       W
      //////////////////////////////////////////////////////////////////
      "1.48",
      "1.49",
      "1.50",
      "1.51",
      "1.52",
      "1.53",
      "1.54",
      "1.55",
      //////////////////////////////////////////////////////////////////
      //  X     Y       Z       [       \       ]       ^       _
      //////////////////////////////////////////////////////////////////
      "1.56",
      "1.57",
      "1.58",
      "1.59",
      "1.60",
      "1.61",
      "1.62",
      "1.63",
      //////////////////////////////////////////////////////////////////
      //  `     a       b       c       d       e       f       g
      //////////////////////////////////////////////////////////////////
      "1.64",
      "1.65",
      "1.66",
      "1.67",
      "1.68",
      "1.69",
      "1.70",
      "1.71",
      //////////////////////////////////////////////////////////////////
      //  h     i       j       k       l       m       n       o
      //////////////////////////////////////////////////////////////////
      "1.72",
      "1.73",
      "1.74",
      "1.75",
      "1.76",
      "1.77",
      "1.78",
      "1.79",
      //////////////////////////////////////////////////////////////////
      //  p     q       r       s       t       u       v       w
      //////////////////////////////////////////////////////////////////
      "1.80",
      "1.81",
      "1.82",
      "1.83",
      "1.84",
      "1.85",
      "1.86",
      "1.87",
      //////////////////////////////////////////////////////////////////
      //  x     y       z       {       |       }       ~       del
      //////////////////////////////////////////////////////////////////
      "1.88",
      "1.89",
      "1.90",
      "1.91",
      "1.92",
      "1.93",
      "1.94",
      "1.95",
      //////////////////////////////////////////////////////////////////
      //  blk  [$]     lbs    arrow
      //////////////////////////////////////////////////////////////////
      "1.96",
      "1.97",
      "1.98",
      "1.99",
      "1.100",
      "",
      "",
      "",
  };

  const std::vector< std::string > arr(tiles);
  tile_load_arr_sprites("data/fonts/font-small.tga", "font_small", UI_FONT_SMALL_WIDTH, UI_FONT_SMALL_HEIGHT, arr);
}

static void gfx_init_font_large(void)
{
  std::initializer_list< std::string > tiles = {
      //////////////////////////////////////////////////////////////////
      // sp     !       "       #       $       %       &       '
      //////////////////////////////////////////////////////////////////
      "2.0",
      "2.1",
      "2.2",
      "2.3",
      "2.4",
      "2.5",
      "2.6",
      "2.7",
      //////////////////////////////////////////////////////////////////
      //  (     )       *       +       ,       -       .       /
      //////////////////////////////////////////////////////////////////
      "2.8",
      "2.9",
      "2.10",
      "2.11",
      "2.12",
      "2.13",
      "2.14",
      "2.15",
      //////////////////////////////////////////////////////////////////
      //  0     1       2       3       4       5       6       7
      //////////////////////////////////////////////////////////////////
      "2.16",
      "2.17",
      "2.18",
      "2.19",
      "2.20",
      "2.21",
      "2.22",
      "2.23",
      //////////////////////////////////////////////////////////////////
      //  8     9       :       ;       <       =       >       ?
      //////////////////////////////////////////////////////////////////
      "2.24",
      "2.25",
      "2.26",
      "2.27",
      "2.28",
      "2.29",
      "2.30",
      "2.31",
      //////////////////////////////////////////////////////////////////
      //  @     A       B       C       D       E       F       G
      //////////////////////////////////////////////////////////////////
      "2.32",
      "2.33",
      "2.34",
      "2.35",
      "2.36",
      "2.37",
      "2.38",
      "2.39",
      //////////////////////////////////////////////////////////////////
      //  H     I       J       K       L       M       N       O
      //////////////////////////////////////////////////////////////////
      "2.40",
      "2.41",
      "2.42",
      "2.43",
      "2.44",
      "2.45",
      "2.46",
      "2.47",
      //////////////////////////////////////////////////////////////////
      //  P     Q       R       S       T       U       V       W
      //////////////////////////////////////////////////////////////////
      "2.48",
      "2.49",
      "2.50",
      "2.51",
      "2.52",
      "2.53",
      "2.54",
      "2.55",
      //////////////////////////////////////////////////////////////////
      //  X     Y       Z       [       \       ]       ^       _
      //////////////////////////////////////////////////////////////////
      "2.56",
      "2.57",
      "2.58",
      "2.59",
      "2.60",
      "2.61",
      "2.62",
      "2.63",
      //////////////////////////////////////////////////////////////////
      //  `     a       b       c       d       e       f       g
      //////////////////////////////////////////////////////////////////
      "2.64",
      "2.65",
      "2.66",
      "2.67",
      "2.68",
      "2.69",
      "2.70",
      "2.71",
      //////////////////////////////////////////////////////////////////
      //  h     i       j       k       l       m       n       o
      //////////////////////////////////////////////////////////////////
      "2.72",
      "2.73",
      "2.74",
      "2.75",
      "2.76",
      "2.77",
      "2.78",
      "2.79",
      //////////////////////////////////////////////////////////////////
      //  p     q       r       s       t       u       v       w
      //////////////////////////////////////////////////////////////////
      "2.80",
      "2.81",
      "2.82",
      "2.83",
      "2.84",
      "2.85",
      "2.86",
      "2.87",
      //////////////////////////////////////////////////////////////////
      //  x     y       z       {       |       }       ~       del
      //////////////////////////////////////////////////////////////////
      "2.88",
      "2.89",
      "2.90",
      "2.91",
      "2.92",
      "2.93",
      "2.94",
      "2.95",
      //////////////////////////////////////////////////////////////////
      //  blk  [$]     lbs    arrow
      //////////////////////////////////////////////////////////////////
      "2.96",
      "2.97",
      "2.98",
      "2.99",
      "2.100",
      "",
      "",
      "",
  };

  const std::vector< std::string > arr(tiles);
  tile_load_arr_sprites("data/fonts/font-large.tga", "font_large", UI_FONT_LARGE_WIDTH, UI_FONT_LARGE_HEIGHT, arr);
}

static void gfx_init_ui(void) {}

void gfx_init(void)
{
  gfx_init_font_small();
  gfx_init_font_large();
  gfx_init_ui();
  gfx_init0();
  gfx_init1();
  gfx_init2();
  gfx_init3();
  gfx_init4();
  gfx_init5();
  gfx_init6();
  gfx_init7();
  gfx_init8();
  gfx_init9();
  gfx_init10();
  gfx_init11();
  gfx_init12();
}

void gfx_fini(void) {}
