//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_game.h"
#include "my_level.h"
#include "my_thing.h"

bool Thing::throw_item_choose_target (Thingp item)
{_
    log("Trying to use: %s", item->to_string().c_str());

    if (!item->is_throwable()) {
        if (is_player()) {
            TOPCON("I don't know how to throw %s.", item->text_the().c_str());
            game->tick_begin("player tried to use something they could not");
        }
        return false;
    }

    if (!target_select(item)) {
        return false;
    }

    game->request_to_throw_item = item;

    return target_select(item);
}

void Thing::throw_at (Thingp item, Thingp target)
{_
    if (!item) {
        item = game->request_to_throw_item;
    }

    if (!item) {
        return;
    }

    if (DISTANCE(mid_at.x, mid_at.y, target->mid_at.x, target->mid_at.y) >
        get_throw_distance()) {

        if (is_player()) {
            TOPCON("You cannot throw %s that far.", item->text_the().c_str());
        }
        return;
    }

    if (is_player()) {
        TOPCON("You throw %s.", item->text_the().c_str());
    }

    log("Thrown %s", item->to_string().c_str());
    item->move_to_immediately(target->mid_at);
    item->visible();

    //
    // Potions for example are used when thrown. Chocolate frogs, no.
    //
    if (level->is_lava(target->mid_at.x, target->mid_at.y) ||
        level->is_chasm(target->mid_at.x, target->mid_at.y)) {
        drop(item, target);

        item->location_check_forced();
    } else {
        if (item->is_used_when_thrown()) {
            used(item, target, true /* remove_after_use */);
        } else {
            drop(item, target);
        }
    }

    if (is_player()) {
        game->tick_begin("player threw an item");
    }

    if (game->state == Game::STATE_CHOOSING_TARGET) {
        game->change_state(Game::STATE_NORMAL);
    }
}
