//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_main.h"
#include "my_game.h"
#include "my_tile.h"
#include "my_tex.h"
#include "my_gl.h"
#include "my_thing.h"
#include "my_wid.h"
#include "my_game_status.h"

void Level::scroll_map_do (void)
{_
    if (wid_find_under_mouse_when_scrolling()) {
        return;
    }

    const float bigstep = 6.0;
    const float medstep = 2.0 / TILE_WIDTH;
    const float smallstep = 1.0 / TILE_WIDTH;

    auto dx = map_at.x - map_wanted_at.x;
    auto dy = map_at.y - map_wanted_at.y;

    if ((fabs(dx) < 0.1) && (fabs(dy) < 0.1)) {
        return;
    }

#if 0
if (player) {
    player->minicon("map_at %f %f map_wanted_at %f %f", 
                    map_at.x,
                    map_at.y,
                    map_wanted_at.x,
                    map_wanted_at.y);
}
#endif

    //
    // If following the player scroll in smaller chunks
    //
    if (map_follow_player) {
        if (fabs(dx) > 5) {
            map_at.x -= dx / bigstep;
        } else if (fabs(dx) > 3) {
            if (map_at.x > map_wanted_at.x) {
                map_at.x -= medstep;
            } else if (map_at.x < map_wanted_at.x) {
                map_at.x += medstep;
            }
        } else if (map_at.x > map_wanted_at.x) {
            map_at.x -= smallstep;
        } else if (map_at.x < map_wanted_at.x) {
            map_at.x += smallstep;
        }

        if (fabs(dy) > 5) {
            map_at.y -= dy / bigstep;
        } else if (fabs(dy) > 3) {
            if (map_at.y > map_wanted_at.y) {
                map_at.y -= medstep;
            } else if (map_at.y < map_wanted_at.y) {
                map_at.y += medstep;
            }
        } else if (map_at.y > map_wanted_at.y) {
            map_at.y -= smallstep;
        } else if (map_at.y < map_wanted_at.y) {
            map_at.y += smallstep;
        }
    } else {
        //
        // Else following the cursor or mouse. Bigger chunks are less sick 
        // inducing.
        //
        map_at.x -= dx / bigstep;
        map_at.y -= dy / bigstep;
    }

    //
    // Round to pixels
    //
    map_at.x *= TILE_WIDTH;
    map_at.y *= TILE_HEIGHT;
    map_at.x = (int) map_at.x;
    map_at.y = (int) map_at.y;
    map_at.x /= TILE_WIDTH;
    map_at.y /= TILE_HEIGHT;

    map_at.x = std::max(map_at.x, (float)0.0);
    map_at.y = std::max(map_at.y, (float)0.0);
    map_at.x = std::min(map_at.x, (float)MAP_WIDTH - TILES_ACROSS);
    map_at.y = std::min(map_at.y, (float)MAP_HEIGHT - TILES_DOWN);
}

void Level::scroll_map (void)
{_
    if (wid_find_under_mouse_when_scrolling()) {
        return;
    }

    scroll_map_do();
}

void Level::scroll_map_to_player (void)
{_
    if (!player) {
        return;
    }

    mouse = -1;
    mouse_old = -1;
    minimap_valid = false;
    map_follow_player = true;

    map_wanted_at = player->mid_at - fpoint(TILES_ACROSS / 2, TILES_DOWN / 2);

    for (auto x = 0; x < 100; x++) {
        scroll_map_set_target();
        scroll_map_do();
    }
}

//
// Make the map scroll to the cursor (or the player)
//
void Level::scroll_map_set_target (void)
{
    fpoint follow;
    float sensitivity;
    float x_sensitivity;
    float y_sensitivity;

    if (wid_find_under_mouse_when_scrolling()) {
        return;
    }

    if (player && map_follow_player) {
        follow = player->mid_at;
        sensitivity = 0.5;
        x_sensitivity = sensitivity * game->config.video_w_h_ratio;
        y_sensitivity = sensitivity;

        //
        // Auto scroll if we cross these limits
        //
        float x1 = ((float)TILES_ACROSS / 2) - x_sensitivity;
        float x2 = ((float)TILES_ACROSS / 2) + x_sensitivity;
        float y1 = ((float)TILES_DOWN / 2) - y_sensitivity;
        float y2 = ((float)TILES_DOWN / 2) + y_sensitivity;

        //
        // Auto scroll
        //
        float dx = follow.x - map_wanted_at.x;
        if (dx > x2) {
            map_wanted_at.x++;
        }
        if (dx < x1) {
            map_wanted_at.x--;
        }

        float dy = follow.y - map_wanted_at.y;
        if (dy > y2) {
            map_wanted_at.y++;
        }
        if (dy < y1) {
            map_wanted_at.y--;
        }
    } else if (cursor && !map_follow_player) {
        //
        // Allow the player to scroll around the scene of carnage
        // once dead
        //
        if (player && player->is_dead) {
            return;
        }

        auto d = 0.3;
        if (mouse_x >= game->config.outer_pix_width - 1) {
            map_wanted_at.x += d;
        }
        if (mouse_x <= 1) {
            map_wanted_at.x -= d;
        }
        if (mouse_y >= game->config.outer_pix_height - 1) {
            map_wanted_at.y += d;
        }
        if (mouse_y <= 1) {
            map_wanted_at.y -= d;
        }
    }
}
