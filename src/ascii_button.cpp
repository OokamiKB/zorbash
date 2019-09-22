/*
 * Copyright goblinhack@gmail.com
 * See the README file for license info.
 */

#include "my_time.h"
#include "my_ascii.h"

static void ascii_put_button_ (int x,
                               int y,
                               int width,
                               color col_tl,
                               color col_mid,
                               color col_br,
                               void *context,
                               const wchar_t *fmt,
                               va_list args)
{_
    wchar_t buf[MAXSHORTSTR];

    if (!width) {
        return;
    }

    assert(fmt);

    auto wrote = vswprintf(buf, MAXSHORTSTR, fmt, args);

    /*
     * Only a single nul is written, but as we read 2 at a time...
     */
    if (wrote && (wrote < MAXSHORTSTR - 1)) {
        buf[wrote+1] = '\0';
    }

    auto b = std::wstring(buf);
    int len = ascii_strlen(b);
    auto c = L'▋';

    ascii_put_shaded_line(x, x + width, y, c, col_tl, col_mid, col_br, context);

    ascii_putf__(x + ((width - len) / 2), y, WHITE, COLOR_NONE, b);
}

void ascii_put_button (button_args b, const wchar_t *fmt, ...)
{_
    va_list args;

    if ((b.col_tl == COLOR_NONE) &&
        (b.col_mid == COLOR_NONE) &&
        (b.col_br == COLOR_NONE)) {

        b.col_tl = WHITE;
        b.col_mid = WHITE;
        b.col_br = WHITE;
    }

    int x = b.x;
    int y = b.y;
    int w = b.width;

    /*
     * Mouse over button
     */
#ifdef UNUSED
    int over = false;

    if ((ascii.mouse_at.y == y) &&
        (ascii.mouse_at.x >= x) && (ascii.mouse_at.x <= x + w)) {
        over = true;
    }
#endif

    /*
     * Draw the button
     */
    va_start(args, fmt);

    ascii_put_button_(b.x,
                      b.y,
                      b.width,
                      b.col_tl,
                      b.col_mid,
                      b.col_br,
                      b.context,
                      fmt,
                      args);

    va_end(args);

    /*
     * Populate the ascii callbacks for this button.
     */

    if (w) while (w--) {

        if (!ascii_ok(x, y)) {
            x++;
            continue;
        }

        set(ascii.sdl_mod, x, y, b.sdl_mod);
        set(ascii.sdl_key, x, y, b.sdl_key);
        set(ascii.mouse_button, x, y, b.mouse_button);

        /*
         * Callbacks for ascii co-ords.
         */
        set(ascii.key_down, x, y, b.key_down);
        set(ascii.mouse_down, x, y, b.mouse_down);
        set(ascii.mouse_over, x, y, b.mouse_over);

        x++;
    }
}
