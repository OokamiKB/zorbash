//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include "my_main.h"
#include "my_level.h"
#include "my_depth.h"
#include "my_color.h"
#include "my_dmap.h"
#include "my_sprintf.h"
#include "my_thing.h"
#include "my_game.h"

Thingp Level::thing_new (const std::string& tp_name, Thingp owner)
{_
    return thing_new(tp_name, owner->mid_at);
}

Thingp Level::thing_new (const std::string& name, const point at)
{_
    return thing_new(name, fpoint(at.x, at.y));
}

Thingp Level::thing_new (const std::string& name, const fpoint at, const fpoint jitter)
{_
    auto t = new struct Thing_();
    t->init(this, name, at, jitter);
    return (t);
}

Thing::Thing_ (void)
{_
    newptr(this, "thing");
}

void Thing::init (Levelp level,
                  const std::string& name,
                  const fpoint born, const fpoint jitter)
{_
    verify(this);

    this->level = level;
    mid_at      = born;
    last_mid_at = born;

    timestamp_next_frame = 0;
    const auto tpp = tp_find(name);
    if (unlikely(!tpp)) {
        DIE("thing template [%s] not found", name.c_str());
        return;
    }

    tp_id = tpp->id;
    tp_or_update();

    //
    // Start off up to data with the player
    //
    set_tick(game->tick_current);

    //
    // Must do this after TP assignment or logging will fail
    //
    game->world.alloc_thing_id(this);
    level_enter();
    level_push();

    if (tpp->is_monst()) {
        new_dmap_scent();
        new_age_map();
    }

    if (tpp->is_player()) {
        level->player = this;
    }

    if (tpp->is_monst() || tpp->is_player() || tpp->is_movable()) {
        set_timestamp_born(time_get_time_ms_cached());
    }

    if (tpp->gfx_animated_can_hflip()) {
        dir            = THING_DIR_LEFT;
        is_facing_left = true;
    } else {
        dir            = THING_DIR_NONE;
        is_facing_left = false;
    }

    is_hungry = tpp->is_hunger_insatiable();

    {_
        auto v = tpp->stats_health_initial();
        if (unlikely(v)) {
            set_stats_health(v);
            set_stats_health_max(v);
        }
    }

    {_
        auto v = tpp->stats_defence();
        if (unlikely(v)) {
            set_stats_defence(v);
            set_stats_defence_max(v);
        }
    }

    {_
        auto v = tpp->tick_rate_tenths();
        if (unlikely(v)) {
            set_tick_rate_tenths(v);
        }
    }

    {_
        auto v = tpp->lifespan();
        if (unlikely(v)) {
            set_lifespan(v);
        }
    }

    {_
        auto v = tpp->stats01();
        if (unlikely(v)) {
            set_stats01(v);
        }
    }

    {_
        auto v = tpp->stats02();
        if (unlikely(v)) {
            set_stats02(v);
        }
    }

    {_
        auto v = tpp->stats03();
        if (unlikely(v)) {
            set_stats03(v);
        }
    }

    {_
        auto v = tpp->stats04();
        if (unlikely(v)) {
            set_stats04(v);
        }
    }

    {_
        auto v = tpp->stats05();
        if (unlikely(v)) {
            set_stats05(v);
        }
    }

    {_
        auto v = tpp->stats06();
        if (unlikely(v)) {
            set_stats06(v);
        }
    }

    {_
        auto v = tpp->stats07();
        if (unlikely(v)) {
            set_stats07(v);
        }
    }

    {_
        auto v = tpp->stats08();
        if (unlikely(v)) {
            set_stats08(v);
        }
    }

    {_
        auto v = tpp->stats09();
        if (unlikely(v)) {
            set_stats09(v);
        }
    }

    {_
        auto v = tpp->stats10();
        if (unlikely(v)) {
            set_stats10(v);
        }
    }

    {_
        auto v = tpp->stats11();
        if (unlikely(v)) {
            set_stats11(v);
        }
    }

    {_
        auto v = tpp->stats12();
        if (unlikely(v)) {
            set_stats12(v);
        }
    }

    {_
        auto v = tpp->stats13();
        if (unlikely(v)) {
            set_stats13(v);
        }
    }

    {_
        auto v = tpp->stats14();
        if (unlikely(v)) {
            set_stats14(v);
        }
    }

    {_
        auto v = tpp->stats15();
        if (unlikely(v)) {
            set_stats15(v);
        }
    }

    {_
        auto v = tpp->stats16();
        if (unlikely(v)) {
            set_stats16(v);
        }
    }

    {_
        auto v = tpp->stats17();
        if (unlikely(v)) {
            set_stats17(v);
        }
    }

    {_
        auto v = tpp->stats18();
        if (unlikely(v)) {
            set_stats18(v);
        }
    }

    {_
        auto v = tpp->stats19();
        if (unlikely(v)) {
            set_stats19(v);
        }
    }

    {_
        auto v = tpp->stats_strength();
        if (unlikely(v)) {
            set_stats_strength(v);
        }
    }

    if (unlikely(tpp->is_entrance())) {
        if (level->world_at.z > 1) {
            is_open = true;
        }
    }

    auto tiles = &tpp->tiles;
    if (tpp->gfx_animated()) {
        auto tile = tile_first(tiles);
        if (tile) {
            tile_curr = tile->global_index;
        } else {
            tile_curr = 0;
        }
    } else {
        auto tile = tile_random(tiles);
        if (tile) {
            tile_curr = tile->global_index;
        } else {
            tile_curr = 0;
        }
    }

    if (unlikely(tpp->is_player())) {
        if (level->player && (level->player != this)) {
            DIE("player exists in multiple places on map, %f, %f and %f, %f",
                level->player->mid_at.x, level->player->mid_at.y, 
                mid_at.x, mid_at.y);
            return;
        }
        level->player = this;

        //
        // keep the light strength half the tiles drawn or we get artifacts
        // at the edges of the fbo
        //
        color col = WHITE;
        new_light(mid_at, TILE_WIDTH, col);

        float d1 = 0.2;
        float d2 = 0.15;
        new_light(mid_at, fpoint(d1, d1), TILE_WIDTH, col);
        new_light(mid_at, fpoint(d1, d2), TILE_WIDTH, col);
        new_light(mid_at, fpoint(d2, d1), TILE_WIDTH, col);
        new_light(mid_at, fpoint(d2, d2), TILE_WIDTH, col);
        new_light(mid_at, fpoint(d1, -d1), TILE_WIDTH, col);
        new_light(mid_at, fpoint(d1, -d2), TILE_WIDTH, col);
        new_light(mid_at, fpoint(d2, -d1), TILE_WIDTH, col);
        new_light(mid_at, fpoint(d2, -d2), TILE_WIDTH, col);
        new_light(mid_at, fpoint(-d1, d1), TILE_WIDTH, col);
        new_light(mid_at, fpoint(-d1, d2), TILE_WIDTH, col);
        new_light(mid_at, fpoint(-d2, d1), TILE_WIDTH, col);
        new_light(mid_at, fpoint(-d2, d2), TILE_WIDTH, col);
        new_light(mid_at, fpoint(-d1, -d1), TILE_WIDTH, col);
        new_light(mid_at, fpoint(-d1, -d2), TILE_WIDTH, col);
        new_light(mid_at, fpoint(-d2, -d1), TILE_WIDTH, col);
        new_light(mid_at, fpoint(-d2, -d2), TILE_WIDTH, col);

        has_light = true;
        log("player created");
    }

    if (tpp->is_loggable_for_unimportant_stuff()) {
        log("created");
    }

#if 0
    //
    // Jitter makes the eating of blood by monsts problematic
    //
    if (unlikely(jitter != fpoint(0.0, 0.0))) {
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
#endif

    //
    // Set position prior to attach
    //
    set_interpolated_mid_at(mid_at);

    //
    // If not the player and has a light source, create the light
    //
    if (unlikely(!tpp->is_player())) {
        if (unlikely(tpp->is_light_strength())) {
            std::string l = tpp->light_color();
            bool add_light = true;
            if (is_lava()) {
                if (random_range(0, 100) < 50) {
                    add_light = false;
                }
            }
            if (add_light) {
                color c = string2color(l);
                new_light(mid_at, (double) tpp->is_light_strength(), c);
                has_light = true;
            }
        }
    }
    update_light();

    if (gfx_bounce_always()) {
        bounce(0.2, 1.0, 500 + random_range(0, 50), 99999);
    }

    //
    // Jitter the initial ticks so things don't all tick the same time
    //
    set_timestamp_last_tick(
       time_get_time_ms_cached() +
       random_range(0, get_tick_rate_tenths() * 100));
}

void Thing::reinit (void)
{_
    verify(this);
    const auto tpp = tp_or_update();
    if (unlikely(!tpp)) {
        DIE("no tp");
        return;
    }

    game->world.realloc_thing_id(this);

    //
    // Probably safest to reset this else things might expire on load
    //
    timestamp_next_frame = 0;
    if (tpp->is_monst() || tpp->is_player()) {
        set_timestamp_born(time_get_time_ms_cached());
    }

    if (unlikely(tpp->is_player())) {
        if (level->player && (level->player != this)) {
            DIE("player exists in multiple places on map, %f, %f and %f, %f",
                level->player->mid_at.x, level->player->mid_at.y,
                mid_at.x, mid_at.y);
            return;
        }
        level->player = this;
        log("player recreated");
    }

    point new_at((int)mid_at.x, (int)mid_at.y);
    if ((new_at.x >= MAP_WIDTH) || (new_at.y >= MAP_HEIGHT)) {
        DIE("new thing is oob at %d, %d", new_at.x, new_at.y);
        return;
    }

    if (tpp->is_loggable_for_unimportant_stuff()) {
        log("recreated");
    }

    //
    // Upon a load it was attached at save time but not now
    //
    if (is_attached) {
        level_push();
    }

    update_light();

    //
    // Relearn the cursor after loading.
    //
    if (is_cursor()) {
        level->cursor = this;
    }
    if (is_player()) {
        level->player = this;
    }
}
