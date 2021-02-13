//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include <SDL.h>

#include "my_sys.h"
#include "my_sdl.h"
#include "slre.h"
#include "my_wid_topcon.h"
#include "my_wid_inventory.h"
#include "my_wid_thing_info.h"
#include "my_wid_thing_collect.h"
#include "my_ttf.h"
#include "my_string.h"
#include "my_wid.h"
#include "my_wid_bag.h"
#include "my_ascii.h"
#include "my_game.h"
#include "my_array_bounds_check.h"
#include "my_vector_bounds_check.h"
#include "my_thing.h"
#include "my_ui.h"

static void wid_topcon_wid_create(void);

Widp wid_topcon_container {};
Widp wid_topcon_vert_scroll {};
Widp wid_topcon_input_line {};
Widp wid_topcon_window {};

static std::wstring last_msg;
static int last_msg_count;

static std::map< unsigned int, std::wstring > wid_topcon_lines;

void wid_topcon_fini (void)
{_
    wid_destroy(&wid_topcon_container);
    wid_destroy(&wid_topcon_vert_scroll);
    wid_destroy(&wid_topcon_input_line);
    wid_destroy(&wid_topcon_window);
}

uint8_t wid_topcon_init (void)
{_
    wid_topcon_wid_create();
    wid_not_visible(wid_topcon_window);

    last_msg = L"";
    last_msg_count = 0;

    return true;
}

