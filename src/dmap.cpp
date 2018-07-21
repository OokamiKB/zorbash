/*
 * Copyright (C) 2017 goblinhack@gmail.com
 *
 * See the README file for license info.
 */

#include "my_main.h"
#include "my_dmap.h"

void dmap_print (dmap *d)
{_
    int16_t x;
    int16_t y;

    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            int16_t e = d->val[x][y];
            if (e == DMAP_IS_WALL) {
                printf("#  ");
                continue;
            }

            if (e > 0) {
                printf("%-3d", e);
            } else {
                printf(".  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * An optimized djkstra map that only looks at map areas that change.
 */
void dmap_process (dmap *D)
{_
    int16_t x;
    int16_t y;
    int16_t a;
    int16_t b;
    int16_t c;
    int16_t d;
    int16_t *e;
    int16_t f;
    int16_t g;
    int16_t h;
    int16_t i;
    int16_t lowest;
    int16_t changed;
    static uint8_t valid[MAP_WIDTH][MAP_HEIGHT];
    static uint8_t new_valid[MAP_WIDTH][MAP_HEIGHT];
    static uint8_t orig_valid[MAP_WIDTH][MAP_HEIGHT];

    memset(valid, 1, sizeof(valid));
    memset(orig_valid, 1, sizeof(valid));

    for (y = 1; y < MAP_HEIGHT - 1; y++) {
        for (x = 1; x < MAP_WIDTH - 1; x++) {
            e = &D->val[x ][y];
            if (*e != DMAP_IS_WALL) {
                continue;
            }

            valid[x][y] = 0;
            orig_valid[x][y] = 0;
        }
    }

#if 0
    int16_t count = 1;
#endif

    do {
        changed = false;
        memset(new_valid, 0, sizeof(new_valid));

#if 0
        printf("run %d %d %d\n", count, x, y);
        count++;
#endif
        for (y = 1; y < MAP_HEIGHT - 1; y++) {
            for (x = 1; x < MAP_WIDTH - 1; x++) {
                if (!orig_valid[x][y]) {
#if 0
printf("# ");
#endif
                    continue;
                }

                if (!valid[x][y]) {
#if 0
printf("  ");
#endif
                    continue;
                }

                e = &D->val[x  ][y];

                /*
                 * Avoid diagonal moves.
                 */
                if ((D->val[x-1][y] == DMAP_IS_WALL) ||
                    (D->val[x][y-1] == DMAP_IS_WALL)) {
                    a = DMAP_IS_WALL;
                } else {
                    a = D->val[x-1][y-1];
                }

                b = D->val[x  ][y-1];

                if ((D->val[x+1][y] == DMAP_IS_WALL) ||
                    (D->val[x][y-1] == DMAP_IS_WALL)) {
                    c = DMAP_IS_WALL;
                } else {
                    c = D->val[x+1][y-1];
                }

                d = D->val[x-1][y];
                f = D->val[x+1][y];

                if ((D->val[x-1][y] == DMAP_IS_WALL) ||
                    (D->val[x][y+1] == DMAP_IS_WALL)) {
                    g = DMAP_IS_WALL;
                } else {
                    g = D->val[x-1][y+1];
                }

                h = D->val[x  ][y+1];

                if ((D->val[x+1][y] == DMAP_IS_WALL) ||
                    (D->val[x][y+1] == DMAP_IS_WALL)) {
                    i = DMAP_IS_WALL;
                } else {
                    i = D->val[x+1][y+1];
                }

                if (a < b) {
                    lowest = a;
                } else {
                    lowest = b;
                }

                if (c < lowest) { lowest = c; }
                if (d < lowest) { lowest = d; }
                if (f < lowest) { lowest = f; }
                if (g < lowest) { lowest = g; }
                if (h < lowest) { lowest = h; }
                if (i < lowest) { lowest = i; }

                if (*e - lowest >= 2) {

                    new_valid[x-1][y-1] = 1;
                    new_valid[x-1][y  ] = 1;
                    new_valid[x-1][y+1] = 1;
                    new_valid[x  ][y-1] = 1;
                    new_valid[x  ][y  ] = 1;
                    new_valid[x  ][y+1] = 1;
                    new_valid[x+1][y-1] = 1;
                    new_valid[x+1][y  ] = 1;
                    new_valid[x+1][y+1] = 1;

                    *e = lowest + 1;
                    changed = true;
#if 0
printf("* ");
                } else {
printf("%-2d", lowest);
                }
            }
printf("\n");
#else
                }
            }
#endif
        }

        memcpy(valid, new_valid, sizeof(new_valid));

    } while (changed);
#if 0
    dmap_print(D);
#endif
}

static bool is_movement_blocking_at (const dmap *D, int x, int y)
{_
    if ((x >= MAP_WIDTH) || (y >= MAP_HEIGHT) || (x < 0) || (y < 0)) {
        return (true);
    }

    if (D->val[x][y] == DMAP_IS_WALL) {
        return (true);
    }

    return (false);
}

/*
 * Make L shaped moves into diagonal ones
 */
void dmap_l_shaped_path_to_diag (const dmap *D, std::vector<point> &path)
{_
    for (;/*ever*/;) {
        auto modified = false;
        size_t i = 0;

        for (;/*ever*/;) {
            if (i + 2 >= path.size()) {
                break;
            }

            auto p = path[i];
            auto px = p.x;
            auto py = p.y;

            auto n = path[i + 1];
            auto nx = n.x;
            auto ny = n.y;

            auto m = path[i + 2];
            auto mx = m.x;
            auto my = m.y;

            if (px - 1 == mx && py + 1 == my && px == nx && py + 1 == ny &&
                ! is_movement_blocking_at(D, px - 1, py)) {
                path.erase(path.begin() + i);
                modified = true;
                break;
            }

            if (px - 1 == mx && py + 1 == my && px - 1 == nx && py == ny &&
                ! is_movement_blocking_at(D, px, py + 1)) {
                path.erase(path.begin() + i);
                modified = true;
                break;
            }

            if (px + 1 == mx && py + 1 == my && px == nx && py + 1 == ny &&
                ! is_movement_blocking_at(D, px + 1, py)) {
                path.erase(path.begin() + i);
                modified = true;
                break;
            }

            if (px + 1 == mx && py + 1 == my && px + 1 == nx && py == ny &&
                ! is_movement_blocking_at(D, px, py + 1)) {
                path.erase(path.begin() + i);
                modified = true;
                break;
            }

            if (px - 1 == mx && py - 1 == my && px == nx && py - 1 == ny &&
                ! is_movement_blocking_at(D, px - 1, py)) {
                path.erase(path.begin() + i);
                modified = true;
                break;
            }

            if (px - 1 == mx && py - 1 == my && px - 1 == nx && py == ny &&
                ! is_movement_blocking_at(D, px, py - 1)) {
                path.erase(path.begin() + i);
                modified = true;
                break;
            }

            if (px + 1 == mx && py - 1 == my && px == nx && py - 1 == ny &&
                ! is_movement_blocking_at(D, px + 1, py)) {
                path.erase(path.begin() + i);
                modified = true;
                break;
            }

            if (px + 1 == mx && py - 1 == my && px + 1 == nx && py == ny && \
                ! is_movement_blocking_at(D, px, py - 1)) {
                path.erase(path.begin() + i);
                modified = true;
                break;
            }

            i++;
        }

        if (! modified) {
            break;
        }
    }
}

std::vector<point> dmap_solve (const dmap *D, 
                               const point start,
                               const point end)
{_
    static const std::vector<point> all_deltas = {
        point(0, -1),
        point(-1, 0),
        point(1, 0),
        point(0, 1),
    };

    static uint8_t walked[MAP_WIDTH][MAP_HEIGHT];
    memset(walked, 0, sizeof(walked));

    auto at = start;
    std::vector<point> out = { at };

    for (;/*ever*/;) {
        auto x = at.x;
        auto y = at.y;

        if ((x >= MAP_WIDTH) || (y >= MAP_HEIGHT) || (x < 0) || (y < 0)) {
            return out;
        }

        auto lowest = D->val[x][y];
        bool got = false;
        point best;

        if (D->val[x][y] == DMAP_IS_WALL) {
            return out;
        }

        for (auto d : all_deltas) {
            auto t = at + d;
            auto tx = t.x;
            auto ty = t.y;

            if ((tx >= MAP_WIDTH) || (ty >= MAP_HEIGHT) || (tx < 0) || (ty < 0)) {
                continue;
            }

            if (walked[tx][ty]) {
                continue;
            }

            if (D->val[tx][ty] == DMAP_IS_WALL) {
                continue;
            }

            auto c = D->val[tx][ty];
            if (c <= lowest) {
                got = true;
                best = t;
                lowest = c;
            }
        }

        if (!got) {
            return (out);
        }

        out.push_back(best);
        at = best;
        walked[best.x][best.y] = true;
    }
    return (out);
}
