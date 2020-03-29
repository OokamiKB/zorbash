//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include "my_game.h"
#include "my_thing.h"
#include "my_font.h"
#include "my_level.h"

void Thing::blit_wall_cladding (fpoint &tl, fpoint &br, const ThingTiles *tiles)
{_
    double dw = game->config.one_pixel_gl_width;
    double dh = game->config.one_pixel_gl_height;

    int x = (int) at.x;
    int y = (int) at.y;

    if (unlikely(x <= 0) ||
        unlikely(y <= 0) ||
        unlikely(x >= MAP_WIDTH - 1) ||
        unlikely(y >= MAP_HEIGHT - 1)) {
        return;
    }

    if (tiles->tile_top && !level->is_wall(x, y - 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit(tiles->tile_top, tl2, br2);
    }

    if (tiles->tile_bot && !level->is_wall(x, y + 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        double dh = game->config.tile_gl_height;
        tl2.y += dh;
        br2.y += dh;
        tile_blit(tiles->tile_bot, tl2, br2);
    }

    if (tiles->tile_left && !level->is_wall(x - 1, y)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        tile_blit(tiles->tile_left, tl2, br2);
    }

    if (tiles->tile_right && !level->is_wall(x + 1, y)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tile_blit(tiles->tile_right, tl2, br2);
    }

    //
    // X---
    // |...
    // |...
    //
    if (tiles->tile_tl &&
        !level->is_wall(x - 1, y - 1) &&
        !level->is_wall(x - 1, y) &&
        !level->is_wall(x, y - 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit(tiles->tile_tl, tl2, br2);
    }

    //
    // ---X
    // ...|
    // ...|
    //
    if (tiles->tile_tr &&
        !level->is_wall(x + 1, y - 1) &&
        !level->is_wall(x + 1, y) &&
        !level->is_wall(x, y - 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit(tiles->tile_tr, tl2, br2);
    }

    //
    //  .|
    //  .|
    //  .X--
    //  ....
    //
    if (tiles->tile_tr &&
        !level->is_wall(x + 1, y - 1) &&
        level->is_wall(x + 1, y) &&
        level->is_wall(x, y - 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit(tiles->tile_tr, tl2, br2);
    }

    //
    //    |.
    //    |.
    //  --X.
    //  ....
    //
    if (tiles->tile_tl &&
        !level->is_wall(x - 1, y - 1) &&
        level->is_wall(x - 1, y) &&
        level->is_wall(x, y - 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit(tiles->tile_tl, tl2, br2);
    }

    dw = 0.00;
    dh = 0.00;

    //
    // |...
    // |...
    // X---
    //
    if (tiles->tile_bl &&
        !level->is_wall(x - 1, y + 1) &&
        !level->is_wall(x - 1, y) &&
        !level->is_wall(x, y + 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit(tiles->tile_bl, tl2, br2);
    }

    //
    // ...|
    // ...|
    // ---X
    //
    if (tiles->tile_br &&
        !level->is_wall(x + 1, y + 1) &&
        !level->is_wall(x + 1, y) &&
        !level->is_wall(x, y + 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit(tiles->tile_br, tl2, br2);
    }

    //
    // .....
    // .X---
    // .|
    // .|
    //
    if (tiles->tile_br &&
        !level->is_wall(x + 1, y + 1) &&
        level->is_wall(x + 1, y) &&
        level->is_wall(x, y + 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit(tiles->tile_br, tl2, br2);
    }

    //
    // ....
    // --X.
    //   |.
    //   |.
    //
    if (tiles->tile_bl &&
        !level->is_wall(x - 1, y + 1) &&
        level->is_wall(x - 1, y) &&
        level->is_wall(x, y + 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit(tiles->tile_bl, tl2, br2);
    }
}

void Thing::blit_rock_cladding (fpoint &tl, fpoint &br, const ThingTiles *tiles)
{_
    double dw = game->config.one_pixel_gl_width;
    double dh = game->config.one_pixel_gl_height;

    int x = (int) at.x;
    int y = (int) at.y;

    if (unlikely(x <= 0) ||
        unlikely(y <= 0) ||
        unlikely(x >= MAP_WIDTH - 1) ||
        unlikely(y >= MAP_HEIGHT - 1)) {
        return;
    }

    if (tiles->tile_top &&
        !level->is_rock(x, y - 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit(tiles->tile_top, tl2, br2);
    }

    if (tiles->tile_bot &&
        !level->is_rock(x, y + 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit(tiles->tile_bot, tl2, br2);
    }

    if (tiles->tile_left &&
        !level->is_rock(x - 1, y)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        tile_blit(tiles->tile_left, tl2, br2);
    }

    if (tiles->tile_right &&
        !level->is_rock(x + 1, y)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tile_blit(tiles->tile_right, tl2, br2);
    }

    //
    // X---
    // |...
    // |...
    //
    if (tiles->tile_tl &&
        !level->is_rock(x - 1, y - 1) &&
        !level->is_rock(x - 1, y) &&
        !level->is_rock(x, y - 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit(tiles->tile_tl, tl2, br2);
    }

    //
    // ---X
    // ...|
    // ...|
    //
    if (tiles->tile_tr &&
        !level->is_rock(x + 1, y - 1) &&
        !level->is_rock(x + 1, y) &&
        !level->is_rock(x, y - 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit(tiles->tile_tr, tl2, br2);
    }

    //
    //  .|
    //  .|
    //  .X--
    //  ....
    //
    if (tiles->tile_tr &&
        !level->is_rock(x + 1, y - 1) &&
        level->is_rock(x + 1, y) &&
        level->is_rock(x, y - 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit(tiles->tile_tr, tl2, br2);
    }

    //
    //    |.
    //    |.
    //  --X.
    //  ....
    //
    if (tiles->tile_tl &&
        !level->is_rock(x - 1, y - 1) &&
        level->is_rock(x - 1, y) &&
        level->is_rock(x, y - 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit(tiles->tile_tl, tl2, br2);
    }

    dw = 0.00;
    dh = 0.00;

    //
    // |...
    // |...
    // X---
    //
    if (tiles->tile_bl &&
        !level->is_rock(x - 1, y + 1) &&
        !level->is_rock(x - 1, y) &&
        !level->is_rock(x, y + 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit(tiles->tile_bl, tl2, br2);
    }

    //
    // ...|
    // ...|
    // ---X
    //
    if (tiles->tile_br &&
        !level->is_rock(x + 1, y + 1) &&
        !level->is_rock(x + 1, y) &&
        !level->is_rock(x, y + 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit(tiles->tile_br, tl2, br2);
    }

    //
    // .....
    // .X---
    // .|
    // .|
    //
    if (tiles->tile_br &&
        !level->is_rock(x + 1, y + 1) &&
        level->is_rock(x + 1, y) &&
        level->is_rock(x, y + 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit(tiles->tile_br, tl2, br2);
    }

    //
    // ....
    // --X.
    //   |.
    //   |.
    //
    if (tiles->tile_bl &&
        !level->is_rock(x - 1, y + 1) &&
        level->is_rock(x - 1, y) &&
        level->is_rock(x, y + 1)) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit(tiles->tile_bl, tl2, br2);
    }
}

void Thing::blit_non_player_owned_shadow (const Tpp &tpp, const Tilep &tile,
                                          const fpoint &blit_tl,
                                          const fpoint &blit_br)
{_
    fpoint shadow_tl = blit_tl;
    fpoint shadow_br = blit_br;

    float dx = game->config.one_pixel_gl_width;
    float dy = game->config.one_pixel_gl_width;

    color c = BLACK;
    c.a = 100;

    if (level->player) {
        if (get_owner_id() == level->player->id) {
            dx *= -4;
            dy *= -4;
        } else if (this != level->player) {
            fpoint p = level->player->at;
            fpoint d = at - p;
            const double D = 50.0;
            dx = d.x / D;
            dy = d.y / D;

            auto dist = distance(at, p);
            if (dist > 3) {
                return;
            }

            if (dist > 0) {
                float a = 200 - (dist * 100);
                if (a <= 0) {
                    return;
                }
                c.a = (int)a;
            } else {
                c.a = 0;
            }
        }
    } else {
        dx *= -4;
        dy *= -4;
    }

    glcolor(c);

    shadow_tl.x += dx;
    shadow_tl.y += dy;
    shadow_br.x += dx;
    shadow_br.y += dy;

    tile_blit(tile, shadow_tl, shadow_br);

    glcolor(WHITE);
}

void Thing::blit_player_owned_shadow (const Tpp &tpp, const Tilep &tile,
                                      const fpoint &blit_tl,
                                      const fpoint &blit_br)
{_
    fpoint shadow_tl = blit_tl;
    fpoint shadow_br = blit_br;

    float dx = game->config.one_pixel_gl_width;
    float dy = game->config.one_pixel_gl_width;

    color c = BLACK;
    c.a = 100;

    dx *= -4;
    dy *= -4;

    glcolor(c);

    shadow_tl.x += dx;
    shadow_tl.y += dy;
    shadow_br.x += dx;
    shadow_br.y += dy;

    tile_blit(tile, shadow_tl, shadow_br);

    glcolor(WHITE);
}

void Thing::blit_shadow (const Tpp &tpp, const Tilep &tile,
                         const fpoint &blit_tl, const fpoint &blit_br)
{_
    if (unlikely(!game->config.gfx_lights)) {
        return;
    }

    if (unlikely(game->config.gfx_show_hidden)) {
        return;
    }

    if (!level->player) {
        blit_non_player_owned_shadow(tpp, tile, blit_tl, blit_br);
        return;
    }

    if (is_player() || (get_owner_id() == level->player->id)) {
        blit_player_owned_shadow(tpp, tile, blit_tl, blit_br);
    } else {
        blit_non_player_owned_shadow(tpp, tile, blit_tl, blit_br);
    }
}

static int blit_msg_strlen (std::string const& text)
{_
    auto text_iter = text.begin();
    int x = 0;

    while (text_iter != text.end()) {
        auto c = *text_iter;
        text_iter++;

        if (c == '%') {
            if (text_iter != text.end()) {
                if (*text_iter == '%') {
                    text_iter++;
                }
            }

            if (std::string(text_iter, text_iter + 3) == "fg=") {
                text_iter += 3;
                auto tmp = std::string(text_iter, text.end());

                int len = 0;
                (void) string2color(tmp, &len);
                text_iter += len + 1;
                continue;
            } else if (std::string(text_iter, text_iter + 3) == "bg=") {
                text_iter += 3;
                auto tmp = std::string(text_iter, text.end());

                int len = 0;
                (void) string2color(tmp, &len);
                text_iter += len + 1;

                continue;
            } else if (std::string(text_iter, text_iter + 3) == "tp=") {
                text_iter += 3;
                auto tmp = std::string(text_iter, text.end());

                int len = 0;
                (void) string2tp(tmp, &len);
                text_iter += len + 1;

                continue;
            } else if (std::string(text_iter, text_iter + 4) == "tex=") {
                text_iter += 4;
                continue;
            } else if (std::string(text_iter, text_iter + 5) == "tile=") {
                text_iter += 5;
                auto tmp = std::string(text_iter, text.end());

                int len = 0;
                (void) string2tile(tmp, &len);
                text_iter += len + 1;
                continue;
            }
        }

        x++;
    }

    return (x);
}

void Thing::blit_text (std::string const& text,
                       fpoint& blit_tl, fpoint& blit_br)
{_
    Tilep tile;
    auto text_iter = text.begin();
    color fg = WHITE;

// printf("ascii_putf__ [%S]/%ld scissors x %d y %d scissors %d %d %d %d %d\n", text.c_str(), text.size(), x, y, scissors_tl.x, scissors_tl.y, scissors_br.x, scissors_br.y, scissors_enabled);
    tile = nullptr;

    auto a = gl_last_color.a;
    float w = blit_br.x - blit_tl.x;
    float h = blit_br.y - blit_tl.y;
    float cw = w / 4.0;
    float ch = h / 3.0;
    float l = blit_msg_strlen(text);

    blit_tl.x -= cw * (l / 2);
    blit_br.x = blit_tl.x + cw;
    blit_br.y = blit_tl.y + ch;

    while (text_iter != text.end()) {
        auto c = *text_iter;
        text_iter++;

        if (unlikely(c == L'%')) {
            if (std::string(text_iter, text_iter + 3) == "fg=") {
                text_iter += 3;
                auto tmp = std::string(text_iter, text.end());
                int len = 0;
                fg = string2color(tmp, &len);
                text_iter += len + 1;
                continue;
            } else if (std::string(text_iter, text_iter + 3) == "tp=") {
                text_iter += 3;
                auto tmp = std::string(text_iter, text.end());

                int len = 0;
                auto tp = string2tp(tmp, &len);
                text_iter += len;

                tile = tp_first_tile(tp);
                continue;
            } else if (std::string(text_iter, text_iter + 4) == "tex=") {
                text_iter += 4;
                continue;
            } else if (std::string(text_iter, text_iter + 5) == "tile=") {
                text_iter += 5;
                auto tmp = std::string(text_iter, text.end());

                int len = 0;
                tile = string2tile(tmp, &len);
                text_iter += len;
                continue;
            }
            continue;
        }

        tile = fixed_font->unicode_to_tile(c);

        fg.a = a;
        glcolor(fg);
        tile_blit_outline(tile, blit_tl, blit_br);

        tile = nullptr;
        blit_tl.x += cw;
        blit_br.x += cw;
    }
}

void Thing::blit_outline_only (int x, int y)
{_
    fpoint sub_tile_tl, sub_tile_br;
    fpoint blit_tl, blit_br;
    Tilep tile = {};

    if (!blit_check(blit_tl, blit_br, sub_tile_tl, sub_tile_br, tile)) {
        return;
    }

    ThingTiles tiles;
    get_tiles(&tiles);
    tile_blit(tiles.tile_outline, blit_tl, blit_br);
    is_blitted = true;
}

bool Thing::blit_check (fpoint &blit_tl, fpoint &blit_br,
                        fpoint &sub_tile_tl, fpoint &sub_tile_br,
                        Tilep &tile)
{_
    int x = (int)at.x;
    int y = (int)at.y;

    if (unlikely(is_hidden)) {
        return (false);
    }

    if (unlikely(is_cursor() || is_cursor_path())) {
        //
        // Always blit
        //
    } else if (unlikely(game->config.gfx_show_hidden)) {
        if (level->is_visited(x, y)) {
            if (is_wall()) {
                glcolor(RED);
            }
        } else {
            if (is_wall()) {
                glcolor(BLUE);
            }
        }

        if (!level->is_dungeon(x, y)) {
            return (false);
        }
    }

    //
    // We render these offset form their owner, so if dead, then it is
    // likely they also have no owner as the swing has ended.
    //
    auto tpp = tp();

    if (tp_gfx_is_attack_anim(tpp) ||
        tp_gfx_is_weapon_carry_anim(tpp)) {
        if (is_dead) {
            return (false);
        }
    }

    is_in_lava = false;
    is_in_water = false;

    float pixw = 1.0 / (float) game->config.video_pix_width;
    float pixh = 1.0 / (float) game->config.video_pix_height;
    float scale = 4;
    float tilew = pixw * TILE_WIDTH * scale;
    float tileh = pixh * TILE_HEIGHT * scale;

    float X = at.x - level->pixel_map_at.x;
    float Y = at.y - level->pixel_map_at.y;

    blit_tl.x = (float)X * tilew;
    blit_tl.y = (float)Y * tileh;
    blit_br.x = blit_tl.x + tilew;
    blit_br.y = blit_tl.y + tileh;

    //
    // Some things (like messages) have no tiles and so use the default.
    //
    float tile_pix_width = TILE_WIDTH;
    float tile_pix_height = TILE_HEIGHT;
    if (!is_no_tile()) {
        tile = tile_index_to_tile(tile_curr);
        if (!tile) {
            err("has no tile, index %d", tile_curr);
            return (false);
        }
        tile_pix_width = tile->pix_width;
        tile_pix_height = tile->pix_height;
    } else {
        tile = {};
    }

    //
    // Scale up tiles that are larger to the same pix scale.
    //
    if (unlikely((tile_pix_width != TILE_WIDTH) ||
                 (tile_pix_height != TILE_HEIGHT))) {
        auto xtiles = tile_pix_width / TILE_WIDTH;
        blit_tl.x -= ((xtiles-1) * tilew) / 2;
        blit_br.x += ((xtiles-1) * tilew) / 2;

        auto ytiles = tile_pix_height / TILE_HEIGHT;
        blit_tl.y -= ((ytiles-1) * tileh) / 2;
        blit_br.y += ((ytiles-1) * tileh) / 2;
    }

    //
    // Put larger tiles on the same y base as small ones.
    //
    if (unlikely(tp_gfx_oversized_but_sitting_on_the_ground(tpp))) {
        double y_offset =
            (((tile_pix_height - TILE_HEIGHT) / TILE_HEIGHT) * tileh) / 2.0;
        blit_tl.y -= y_offset;
        blit_br.y -= y_offset;
    }

    //
    // Flipping
    //
    if (unlikely(tp_gfx_animated_can_hflip(tpp))) {
        if (get_timestamp_flip_start()) {
            //
            // Slow flip
            //
            auto diff = time_get_time_ms_cached() - get_timestamp_flip_start();
            timestamp_t flip_time = 100;
            timestamp_t flip_steps = flip_time;

            if (diff > flip_time) {
                set_timestamp_flip_start(0);
                is_facing_left = !is_facing_left;
                if (is_dir_left() ||
                    is_dir_tl()   ||
                    is_dir_bl()) {
                    std::swap(blit_tl.x, blit_br.x);
                }
            } else {
                if (is_dir_right() ||
                    is_dir_tr()   ||
                    is_dir_br()) {
                    std::swap(blit_tl.x, blit_br.x);
                }
                double w = blit_br.x - blit_tl.x;
                double dw = w / flip_steps;
                double tlx = blit_tl.x;
                double brx = blit_br.x;

                blit_tl.x = tlx + dw * diff;
                blit_br.x = brx - dw * diff;
                std::swap(blit_tl.x, blit_br.x);
            }
        } else {
            //
            // Fast flip
            //
            if (is_dir_right() || is_dir_tr() || is_dir_br()) {
                std::swap(blit_tl.x, blit_br.x);
            }
        }
    }

    if (unlikely(tp_gfx_animated_can_vflip(tpp))) {
        if (is_dir_down() || is_dir_br() || is_dir_bl()) {
            std::swap(blit_tl.y, blit_br.y);
        }
    }

    //
    // Boing.
    //
    if (unlikely(is_bouncing)) {
        double b = get_bounce();
        blit_tl.y -= (tileh / TILE_HEIGHT) * (int)(b * TILE_HEIGHT);
        blit_br.y -= (tileh / TILE_HEIGHT) * (int)(b * TILE_HEIGHT);
    }

    //
    // Fading.
    //
    double fadeup = get_fadeup();
    if (likely(fadeup == 0)) {
    } else if (fadeup < 0) {
        return (false);
    } else {
        blit_tl.y -= fadeup;
        blit_br.y -= fadeup;
    }

    //
    // If the owner is submerged, so is the weapon
    //
    auto owner = owner_get();
    if (owner && owner->is_in_water) {
        is_in_water = true;
    }

    //
    // Render the weapon and player on the same tile rules
    //
    auto map_loc = at;
    if (owner) {
        map_loc = owner->at;
    }

    sub_tile_tl = fpoint(0, 0);
    sub_tile_br = fpoint(1, 1);

    if (is_monst() ||
        is_player() ||
        tp_gfx_is_on_fire_anim(tpp) ||
        tp_gfx_is_attack_anim(tpp) ||
        tp_gfx_is_weapon_carry_anim(tpp)) {

        set_submerged_offset(0);

        if (level->is_lava((int)map_loc.x, (int)map_loc.y)) {
            is_in_lava = true;
        } else if (level->is_water((int)map_loc.x, (int)map_loc.y)) {
            is_in_water = true;
        }
    }

    last_blit_tl = blit_tl;
    last_blit_br = blit_br;

    return (true);
}

void Thing::blit (void)
{_
    fpoint sub_tile_tl, sub_tile_br;
    fpoint blit_tl, blit_br;
    Tilep tile = {};

    if (!blit_check(blit_tl, blit_br, sub_tile_tl, sub_tile_br, tile)) {
        return;
    }

    auto tpp = tp();
    is_in_lava = false;
    is_in_water = false;

    if (unlikely(tp_gfx_small_shadow_caster(tpp))) {
        blit_shadow(tpp, tile, blit_tl, blit_br);
    }

    if (unlikely(is_msg())) {
        blit_text(get_msg(), blit_tl, blit_br);
    }

    if (unlikely(get_on_fire_anim_id())) {
        static uint32_t ts;
        static color c = WHITE;
        if (time_have_x_tenths_passed_since(1, ts)) {
            ts = time_get_time_ms_cached();
            if (random_range(0, 100) < 10) {
                c = WHITE;
            } else if (random_range(0, 100) < 50) {
                c = ORANGE;
            } else {
                c = RED;
            }
        }
        glcolor(c);
    }

    if (tp_gfx_show_outlined(tpp) && !thing_map_black_and_white) {
        tile_blit_outline(tile, blit_tl, blit_br);
    } else {
        tile_blit(tile, blit_tl, blit_br);
    }

    if (likely(!game->config.gfx_show_hidden)) {
        if (!thing_map_black_and_white) {
            ThingTiles tiles;
            get_tiles(&tiles);

            if (is_wall()) {
                blit_wall_cladding(blit_tl, blit_br, &tiles);
            } else if (is_rock()) {
                blit_rock_cladding(blit_tl, blit_br, &tiles);
            }
        }
    }

    is_blitted = true;
}
