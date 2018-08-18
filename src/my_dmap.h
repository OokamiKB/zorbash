/*
 * Copyright (C) 2017 goblinhack@gmail.com
 *
 * See the README file for license info.
 */

#pragma once

#include "my_point.h"

typedef struct dmap_ {
    int16_t val[MAP_WIDTH][MAP_HEIGHT];
} dmap;

extern void dmap_process(dmap *d);
extern void dmap_process(dmap *D, point start, point end);
extern void dmap_print(dmap *d);
extern void dmap_print_walls(dmap *d);
extern std::vector<point> dmap_solve(const dmap *d, const point end, 
                                     const point start);
extern void dmap_l_shaped_path_to_diag(const dmap *D, 
                                       std::vector<point> &path);
extern uint64_t dmap_hash(dmap *d);

#define DMAP_IS_WALL     999
#define DMAP_IS_PASSABLE 998
#define DMAP_IS_GOAL     0
