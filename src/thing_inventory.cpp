//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_game.h"
#include "my_level.h"
#include "my_thing.h"
#include "my_wid_inventory.h"
#include "my_wid_thing_info.h"
#include "my_random.h"
#include "my_monst.h"
#include "my_array_bounds_check.h"
#include "my_vector_bounds_check.h"
#include "my_ui.h"

void Thing::inventory_particle (Thingp item, uint32_t slot)
{_
    log("Inventory particle %s", item->to_string().c_str());
_
    //
    // No animations at the start
    //
    if (level->is_starting) {
        log("Not while starting the level");
        return;
    }

    if (item->is_item_collected_as_gold()) {
        std::string name = "gold and keys";
        auto w = wid_find(name);
        if (!w) {
            err("Could not find wid %s", name.c_str());
            return;
        }

        auto p = (w->abs_tl + w->abs_br) / 2;
        p.x = (int)(((float)game->config.game_pix_width / (float)TERM_WIDTH) * (float)p.x);
        p.y = (int)(((float)game->config.game_pix_height / (float)TERM_HEIGHT) * (float)p.y);

        int value = item->get_gold_value();
        int particle_count;
        if (is_gold()) {
            particle_count = value;
        } else {
            particle_count = 1;
        }

        auto player = level->player;
        if (player) {
            player->incr_score(value * 10);
            player->incr_gold(value);
        }

        for (int c = 0; c < particle_count; c++) {
            point s = (last_blit_tl + last_blit_br) / 2;
            point j(random_range(0, TILE_WIDTH) - TILE_WIDTH / 2,
                    random_range(0, TILE_HEIGHT) - TILE_HEIGHT / 2);
            std::string name = "gold." + std::to_string(random_range(1, 8));
            level->new_external_particle(
                     s + j, p,
                     isize(TILE_WIDTH / 2, TILE_HEIGHT / 2), 
                     PARTICLE_SPEED_MS,
                     tile_find_mand(name), false,
                     false /* make_visible_at_end */);
        }
        return;
    }

    if (item->is_collect_as_keys()) {
        std::string name = "gold and keys";
        auto w = wid_find(name);
        if (!w) {
            err("Could not find wid %s", name.c_str());
            return;
        }

        auto p = (w->abs_tl + w->abs_br) / 2;
	p.x = (int)(((float)game->config.game_pix_width / (float)TERM_WIDTH) * (float)p.x);
	p.y = (int)(((float)game->config.game_pix_height / (float)TERM_HEIGHT) * (float)p.y);

        point s = (last_blit_tl + last_blit_br) / 2;
        point j(random_range(0, TILE_WIDTH) - TILE_WIDTH / 2,
                random_range(0, TILE_HEIGHT) - TILE_HEIGHT / 2);

        std::string tile_name = "key.1";
        level->new_external_particle(
                 s + j, p,
                 isize(TILE_WIDTH / 2, TILE_HEIGHT / 2), 
                 PARTICLE_SPEED_MS,
                 tile_find_mand(tile_name), false,
                 false /* make_visible_at_end */);
        return;
    }

    {
        std::string name = "inventory slot" + std::to_string(slot);
        auto w = wid_find(name);
        if (!w) {
            err("Could not find wid %s", name.c_str());
            return;
        }

        auto p = (w->abs_tl + w->abs_br) / 2;
        p.x = (int)(((float)game->config.game_pix_width / (float)TERM_WIDTH) * (float)p.x);
        p.y = (int)(((float)game->config.game_pix_height / (float)TERM_HEIGHT) * (float)p.y);

        level->new_external_particle(
                 item->id,
                 (last_blit_tl + last_blit_br) / 2, p,
                 isize(TILE_WIDTH, TILE_HEIGHT), 
                 PARTICLE_SPEED_MS,
                 tile_index_to_tile(item->tile_curr),
                 (item->is_dir_br() || item->is_dir_right() || item->is_dir_tr()),
                 false /* make_visible_at_end */);
    }
}

