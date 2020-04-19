//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include "my_game.h"
#include "my_dungeon.h"
#include "my_thing.h"

void Level::update_map (void)
{
}

bool Level::is_anything_at (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }

    for (auto t : get(all_thing_ptrs_at, x, y)) {
        if (t) {
            verify(t);
            return (true);
        }
    }
    return (false);
}

bool Level::is_anything_at (const point &p)
{_
    return (is_anything_at(p.x, p.y));
}

bool Level::is_lava (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_lava, p.x, p.y));
}

bool Level::is_lava (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_lava, x, y));
}

void Level::set_lava (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_lava, x, y, true);
}

void Level::unset_lava (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_lava, x, y, false);
}

bool Level::is_hazard (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_hazard, p.x, p.y));
}

bool Level::is_hazard (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_hazard, x, y));
}

void Level::set_hazard (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_hazard, x, y, true);
}

void Level::unset_hazard (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_hazard, x, y, false);
}

bool Level::is_secret_door (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_secret_door, p.x, p.y));
}

bool Level::is_secret_door (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_secret_door, x, y));
}

void Level::set_secret_door (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_secret_door, x, y, true);
}

void Level::unset_secret_door (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_secret_door, x, y, false);
}

bool Level::is_blood (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_blood, p.x, p.y));
}

bool Level::is_blood (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_blood, x, y));
}

void Level::set_blood (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    set(_is_blood, x, y, true);
}

void Level::unset_blood (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    set(_is_blood, x, y, false);
}

bool Level::is_water (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_water, p.x, p.y));
}

bool Level::is_water (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_water, x, y));
}

void Level::set_water (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_water, x, y, true);
}

void Level::unset_water (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_water, x, y, false);
}

bool Level::is_wall (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_wall, p.x, p.y));
}

bool Level::is_wall (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_wall, x, y));
}

void Level::set_wall (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_wall, x, y, true);
}

void Level::unset_wall (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_wall, x, y, false);
}

bool Level::is_corridor (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_corridor, p.x, p.y));
}

bool Level::is_corridor (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_corridor, x, y));
}

void Level::set_corridor (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_corridor, x, y, true);
}

void Level::unset_corridor (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_corridor, x, y, false);
}

bool Level::is_dirt (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_dirt, p.x, p.y));
}

bool Level::is_dirt (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_dirt, x, y));
}

void Level::set_dirt (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_dirt, x, y, true);
}

void Level::unset_dirt (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_dirt, x, y, false);
}

bool Level::is_floor (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_floor, x, y));
}

void Level::set_floor (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_floor, x, y, true);
}

void Level::unset_floor (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_floor, x, y, false);
}

bool Level::is_monst (const point &p)
{_
    return (is_monst(p.x, p.y));
}

bool Level::is_monst (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }

    for (auto t : get(all_thing_ptrs_at, x, y)) {
        if (t) {
            verify(t);
            auto tpp = t->tp();
            if (tp_is_monst(tpp)) {
                return (true);
            }
        }
    }
    return (false);
}

bool Level::is_food (const point &p)
{_
    return (is_food(p.x, p.y));
}

bool Level::is_food (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }

    for (auto t : get(all_thing_ptrs_at, x, y)) {
        if (t) {
            verify(t);
            auto tpp = t->tp();
            if (tp_is_food(tpp)) {
                return (true);
            }
        }
    }
    return (false);
}

bool Level::is_rock (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_rock, p.x, p.y));
}

bool Level::is_rock (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_rock, x, y));
}

void Level::set_rock (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_rock, x, y, true);
}

void Level::unset_rock (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_rock, x, y, false);
}

bool Level::is_dungeon (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_dungeon, p.x, p.y));
}

bool Level::is_dungeon (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_dungeon, x, y));
}

void Level::set_dungeon (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_dungeon, x, y, true);
}

void Level::unset_dungeon (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    map_changed = true;
    set(_is_dungeon, x, y, false);
}

bool Level::is_key (const point &p)
{_
    return (is_key(p.x, p.y));
}

bool Level::is_key (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }

    for (auto t : get(all_thing_ptrs_at, x, y)) {
        if (t) {
            verify(t);
            auto tpp = t->tp();
            if (tp_is_key(tpp)) {
                return (true);
            }
        }
    }
    return (false);
}

bool Level::is_corpse (const point &p)
{_
    if (unlikely(is_oob(p.x, p.y))) {
        return (false);
    }
    return (get(_is_corpse, p.x, p.y));
}

bool Level::is_corpse (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }
    return (get(_is_corpse, x, y));
}

void Level::set_corpse (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    set(_is_corpse, x, y, true);
}

void Level::unset_corpse (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return;
    }
    set(_is_corpse, x, y, false);
}

bool Level::is_door (const point &p)
{_
    return (is_door(p.x, p.y));
}

bool Level::is_door (const int x, const int y)
{_
    if (unlikely(is_oob(x, y))) {
        return (false);
    }

    for (auto t : get(all_thing_ptrs_at, x, y)) {
        if (t) {
            verify(t);
            auto tpp = t->tp();
            if (tp_is_door(tpp)) {
                return (true);
            }
        }
    }
    return (false);
}
