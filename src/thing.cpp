//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include "my_game.h"
#include "my_color.h"
#include "my_dmap.h"
#include <list>

static uint32_t next_thing_id;

#undef ENABLE_THING_DEBUG

static std::list<uint32_t> things_to_delete;

void thing_gc (void)
{
    for (auto id : things_to_delete) {
        auto t = thing_find(id);
        if (!t) {
            ERR("thing %u not found to garbage collect", id);
            continue;
        }

        t->log("garbage collect");
        delete t;
    }

    //
    // No need to call remove as we did the safe destroy above.
    //
    things_to_delete.clear();
}

Thingp thing_new (std::string tp_name, Thingp owner)
{_
    return thing_new(tp_name, owner->mid_at - fpoint(0.5, 0.5));
}

Thingp thing_new (std::string name, fpoint at, fpoint jitter)
{_
    auto t = new Thing;
    t->init(name, at, jitter);
    return (t);
}

Thing::Thing (void)
{_
    newptr(this, "thing");
}

Thing::~Thing (void)
{_
    verify(this);
    if (is_being_destroyed) {
        die("death recursion");
    }
    is_being_destroyed = true;
    destroy();
    if (monst) {
        oldptr(monst);
        delete monst;
    }
    oldptr(this);
}

void Thing::init (std::string name, fpoint at, fpoint jitter)
{_
    id = ++next_thing_id;

    tile_curr = 0;
    timestamp_next_frame = 0;
    dir = 0;
    has_ever_moved = 0;
    is_attached = 0;
    is_being_destroyed = 0;
    is_bouncing = 0;
    is_dead = 0;
    is_facing_left = 0;
    is_hidden = 0;
    is_hungry = 0;
    is_moving = 0;
    is_open = 0;
    is_sleeping = 0;
    is_starving = 0;
    is_submerged = 0;
    is_waiting_for_ai = 0;

    auto tp = tp_find(name);
    if (!tp) {
        DIE("thing [%s] not found", name.c_str());
    }
    tp_id = tp->id;

    if (tp_is_monst(tp) || tp_is_player(tp)) {
        new_dmap_scent();
        new_dmap_goals();
        new_age_map();
        set_timestamp_born(time_get_time_ms_cached());
    }

    auto p = std::make_pair(id, this);
    auto result = world->all_things.insert(p);
    if (result.second == false) {
        DIE("thing insert [%d] failed", id);
    }

    if (tp_is_active(tp)) {
        auto result = world->all_active_things.insert(p);
        if (result.second == false) {
            DIE("thing insert active [%d] failed", id);
        }
    }

    auto sz = fsize(1.0, 1.0);
    at += fpoint(sz.w / 2, sz.h / 2);

    point new_at((int)at.x, (int)at.y);
    if ((new_at.x >= MAP_WIDTH) || (new_at.y >= MAP_HEIGHT)) {
        DIE("new thing is oob at %d, %d", new_at.x, new_at.y);
    }

    //
    // Find which wall is the closest to cling onto if this is a wall clinger
    //
    mid_at             = at;
    last_mid_at        = mid_at;

    if (tp_gfx_can_hflip(tp)) {
        dir            = THING_DIR_LEFT;
        is_facing_left = true;
    } else {
        dir            = THING_DIR_NONE;
        is_facing_left = false;
    }

    is_hungry             = tp_hunger_constant(tp);
    is_starving           = false;
    is_dead               = false;
    is_hidden             = false;
    is_sleeping           = false;
    is_moving             = false;
    has_ever_moved        = false;
    is_open               = false;
    is_bouncing           = false;
    is_attached           = false;
    is_being_destroyed    = false;
    is_waiting_for_ai     = false;
    is_submerged          = false;

    auto h = tp_hunger_initial_health_at(tp);
    if (h) {
        set_health(h);
        set_health_max(h);
    }

    auto tiles = tp_tiles(tp);
    if (tp->gfx_animated) {
        auto tile = tile_first(tiles);
        if (tile) {
            tile_curr = tile->global_index;
        }
    } else {
        auto tile = tile_random(tiles);
        if (tile) {
            tile_curr = tile->global_index;
        }
    }

    if (tp_is_player(tp)) {
        if (world->player && (world->player != this)) {
            DIE("player exists in multiple places on map, %f, %f and %f, %f",
                world->player->mid_at.x,
                world->player->mid_at.y,
                mid_at.x,
                mid_at.y);
        }
        world->player = this;

        new_light(at);
        log("player created");
    }

    if (tp_is_wall(tp)) {
        world->set_wall(new_at.x, new_at.y);
    }
    if (tp_is_wall(tp)) {
        world->set_solid(new_at.x, new_at.y);
    }
    if (tp_is_floor(tp)) {
        world->set_floor(new_at.x, new_at.y);
    }
    if (tp_is_lava(tp)) {
        world->set_lava(new_at.x, new_at.y);
    }
    if (tp_is_blood(tp)) {
        world->set_blood(new_at.x, new_at.y);
    }
    if (tp_is_water(tp)) {
        world->set_water(new_at.x, new_at.y);
    }
    if (tp_is_deep_water(tp)) {
        world->set_deep_water(new_at.x, new_at.y);
        world->set_water(new_at.x, new_at.y);
    }
    if (tp_is_corridor(tp)) {
        world->set_corridor(new_at.x, new_at.y);
    }
    if (tp_is_dirt(tp)) {
        world->dir_sett(new_at.x, new_at.y);
    }
    if (tp_is_grass(tp)) {
        world->set_grass(new_at.x, new_at.y);
    }
    if (tp_is_soil(tp)) {
        world->set_soil(new_at.x, new_at.y);
    }
    if (tp_is_gravel(tp)) {
        world->set_gravel(new_at.x, new_at.y);
    }
    if (tp_is_snow(tp)) {
        world->set_snow(new_at.x, new_at.y);
    }
    if (tp_is_monst(tp)) {
        world->set_monst(new_at.x, new_at.y);
    }
    if (tp_is_food(tp)) {
        world->set_food(new_at.x, new_at.y);
    }
    if (tp_is_rock(tp)) {
        world->set_rock(new_at.x, new_at.y);
    }
    if (tp_is_key(tp)) {
        world->set_key(new_at.x, new_at.y);
    }
    if (tp_gfx_large_shadow_caster(tp)) {
        world->set_gfx_large_shadow_caster(new_at.x, new_at.y);
    }
    if (tp_is_door(tp)) {
        world->set_door(new_at.x, new_at.y);
    }

    if (!tp_does_nothing(tp)) {
        log("created");
    }

    if (jitter != fpoint(0.0, 0.0)) {
        double dx = random_range(0, TILE_WIDTH);
        double dy = random_range(0, TILE_WIDTH);

        dx -= TILE_WIDTH / 2;
        dy -= TILE_WIDTH / 2;

        dx /= TILE_WIDTH;
        dy /= TILE_WIDTH;

        dx *= jitter.x;
        dy *= jitter.y;

        move_to_immediately(fpoint(mid_at.x + dx, mid_at.y + dy));
    }

    update_coordinates();
    attach();

    if (tp_is_light_strength(tp)) {
        new_light(at);
    }
}

