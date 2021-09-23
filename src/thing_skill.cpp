//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
// Please use spaces indent of 2, no tabs and column width of 120 to view.
//

#include "my_sys.h"
#include "my_level.h"
#include "my_thing.h"
#include "my_game.h"
#include "my_monst.h"
#include "my_wid_skillbox.h"
#include "my_array_bounds_check.h"
#include "my_vector_bounds_check.h"
#include "my_ui.h"
#include "my_ptrcheck.h"

bool Thing::skill_add(Thingp what)
{
  TRACE_AND_INDENT();
  dbg("Try to add skill %s", what->to_string().c_str());
  TRACE_AND_INDENT();
  if (! monstp) {
    dbg("No; not a monst");
    return false;
  }

  auto existing_owner = what->get_immediate_owner();
  if (existing_owner) {
    if (existing_owner == this) {
      dbg("No; same owner");
      return false;
    }
    existing_owner->drop(what);
  }

  for (const auto &item : monstp->skills) {
    if (item == what->id) {
      dbg("No; already carried");
      return false;
    }
  }

  if (is_player()) {
    if (! skillbox_id_insert(what)) {
      dbg("No; no space in skillbox");
      return false;
    }
  }

  monstp->skills.push_front(what->id);
  what->set_owner(this);
  what->hide();

  dbg("Add skill %s", what->to_string().c_str());

  if (is_player()) {
    wid_skillbox_init();
  }

  return true;
}

bool Thing::skill_remove(Thingp what)
{
  TRACE_AND_INDENT();
  dbg("Removing skill %s", what->to_string().c_str());
  TRACE_AND_INDENT();
  auto existing_owner = what->get_immediate_owner();
  if (existing_owner != this) {
    err("Attempt to remove skill %s which is not owned", what->to_string().c_str());
    return false;
  }

  Thingp top_owner;
  if (is_player()) {
    top_owner = this;
  } else {
    top_owner = get_top_owner();
  }

  if (top_owner) {
    if (top_owner->is_player()) {
      top_owner->skillbox_id_remove(what);
    }
  }

  dbg("Update bag with drop of: %s", what->to_string().c_str());
  bag_remove(what);
  while (bag_compress()) {
  }

  what->remove_owner();
  monstp->skills.remove(what->id);
  game->request_remake_skillbox = true;

  dbg("Dropped %s into the ether", what->to_string().c_str());

  return true;
}

void Thing::skill_remove_all(void)
{
  TRACE_AND_INDENT();
  if (! monstp) {
    return;
  }

  while (! monstp->skills.empty()) {
    auto id = *monstp->skills.begin();
    auto t  = level->thing_find(id);
    if (! t) {
      return;
    }
    skill_remove(t);
  }
}

bool Thing::skill_use(Thingp what)
{
  TRACE_AND_INDENT();
  dbg("Try to use skill %s", what->to_string().c_str());
  used(what, this, false /* remove after use */);
  return true;
}

void Thing::skill_deactivate(Thingp what)
{
  TRACE_AND_INDENT();
  what->is_activated            = false;
  game->request_remake_skillbox = true;
}

void Thing::skill_activate(Thingp what)
{
  TRACE_AND_INDENT();
  what->is_activated            = true;
  game->request_remake_skillbox = true;
}

int Thing::skill_enchant_count(const uint32_t slot)
{
  TRACE_AND_INDENT();
  if (! monstp) {
    return 0;
  }

  auto tp_id = get(monstp->skillbox_id, slot);
  if (! tp_id) {
    return 0;
  }

  for (auto oid : monstp->skills) {
    auto o = game->level->thing_find(oid);
    if (o) {
      if (o->tp()->id == tp_id) {
        return o->get_enchant();
      }
    }
  }

  return 0;
}

bool Thing::add_skill(Tpp what)
{
  TRACE_AND_INDENT();
  auto t = level->thing_new(what, mid_at);
  if (! t) {
    err("Cannot learn skill");
    return false;
  }

  TOPCON("You learn %s skill.", t->text_the().c_str());
  skill_add(t);

  //
  // Drop an skillstone
  //
  auto found = false;
  for (auto id : monstp->carrying) {
    auto t = level->thing_find(id);
    if (! t) {
      continue;
    }
    if (t->is_skillstone()) {
      t->dead("used");
      found = true;
      break;
    }
  }
  if (! found) {
    err("no skillstone found");
  }

  return true;
}
