//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include <algorithm>
#include <set>

#include "my_array_bounds_check.hpp"
#include "my_dmap.hpp"
#include "my_level.hpp"
#include "my_main.hpp"
#include "my_math.hpp"
#include "my_ptrcheck.hpp"
#include "my_sys.hpp"
#include "my_thing.hpp"
#include "my_thing_template.hpp"

void Thing::dmap_modify_terrain_cost(point p, uint8_t *d)
{
  TRACE_AND_INDENT();
  int pref = *d;

  if (collision_obstacle(p)) {
    pref++;
  }

  std::vector< std::pair< Thingp, int > > possible;

  {
    static const std::vector< point > all_deltas = {
        point(-1, -1), point(1, -1), point(-1, 1), point(1, 1), point(0, 0),
        point(0, -1),  point(-1, 0), point(1, 0),  point(0, 1),
    };

    for (const auto &d : all_deltas) {
      auto x = p.x + d.x;
      auto y = p.y + d.y;

      if (will_avoid_monst(point(x, y))) {
        pref += DMAP_LESS_PREFERRED_TERRAIN;
      }
    }
  }

  if (is_hated_by_me(p)) {
    pref += DMAP_LESS_PREFERRED_TERRAIN;
  } else if (is_disliked_by_me(p)) {
    pref += DMAP_LESS_PREFERRED_TERRAIN / 2;
  }

  if (pref > DMAP_MAX_LESS_PREFERRED_TERRAIN) {
    pref = DMAP_MAX_LESS_PREFERRED_TERRAIN;
  }

  *d = (uint8_t) pref;
}

uint8_t Thing::get_terrain_cost(point p)
{
  TRACE_AND_INDENT();
  uint8_t pref = 0;

  dmap_modify_terrain_cost(p, &pref);

  return (uint8_t) pref;
}

bool Thing::will_prefer_terrain(const Thingp itp)
{
  TRACE_AND_INDENT();
  auto me = tp();
  auto it = itp->tp();

  if (me->environ_loves_water()) {
    if (it->is_shallow_water() || it->is_deep_water()) {
      return true;
    }
  }

  if (me->environ_loves_acid()) {
    if (it->is_acid()) {
      return true;
    }
  }

  return false;
}