void Thing::destroy (void)
{_
    verify(this);
#ifdef ENABLE_THING_DEBUG
    log("destroy");
#else
    if (!does_nothing()) {
        log("destroy");
    }
#endif

    detach();

    auto tpp = tp();

    {
        auto a = &world->all_things;
        auto iter = a->find(id);
        if (iter != a->end()) {
            if (is_active()) {
                log("erasing from all things");
            }
            world->all_things.erase(iter);
        } else {
            //
            // May have been removed already in cleanup. Ignore.
            //
        }
    }

    {
        auto a = &world->all_active_things;
        auto iter = a->find(id);
        if (iter != a->end()) {
            if (is_active()) {
                log("erasing from active things");
            }
            world->all_active_things.erase(iter);
        } else {
            //
            // May have been removed already in cleanup. Ignore.
            //
        }
    }

    //
    // Pop from the map
    //
    point old_at((int)mid_at.x, (int)mid_at.y);

    if (is_wall()) {
        world->unset_wall(old_at.x, old_at.y);
    }
    if (is_wall() || is_rock()) {
        world->unset_solid(old_at.x, old_at.y);
    }
    if (is_floor()) {
        world->unset_floor(old_at.x, old_at.y);
    }
    if (is_lava()) {
        world->unset_lava(old_at.x, old_at.y);
    }
    if (is_blood()) {
        world->unset_blood(old_at.x, old_at.y);
    }
    if (is_water()) {
        world->unset_water(old_at.x, old_at.y);
    }
    if (is_deep_water()) {
        world->unset_deep_water(old_at.x, old_at.y);
    }
    if (is_corridor()) {
        world->unset_corridor(old_at.x, old_at.y);
    }
    if (is_dirt()) {
        world->undir_sett(old_at.x, old_at.y);
    }
    if (is_grass()) {
        world->unset_grass(old_at.x, old_at.y);
    }
    if (is_soil()) {
        world->unset_soil(old_at.x, old_at.y);
    }
    if (is_gravel()) {
        world->unset_gravel(old_at.x, old_at.y);
    }
    if (is_snow()) {
        world->unset_snow(old_at.x, old_at.y);
    }
    if (is_monst()) {
        world->unset_monst(old_at.x, old_at.y);
    }
    if (is_food()) {
        world->unset_food(old_at.x, old_at.y);
    }
    if (is_rock()) {
        world->unset_rock(old_at.x, old_at.y);
    }
    if (is_key()) {
        world->unset_key(old_at.x, old_at.y);
    }
    if (tp_gfx_large_shadow_caster(tpp)) {
        world->unset_gfx_large_shadow_caster(old_at.x, old_at.y);
    }
    if (is_door()) {
        world->unset_door(old_at.x, old_at.y);
    }
    if (is_player()) {
        world->player = nullptr;
    }
    delete_dmap_scent();
    delete_dmap_goals();
    delete_age_map();
}

