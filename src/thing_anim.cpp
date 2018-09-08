/*
 * Copyright (C) 2018 goblinhack@gmail.com
 *
 * See the LICENSE file for license.
 */

#include "my_tile_info.h"
#include "my_thing.h"

void Thing::animate (void)
{_
    auto t = this;

    Tileinfop tile;
    Tileinfop otile;
    Tileinfomap tiles;
    Tpp tp = t->tp;

    if (!tp_is_animated(tp)) {
        return;
    }

    otile = tile = t->current_tile;

    if (tile) {
        /*
         * If within the animate time of this frame, keep with it.
         */
        if (t->next_frame_ms > time_get_time_ms_cached()) {
            return;
        }

        /*
         * Stop the animation here?
         */
        if (tile_info_is_end_of_anim(tile)) {

            if (tile_info_is_dead_on_end_of_anim(tile)) {
                t->dead(0, "end of anim");
            }

            return;
        }
    }

    tiles = tp_get_tiles(tp);
    if (tiles.empty()) {
        return;
    }

    int chose_tile = false;

    /*
     * Get the next tile.
     */
    if (tile) {
        /*
         * If walking and now we've stopped, choose the idle no dir tile.
         */
        if (tp_is_player(tp) && !t->is_dead && !t->is_moving &&
            (time_get_time_ms() >= t->last_move_ms + 5000)) {

            Tileinfop new_tile;

            {
                new_tile = tile_info_next(tiles, tile);
                if (!new_tile) {
                    new_tile = tile_info_first(tiles);
                }

                while (new_tile) {
                    if (tile_info_is_dir_none(new_tile)) {
                        chose_tile = true;
                        tile = new_tile;
                        break;
                    }

                    auto otile = new_tile;
                    new_tile = tile_info_next(tiles, new_tile);
                    if (new_tile == otile) {
                        DIE("wtf");
                    }
                    continue;
                }
            }
        } else {
            verify(tile.get());
            tile = tile_info_next(tiles, tile);
        }
    }

    /*
     * Find a tile that matches the things current mode.
     */
    uint32_t size = tiles.size();
    uint32_t tries = 0;

    if (!chose_tile) {
        while (tries < size) {
            tries++;

            /*
             * Cater for wraps.
             */
            if (!tile) {
                tile = tile_info_first(tiles);
            }
            verify(tile.get());

            if (!t->is_dead) {
                if (tile_info_is_dead(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            }

            if (t->is_moving) {
                if (!tile_info_is_moving(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            }

            if (!t->is_moving) {
                if (tile_info_is_moving(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            }

            if (t->is_dead) {
                if (!tile_info_is_dead(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            } else if (t->is_sleeping) {
                if (!tile_info_is_sleeping(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
#if 0
            } else if (tp->has_dir_anim && thing_is_dir_tl(t)) {
                if (!tile_info_is_dir_tl(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            } else if (tp->has_dir_anim && thing_is_dir_bl(t)) {
                if (!tile_info_is_dir_bl(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            } else if (tp->has_dir_anim && thing_is_dir_br(t)) {
                if (!tile_info_is_dir_br(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            } else if (tp->has_dir_anim && thing_is_dir_tr(t)) {
                if (!tile_info_is_dir_tr(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
#endif
            } else if (tp->has_dir_anim && t->is_dir_up()) {
                if (!tile_info_is_dir_up(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            } else if (tp->has_dir_anim && t->is_dir_down()) {
                if (!tile_info_is_dir_down(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            } else if (tp->has_dir_anim && t->is_dir_left()) {
                if (!tile_info_is_dir_left(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            } else if (tp->has_dir_anim && t->is_dir_right()) {
                if (!tile_info_is_dir_right(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            } else if (tp->has_dir_anim && t->is_dir_none()) {
                if (!tile_info_is_dir_none(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            } else if (t->is_open) {
                if (!tile_info_is_open(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            } else {
                if (tile_info_is_sleeping(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }

                if (tile_info_is_dead(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }

                if (tile_info_is_open(tile)) {
                    tile = tile_info_next(tiles, tile);
                    continue;
                }
            }

            break;
        }
    }

    if (!tile) {
        return;
    }

    /*
     * Use this tile!
     */
    if (!tile->tile) {
        tile->tile = tile_find(tile_info_name(tile));
        if (!tile->tile) {
            ERR("cannot find tile %s", tile_info_name(tile).c_str());
            return;
        }
    }

#if 0
    if (tile && otile) {
        if(thing_is_joinable(t)) {
            CON("%s-> %s", tile_info_name(otile), tile_info_name(tile));
        }
    }
#endif
//CON("set %s", tile_info_name(tile).c_str());

//    t->set_tilename(tile_info_name(tile));
    t->current_tile = tile;

    /*
     * When does this tile expire ?
     */
    uint32_t delay = tile_info_delay_ms(tile);
    if (delay) {
        delay = delay + (myrand() % delay) / 10;
    }

    t->next_frame_ms = time_get_time_ms_cached() + delay;
}
