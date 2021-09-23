//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
// Please use spaces indent of 2, no tabs and column width of 120 to view.
//

#include "my_sys.h"
#include "my_main.h"
#include "my_level.h"
#include "my_depth.h"
#include "my_thing.h"
#include "my_sprintf.h"
#include "my_array_bounds_check.h"
#include "my_vector_bounds_check.h"
#include "my_dmap.h"
#include "my_monst.h"
#include "my_python.h"
#include "my_string.h"

//
// Python callback upon being fire
//
void Thing::on_fire(void)
{
  TRACE_AND_INDENT();
  auto on_fire = tp()->on_fire_do();
  if (std::empty(on_fire)) {
    return;
  }

  auto t = split_tokens(on_fire, '.');
  if (t.size() == 2) {
    auto        mod   = t[ 0 ];
    auto        fn    = t[ 1 ];
    std::size_t found = fn.find("()");
    if (found != std::string::npos) {
      fn = fn.replace(found, 2, "");
    }

    dbg("Call %s.%s(%s)", mod.c_str(), fn.c_str(), to_string().c_str());

    py_call_void_fn(mod.c_str(), fn.c_str(), id.id, (unsigned int) mid_at.x, (unsigned int) mid_at.y);
  } else {
    ERR("Bad on_fire call [%s] expected mod:function, got %d elems", on_fire.c_str(), (int) on_fire.size());
  }
}

bool Thing::is_on_fire(void) const
{
  TRACE_AND_INDENT();
  auto id = get_on_fire_anim_id();
  if (! id) {
    return false;
  }

  return id.ok();
}

void Thing::unset_on_fire(void)
{
  TRACE_AND_INDENT();
  auto id = get_on_fire_anim_id();
  if (! id) {
    return;
  }

  auto fire_anim = level->thing_find(id);
  if (fire_anim) {
    dbg("Unset on fire");
    fire_anim->dead("by removing fire");
    set_on_fire_anim_id(0);
  }
}

bool Thing::set_on_fire(const std::string &why)
{
  TRACE_AND_INDENT();
  if (! is_burnable() && ! is_combustible()) {
    return false;
  }

  if (get_on_fire_anim_id().ok()) {
    return false;
  }

  dbg("Set on fire, %s", why.c_str());
  auto on_fire_anim = level->thing_new("fire", this);
  set_on_fire_anim_id(on_fire_anim->id);
  on_fire_anim->set_owner(this);
  move_carried_items();

  if (! is_dead) {
    on_fire();
  }

  //
  // In case the fire is over a chasm. Don't call forced as we could
  // have already stepped on lava that triggered this.
  //
  location_check_all_things_at();

  return true;
}

//
// When on fire, where to run to?
//
bool Thing::ai_create_on_fire_path(point &nh, const point start, const point end)
{
  TRACE_AND_INDENT();
  Dmap  dmap {};
  point dmap_start = start;
  point dmap_end   = end;

  int minx, miny, maxx, maxy;
  if (dmap_start.x < dmap_end.x) {
    minx = dmap_start.x;
    maxx = dmap_end.x;
  } else {
    minx = dmap_end.x;
    maxx = dmap_start.x;
  }
  if (dmap_start.y < dmap_end.y) {
    miny = dmap_start.y;
    maxy = dmap_end.y;
  } else {
    miny = dmap_end.y;
    maxy = dmap_start.y;
  }

  auto border = TILES_ACROSS / 2;
  minx -= border;
  miny -= border;
  maxx += border;
  maxy += border;

  if (minx < 0) {
    minx = 0;
  }
  if (miny < 0) {
    miny = 0;
  }
  if (maxx >= MAP_WIDTH) {
    maxx = MAP_WIDTH - 1;
  }
  if (maxy >= MAP_HEIGHT) {
    maxy = MAP_HEIGHT - 1;
  }

  //
  // Set up obstacles for the search. Don't avoid all bad things
  // as we're on fire!
  //
  for (auto y = miny; y < maxy; y++) {
    for (auto x = minx; x < maxx; x++) {
      if (collision_obstacle(point(x, y))) {
        set(dmap.val, x, y, DMAP_IS_WALL);
      } else {
        set(dmap.val, x, y, DMAP_IS_PASSABLE);
      }
    }
  }

  dmap_start = point(minx, miny);
  dmap_end   = point(maxx, maxy);

  set(dmap.val, end.x, end.y, DMAP_IS_GOAL);
  set(dmap.val, start.x, start.y, DMAP_IS_PASSABLE);

  dmap_process(&dmap, dmap_start, dmap_end);
#if 0
  dmap_print(&dmap, start, dmap_start, dmap_end);
#endif

  auto p = dmap_solve(&dmap, start);

  char path_debug = '\0'; // astart path debug
  auto result     = astar_solve(NULL, path_debug, start, end, &dmap);
#if 0
  for (auto i : result.path) {
    set(dmap.val, i.x, i.y, (uint8_t)0);
  }
  dmap_print(&dmap, start, dmap_start, dmap_end);
#endif

  auto hops     = result.path;
  auto hops_len = hops.size();

  if (hops_len >= 2) {
    auto hop0 = get(hops, hops_len - 1);
    auto hop1 = get(hops, hops_len - 2);
    if (dmap_can_i_move_diagonally(&dmap, start, hop0, hop1)) {
      nh = hop1;
    } else {
      nh = hop0;
    }
    return true;
  } else if (hops_len >= 1) {
    auto hop0 = get(hops, hops_len - 1);
    nh        = hop0;
    return true;
  } else {
    return false;
  }
}

bool Thing::ai_on_fire_choose_target(point &nh)
{
  TRACE_AND_INDENT();
  point start(mid_at.x, mid_at.y);

  //
  // Reached the target? Choose a new one.
  //
  auto target = monstp->wander_target;

  if (target != point(0, 0)) {
    if (! level->is_shallow_water(target.x, target.y)) {
      //
      // Choose a new wander location
      //
      monstp->wander_target = point(0, 0);
    }
  }

  if (target != point(0, 0)) {
    if (ai_create_on_fire_path(nh, start, target)) {
      return true;
    }
  }

  //
  // Choose a new wander location
  //
  monstp->wander_target = point(0, 0);

  auto attempts = 10;
  while (attempts--) {
    auto  tries   = 1000;
    auto  closest = std::numeric_limits< int >::max();
    point best;
    auto  got_one = false;

    while (tries--) {
      auto target = get_random_scent_target();
      if (level->is_shallow_water(target)) {
        if (distance(start, target) < closest) {
          best    = target;
          got_one = true;
        }
      }
    }

    if (got_one) {
      target = best;
      if (ai_create_on_fire_path(nh, start, target)) {
        monstp->wander_target = target;
        dbg("On-fire move to %d,%d nh %d,%d", target.x, target.y, nh.x, nh.y);
        return true;
      }
    }
  }

  dbg("on-fire wander failed");
  return false;
}

bool Thing::ai_on_fire(void)
{
  TRACE_AND_INDENT();
  dbg("Ai on fire");
  auto tries = 10;
  while (tries--) {
    point nh;
    if (ai_on_fire_choose_target(nh)) {
      if (move_to_or_escape(nh)) {
        return true;
      }

      //
      // Set this so next time we will choose another target
      //
      monstp->wander_target = point(0, 0);
    }
  }

  return false;
}