void Thing::hide (void)
{_
    is_hidden = true;

    //
    // Hide the weapon too or it just floats in the air.
    //
    auto weapon_carry_anim = weapon_get_carry_anim();
    if (weapon_carry_anim) {
        weapon_carry_anim->hide();
    }
}

void Thing::visible (void)
{_
    is_hidden = false;

    //
    // If this thing has an owner, should the thing stay hidden?
    //
    auto owner = owner_get();
    if (owner) {
        if (this == owner->weapon_get_carry_anim()) {
            if (owner->weapon_get_use_anim()) {
                //
                // Stay hidden until the weapon use is done.
                //
                return;
            }
        }
    }

    //
    // Reveal the weapon again too.
    //
    auto weapon_carry_anim = weapon_get_carry_anim();
    if (weapon_carry_anim) {
        weapon_carry_anim->visible();
    }
}

uint8_t Thing::is_visible (void)
{
    return (!is_hidden);
}

//
// Get rid of all the hooks to other things that this thing has. e.g. the
// weapons it carries etc.
//
void Thing::hooks_remove ()
{_
    //
    // We are owned by something. i.e. we are a sword.
    //
    Thingp owner = 0;

    if (get_owner_id()) {
        owner = owner_get();
    }

    if (owner) {
#ifdef ENABLE_THING_DEBUG
        log("detach %d from owner %s", id, owner->to_string().c_str());
#endif
        if (id == owner->get_weapon_id_carry_anim()) {
            unwield("remove hooks");

#ifdef ENABLE_THING_DEBUG
            log("detach from carry anim owner %s", owner->to_string().c_str());
#endif

            owner->weapon_set_carry_anim(nullptr);
        }

        if (id == owner->get_weapon_id_use_anim()) {
#ifdef ENABLE_THING_DEBUG
            log("detach from use anim owner %s", owner->to_string().c_str());
#endif
            owner->weapon_set_use_anim(nullptr);

            //
            // End of the use animation, make the sword visible again.
            //
            auto carrying = owner->weapon_get_carry_anim();
            if (carrying) {
                //
                // But only if the owner is visible. They may have reached the
                // level.
                //
                if (owner->is_visible()) {
                    carrying->visible();
                }
            }
        }

        set_owner(nullptr);
    }

    //
    // We own things like a sword. i.e. we are a player.
    //
    {
    }
        auto item = weapon_get_carry_anim();
        if (item) {
            weapon_set_carry_anim(nullptr);
            verify(item);
            item->set_owner(nullptr);
            item->dead("weapon carry anim owner killed");
        }

    {
        auto item = weapon_get_use_anim();
        if (item) {
            weapon_set_use_anim(nullptr);
            verify(item);
            item->set_owner(nullptr);
            item->dead("weapon use anim owner killed");
        }
    }

    //
    // Some things have lots of things they own
    //
    if (get_owned_count()) {
        log("remove remaining %u owned things", get_owned_count());

        for (auto i : world->all_active_things) {
            Thingp t = i.second;
            auto o = t->owner_get();
            if (o && (o == t)) {
                t->set_owner(nullptr);
            }
        }
    }
}

