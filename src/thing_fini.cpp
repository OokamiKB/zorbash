//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_game.h"
#include "my_world.h"
#include "my_level.h"
#include "my_depth.h"
#include "my_color.h"
#include "my_dmap.h"
#include "my_sprintf.h"
#include "my_thing.h"
#include "my_monst.h"
#include "my_ptrcheck.h"
#include "my_globals.h"

Thing::~Thing_ (void)
{_
    verify(this);
    destroy();
    oldptr(this);
}

void Thing::destroy (void)
{_
    verify(this);

    if (g_opt_debug2) {
        if (is_loggable_for_important_stuff()) {
            log("destroy");
        }
    }

    if (is_being_destroyed) {
        err("Death recursion in thing destroy");
        return;
    }
    is_being_destroyed = true;

    level_pop();
    level_leave();

    unwield("owner is destroyed");

    //
    // hooks remove must be after unwield
    //
    hooks_remove();

    //
    // Remove any references still to this item
    //
    remove_all_references();

    //
    // Pop from the map
    //
    point old_at((int)mid_at.x, (int)mid_at.y);

    if (is_player()) {
        level->player = nullptr;
    }

    delete_dmap_scent();
    delete_age_map();
    delete_lights();
    delete_particle();

    {
        auto f = level->all_gc_things.find(id);
        if (f != level->all_gc_things.end()) {
            dbg("Remove from gc");
            level->all_gc_things.erase(f);
        }
    }

    game->world.free_thing_id(this);

    if (level->player == this) {
        level->player = nullptr;
    }

    if (level->cursor == this) {
        level->cursor = nullptr;
    }

    if (monstp) {
        oldptr(monstp);
        delete monstp;
    }
}
