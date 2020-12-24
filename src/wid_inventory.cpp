//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_game.h"
#include "my_wid_inventory.h"
#include "my_wid_thing_info.h"
#include "my_thing.h"

static void wid_inventory_create(void);

Widp wid_inventory_window {};

void wid_inventory_fini (void)
{_
    if (game->remake_inventory) {
        //
        // continue
        //
    } else {
        if (game->moving_items) {
            return;
        }
    }

    wid_destroy(&wid_inventory_window);
    if (wid_inventory_window) {
        DIE("wid_inventory_window exists after destroy");
    }
}

uint8_t wid_inventory_init (void)
{_
    wid_inventory_create();

    return true;
}

static void wid_inventory_mouse_over_b (Widp w, int32_t relx, int32_t rely, int32_t wheelx, int32_t wheely)
{
    if (game->moving_items) {
        return;
    }

    if (game->paused()) {
        return;
    }

    auto level = game->level;
    if (!level) {
        return;
    }

    auto slot = wid_get_int_context(w);
    if (!level->inventory_over(slot)) {
        return;
    }

    level->inventory_describe(slot);

    auto t = level->inventory_get(slot);
    if (t) {
        game->wid_thing_info_create(t);
    }
}

static void wid_inventory_mouse_over_e (Widp w)
{
    if (game->moving_items) {
        return;
    }

    if (game->paused()) {
        return;
    }

    auto level = game->level;
    if (!level) {
        return;
    }

    auto slot = wid_get_int_context(w);
    if (!level->inventory_over(slot)) {
        return;
    }

    game->wid_thing_info_destroy();

    //
    // Do not create new wids in here
    //
}

static uint8_t wid_inventory_mouse_down_on_bag (Widp w,
                                                int32_t x,
                                                int32_t y,
                                                uint32_t button)
{_
    BOTCON("Press %%fg=red$ESCAPE%%fg=reset$ when done moving items around.");
    game->moving_items = true;
MINICON("NOT MOVING ITEMS %s", __FUNCTION__);
    return true;
}

static uint8_t wid_inventory_mouse_down (Widp w,
                                         int32_t x,
                                         int32_t y,
                                         uint32_t button)
{_
    if (game->moving_items) {
        wid_thing_info_fini();
    }

    if (game->paused()) {
        return false;
    }

    auto level = game->level;
    if (!level) {
        return true;
    }

    auto slot = wid_get_int_context(w);
    if (!level->inventory_chosen(slot)) {
        return true;
    }

    level->inventory_describe(slot);

    auto t = level->inventory_get(slot);
    if (t) {
        game->wid_thing_info_create(t);
    }

    return true;
}