//
// Particle from the inventory to tp_id target
//
void Thing::inventory_particle (Thingp item, 
                                uint32_t slot, 
                                Thingp particle_target)
{_
    log("Inventory particle %s with target %s",
        item->to_string().c_str(), particle_target->to_string().c_str());
_
    if (game->state == Game::STATE_MOVING_ITEMS || 
        game->state == Game::STATE_COLLECTING_ITEMS) {
        //
        // No animations when moving stuff around
        //
        return;
    }

    //
    // No animations at the start
    //
    if (level->is_starting) {
        return;
    }

    //
    // We can throw from the inventory or from the player. I think it
    // looks better to throw from the player.
    //
    bool throw_from_inventory = false;
    point where_from;

    if (throw_from_inventory) {
        std::string name = "inventory slot" + std::to_string(slot);
        auto w = wid_find(name);
        if (!w) {
            err("Could not find wid %s", name.c_str());
            return;
        }

        where_from = (w->abs_tl + w->abs_br) / 2;
        where_from.x = (int)(((float)game->config.game_pix_width / 
                             (float)TERM_WIDTH) * (float)where_from.x);
        where_from.y = (int)(((float)game->config.game_pix_height / 
                             (float)TERM_HEIGHT) * (float)where_from.y);
    } else {
        where_from = (last_blit_tl + last_blit_br) / 2;
    }

    point where_to = (particle_target->last_blit_tl +
                      particle_target->last_blit_br) / 2;


    level->new_external_particle(item->id, where_from, where_to,
                                 isize(TILE_WIDTH, TILE_HEIGHT), 
                                 PARTICLE_SPEED_MS,
                                 tile_index_to_tile(item->tile_curr),
                                 (item->is_dir_br() || 
                                  item->is_dir_right() || 
                                  item->is_dir_tr()),
                                 true /* make_visible_at_end */);
}

bool Thing::inventory_id_insert (Thingp item)
{_
    log("Inventory insert %s", item->to_string().c_str());
_
    auto player = level->player;
    if (!player) {
        return false;
    }

    if (!is_player()) {
        return false;
    }

    if (!monstp) {
        return false;
    }

    if (item->is_item_collected_as_gold()) {
        wid_inventory_init();
        wid_thing_info_fini();
        inventory_particle(item, monstp->inventory_id.size() - 1);
        item->dead("by being collected");

        //
        // If we just picked up some gold snd other items are on the
        // ground that are not auto collected, then describe them
        //
        if (game->state == Game::STATE_NORMAL) {
            if (is_player()) {
                level->describe(mid_at);
            }
        }

        return false;
    }

    if (item->is_collect_as_keys()) {
        wid_inventory_init();
        wid_thing_info_fini();
        incr_keys(1);
        inventory_particle(item, monstp->inventory_id.size() - 1);
        item->dead("by being collected");

        //
        // If we just picked up some keys snd other items are on the
        // ground that are not auto collected, then describe them
        //
        if (game->state == Game::STATE_NORMAL) {
            if (is_player()) {
                level->describe(mid_at);
            }
        }

        return false;
    }

    int free_slot = -1;
    auto inventory_items = player->monstp->inventory_id.size();
    for (auto i = 0U; i < inventory_items; i++) {
        auto tp_id = monstp->inventory_id[i];
        if (!tp_id) {
            if (free_slot == -1) {
                free_slot = i;
            }
            continue;
        }

        auto tpp = tp_find(tp_id);
        if (!tpp) {
            continue;
        }

        if (item->tp() == tpp) {
            if (item->is_item_not_stackable()) {
                //
                // Needs its own slot
                //
            } else {
                wid_inventory_init();
                if (game->state != Game::STATE_CHOOSING_TARGET &&
                    game->state != Game::STATE_MOVING_ITEMS &&
                    game->state != Game::STATE_COLLECTING_ITEMS) {
                    wid_thing_info_fini();
                }
                inventory_particle(item, i);
                return true;
            }
        }
    }

    int item_slot = -1;
    if (free_slot != -1) {
        monstp->inventory_id[free_slot] = item->tp_id;
        item_slot = free_slot;
    } else {
        if (inventory_items >= UI_ACTIONBAR_MAX_ITEMS) {
            TOPCON("No space to carry %s.",
                    item->text_the().c_str());
            return false;
        }

        monstp->inventory_id.push_back(item->tp_id);
        item_slot = monstp->inventory_id.size() - 1;
    }

    game->previous_slot = item_slot;

    wid_inventory_init();
    if (game->state != Game::STATE_CHOOSING_TARGET &&
        game->state != Game::STATE_MOVING_ITEMS &&
        game->state != Game::STATE_COLLECTING_ITEMS) {
        wid_thing_info_fini();
    }

    inventory_particle(item, item_slot);
    level->inventory_describe(item_slot);

    return true;
}