Thingp Thing::owner_get (void)
{
    auto id = get_owner_id();
    if (id) {
        return (thing_find(id));
    } else {
        return (nullptr);
    }
}

void Thing::set_owner (Thingp owner)
{
    if (owner) {
        verify(owner);
    }

    auto old_owner = owner_get();
    if (old_owner) {
        if (old_owner == owner) {
            return;
        }

        if (owner) {
            log("set-owner change %s->%s", old_owner->to_string().c_str(),
                owner->to_string().c_str());
        } else {
            log("set-owner remove owner %s", old_owner->to_string().c_str());
        }
    } else {
        if (owner) {
            log("set-owner %s", owner->to_string().c_str());
        }
    }

    if (owner) {
        set_owner_id(owner->id);
        owner->incr_owned_count();
    } else {
        set_owner_id(0);
        if (old_owner) {
            old_owner->decr_owned_count();
        }
    }
}

void Thing::update_light (void)
{_
    //
    // Light source follows the thing.
    //
    auto l = get_light();
    if (l) {
        l->move_to(get_interpolated_mid_at());
        l->calculate();
    }
}

void Thing::move_carried_items (void)
{_
    //
    // Light source follows the thing.
    //
    update_light();

    //
    // Weapons follow also.
    //
    if (get_weapon_id_carry_anim()) {
        auto w = thing_find(get_weapon_id_carry_anim());
        if (!w) {
            die("weapon_id_carry_anim set to %d but not found",
                get_weapon_id_carry_anim());
        }
        w->move_to(mid_at);
        w->dir = dir;
    }

    if (get_weapon_id_use_anim()) {
        auto w = thing_find(get_weapon_id_use_anim());
        if (!w) {
            die("weapon_id_use_anim set to %d but not found",
                get_weapon_id_use_anim());
        }
        w->move_to(mid_at);
        w->dir = dir;
    }

    //
    // If something moves on the water, make a ripple
    //
    if (is_monst() || is_player()) {
        if (world->is_water((int)mid_at.x, (int)mid_at.y)) {
            fpoint at(mid_at.x - 0.5, mid_at.y - 0.5);
            if (random_range(0, 1000) > 500) {
                thing_new(tp_name(tp_random_ripple()), at);
            }
        }
    }
}

//
// Find an existing thing.
//
Thingp thing_find (uint32_t id)
{_
    auto result = world->all_things.find(id);
    if (result == world->all_things.end()) {
        return (0);
    }

    auto t = result->second;
    verify(t);
    return (t);
}

std::string Thing::to_string (void)
{_
    auto tpp = tp();
    verify(this);
    verify(tpp);
    return (string_sprintf("%u(%s%s) at (%g,%g)",
                           id, tpp->name.c_str(),
                           is_dead ? "/dead" : "",
                           mid_at.x, mid_at.y));
}

const char * Thing::to_cstring (void)
{
    return (to_string().c_str());
}

void Thing::kill (void)
{_
    if (is_dead) {
        return;
    }
    is_dead = true;

    if (is_corpse_on_death()) {
        return;
    }

    hooks_remove();
    things_to_delete.push_back(id);
}