//
// Key down etc...
//
static uint8_t wid_topcon_input (Widp w, const SDL_Keysym *key)
{_
    if (!game) {
        return false;
    }

    auto level = game->level;
    if (!level) {
        return false;
    }

    if (key->scancode == (SDL_Scancode)game->config.key_console) {
        return false;
    }

    if (key->scancode == (SDL_Scancode)game->config.key_zoom_out) {
        CON("USERCFG: zoom out");
        config_gfx_zoom_out();
        return true;
    }

    if (key->scancode == (SDL_Scancode)game->config.key_zoom_in) {
        TOPCON("Zoom in");
        config_gfx_zoom_in();
        return true;
    }

    //
    // Events after this cannot be invoked when dead
    //
    auto player = level->player;
    if (player && player->is_dead) {
        return false;
    }

    //
    // Stop rapid pickup/drop events if particles are still in progress
    //
    if (player->particle_anim_exists()) {
        return false;
    }

    if (game->state == Game::STATE_MOVING_ITEMS) {
        if (key->scancode == SDL_SCANCODE_ESCAPE) {
            LOG("Escape pressed, clear moving items flag");
            game->change_state(Game::STATE_NORMAL);
            return true;
        }
    }

    if (game->state == Game::STATE_COLLECTING_ITEMS) {
        if (key->scancode == SDL_SCANCODE_ESCAPE) {
            LOG("Escape pressed, clear collecting items flag");
            game->change_state(Game::STATE_NORMAL);
            return true;
        }
    }

    if (key->scancode == (SDL_Scancode)game->config.key_drop) {
        //
        // Drop whatever we are moving between bags
        //
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            game->change_state(Game::STATE_NORMAL);
            return true;
        }

        if (game->state == Game::STATE_CHOOSING_TARGET) {
            game->change_state(Game::STATE_NORMAL);
            return true;
        }

        if (game->state == Game::STATE_COLLECTING_ITEMS) {
            game->change_state(Game::STATE_NORMAL);
            return true;
        }

        //
        // If we are moving an item, prefer to drop that.
        // Else drop whatever we have highlighted in the inventory
        //
        if (game->in_transit_item) {
            game->change_state(Game::STATE_NORMAL);
        } else {
            game->change_state(Game::STATE_NORMAL);
            auto what = level->inventory_get();
            if (what) {
                if (player->drop(what)) {
                    game->tick_begin("drop");
                }
            }
        }
        wid_inventory_init();
        return true;
    }

    if (key->scancode == (SDL_Scancode)game->config.key_eat) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            game->change_state(Game::STATE_NORMAL);
        }

        if (game->state == Game::STATE_MOVING_ITEMS || 
            game->state == Game::STATE_COLLECTING_ITEMS) {
            return false;
        }
        auto what = level->inventory_get();
        if (what) {
            player->use(what);
        }
        return true;
    }

    if (game->state == Game::STATE_CHOOSING_TARGET) {
        if (key->scancode == SDL_SCANCODE_ESCAPE) {
            LOG("Escape pressed, clear choosing target flag");
            game->change_state(Game::STATE_NORMAL);
            return true;
        }
    }

    if (key->scancode == (SDL_Scancode)game->config.key_load) {
        if (game->state == Game::STATE_CHOOSING_TARGET ||
            game->state == Game::STATE_MOVING_ITEMS || 
            game->state == Game::STATE_COLLECTING_ITEMS) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        CON("USERCFG: loading game");
        game->load_select();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_save) {
        if (game->state == Game::STATE_CHOOSING_TARGET ||
            game->state == Game::STATE_MOVING_ITEMS || 
            game->state == Game::STATE_COLLECTING_ITEMS) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        CON("USERCFG: saving the game");
        game->save_select();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_pause) {
        if (game->state == Game::STATE_CHOOSING_TARGET ||
            game->state == Game::STATE_MOVING_ITEMS || 
            game->state == Game::STATE_COLLECTING_ITEMS) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        TOPCON("Pausing the game");
        CON("USERCFG: pausing the game");
        game->pause_select();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_help) {
        if (game->state == Game::STATE_CHOOSING_TARGET ||
            game->state == Game::STATE_MOVING_ITEMS || 
            game->state == Game::STATE_COLLECTING_ITEMS) {
            return false;
        }
        game->config_keyboard_select();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_quit) {
        if (game->state == Game::STATE_CHOOSING_TARGET ||
            game->state == Game::STATE_MOVING_ITEMS || 
            game->state == Game::STATE_COLLECTING_ITEMS) {
            return false;
        }
        game->quit_select();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_action0) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        level->inventory_chosen(0);
        wid_inventory_init();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_action1) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        level->inventory_chosen(1);
        wid_inventory_init();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_action2) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        level->inventory_chosen(2);
        wid_inventory_init();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_action3) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        level->inventory_chosen(3);
        wid_inventory_init();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_action4) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        level->inventory_chosen(4);
        wid_inventory_init();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_action5) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        level->inventory_chosen(5);
        wid_inventory_init();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_action6) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        level->inventory_chosen(6);
        wid_inventory_init();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_action7) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        level->inventory_chosen(7);
        wid_inventory_init();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_action8) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        level->inventory_chosen(8);
        wid_inventory_init();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_action9) {
        if (game->state == Game::STATE_CHOOSING_TARGET) {
            return false;
        }
        wid_thing_info_fini(); // To remove bag or other info
        level->inventory_chosen(9);
        wid_inventory_init();
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_use) {
        if (game->state == Game::STATE_CHOOSING_TARGET ||
            game->state == Game::STATE_MOVING_ITEMS || 
            game->state == Game::STATE_COLLECTING_ITEMS) {
            return false;
        }
        auto what = level->inventory_get();
        if (what) {
            player->use(what);
        }
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_throw) {
        if (game->state == Game::STATE_CHOOSING_TARGET ||
            game->state == Game::STATE_MOVING_ITEMS || 
            game->state == Game::STATE_COLLECTING_ITEMS) {
            return false;
        }
        auto what = level->inventory_get();
        if (what) {
            player->throw_item(what);
        }
        return true;
    }
    if (key->scancode == (SDL_Scancode)game->config.key_inventory) {
        game->wid_thing_info_create(game->level->player, false);
        game->request_remake_inventory = true;
        game->change_state(Game::STATE_MOVING_ITEMS);
        return true;
    }

    return false;
}

//
// Scroll back to the bottom of the screen.
//
static void wid_topcon_reset_scroll (void)
{_
    if (!wid_topcon_vert_scroll) {
        return;
    }

    wid_move_to_bottom(wid_topcon_vert_scroll);
}

static void wid_topcon_scroll (Widp w, std::wstring str)
{_
    Widp tmp {};

    wid_scroll_text(w);

    //
    // Get the wid on the bottom of the list/screen.
    //
    tmp = wid_get_head(w);
    if (tmp) {
        wid_set_text(tmp, str);
    }
}

static void wid_topcon_replace (Widp w, std::wstring str)
{_
    Widp tmp {};

    //
    // Get the wid on the bottom of the list/screen.
    //
    tmp = wid_get_head(w);
    if (tmp) {
        wid_set_text(tmp, str);
    }
}