bool Thing::inventory_id_remove (Thingp item)
{_
    log("Inventory remove %s", item->to_string().c_str());
_
    auto player = level->player;
    if (!player) {
        return false;
    }

    if (!is_player()) {
        return false;
    }

    if (!monstp) {
        return false;
    }

    auto immediate_owner = item->get_immediate_owner();
    if (immediate_owner) {
        immediate_owner->bag_remove(item);
    }

    auto inventory_items = player->monstp->inventory_id.size();
    for (auto i = 0U; i < inventory_items; i++) {
        auto tp_id = monstp->inventory_id[i];
        if (!tp_id) {
            continue;
        }
        auto tpp = tp_find(tp_id);
        if (!tpp) {
            continue;
        }

        if (item->tp() == tpp) {
            game->request_remake_inventory = true;

            inventory_particle(item, i, this);

            auto cnt = item_slot_count(i);
            log("Remove slot %d, count %d", i, cnt);
            if (cnt > 1) {_
                log("Decrement slot count");
            } else {_
                log("Remove slot");
                monstp->inventory_id[i] = 0;

                if (!monstp->inventory_id.size()) {
                    game->inventory_highlight_slot = {};
                } else {
                    while (game->inventory_highlight_slot >= 
                        monstp->inventory_id.size()) {
                        game->inventory_highlight_slot--;
                    }
                }
            }

            level->inventory_describe(game->inventory_highlight_slot);
            wid_inventory_init();
            if (game->state != Game::STATE_CHOOSING_TARGET &&
                game->state != Game::STATE_MOVING_ITEMS && 
                game->state != Game::STATE_COLLECTING_ITEMS) {
                wid_thing_info_fini();
            }
            return true;
        }
    }
    return false;
}

bool Thing::inventory_id_remove (Thingp item, Thingp particle_target)
{_
    log("Inventory remove %s with target %s",
        item->to_string().c_str(), particle_target->to_string().c_str());
_
    auto player = level->player;
    if (!player) {
        return false;
    }

    if (!is_player()) {
        return false;
    }

    if (!monstp) {
        return false;
    }

    auto immediate_owner = item->get_immediate_owner();
    if (immediate_owner) {
        immediate_owner->bag_remove(item);
    }

    auto inventory_items = player->monstp->inventory_id.size();
    for (auto i = 0U; i < inventory_items; i++) {
        auto tp_id = monstp->inventory_id[i];
        if (!tp_id) {
            continue;
        }
        auto tpp = tp_find(tp_id);
        if (!tpp) {
            continue;
        }

        if (item->tp() == tpp) {
            game->request_remake_inventory = true;

            if (particle_target) {
                inventory_particle(item, i, particle_target);
            }

            auto cnt = item_slot_count(i);
            log("Remove slot %d, count %d", i, cnt);
            if (cnt > 1) {_
                log("Decrement slot count");
            } else {_
                log("Remove slot");
                monstp->inventory_id.erase(monstp->inventory_id.begin() + i);

                if (!monstp->inventory_id.size()) {
                    game->inventory_highlight_slot = {};
                } else {
                    while (game->inventory_highlight_slot >= 
                        monstp->inventory_id.size()) {
                        game->inventory_highlight_slot--;
                    }

                    level->inventory_describe(game->inventory_highlight_slot);
                }
            }

            wid_inventory_init();
            if (game->state != Game::STATE_CHOOSING_TARGET &&
                game->state != Game::STATE_MOVING_ITEMS &&
                game->state != Game::STATE_COLLECTING_ITEMS) {
                wid_thing_info_fini();
            }
            return true;
        }
    }

    return false;
}

int Thing::item_slot_charge_count (const uint32_t slot)
{_
    if (!monstp) {
        return 0;
    }

    auto tp_id = get(monstp->inventory_id, slot);
    if (!tp_id) {
        return 0;
    }

    auto tpp = tp_find(tp_id);
    if (!tpp) {
        return 0;
    }

    return item_count_including_charges(tpp);
}

int Thing::item_enchant_count (const uint32_t slot)
{_
    if (!monstp) {
        return 0;
    }

    auto tp_id = get(monstp->inventory_id, slot);
    if (!tp_id) {
        return 0;
    }

    for (auto oid : monstp->carrying) {
        auto o = game->level->thing_find(oid);
        if (o) {
            if (o->tp()->id == tp_id) {
                return o->get_enchant();
            }
        }
    }

    return 0;
}

int Thing::item_slot_count (const uint32_t slot)
{_
    auto tp_id = get(monstp->inventory_id, slot);
    if (!tp_id) {
        return 0;
    }

    if (!monstp) {
        return 0;
    }

    auto tpp = tp_find(tp_id);
    if (!tpp) {
        return 0;
    }

    return item_count_excluding_charges(tpp);
}