//
// Create the test
//
static void wid_inventory_create (void)
{_
    if (game->remake_inventory) {
        //
        // continue
        //
    } else {
        if (game->moving_items) {
            return;
        }
    }

    auto level = game->level;
    if (!level) {
        return;
    }
    auto player = level->player;
    if (!player) {
        return;
    }

    //
    // Stop this window popping on top of dialogs like when setting keys
    //
    if (game->paused()) {
        return;
    }

    static bool recursion;
    if (recursion) {
        DIE("recursion");
    }
    recursion = true;

    wid_inventory_fini();

    {

        {_
            auto x1 = TERM_WIDTH - UI_SIDEBAR_RIGHT_WIDTH;
            auto x2 = TERM_WIDTH - 1;
            point tl = make_point(x1, TERM_HEIGHT - 22);
            point br = make_point(x2, TERM_HEIGHT - 1);
            color c;

            if (wid_inventory_window) {
                DIE("wid_inventory_window exists");
            }
            wid_inventory_window = wid_new_square_window("wid inventory");
            wid_set_pos(wid_inventory_window, tl, br);
            wid_set_style(wid_inventory_window, UI_WID_STYLE_NONE);
        }
    }

    {
        auto monstp = player->monstp;
        auto inventory_items = monstp->inventory_id.size();
        std::vector<Widp> wid_inventory_items;

        uint8_t item = 0;
        uint8_t y = 0;
        for (auto i = 0U; i < UI_ACTIONBAR_MAX_ITEMS; i++) {
            if (item >= inventory_items) {
                break;
            }

            //
            // slot number
            //
            auto slot(std::to_string(i));

            if (item < monstp->inventory_id.size()) {
                auto tp_id = get(monstp->inventory_id, item);
                if (tp_id) {
                    auto tpp = tp_find(tp_id);
                    auto tiles = &tpp->tiles;

                    if (tiles) {
                        auto tile = tile_first(tiles);
                        if (tile) {
                            auto s = "inventory icon" + std::to_string(i);
                            auto w = wid_new_square_button(wid_inventory_window, s);
                            point tl = make_point(0, y);
                            point br = make_point(0, y);

                            wid_set_pos(w, tl, br);

                            wid_set_fg_tile(w, tile);
                        }
                    }
                }
            }

            {
                auto name = "inventory slot" + slot;
                auto w = wid_new_square_button(wid_inventory_window, name);
                point tl = make_point(1, y);
                point br = make_point(1, y);
                wid_set_pos(w, tl, br);

                if (i == game->inventory_highlight_slot) {
                    wid_set_color(w, WID_COLOR_TEXT_FG, GRAY60);
                } else {
                    wid_set_color(w, WID_COLOR_TEXT_FG, GRAY40);
                }

                wid_set_text(w, std::to_string(item));
            }

            {
                {
                    auto w = wid_new_square_button(wid_inventory_window, "inventory item");
                    wid_inventory_items.push_back(w);
                    point tl = make_point(3, y);
                    point br = make_point(UI_SIDEBAR_RIGHT_WIDTH, y);

                    wid_set_pos(w, tl, br);
                    wid_set_text_lhs(w, true);

                    if (i == game->inventory_highlight_slot) {
                        wid_set_color(w, WID_COLOR_TEXT_FG, WHITE);
                    } else {
                        wid_set_color(w, WID_COLOR_TEXT_FG, GRAY);
                    }

                    wid_set_on_mouse_over_b(w, wid_inventory_mouse_over_b);
                    wid_set_on_mouse_over_e(w, wid_inventory_mouse_over_e);
                    wid_set_int_context(w, i);

                    if (item < inventory_items) {
                        auto tp_id = monstp->inventory_id[i];
                        if (tp_id) {
                            auto tpp = tp_find(tp_id);
                            wid_set_text(w, tpp->text_name());
                            if (tpp->is_bag()) {
                                wid_set_on_mouse_down(w, wid_inventory_mouse_down_on_bag);
                            } else {
                                wid_set_on_mouse_down(w, wid_inventory_mouse_down);
                            }
                        }
                    } else {
                        wid_set_text(w, "-");
                    }
                }
            }

            {
                if (item < inventory_items) {
                    auto count = player->inventory_id_slot_count(i);
                    if (count > 1) {
                        y++;
                        auto w = wid_new_square_button(wid_inventory_window, 
                                                       "inventory count");
                        auto text = "x" + std::to_string(count);
                        point tl = make_point(UI_SIDEBAR_RIGHT_WIDTH - text.size(), y);
                        point br = make_point(UI_SIDEBAR_RIGHT_WIDTH - 1, y);
                        wid_set_pos(w, tl, br);
                        wid_set_color(w, WID_COLOR_TEXT_FG, LIGHTBLUE);
                        wid_set_text(w, text);
                    }
                }
            }

            auto weapon = player->weapon_get();
            if (weapon) {
                auto weapon_tp_id = weapon->tp()->id;
                if (item < inventory_items) {
                    auto tp_id = monstp->inventory_id[i];
                    if (tp_id == weapon_tp_id) {
                        auto w = wid_new_square_button(wid_inventory_window, "inventory weapon");
                        point tl = make_point(2, y);
                        point br = make_point(2, y);
                        wid_set_pos(w, tl, br);

                        static Tilep tile;
                        if (!tile) {
                            tile = tile_find_mand("right-hand");
                        }
                        wid_set_fg_tile(w, tile);

                        y++;

                        {
                            auto w = wid_new_square_button(wid_inventory_window, 
                                                           "wid wielded");
                            point tl = make_point(1, y);
                            point br = make_point(UI_SIDEBAR_RIGHT_WIDTH - 1, y);
                            wid_set_pos(w, tl, br);
                            wid_set_color(w, WID_COLOR_TEXT_FG, YELLOW);
                            wid_set_text(w, "(wielded)");
                            wid_set_on_mouse_over_b(w, wid_inventory_mouse_over_b);
                            wid_set_on_mouse_over_e(w, wid_inventory_mouse_over_e);
                            wid_set_int_context(w, i);
                        }
                    }
                }
            }
            y++;
            item++;
        }

        wid_update(wid_inventory_window);
    }
    recursion = false;

    if (game->remake_inventory) {
        auto slot = game->inventory_highlight_slot;
        auto t = level->inventory_get(slot);
        if (t) {
            game->wid_thing_info_create(t);
        }
    }
}

bool is_mouse_over_inventory (void)
{
    extern Widp wid_inventory_window;

    if (!wid_inventory_window) {
        return false;
    }

    //
    // If we are in the portion of the lower screen above the itembar
    // then do not scroll
    //
    int x = mouse_x;
    int y = mouse_y;
    pixel_to_ascii(&x, &y);

    static int tlx, tly, brx, bry, cached;
    if (cached != TERM_HEIGHT) {
        cached = TERM_HEIGHT;
    }

    wid_get_tl_x_tl_y_br_x_br_y(wid_inventory_window, &tlx, &tly, &brx, &bry);

    //
    // Add some border
    //
    tlx -= 1;
    brx += 1;
    tly -= 1;
    bry += 1;

    if ((x >= tlx) && (x < brx) && (y >= tly)) {
        //CON("    inventory %d %d %d", tlx, brx, x);
        return true;
    }
    //CON("NOT inventory %d %d %d", tlx, brx, x);

    return false;
}
