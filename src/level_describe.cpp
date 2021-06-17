//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_game.h"
#include "my_tile.h"
#include "my_thing.h"
#include "my_thing_template.h"
#include "my_wid_thing_info.h"
#include "my_wid_inventory.h"
#include "my_wid_bag.h"
#include "my_globals.h"
#include "my_array_bounds_check.h"
#include "my_ptrcheck.h"
#include "my_sdl.h"
#include "my_template.h"

void Level::describe (fpoint p)
{_
    bool got_one_with_long_text = false;

    if (!player) {
        return;
    }

    dbg3("Describe %f,%f", p.x, p.y);

    if ((game->state == Game::STATE_MOVING_ITEMS) || 
        (game->state == Game::STATE_COLLECTING_ITEMS) ||
        (game->state == Game::STATE_ENCHANTING_ITEMS) ||
        (game->state == Game::STATE_CHOOSING_SKILLS)) {
        dbg3("Describe %f,%f; no wrong state", p.x, p.y);
        return;
    }

    std::vector<Thingp> hover_over_things;
    hover_over = nullptr;

    FOR_ALL_ACTIVE_THINGS(this, t, p.x, p.y) {
        int x = p.x;
        int y = p.y;
        if (!is_lit(x, y) && !is_visited(x, y)) {_
            continue;
        }

        //
        // Dead monst clog up the screen
        //
        if (t->is_monst() && t->is_dead) {
            continue;
        }

        if (t->get_immediate_owner() ||
            t->is_cursor() ||
            t->is_player() ||
            t->is_cursor_path() ||
            t->is_the_grid) {
            continue;
        }

        if (t->is_described_when_hovering_over()) {
            t->describe_when_hovering_over();

            if (!t->text_description().empty() ||
                !t->long_text_description().empty()) {
                got_one_with_long_text |= t->long_text_description().empty();
                push_back_if_unique(hover_over_things, t);
            }
        }

        if (!hover_over) {
            hover_over = t;
        }
    } FOR_ALL_THINGS_END()

    FOR_ALL_INTERESTING_THINGS(this, t, p.x, p.y) {
        int x = p.x;
        int y = p.y;
        if (!is_lit(x, y) && !is_visited(x, y)) {_
            continue;
        }

        //
        // Dead monst clog up the screen
        //
        if (t->is_monst() && t->is_dead) {
            continue;
        }

        if (t->get_immediate_owner() ||
            t->is_cursor() ||
            t->is_player() ||
            t->is_cursor_path() ||
            t->is_the_grid) {
            continue;
        }

        if (t->is_described_when_hovering_over()) {
            t->describe_when_hovering_over();

            if (!t->text_description().empty() ||
                !t->long_text_description().empty()) {
                got_one_with_long_text |= t->long_text_description().empty();
                push_back_if_unique(hover_over_things, t);
            }
        }

        if (!hover_over) {
            hover_over = t;
        }
    } FOR_ALL_THINGS_END()

    FOR_ALL_THINGS(this, t, p.x, p.y) {
        int x = p.x;
        int y = p.y;
        if (!is_lit(x, y) && !is_visited(x, y)) {_
            continue;
        }

        //
        // Only show the player as fallback if we have nothing else
        //
        if (hover_over_things.size()) {
            if(t->is_player()) {
                continue;
            }

            //
            // Dead monst clog up the screen. Unless we have nothing else.
            //
            if (t->is_monst() && t->is_dead) {
                continue;
            }
        }

        if (t->get_immediate_owner() ||
            t->is_cursor() ||
            t->is_cursor_path() ||
            t->is_the_grid) {
            continue;
        }

        if (t->is_described_when_hovering_over()) {
            t->describe_when_hovering_over();

            if (!t->text_description().empty() ||
                !t->long_text_description().empty()) {
                got_one_with_long_text |= t->long_text_description().empty();
                push_back_if_unique(hover_over_things, t);
            }
        }

        if (!hover_over) {
            hover_over = t;
        }
    } FOR_ALL_THINGS_END()

    if (!got_one_with_long_text || !hover_over_things.size()) {
        //
        // If we found nothing, then check to see if we are already showing
        // something of interest and if so, keep it.
        //
        dbg3("Describe %f,%f; nothing found", p.x, p.y);
_
        auto o = game->current_wid_thing_info;
        if (o) {
            dbg3("Currently describing %s", o->to_string().c_str()); 
            if (o->is_hidden) {
                dbg3("Currently describing %s; prefer me over current", 
                    o->to_string().c_str());
            }

            //
            // If showing something under the player, then prefer
            // to keep showing that if nothing else.
            //
            if (o->mid_at == player->mid_at) {
                dbg3("Describe %s; prefer me over current", o->to_string().c_str());
                return;
            }
        }

        if (wid_thing_info_window.size()) {
            auto o = wid_thing_info_window.front()->t;
            if (o) {
                dbg3("Describe %s", o->to_string().c_str());
                if (o->is_hidden) {
                    dbg3("Describe %s; prefer me over current", o->to_string().c_str());
                    return;
                }

                if (o->mid_at == player->mid_at) {
                    dbg3("Describe %s; prefer me over current", o->to_string().c_str());
                    return;
                }
            }
        }

        wid_thing_info_fini();
    }

    if (hover_over_things.size()) {
        dbg3("Describe %f,%f; found %d things", p.x, p.y, (int) hover_over_things.size());
        game->wid_thing_info_create_when_hovering_over_list(hover_over_things);
    }
}

void Level::describe (Thingp t)
{_
    if (!t) {
        err("Null thing");
        return;
    }

    dbg3("Describe %s", t->to_string().c_str());

    if ((game->state == Game::STATE_MOVING_ITEMS) || 
        (game->state == Game::STATE_COLLECTING_ITEMS) ||
        (game->state == Game::STATE_ENCHANTING_ITEMS)) {
        dbg3("Describe %s; no wrong state", t->to_string().c_str());
        return;
    }

    if (!t->is_described_when_hovering_over()) {
        dbg3("Describe %s; no not described", t->to_string().c_str());
        return;
    }

    //
    // If we're trying to show the player, then don't do that
    // if we're showing something more interesting from the
    // inventory.
    //
    auto o = game->current_wid_thing_info;
    if (o) {
        dbg3("Currently Describe %s", o->to_string().c_str()); 
        if (o->is_hidden) {
            dbg3("Currently Describe %s; prefer me over current", 
                o->to_string().c_str());
        }

        //
        // If showing something under the player, then prefer
        // to keep showing that if nothing else.
        //
        if (o->mid_at == player->mid_at) {
            dbg3("Describe %s; prefer me over current", o->to_string().c_str());
            return;
        }
    }

    if (wid_thing_info_window.size()) {
        auto o = wid_thing_info_window.front()->t;
        if (o) {
            dbg3("Describe %s", o->to_string().c_str());
            if (o->is_hidden) {
                dbg3("Describe %s; prefer me over current", o->to_string().c_str());
                return;
            }

            if (o->mid_at == player->mid_at) {
                dbg3("Describe %s; prefer me over current", o->to_string().c_str());
                return;
            }
        }
    }

    wid_thing_info_fini();

    if (t->long_text_description().empty()) {
        dbg3("Describe %s; has no text", t->to_string().c_str());
        t->show_botcon_description();
        return;
    }

    std::vector<Thingp> hover_over_things;
    hover_over_things.push_back(t);
    game->wid_thing_info_create_when_hovering_over_list(hover_over_things);
}