Thingp Level::inventory_get (const uint32_t slot)
{_
    log("Inventory get slot %d", slot);
_
    if (!player) {
        ERR("No player");
        return nullptr;
    }

    auto monstp = player->monstp;
    if (!monstp) {
        ERR("No monstp for player");
        return nullptr;
    }

    if (slot >= monstp->inventory_id.size()) {
        LOG("Slot %d out of range, max %d", slot, (int)monstp->inventory_id.size());
        return nullptr;
    }

    auto tp_id = get(monstp->inventory_id, slot);
    if (!tp_id) {
        LOG("Slot %d has no tp", slot);
        return nullptr;
    }

    auto tpp = tp_find(tp_id);
    if (!tpp) {
        LOG("Slot %d has no valid tp", slot);
        return nullptr;
    }

    LOG("Slot %d has %s", slot, tpp->name().c_str());

    for (auto oid : monstp->carrying) {
        auto o = thing_find(oid);
        if (o) {
            if (o->tp() == tpp) {
                o->log("Got inventory item %s", tpp->name().c_str());
                return o;
            }
        }
    }

    LOG("Slot %d has tp %s that is not carried", slot, tpp->name().c_str());
    return nullptr;
}

Thingp Level::inventory_get (void)
{
    return inventory_get(game->inventory_highlight_slot);
}

bool Level::inventory_over (const uint32_t slot)
{_
    LOG("Inventory: over inventory slot %d", slot);
_
    if (!player) {
        LOG("Inventory: ignore; no player");
        return false;
    }

    if (slot >= player->monstp->inventory_id.size()) {
        LOG("Inventory: ignore; slot out of range");
        return false;
    }

    auto oid = get(player->monstp->inventory_id, slot);
    if (!oid) {
        LOG("Inventory: ignore; nothing at that slot");
        return false;
    }

    Thingp item;

    if (slot != game->inventory_highlight_slot) {
        LOG("Inventory: request to remake inventory");
        game->request_remake_inventory = true;
        game->inventory_highlight_slot = slot;
        item = inventory_describe(slot);
    } else {
        item = inventory_describe(game->inventory_highlight_slot);
    }

    if (!item) {
        return false;
    }

    item->log("Over inventory item");
    return true;
}

bool Level::inventory_chosen (const uint32_t slot)
{_
    LOG("Inventory: chosen inventory slot %d", slot);
_
    if (!player) {
        return false;
    }

    if (slot >= player->monstp->inventory_id.size()) {
        return false;
    }

    LOG("Inventory: request to remake inventory");
    game->request_remake_inventory = true;

    auto oid = get(player->monstp->inventory_id, slot);
    if (!oid) {
        return false;
    }

    Thingp item;
    bool changed_highlight_slot = false;

    if (slot != game->inventory_highlight_slot) {
        game->inventory_highlight_slot = slot;
        changed_highlight_slot = true;

        item = inventory_describe(slot);
    } else {
        item = inventory_describe(game->inventory_highlight_slot);
    }

    if (!item) {
        return false;
    }

    item->log("Chosen inventory item");
    if (item->is_weapon()) {
        if (player->wield(item)) {
            if (changed_highlight_slot) {
                game->tick_begin("player changed weapon");
            }
        }
        game->change_state(Game::STATE_NORMAL);
        describe(item);
    } else if (item->is_enchantstone()) {
        game->wid_enchant_an_item();
        describe(item);
    } else if (item->is_skillstone()) {
        game->wid_skill_choose();
        describe(item);
    } else if (item->is_bag()) {
        game->wid_thing_info_create(item);
        item->log("Moving items flag set");
        game->change_state(Game::STATE_MOVING_ITEMS);
    } else if (item->is_thrown_automatically_when_chosen()) {
        player->throw_item_choose_target(item);
        describe(item);
    } else if (item->is_target_select_automatically_when_chosen()) {
        player->fire_at_and_choose_target(item);
        describe(item);
    } else if (item->is_used_automatically_when_selected()) {
        player->use(item);
        describe(item);
    } else {
        game->change_state(Game::STATE_NORMAL);
        describe(item);
    }

    return true;
}

Thingp Level::inventory_describe (const uint32_t slot)
{_
    LOG("Inventory: describe slot %d", slot);
_
    auto item = inventory_get(slot);
    if (item) {
        item->log("Inventory: describe slot %d", slot);
        item->describe_when_hovered_over_in_rightbar();
    } else {
        LOG("Inventory: describe slot %d => nothing there", slot);
    }
    return item;
}