//
// Log a message to the topcon
//
static void wid_topcon_log_ (std::wstring s)
{_
    static int32_t log_wid_topcon_buffered_lines;

    wid_topcon_reset_scroll();

    //
    // Before the topcon is ready, we buffer the logs.
    //
    if (!wid_topcon_input_line) {
        auto result = wid_topcon_lines.insert(
                        std::make_pair(log_wid_topcon_buffered_lines++, s));

        if (result.second == false) {
            DIE("Wid topcon lines insert name [%s] failed",
                wstring_to_string(s).c_str());
        }

        return;
    }

    //
    // Flush the logs now the topcon exists.
    //
    wid_topcon_flush();

    if (last_msg == s) {
        s = last_msg + L" (x" + std::to_wstring(last_msg_count + 2) + L")";
        last_msg_count++;
        wid_topcon_replace(wid_topcon_input_line, s);
    } else {
        last_msg = s;
        last_msg_count = 0;
        wid_topcon_scroll(wid_topcon_input_line, s);
    }
}

void wid_topcon_flush (void)
{_
    auto iter = wid_topcon_lines.begin();

    while (iter != wid_topcon_lines.end()) {
        wid_topcon_scroll(wid_topcon_input_line, iter->second);
        iter = wid_topcon_lines.erase(iter);
    }

    wid_topcon_reset_scroll();
}

//
// Log a message to the topcon
//
void wid_topcon_log (std::string s)
{_
    int chars_per_line = UI_TOPCON_WIDTH;

    auto d = split(s, chars_per_line);

    if (d) {
        for (const auto& c : *d) {
            wid_topcon_log_(string_to_wstring(c));
        }
    }
}

//
// Log a message to the topcon
//
void wid_topcon_log (std::wstring s)
{_
    int chars_per_line = UI_TOPCON_WIDTH;

    auto d = split(s, chars_per_line);

    if (d) {
        for (const auto& c : *d) {
            wid_topcon_log_(c);
        }
    }
}

//
// Create the topcon
//
static void wid_topcon_wid_create (void)
{_
    int h = UI_TOPCON_VIS_HEIGHT;

    {
        point tl = make_point(0, 0);
        point br = make_point(UI_TOPCON_VIS_WIDTH - 1, h);

        wid_topcon_window = wid_new_square_window("wid topcon");
        wid_set_name(wid_topcon_window, "wid topcon window");
        wid_set_pos(wid_topcon_window, tl, br);
        wid_set_shape_none(wid_topcon_window);
        wid_set_on_key_down(wid_topcon_window, wid_topcon_input);
    }

    {
        point tl = make_point(0, 0);
        point br = make_point(UI_TOPCON_VIS_WIDTH - 1, h);

        wid_topcon_container = wid_new_container(wid_topcon_window,
                                                  "wid topcon container");
        wid_set_pos(wid_topcon_container, tl, br);
        wid_set_shape_square(wid_topcon_container);
        wid_set_style(wid_topcon_container, 1);
        color c = GRAY;
        c.a = 150;
        wid_set_color(wid_topcon_container, WID_COLOR_BG, c);
    }

  {
        int32_t row;
        int row_bottom = h - 1;

        Widp child {};
        Widp prev {};

        for (row = 0; row < UI_TOPCON_HEIGHT; row++) {
            row_bottom --;
            point tl = make_point(0, row_bottom);
            point br = make_point(UI_TOPCON_WIDTH, row_bottom);

            child = wid_new_container(wid_topcon_container, "");

            wid_set_shape_none(child);
            wid_set_pos(child, tl, br);
            wid_set_text_lhs(child, true);

            wid_set_prev(child, prev);
            prev = child;

            if (row == 0) {
                wid_topcon_input_line = child;
            }

            wid_set_color(child, WID_COLOR_TEXT_FG, UI_TOPCON_TEXT_COLOR);
            wid_set_color(child, WID_COLOR_BG, COLOR_NONE);
            wid_set_name(child, "topcon output");
        }

        wid_raise(wid_topcon_input_line);
    }

    wid_topcon_vert_scroll =
        wid_new_vert_scroll_bar(wid_topcon_window, "", wid_topcon_container);

    wid_visible(wid_get_parent(wid_topcon_vert_scroll));

    wid_update(wid_topcon_window);
}

std::vector<std::wstring> wid_topcon_serialize (void)
{_
    std::vector<std::wstring> r;
    auto tmp = wid_get_head(wid_topcon_input_line);
    while (tmp) {
        auto s = wid_get_text(tmp);
        if (s.size()) {
            r.push_back(wid_get_text(tmp));
        }
        tmp = wid_get_next(tmp);
    }
    std::reverse(r.begin(), r.end());
    return (r);
}

void wid_topcon_deserialize(std::vector<std::wstring> r)
{_
    for (const auto& s : r) {
        auto tmp = wstring_to_string(s);
        if (tmp.size()) {
            TOPCON("%s", tmp.c_str());
        }
    }
}