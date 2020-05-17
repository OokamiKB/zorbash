//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include "my_main.h"
#include "my_game.h"
#include "my_depth.h"
#include "my_thing.h"
#include "my_font.h"
#include "my_level.h"
#include "my_tex.h"
#include "my_gl.h"

void Level::display_lava (int fbo,
                           uint16_t minx, uint16_t miny,
                           uint16_t maxx, uint16_t maxy)
{_
#define LAVA_ACROSS 8
#define LAVA_DOWN   8

    static std::array<std::array<Tilep, LAVA_DOWN>, LAVA_ACROSS> lava;
    if (!lava[0][0]) {
        set(lava, 0, 0, tile_find("lava1a"));
        set(lava, 1, 0, tile_find("lava2a"));
        set(lava, 2, 0, tile_find("lava3a"));
        set(lava, 3, 0, tile_find("lava4a"));
        set(lava, 4, 0, tile_find("lava5a"));
        set(lava, 5, 0, tile_find("lava6a"));
        set(lava, 6, 0, tile_find("lava7a"));
        set(lava, 7, 0, tile_find("lava8a"));
        set(lava, 0, 1, tile_find("lava1b"));
        set(lava, 1, 1, tile_find("lava2b"));
        set(lava, 2, 1, tile_find("lava3b"));
        set(lava, 3, 1, tile_find("lava4b"));
        set(lava, 4, 1, tile_find("lava5b"));
        set(lava, 5, 1, tile_find("lava6b"));
        set(lava, 6, 1, tile_find("lava7b"));
        set(lava, 7, 1, tile_find("lava8b"));
        set(lava, 0, 2, tile_find("lava1c"));
        set(lava, 1, 2, tile_find("lava2c"));
        set(lava, 2, 2, tile_find("lava3c"));
        set(lava, 3, 2, tile_find("lava4c"));
        set(lava, 4, 2, tile_find("lava5c"));
        set(lava, 5, 2, tile_find("lava6c"));
        set(lava, 6, 2, tile_find("lava7c"));
        set(lava, 7, 2, tile_find("lava8c"));
        set(lava, 0, 3, tile_find("lava1d"));
        set(lava, 1, 3, tile_find("lava2d"));
        set(lava, 2, 3, tile_find("lava3d"));
        set(lava, 3, 3, tile_find("lava4d"));
        set(lava, 4, 3, tile_find("lava5d"));
        set(lava, 5, 3, tile_find("lava6d"));
        set(lava, 6, 3, tile_find("lava7d"));
        set(lava, 7, 3, tile_find("lava8d"));
        set(lava, 0, 4, tile_find("lava1e"));
        set(lava, 1, 4, tile_find("lava2e"));
        set(lava, 2, 4, tile_find("lava3e"));
        set(lava, 3, 4, tile_find("lava4e"));
        set(lava, 4, 4, tile_find("lava5e"));
        set(lava, 5, 4, tile_find("lava6e"));
        set(lava, 6, 4, tile_find("lava7e"));
        set(lava, 7, 4, tile_find("lava8e"));
        set(lava, 0, 5, tile_find("lava1f"));
        set(lava, 1, 5, tile_find("lava2f"));
        set(lava, 2, 5, tile_find("lava3f"));
        set(lava, 3, 5, tile_find("lava4f"));
        set(lava, 4, 5, tile_find("lava5f"));
        set(lava, 5, 5, tile_find("lava6f"));
        set(lava, 6, 5, tile_find("lava7f"));
        set(lava, 7, 5, tile_find("lava8f"));
        set(lava, 0, 6, tile_find("lava1g"));
        set(lava, 1, 6, tile_find("lava2g"));
        set(lava, 2, 6, tile_find("lava3g"));
        set(lava, 3, 6, tile_find("lava4g"));
        set(lava, 4, 6, tile_find("lava5g"));
        set(lava, 5, 6, tile_find("lava6g"));
        set(lava, 6, 6, tile_find("lava7g"));
        set(lava, 7, 6, tile_find("lava8g"));
        set(lava, 0, 7, tile_find("lava1h"));
        set(lava, 1, 7, tile_find("lava2h"));
        set(lava, 2, 7, tile_find("lava3h"));
        set(lava, 3, 7, tile_find("lava4h"));
        set(lava, 4, 7, tile_find("lava5h"));
        set(lava, 5, 7, tile_find("lava6h"));
        set(lava, 6, 7, tile_find("lava7h"));
        set(lava, 7, 7, tile_find("lava8h"));
    }

    auto z = MAP_DEPTH_LAVA;

    /////////////////////////////////////////////////////////////////////
    // Draw white mask tiles only
    /////////////////////////////////////////////////////////////////////
    blit_init();
    glcolor(WHITE);
    glDisable(GL_TEXTURE_2D);
    blit_fbo_bind(FBO_MASK1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    for (auto y = miny; y < maxy; y++) {
        for (auto x = minx; x < maxx; x++) {
            if (likely(!level->is_lava(x, y))) {
                continue;
            }
            if (likely(!game->config.gfx_show_hidden)) {
                if (!is_visited(x, y)) {
                    continue;
                }
            }
            FOR_ALL_THINGS_AT_DEPTH(level, t, x, y, z) {
                auto tpp = t->tp();
                if (!tp_is_lava(tpp)) {
                    continue;
                }
                t->blit();
            } FOR_ALL_THINGS_END()
        }
    }
    glEnable(GL_TEXTURE_2D);
    blit_flush();

    /////////////////////////////////////////////////////////////////////
    // Draw the tiles that we will want to combine with the mask later
    /////////////////////////////////////////////////////////////////////
    blit_init();
    glcolor(WHITE);
    blit_fbo_bind(FBO_MASK2);
    glBlendFunc(GL_ONE, GL_ZERO);
    auto tile_map = level->lava_tile_map;
    for (auto y = miny; y < maxy; y+=2) {
        for (auto x = minx; x < maxx; x+=2) {
            if (likely(!get(tile_map, x, y))) {
                continue;
            }
            int tx = (x & ~1);
            int ty = (y & ~1);
            int tlx = tx * TILE_WIDTH;
            int tly = ty * TILE_HEIGHT;
            int brx = tlx + (2 * TILE_WIDTH);
            int bry = tly + (2 * TILE_HEIGHT);

            tlx -= pixel_map_at.x;
            tly -= pixel_map_at.y;
            brx -= pixel_map_at.x;
            bry -= pixel_map_at.y;

            auto tile = get(lava,
                            (x&~1) % LAVA_ACROSS,
                            (y&~1) % LAVA_DOWN);
                            // (y + (int)lava_step2/4) % LAVA_DOWN);
            auto x1 = tile->x1;
            auto x2 = tile->x2;
            auto y1 = tile->y1;
            auto y2 = tile->y2;

            float one_pix = (1.0 / tex_get_height(tile->tex));
            y1 += one_pix * lava_step2;
            y2 += one_pix * lava_step2;

            blit(tile->gl_binding(), x1, y2, x2, y1, tlx, bry, brx, tly);
        }
    }
    blit_flush();

    /////////////////////////////////////////////////////////////////////
    // Add reflections
    /////////////////////////////////////////////////////////////////////
    blit_init();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    for (auto z = MAP_DEPTH_LAST_FLOOR_TYPE + 1; z < MAP_DEPTH; z++) {
        for (auto y = miny; y < maxy; y++) {
            for (auto x = minx; x < maxx; x++) {
                if (g_render_black_and_white) {
                    if (!is_visited(x, y)) {
                        continue;
                    }
                }
                if (likely(!get(tile_map, x, y + 1))) {
                    continue;
                }
                FOR_ALL_THINGS_AT_DEPTH(level, t, x, y, z) {
                    if (g_render_black_and_white) {
                        if (t->is_monst() ||
                            t->owner_get() ||
                            t->get_light_count()) {
                            continue;
                        }
                    }
                    t->blit_upside_down();
                } FOR_ALL_THINGS_END()
            }
        }
    }
    blit_flush();

    /////////////////////////////////////////////////////////////////////
    // Merge the mask and tiles
    /////////////////////////////////////////////////////////////////////
    blit_fbo_bind(FBO_MASK3);
    glClear(GL_COLOR_BUFFER_BIT);
    glcolor(WHITE);
    blit_fbo(FBO_MASK1);
    glBlendFunc(GL_DST_ALPHA, GL_ZERO);
    blit_fbo(FBO_MASK2);

    /////////////////////////////////////////////////////////////////////
    // Create an outline mask
    /////////////////////////////////////////////////////////////////////
    blit_fbo_bind(FBO_MASK4);
    glClear(GL_COLOR_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glcolor(BLACK);
    glTranslatef( 0, -4, 0); blit_fbo(FBO_MASK1); glTranslatef( 0,  4, 0);
    glTranslatef(-2, -2, 0); blit_fbo(FBO_MASK1); glTranslatef( 2,  2, 0);
    glTranslatef( 0, -2, 0); blit_fbo(FBO_MASK1); glTranslatef( 0,  2, 0);
    glTranslatef( 2, -2, 0); blit_fbo(FBO_MASK1); glTranslatef(-2,  2, 0);
    glTranslatef(-2,  0, 0); blit_fbo(FBO_MASK1); glTranslatef( 2,  0, 0);
    glTranslatef( 2,  0, 0); blit_fbo(FBO_MASK1); glTranslatef(-2,  0, 0);
    glTranslatef(-2,  2, 0); blit_fbo(FBO_MASK1); glTranslatef( 2, -2, 0);
    glTranslatef( 0,  2, 0); blit_fbo(FBO_MASK1); glTranslatef( 0, -2, 0);
    glTranslatef( 2,  2, 0); blit_fbo(FBO_MASK1); glTranslatef(-2, -2, 0);
    color c = RED;
    c.a = 200;
    if (g_render_black_and_white) {
        c = BLACK;
    }
    glcolor(c);
    glTranslatef(-1, -1, 0); blit_fbo(FBO_MASK1); glTranslatef( 1,  1, 0);
    glTranslatef( 0, -1, 0); blit_fbo(FBO_MASK1); glTranslatef( 0,  1, 0);
    glTranslatef( 1, -1, 0); blit_fbo(FBO_MASK1); glTranslatef(-1,  1, 0);
    glTranslatef(-1,  0, 0); blit_fbo(FBO_MASK1); glTranslatef( 1,  0, 0);
    glTranslatef( 1,  0, 0); blit_fbo(FBO_MASK1); glTranslatef(-1,  0, 0);
    glTranslatef(-1,  1, 0); blit_fbo(FBO_MASK1); glTranslatef( 1, -1, 0);
    glTranslatef( 0,  1, 0); blit_fbo(FBO_MASK1); glTranslatef( 0, -1, 0);
    glTranslatef( 1,  1, 0); blit_fbo(FBO_MASK1); glTranslatef(-1, -1, 0);

    /////////////////////////////////////////////////////////////////////
    // Create a hole in the middle of the outline mask
    /////////////////////////////////////////////////////////////////////
    glBlendFunc(GL_ONE_MINUS_DST_ALPHA, GL_ONE_MINUS_SRC_COLOR);
    glcolor(BLACK);
    blit_fbo(FBO_MASK3);

    /////////////////////////////////////////////////////////////////////
    // Merge the outline mask and the masked tiles
    /////////////////////////////////////////////////////////////////////
    glcolor(WHITE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    blit_fbo_bind(fbo);
    blit_fbo(FBO_MASK4);
    blit_fbo(FBO_MASK3);
}
