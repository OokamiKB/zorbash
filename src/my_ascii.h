//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#pragma once

#include "wchar.h"
#include "my_point.h"
#include "my_tile.h"
#include "my_color.h"

typedef int (*ascii_key_down_callback)(int x, int y, const struct SDL_KEYSYM * key);
typedef int (*ascii_mouse_down_callback)(int x, int y, int button);
typedef int (*ascii_mouse_over_callback)(int x, int y);

struct ascii_ {
    //
    // In ascii mode, where on the ASCII we are
    //
    point mouse_at;
    //
    // UI triggers for ASCII co-ords.
    //
    std::array<std::array<int32_t, 
                    ASCII_HEIGHT_MAX>, ASCII_WIDTH_MAX> sdl_mod {};
    std::array<std::array<int32_t, 
                    ASCII_HEIGHT_MAX>, ASCII_WIDTH_MAX> sdl_key {};
    std::array<std::array<int32_t, 
                    ASCII_HEIGHT_MAX>, ASCII_WIDTH_MAX> mouse_button {};

    //
    // Callbacks for ASCII co-ords.
    //
    std::array<
      std::array<ascii_key_down_callback, ASCII_HEIGHT_MAX>, 
                    ASCII_WIDTH_MAX> key_down {};
    std::array<
      std::array<ascii_mouse_down_callback, ASCII_HEIGHT_MAX>, 
                    ASCII_WIDTH_MAX> mouse_down {};
    std::array<
      std::array<ascii_mouse_over_callback, ASCII_HEIGHT_MAX>, 
                    ASCII_WIDTH_MAX> mouse_over {};
};

extern struct ascii_ ascii;

extern int ASCII_WIDTH;
extern int ASCII_HEIGHT;

void pixel_to_ascii(int *x, int *y);

void ascii_set_bg(int x, int y, Texp, float tx, float ty, float dx, float dy);
void ascii_set_bg(int x, int y, Tilep);
void ascii_set_bg(int x, int y, color c);
void ascii_set_bg(int x, int y, const char *tilename);
void ascii_set_bg(int x, int y, const wchar_t c);
void ascii_set_bg2(int x, int y, Tilep);
void ascii_set_bg2(int x, int y, Tilep, float tx, float ty, float dx, float dy);
void ascii_set_bg2(int x, int y, color c);
void ascii_set_fg(int x, int y, Texp, float tx, float ty, float dx, float dy);
void ascii_set_fg(int x, int y, Tilep);
void ascii_set_fg(int x, int y, color c);
void ascii_set_fg(int x, int y, const char *tilename);
void ascii_set_fg(int x, int y, const wchar_t c);
void ascii_set_fg2(int x, int y, Tilep);
void ascii_set_fg2(int x, int y, Tilep, float tx, float ty, float dx, float dy);
void ascii_set_fg2(int x, int y, color c);

void ascii_dim(int x, int y, int z, float alpha);

void ascii_putf(int x, int y, const wchar_t *fmt, ...);
void ascii_putf(int x, int y, color fg, const wchar_t *fmt, ...);
void ascii_putf(int x, int y, color fg, color bg, const wchar_t *fmt, ...);
void ascii_putf(int x, int y, const std::wstring fmt, ...);
void ascii_putf(int x, int y, color fg, std::wstring fmt, ...);
void ascii_putf(int x, int y, color fg, color bg, std::wstring fmt, ...);
void ascii_putf__(int x, int y, color fg, color bg, std::wstring &text);

void ascii_display(void);

int ascii_tp_tile_tl(int x, int y, fpoint *);
int ascii_tp_tile_br(int x, int y, fpoint *);
int ascii_tp_tile_mid(int x, int y, fpoint *);

void ascii_put_bg_square(int tlx, int tly, int brx, int bry,
                         const char *tilename, color c);
void ascii_put_bg_square(int tlx, int tly, int brx, int bry,
                         wchar_t what, color c);
void ascii_put_bg_square(int tlx, int tly, int brx, int bry,
                         Tilep what, color c);

void ascii_draw_line(int x0, int y0, int x1, int y1, const char *tilename,
                     color c);
void ascii_draw_line(int x0, int y0, int x1, int y1, wchar_t what, color c);
void ascii_draw_line(int x0, int y0, int x1, int y1, Tilep what, color c);

int ascii_strlen(std::wstring &);
int ascii_strlen(std::wstring &buf, std::wstring *col);

void ascii_clear_scissors(void);
void ascii_set_scissors(point tl, point br);

typedef struct {
    int x;
    int y;
    int width;
    int over;

    int sdl_mod;
    int sdl_key;
    int mouse_button;

    color col;

    ascii_key_down_callback key_down;
    ascii_mouse_down_callback mouse_down;
    ascii_mouse_over_callback mouse_over;

    void *context;
} button_args;

typedef struct {
    int x;
    int y;
    int width;
    int height;
    int over;

    int sdl_mod;
    int sdl_key;
    int mouse_button;

    color col_bg;
    color col_text;

    ascii_key_down_callback key_down;
    ascii_mouse_down_callback mouse_down;
    ascii_mouse_over_callback mouse_over;

    void *context;
} box_args;

extern color ascii_get_color(int x, int y, int z);
extern void *ascii_get_context(int x, int y);
extern void ascii_blit_layer(int z, int no_color);
extern void ascii_put_box(box_args b, int style, Tilep bg_tile, Tilep fg_tile, const wchar_t *fmt, ...);
extern void ascii_set_context(int x, int y, void *context);
extern void ascii_shade(void);

static inline int ascii_ok (int x, int y)
{
    if (unlikely(x < 0)) {
        return (false);
    }

    if (unlikely(x >= ASCII_WIDTH)) {
        return (false);
    }

    if (unlikely(y < 0)) {
        return (false);
    }

    if (unlikely(y >= ASCII_HEIGHT)) {
        return (false);
    }

    return (true);
}

static inline int ascii_x_ok (int x)
{
    if (unlikely(x < 0)) {
        return (false);
    }

    if (unlikely(x >= ASCII_WIDTH)) {
        return (false);
    }

    return (true);
}

static inline int ascii_y_ok (int y)
{
    if (unlikely(y < 0)) {
        return (false);
    }

    if (unlikely(y >= ASCII_HEIGHT)) {
        return (false);
    }

    return (true);
}

extern float tile_pix_w;
extern float tile_pix_h;

#define ASCII_CURSOR_UCHAR     L'¦'
