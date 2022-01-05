//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_color.hpp"
#include "my_level.hpp"
#include "my_ptrcheck.hpp"
#include "my_sprintf.hpp"
#include "my_sys.hpp"
#include "my_thing.hpp"

Thingp Thing::get_top_spawned_owner(void)
{
  TRACE_NO_INDENT();
  auto id = get_immediate_spawned_owner_id();
  if (likely(id.ok())) {
    auto i = level->thing_find(id);
    if (unlikely(! i)) {
      return nullptr;
    }
    if (unlikely(i->get_immediate_spawned_owner_id().ok())) {
      return i->get_immediate_spawned_owner();
    }
    return i;
  } else {
    return nullptr;
  }
}

Thingp Thing::get_immediate_spawned_owner(void)
{
  TRACE_NO_INDENT();
  auto id = get_immediate_spawned_owner_id();
  if (likely(id.ok())) {
    auto i = level->thing_find(id);
    if (unlikely(! i)) {
      return nullptr;
    }
    return i;
  } else {
    return nullptr;
  }
}

void Thing::set_spawned_owner(Thingp spawner_owner)
{
  TRACE_NO_INDENT();
  if (spawner_owner) {
    verify(MTYPE_THING, spawner_owner);
  }

  auto old_spawner_owner = get_immediate_spawned_owner();
  if (old_spawner_owner) {
    if (old_spawner_owner == spawner_owner) {
      return;
    }

    if (spawner_owner) {
      dbg("Will change spawner owner %s->%s", old_spawner_owner->to_string().c_str(),
          spawner_owner->to_string().c_str());
    } else {
      dbg("Will remove spawner owner %s", old_spawner_owner->to_string().c_str());
    }
  } else {
    if (spawner_owner) {
      dbg("Will set spawner owner to %s", spawner_owner->to_string().c_str());
    }
  }

  if (spawner_owner) {
    set_spawned_owner_id(spawner_owner->id);
    spawner_owner->incr_spawned_count();
  } else {
    set_spawned_owner_id(NoThingId);
    if (old_spawner_owner) {
      old_spawner_owner->decr_spawned_count();
    }
  }
}

void Thing::remove_spawner_owner(void)
{
  TRACE_NO_INDENT();
  auto old_spawner_owner = get_immediate_spawned_owner();
  if (! old_spawner_owner) {
    err("No spawner owner");
    return;
  }

  dbg("Remove spawner owner %s", old_spawner_owner->to_string().c_str());

  set_spawned_owner_id(NoThingId);
  old_spawner_owner->decr_spawned_count();
}

//
// Kill and detach all spawners from their owner
//
void Thing::destroy_spawned(Thingp defeater)
{
  TRACE_NO_INDENT();
  //
  // Warning defeater can be nullptr - e.g. when a mob falls to
  // a new level
  //

  if (! is_spawner()) {
    return;
  }

  if (! get_spawned_count()) {
    return;
  }

  //
  // Slow, but not used too often
  //
  FOR_ALL_THING_GROUPS(group)
  {
    for (auto p : level->all_things[ group ]) {
      auto spawner = p.second;
      auto o       = spawner->get_immediate_spawned_owner();
      if (o && (o == this)) {
        spawner->remove_spawner_owner();
        spawner->dead(defeater, "its spawner died");
      }
    }
  }
}

void Thing::unleash_spawners_things(void)
{
  TRACE_NO_INDENT();
  if (! is_spawner()) {
    return;
  }

  if (! get_spawned_count()) {
    return;
  }

  //
  // Slow, but not used too often
  //
  FOR_ALL_THING_GROUPS(group)
  {
    for (auto p : level->all_things[ group ]) {
      auto spawner = p.second;
      auto o       = spawner->get_immediate_spawned_owner();
      if (o && (o == this)) {
        spawner->remove_spawner_owner();
      }
    }
  }
}
