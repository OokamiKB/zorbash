//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_game.h"
#include "my_depth.h"
#include "my_wid_console.h"
#include "my_sdl.h"
#include "my_ascii.h"
#include "my_wid.h"
#include "my_thing.h"
#include "my_monst.h"
#include "my_dmap.h"
#include "my_array_bounds_check.h"
#include "my_ptrcheck.h"

bool Thing::cursor_path_pop_next_and_move (void)
{_
    if (monstp && monstp->move_path.size()) {
        if (unlikely(g_opt_debug3)) {
            std::string s = "";
            for (auto p : monstp->move_path) {
                s += p.to_string() + " ";
            }
            log("Move path: %s", s.c_str());
        }

        auto to = monstp->move_path[0];
        auto future_pos = fpoint(to.x, to.y);

        FOR_ALL_CURSOR_PATH_THINGS(level, t, to.x, to.y) {
            t->dead("by end of life");
        } FOR_ALL_THINGS_END()

	//
	// Just in case the cursor next hop ends up too far away
	// for a single move, then reset it.
	//
        if ((fabs(to.x - mid_at.x) > 1) || (fabs(to.x - mid_at.x) > 1)) {
	    clear_move_path("Cursor next-hop is too far away");
	    return false;
        }

        monstp->move_path.erase(monstp->move_path.begin());

        //
        // If in robot mode, or player mode? jump over obstacles if they
        // appear in the path
        //
        if (is_player() && game->robot_mode) {
            if (will_avoid_threat(future_pos)) {
                log("Next position %d,%d is a threat",
                    (int)future_pos.x, (int)future_pos.y);
_
                if (monstp->move_path.size()) {
                    auto jump_pos = monstp->move_path[0];
                    monstp->move_path.erase(monstp->move_path.begin());

                    //
                    // If the thing we are going to land on is also a threat,
                    // can we jump further?
                    //
                    log("Next next position %d,%d is also a threat",
                        (int)future_pos.x, (int)future_pos.y);
_
                    if (will_avoid_threat(jump_pos) && monstp->move_path.size()) {
                        auto jump_pos = monstp->move_path[0];
                        monstp->move_path.erase(monstp->move_path.begin());

                        if (will_avoid_threat(jump_pos)) {
                            //
                            // Give up
                            //
                            clear_move_path("Cannot jump over all threats");
                            return false;
                        } else if (try_to_jump(jump_pos)) {
                            game->tick_begin("player tried a long jump");
                            clear_move_path("Player tried a long jump");
                            return true;
                        } else {
                            clear_move_path("Player tried a jump but cannot pass");
                            return false;
                        }
                    } else if (try_to_jump(jump_pos)) {
                        game->tick_begin("player tried to jump");
                        clear_move_path("Player tried to jump");
                        return true;
                    } else {
                        clear_move_path("Player cannot pass");
                        return false;
                    }
                }
            }
        }

        if (move_no_shove(future_pos)) {
            return true;
        }
    }
    return false;
}

//
// true on having performed an action
//
bool Thing::cursor_path_pop_first_move (void)
{_
    auto cursor = level->cursor;

    if (game->cursor_move_path.size()) {
        dbg("Cursor path exists");

        //
        // A path to the target exists.
        //
        new_monst();
        monstp->move_path = game->cursor_move_path;
        game->cursor_move_path.clear();

        if (cursor_path_pop_next_and_move()) {
            dbg("Move to cursor next hop");
            if (game->cursor_move_path.empty()) {
                level->cursor_path_create();
            }
            return true;
        }

        //
        // We get here if for example we click on a monster but
        // are unable to move into its cell because it blocks
        //
        // Or we click on a locked door and cannot pass through.
        //
        dbg("Failed to move to cursor next hop");
        level->cursor_path_create();
        return false;
    }

    //
    // A path to the target does not exist. Jump?
    //
    point future_pos = make_point(cursor->mid_at.x,
                                  cursor->mid_at.y);

    //
    // If adjacent, try to move there. There may be no path
    // because perhaps a monster just moved but now we can
    // step there.
    //
    if ((fabs(future_pos.x - mid_at.x) <= 1) &&
        (fabs(future_pos.y - mid_at.y) <= 1)) {
        dbg("Target is adjacent, attack or move to %f,%F",
            cursor->mid_at.x, cursor->mid_at.y);
        attack(cursor->mid_at);
        level->cursor_path_create();
        return true;
    }

    //
    // If not adjacent, try and jump.
    //
    if (try_to_jump(future_pos)) {
        game->tick_begin("player tried to jump");
        return true;
    }

    //
    // Jump failed. Maybe too tired?
    //
    // game->tick_begin("not sure about this one");
    return false;
}
