//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_array_bounds_check.hpp"
#include "my_game.hpp"
#include "my_hiscore.hpp"
#include "my_level.hpp"
#include "my_ptrcheck.hpp"
#include "my_py_thing.hpp"
#include "my_python.hpp"
#include "my_sys.hpp"
#include "my_thing.hpp"
#include "my_thing_template.hpp"

#define THING_BODY_SET_INT(__func__, __api__)                                                                        \
  PyObject *__func__(PyObject * obj, PyObject * args, PyObject * keywds)                                             \
  {                                                                                                                  \
    TRACE_AND_INDENT();                                                                                              \
    uint32_t     id       = 0;                                                                                       \
    uint32_t     value    = 0;                                                                                       \
    static char *kwlist[] = {(char *) "id", (char *) "value", 0};                                                    \
                                                                                                                     \
    if (! PyArg_ParseTupleAndKeywords(args, keywds, "Ii", kwlist, &id, &value)) {                                    \
      ERR("%s: Failed parsing keywords", __FUNCTION__);                                                              \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    Thingp t = game->thing_find(id);                                                                                 \
    if (unlikely(! t)) {                                                                                             \
      ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);                                                          \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    t->__api__(value);                                                                                               \
    Py_RETURN_TRUE;                                                                                                  \
  }

#define THING_BODY_GET_INT(__func__, __api__)                                                                        \
  PyObject *__func__(PyObject * obj, PyObject * args, PyObject * keywds)                                             \
  {                                                                                                                  \
    TRACE_AND_INDENT();                                                                                              \
    uint32_t     id       = 0;                                                                                       \
    static char *kwlist[] = {(char *) "id", 0};                                                                      \
                                                                                                                     \
    if (! PyArg_ParseTupleAndKeywords(args, keywds, "I", kwlist, &id)) {                                             \
      ERR("%s: Failed parsing keywords", __FUNCTION__);                                                              \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    Thingp t = game->thing_find(id);                                                                                 \
    if (unlikely(! t)) {                                                                                             \
      ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);                                                          \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    auto value = t->__api__();                                                                                       \
    return Py_BuildValue("i", (int) value);                                                                          \
  }

#define THING_BODY_GET_STRING(__func__, __api__)                                                                     \
  PyObject *__func__(PyObject * obj, PyObject * args, PyObject * keywds)                                             \
  {                                                                                                                  \
    TRACE_AND_INDENT();                                                                                              \
    uint32_t     id       = 0;                                                                                       \
    static char *kwlist[] = {(char *) "id", 0};                                                                      \
                                                                                                                     \
    if (! PyArg_ParseTupleAndKeywords(args, keywds, "I", kwlist, &id)) {                                             \
      ERR("%s: Failed parsing keywords", __FUNCTION__);                                                              \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    Thingp t = game->thing_find(id);                                                                                 \
    if (unlikely(! t)) {                                                                                             \
      ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);                                                          \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    auto value = t->__api__();                                                                                       \
    return Py_BuildValue("s", value.c_str());                                                                        \
  }

#define THING_BODY_SET_THING(__func__, __api__)                                                                      \
  PyObject *__func__(PyObject * obj, PyObject * args, PyObject * keywds)                                             \
  {                                                                                                                  \
    TRACE_AND_INDENT();                                                                                              \
    uint32_t     id       = 0;                                                                                       \
    uint32_t     oid      = 0;                                                                                       \
    static char *kwlist[] = {(char *) "id", (char *) "oid", 0};                                                      \
                                                                                                                     \
    if (! PyArg_ParseTupleAndKeywords(args, keywds, "II", kwlist, &id, &oid)) {                                      \
      ERR("%s: Failed parsing keywords", __FUNCTION__);                                                              \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    if (! id) {                                                                                                      \
      ERR("%s: No thing ID set", __FUNCTION__);                                                                      \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    if (! oid) {                                                                                                     \
      ERR("%s: No oid thing ID set", __FUNCTION__);                                                                  \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    Thingp t = game->thing_find(id);                                                                                 \
    if (unlikely(! t)) {                                                                                             \
      ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);                                                          \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    Thingp o = game->thing_find(oid);                                                                                \
    if (unlikely(! t)) {                                                                                             \
      ERR("%s: Cannot find thing ID %u", __FUNCTION__, oid);                                                         \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    t->__api__(o);                                                                                                   \
    Py_RETURN_TRUE;                                                                                                  \
  }

#define THING_BODY_GET_THING(__func__, __api__)                                                                      \
  PyObject *__func__(PyObject * obj, PyObject * args, PyObject * keywds)                                             \
  {                                                                                                                  \
    TRACE_AND_INDENT();                                                                                              \
    uint32_t     id       = 0;                                                                                       \
    static char *kwlist[] = {(char *) "id", 0};                                                                      \
                                                                                                                     \
    if (! PyArg_ParseTupleAndKeywords(args, keywds, "I", kwlist, &id)) {                                             \
      ERR("%s: Failed parsing keywords", __FUNCTION__);                                                              \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    if (! id) {                                                                                                      \
      ERR("%s: No thing ID set", __FUNCTION__);                                                                      \
      return Py_BuildValue("I", 0);                                                                                  \
    }                                                                                                                \
                                                                                                                     \
    Thingp t = game->thing_find(id);                                                                                 \
    if (unlikely(! t)) {                                                                                             \
      ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);                                                          \
      return Py_BuildValue("I", 0);                                                                                  \
    }                                                                                                                \
                                                                                                                     \
    ThingId found = t->__api__();                                                                                    \
    return Py_BuildValue("I", found.id);                                                                             \
  }

#define THING_BODY_GET_BOOL(__func__, __api__)                                                                       \
  PyObject *__func__(PyObject * obj, PyObject * args, PyObject * keywds)                                             \
  {                                                                                                                  \
    TRACE_AND_INDENT();                                                                                              \
    uint32_t     id       = 0;                                                                                       \
    static char *kwlist[] = {(char *) "id", 0};                                                                      \
                                                                                                                     \
    if (! PyArg_ParseTupleAndKeywords(args, keywds, "I", kwlist, &id)) {                                             \
      ERR("%s: Failed parsing keywords", __FUNCTION__);                                                              \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    if (! id) {                                                                                                      \
      ERR("%s: No thing ID set", __FUNCTION__);                                                                      \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    Thingp t = game->thing_find(id);                                                                                 \
    if (unlikely(! t)) {                                                                                             \
      ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);                                                          \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    if (t->__api__()) {                                                                                              \
      Py_RETURN_TRUE;                                                                                                \
    } else {                                                                                                         \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
  }

PyObject *thing_get_coords(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     id       = 0;
  static char *kwlist[] = {(char *) "id", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "I", kwlist, &id)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! id) {
    ERR("%s: No thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp t = game->thing_find(id);
  if (unlikely(! t)) {
    ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);
    Py_RETURN_NONE;
  }

  Py_ssize_t size      = 2;
  auto       the_tuple = PyTuple_New(size);
  if (! the_tuple) {
    ERR("%s: Cannot create tuple for ID %u", __FUNCTION__, id);
    Py_RETURN_NONE;
  }

  auto err = PyTuple_SetItem(the_tuple, (Py_ssize_t) 0, PyLong_FromLong((long) t->curr_at.x));
  if (err < 0) {
    ERR("%s: Cannot create tuple (a) for ID %u", __FUNCTION__, id);
    Py_RETURN_NONE;
  }

  err = PyTuple_SetItem(the_tuple, (Py_ssize_t) 1, PyLong_FromLong((long) t->curr_at.y));
  if (err < 0) {
    ERR("%s: Cannot create tuple (a) for ID %u", __FUNCTION__, id);
    Py_RETURN_NONE;
  }

  return the_tuple;
}

PyObject *thing_hit(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     hitter_id = 0;
  uint32_t     target_id = 0;
  static char *kwlist[]  = {(char *) "hitter", (char *) "target", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "II", kwlist, &hitter_id, &target_id)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! hitter_id) {
    ERR("%s: No hitter thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp hitter = game->thing_find(hitter_id);
  if (! hitter) {
    ERR("%s: Cannot find hitter thing ID %u", __FUNCTION__, hitter_id);
    Py_RETURN_NONE;
  }

  if (! target_id) {
    ERR("%s: No target thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp target = game->thing_find(target_id);
  if (! target) {
    ERR("%s: Cannot find target thing ID %u", __FUNCTION__, target_id);
    Py_RETURN_NONE;
  }

  if (hitter->attack(target)) {
    Py_RETURN_TRUE;
  } else {
    Py_RETURN_FALSE;
  }
}

PyObject *thing_possible_to_attack(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     hitter_id = 0;
  uint32_t     target_id = 0;
  static char *kwlist[]  = {(char *) "hitter", (char *) "target", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "II", kwlist, &hitter_id, &target_id)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! hitter_id) {
    ERR("%s: No hitter thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp hitter = game->thing_find(hitter_id);
  if (! hitter) {
    ERR("%s: Cannot find hitter thing ID %u", __FUNCTION__, hitter_id);
    Py_RETURN_NONE;
  }

  if (! target_id) {
    ERR("%s: No target thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp target = game->thing_find(target_id);
  if (! target) {
    ERR("%s: Cannot find target thing ID %u", __FUNCTION__, target_id);
    Py_RETURN_NONE;
  }

  hitter->log("Check if possible to attack target %s", target->to_string().c_str());

  if (hitter->possible_to_attack(target)) {
    hitter->log("Check if possible to target %s; yes", target->to_string().c_str());
    Py_RETURN_TRUE;
  } else {
    hitter->log("Check if possible to attack %s; no", target->to_string().c_str());
    Py_RETURN_FALSE;
  }
}

PyObject *thing_fire_at(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     owner_id  = 0;
  char        *item      = nullptr;
  uint32_t     target_id = 0;
  static char *kwlist[]  = {(char *) "owner", (char *) "item", (char *) "target", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "IsI", kwlist, &owner_id, &item, &target_id)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! owner_id) {
    ERR("%s: No owner thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp owner = game->thing_find(owner_id);
  if (! owner) {
    ERR("%s: Cannot find owner thing ID %u", __FUNCTION__, owner_id);
    Py_RETURN_NONE;
  }

  if (! item) {
    ERR("%s: No item thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! target_id) {
    ERR("%s: No target thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp target = game->thing_find(target_id);
  if (! target) {
    ERR("%s: Cannot find target thing ID %u", __FUNCTION__, target_id);
    Py_RETURN_NONE;
  }

  owner->log("Fire %s at %s", item, target->to_string().c_str());

  auto what      = std::string(item);
  auto fire_what = tp_find(what);
  if (fire_what->is_projectile()) {
    if (owner->projectile_fire_at(std::string(item), target)) {
      Py_RETURN_TRUE;
    } else {
      Py_RETURN_FALSE;
    }
  } else if (fire_what->is_laser()) {
    if (owner->laser_fire_at(std::string(item), target)) {
      Py_RETURN_TRUE;
    } else {
      Py_RETURN_FALSE;
    }
  } else {
    owner->err("Cannot fire %s at %s", item, target->to_string().c_str());
    Py_RETURN_FALSE;
  }
}

PyObject *thing_killed_by(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     me_id     = 0;
  char        *reason    = nullptr;
  uint32_t     killer_id = 0;
  static char *kwlist[]  = {(char *) "me", (char *) "reason", (char *) "defeater", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "IsI", kwlist, &me_id, &reason, &killer_id)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! me_id) {
    ERR("%s: No me thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp me = game->thing_find(me_id);
  if (! me) {
    ERR("%s: Cannot find me thing ID %u", __FUNCTION__, me_id);
    Py_RETURN_NONE;
  }

  if (! reason) {
    ERR("%s: No reason thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! killer_id) {
    ERR("%s: No defeater thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp defeater = game->thing_find(killer_id);
  if (! defeater) {
    ERR("%s: Cannot find defeater thing ID %u", __FUNCTION__, killer_id);
    Py_RETURN_NONE;
  }

  me->log("Killed by %s, reason %s", defeater->to_string().c_str(), reason);
  me->dead(defeater, "%s", reason);

  Py_RETURN_NONE;
}

PyObject *thing_kill(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     me_id    = 0;
  char        *reason   = nullptr;
  static char *kwlist[] = {(char *) "me", (char *) "reason", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &me_id, &reason)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! me_id) {
    ERR("%s: No me thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp me = game->thing_find(me_id);
  if (! me) {
    ERR("%s: Cannot find me thing ID %u", __FUNCTION__, me_id);
    Py_RETURN_NONE;
  }

  if (! reason) {
    ERR("%s: No reason thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  me->log("Defeated: reason %s", reason);
  me->dead("%s", reason);
  Py_RETURN_NONE;
}

PyObject *thing_carry(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     me_id    = 0;
  char        *what     = nullptr;
  static char *kwlist[] = {(char *) "me", (char *) "what", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &me_id, &what)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! me_id) {
    ERR("%s: No me thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp me = game->thing_find(me_id);
  if (! me) {
    ERR("%s: Cannot find me thing ID %u", __FUNCTION__, me_id);
    Py_RETURN_NONE;
  }

  if (! what) {
    me->err("Could not carry nameless object");
    Py_RETURN_NONE;
  }

  auto tp = tp_find(what);
  if (unlikely(! tp)) {
    me->err("Could not find to carry %s", what);
    Py_RETURN_NONE;
  }

  auto item = me->level->thing_new(tp, me->curr_at);
  if (! item) {
    me->err("Could not create to carry %s", what);
    Py_RETURN_NONE;
  }

  if (! me->carry(item)) {
    me->err("Could not carry %s", what);
    Py_RETURN_NONE;
  }

  return Py_BuildValue("I", item->id);
}

PyObject *thing_polymorph(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     me_id    = 0;
  char        *into     = nullptr;
  static char *kwlist[] = {(char *) "me", (char *) "into", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &me_id, &into)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! me_id) {
    ERR("%s: No me thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp me = game->thing_find(me_id);
  if (! me) {
    ERR("%s: Cannot find me thing ID %u", __FUNCTION__, me_id);
    Py_RETURN_NONE;
  }

  auto tp = tp_find(into);
  if (unlikely(! tp)) {
    ERR("%s: No polymorph into %s found", __FUNCTION__, into);
    Py_RETURN_NONE;
  }

  me->polymorph(tp);
  Py_RETURN_NONE;
}

PyObject *thing_set_manifestor(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     me_id    = 0;
  uint32_t     owner_id = 0;
  static char *kwlist[] = {(char *) "me", (char *) "owner", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "II", kwlist, &me_id, &owner_id)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! me_id) {
    ERR("%s: No me thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! owner_id) {
    ERR("%s: No owner thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp me = game->thing_find(me_id);
  if (! me) {
    ERR("%s: Cannot find me thing ID %u", __FUNCTION__, me_id);
    Py_RETURN_NONE;
  }

  Thingp owner = game->thing_find(owner_id);
  if (! owner) {
    ERR("%s: Cannot find owner thing ID %u", __FUNCTION__, owner_id);
    Py_RETURN_NONE;
  }

  me->set_manifestor(owner);
  Py_RETURN_NONE;
}

PyObject *thing_set_leader(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     me_id    = 0;
  uint32_t     owner_id = 0;
  static char *kwlist[] = {(char *) "me", (char *) "owner", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "II", kwlist, &me_id, &owner_id)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! me_id) {
    ERR("%s: No me thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! owner_id) {
    ERR("%s: No owner thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp me = game->thing_find(me_id);
  if (! me) {
    ERR("%s: Cannot find me thing ID %u", __FUNCTION__, me_id);
    Py_RETURN_NONE;
  }

  Thingp owner = game->thing_find(owner_id);
  if (! owner) {
    ERR("%s: Cannot find owner thing ID %u", __FUNCTION__, owner_id);
    Py_RETURN_NONE;
  }

  me->set_leader(owner);
  Py_RETURN_NONE;
}

PyObject *thing_buff_add(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     owner_id = 0;
  char        *what     = nullptr;
  static char *kwlist[] = {(char *) "owner", (char *) "what", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &owner_id, &what)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! owner_id) {
    ERR("%s: No owner thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp owner = game->thing_find(owner_id);
  if (! owner) {
    ERR("%s: Cannot find owner thing ID %u", __FUNCTION__, owner_id);
    Py_RETURN_NONE;
  }

  if (! what) {
    ERR("%s: No buff name set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  auto tp = tp_find(what);
  if (unlikely(! tp)) {
    ERR("%s: No buff tp called %s found", __FUNCTION__, what);
    Py_RETURN_NONE;
  }

  owner->buff_add(tp);
  Py_RETURN_NONE;
}

PyObject *thing_debuff_add(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     owner_id = 0;
  char        *what     = nullptr;
  static char *kwlist[] = {(char *) "owner", (char *) "what", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &owner_id, &what)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! owner_id) {
    ERR("%s: No owner thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp owner = game->thing_find(owner_id);
  if (! owner) {
    ERR("%s: Cannot find owner thing ID %u", __FUNCTION__, owner_id);
    Py_RETURN_NONE;
  }

  if (! what) {
    ERR("%s: No debuff name set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  auto tp = tp_find(what);
  if (unlikely(! tp)) {
    ERR("%s: No debuff tp called %s found", __FUNCTION__, what);
    Py_RETURN_NONE;
  }

  owner->debuff_add(tp);
  Py_RETURN_NONE;
}

PyObject *thing_buff_remove(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     owner_id = 0;
  char        *what     = nullptr;
  static char *kwlist[] = {(char *) "owner", (char *) "what", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &owner_id, &what)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! owner_id) {
    ERR("%s: No owner thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp owner = game->thing_find(owner_id);
  if (! owner) {
    ERR("%s: Cannot find owner thing ID %u", __FUNCTION__, owner_id);
    Py_RETURN_NONE;
  }

  if (! what) {
    ERR("%s: No buff name set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  auto tp = tp_find(what);
  if (unlikely(! tp)) {
    ERR("%s: No buff tp called %s found", __FUNCTION__, what);
    Py_RETURN_NONE;
  }

  owner->buff_remove(tp);
  Py_RETURN_NONE;
}

PyObject *thing_debuff_remove(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     owner_id = 0;
  char        *what     = nullptr;
  static char *kwlist[] = {(char *) "owner", (char *) "what", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &owner_id, &what)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! owner_id) {
    ERR("%s: No owner thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp owner = game->thing_find(owner_id);
  if (! owner) {
    ERR("%s: Cannot find owner thing ID %u", __FUNCTION__, owner_id);
    Py_RETURN_NONE;
  }

  if (! what) {
    ERR("%s: No debuff name set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  auto tp = tp_find(what);
  if (unlikely(! tp)) {
    ERR("%s: No debuff tp called %s found", __FUNCTION__, what);
    Py_RETURN_NONE;
  }

  owner->debuff_remove(tp);
  Py_RETURN_NONE;
}

PyObject *thing_msg(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     owner_id = 0;
  char        *msg      = nullptr;
  static char *kwlist[] = {(char *) "owner", (char *) "msg", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &owner_id, &msg)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_NONE;
  }

  if (! owner_id) {
    ERR("%s: No owner thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp owner = game->thing_find(owner_id);
  if (! owner) {
    ERR("%s: Cannot find owner thing ID %u", __FUNCTION__, owner_id);
    Py_RETURN_NONE;
  }

  if (! msg) {
    ERR("%s: No msg thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  //
  // If not reachable, suppress the msg
  //
  if (owner->get_distance_to_player() < DMAP_IS_PASSABLE) {
    TOPCON("%s", msg);
  }

  Py_RETURN_NONE;
}

PyObject *thing_sound_play_(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  char    *name     = 0;
  uint32_t owner_id = 0;

  static char *kwlist[] = {(char *) "owner", (char *) "name", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &owner_id, &name)) {
    ERR("thing_sound_play: Bad arguments");
    Py_RETURN_FALSE;
  }

  if (! owner_id) {
    ERR("%s: No owner thing ID set", __FUNCTION__);
    Py_RETURN_NONE;
  }

  Thingp owner = game->thing_find(owner_id);
  if (! owner) {
    ERR("%s: Cannot find owner thing ID %u", __FUNCTION__, owner_id);
    Py_RETURN_NONE;
  }

  if (! name) {
    ERR("thing_sound_play: Missing name attr");
    Py_RETURN_FALSE;
  }

  PY_DBG("thing_sound_play(name=%s)", name);

  std::string alias = name;
  if (! owner->thing_sound_play(alias)) {
    Py_RETURN_FALSE;
  }

  Py_RETURN_TRUE;
}

PyObject *thing_sound_play_channel_(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t owner_id = 0;
  char    *name     = 0;
  int      channel  = 0;

  static char *kwlist[] = {(char *) "owner", (char *) "channel", (char *) "name", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Iis", kwlist, &owner_id, &channel, &name)) {
    ERR("thing_sound_play_channel: Bad arguments");
    Py_RETURN_FALSE;
  }

  Thingp owner = game->thing_find(owner_id);
  if (! owner) {
    ERR("%s: Cannot find owner thing ID %u", __FUNCTION__, owner_id);
    Py_RETURN_NONE;
  }

  if (! name) {
    ERR("thing_sound_play: Missing name attr");
    Py_RETURN_FALSE;
  }
  if (! name) {
    ERR("thing_sound_play_channel: Missing name attr");
    Py_RETURN_FALSE;
  }

  PY_DBG("sound_play_channel(channel=%d, name=%s)", channel, name);

  std::string alias = name;
  if (! owner->thing_sound_play_channel(channel, alias)) {
    Py_RETURN_FALSE;
  }

  Py_RETURN_TRUE;
}

THING_BODY_GET_BOOL(level_is_able_to_fire_at, is_able_to_fire_at)
THING_BODY_GET_BOOL(level_is_attackable_by_monst, is_attackable_by_monst)
THING_BODY_GET_BOOL(level_is_attackable_by_player, is_attackable_by_player)
THING_BODY_GET_BOOL(thing_aggression_level_pct, aggression_level_pct)
THING_BODY_GET_BOOL(thing_collateral_damage_pct, collateral_damage_pct)
THING_BODY_GET_BOOL(thing_ai_detect_secret_doors, ai_detect_secret_doors)
THING_BODY_GET_BOOL(thing_ai_resent_count, ai_resent_count)
THING_BODY_GET_BOOL(thing_ai_wanderer, ai_wanderer)
THING_BODY_GET_BOOL(thing_attack_blood, attack_blood)
THING_BODY_GET_BOOL(thing_attack_engulf_chance_d1000, attack_engulf_chance_d1000)
THING_BODY_GET_BOOL(thing_attack_undead, attack_undead)
THING_BODY_GET_BOOL(thing_damage_acid_chance_d1000, damage_acid_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_crush_chance_d1000, damage_crush_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_digest_chance_d1000, damage_digest_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_energy_chance_d1000, damage_energy_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_fire_chance_d1000, damage_fire_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_future1_chance_d1000, damage_future1_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_future2_chance_d1000, damage_future2_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_future3_chance_d1000, damage_future3_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_future4_chance_d1000, damage_future4_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_lightning_chance_d1000, damage_lightning_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_necrosis_chance_d1000, damage_necrosis_chance_d1000)
THING_BODY_GET_BOOL(thing_damage_poison_chance_d1000, damage_poison_chance_d1000)
THING_BODY_GET_BOOL(thing_distance_jump, distance_jump)
THING_BODY_GET_BOOL(thing_distance_leader_max, distance_leader_max)
THING_BODY_GET_BOOL(thing_distance_recruitment_max, distance_recruitment_max)
THING_BODY_GET_BOOL(thing_enchant_level, enchant_level)
THING_BODY_GET_BOOL(thing_enchant_max, enchant_max)
THING_BODY_GET_BOOL(thing_environ_avoids_acid, environ_avoids_acid)
THING_BODY_GET_BOOL(thing_environ_avoids_fire, environ_avoids_fire)
THING_BODY_GET_BOOL(thing_environ_avoids_necrosis, environ_avoids_necrosis)
THING_BODY_GET_BOOL(thing_environ_avoids_poison, environ_avoids_poison)
THING_BODY_GET_BOOL(thing_environ_avoids_water, environ_avoids_water)
THING_BODY_GET_BOOL(thing_environ_prefers_acid, environ_prefers_acid)
THING_BODY_GET_BOOL(thing_environ_prefers_fire, environ_prefers_fire)
THING_BODY_GET_BOOL(thing_environ_prefers_necrosis, environ_prefers_necrosis)
THING_BODY_GET_BOOL(thing_environ_prefers_poison, environ_prefers_poison)
THING_BODY_GET_BOOL(thing_environ_prefers_spiderwebs, environ_prefers_spiderwebs)
THING_BODY_GET_BOOL(thing_environ_prefers_water, environ_prefers_water)
THING_BODY_GET_BOOL(thing_get_distance_minion_vision_shared, distance_minion_vision_shared)
THING_BODY_GET_BOOL(thing_get_distance_vision, get_distance_vision)
THING_BODY_GET_BOOL(thing_gfx_flickers, gfx_flickers)
THING_BODY_GET_BOOL(thing_gfx_long_shadow_caster, gfx_long_shadow_caster)
THING_BODY_GET_BOOL(thing_gfx_solid_shadow, gfx_solid_shadow)
THING_BODY_GET_BOOL(thing_gfx_very_short_shadow_caster, gfx_very_short_shadow_caster)
THING_BODY_GET_BOOL(thing_gfx_water, gfx_water)
THING_BODY_GET_BOOL(thing_hunger_clock_tick_frequency, get_hunger_clock_tick_frequency)
THING_BODY_GET_BOOL(thing_hunger_is_insatiable, hunger_is_insatiable)
THING_BODY_GET_BOOL(thing_is_able_to_attack_mobs, is_able_to_attack_mobs)
THING_BODY_GET_BOOL(thing_is_able_to_break_down_doors, is_able_to_break_down_doors)
THING_BODY_GET_BOOL(thing_is_able_to_break_out_of_webs, is_able_to_break_out_of_webs)
THING_BODY_GET_BOOL(thing_is_able_to_change_levels, is_able_to_change_levels)
THING_BODY_GET_BOOL(thing_is_able_to_collect_keys, is_able_to_collect_keys)
THING_BODY_GET_BOOL(thing_is_able_to_enchant_items, is_able_to_enchant_items)
THING_BODY_GET_BOOL(thing_is_able_to_fall, is_able_to_fall)
THING_BODY_GET_BOOL(thing_is_able_to_follow, is_able_to_follow)
THING_BODY_GET_BOOL(thing_is_able_to_jump_attack_chance_d1000, is_able_to_jump_attack_chance_d1000)
THING_BODY_GET_BOOL(thing_is_able_to_jump_attack, is_able_to_jump_attack)
THING_BODY_GET_BOOL(thing_is_able_to_jump_escape, is_able_to_jump_escape)
THING_BODY_GET_BOOL(thing_is_able_to_jump, is_able_to_jump)
THING_BODY_GET_BOOL(thing_is_able_to_jump_on_low_hp_chance_d1000, is_able_to_jump_on_low_hp_chance_d1000)
THING_BODY_GET_BOOL(thing_is_able_to_jump_onto_chance_d1000, is_able_to_jump_onto_chance_d1000)
THING_BODY_GET_BOOL(thing_is_able_to_jump_onto, is_able_to_jump_onto)
THING_BODY_GET_BOOL(thing_is_able_to_jump_randomly_chance_d1000, is_able_to_jump_randomly_chance_d1000)
THING_BODY_GET_BOOL(thing_is_able_to_jump_without_tiring, is_able_to_jump_without_tiring)
THING_BODY_GET_BOOL(thing_is_able_to_learn_skills, is_able_to_learn_skills)
THING_BODY_GET_BOOL(thing_is_able_to_open_doors, is_able_to_open_doors)
THING_BODY_GET_BOOL(thing_is_able_to_see_in_the_dark, is_able_to_see_in_the_dark)
THING_BODY_GET_BOOL(thing_is_able_to_see_through_doors, is_able_to_see_through_doors)
THING_BODY_GET_BOOL(thing_is_able_to_tire, is_able_to_tire)
THING_BODY_GET_BOOL(thing_is_able_to_use_weapons, is_able_to_use_weapons)
THING_BODY_GET_BOOL(thing_is_able_to_walk_through_walls, is_able_to_walk_through_walls)
THING_BODY_GET_BOOL(thing_is_acid, is_acid)
THING_BODY_GET_BOOL(thing_is_alive_monst, is_alive_monst)
THING_BODY_GET_BOOL(thing_is_alive_on_end_of_anim, is_alive_on_end_of_anim)
THING_BODY_GET_BOOL(thing_is_always_hit, is_always_hit)
THING_BODY_GET_BOOL(thing_is_aquatic, is_aquatic)
THING_BODY_GET_BOOL(thing_is_ascend_dungeon, is_ascend_dungeon)
THING_BODY_GET_BOOL(thing_is_ascend_sewer, is_ascend_sewer)
THING_BODY_GET_BOOL(thing_is_auto_collect_item, is_auto_collect_item)
THING_BODY_GET_BOOL(thing_is_auto_equipped, is_auto_equipped)
THING_BODY_GET_BOOL(thing_is_auto_throw, is_auto_throw)
THING_BODY_GET_BOOL(thing_is_auto_use, is_auto_use)
THING_BODY_GET_BOOL(thing_is_bag, is_bag)
THING_BODY_GET_BOOL(thing_is_bag_item_container, is_bag_item_container)
THING_BODY_GET_BOOL(thing_is_bag_item, is_bag_item)
THING_BODY_GET_BOOL(thing_is_bag_item_not_stackable, is_bag_item_not_stackable)
THING_BODY_GET_BOOL(thing_is_barrel, is_barrel)
THING_BODY_GET_BOOL(thing_is_bleeder, is_bleeder)
THING_BODY_GET_BOOL(thing_is_blood_eater, is_blood_eater)
THING_BODY_GET_BOOL(thing_is_bloodied, is_bloodied)
THING_BODY_GET_BOOL(thing_is_blood, is_blood)
THING_BODY_GET_BOOL(thing_is_blood_splatter, is_blood_splatter)
THING_BODY_GET_BOOL(thing_is_bones, is_bones)
THING_BODY_GET_BOOL(thing_is_bony, is_bony)
THING_BODY_GET_BOOL(thing_is_brazier, is_brazier)
THING_BODY_GET_BOOL(thing_is_bridge, is_bridge)
THING_BODY_GET_BOOL(thing_is_buff, is_buff)
THING_BODY_GET_BOOL(thing_is_burnable, is_burnable)
THING_BODY_GET_BOOL(thing_is_carrier_of_treasure_class_a, is_carrier_of_treasure_class_a)
THING_BODY_GET_BOOL(thing_is_carrier_of_treasure_class_b, is_carrier_of_treasure_class_b)
THING_BODY_GET_BOOL(thing_is_carrier_of_treasure_class_c, is_carrier_of_treasure_class_c)
THING_BODY_GET_BOOL(thing_is_carrying_item, is_carrying_item)
THING_BODY_GET_BOOL(thing_is_carrying_treasure, is_carrying_treasure)
THING_BODY_GET_BOOL(thing_is_chasm, is_chasm)
THING_BODY_GET_BOOL(thing_is_collectable, is_collectable)
THING_BODY_GET_BOOL(thing_is_collect_as_keys, is_collect_as_keys)
THING_BODY_GET_BOOL(thing_is_collected_as_gold, is_collected_as_gold)
THING_BODY_GET_BOOL(thing_is_combustible, is_combustible)
THING_BODY_GET_BOOL(thing_is_corpse, is_corpse)
THING_BODY_GET_BOOL(thing_is_corpse_on_death, is_corpse_on_death)
THING_BODY_GET_BOOL(thing_is_corridor, is_corridor)
THING_BODY_GET_BOOL(thing_is_critical_to_level, is_critical_to_level)
THING_BODY_GET_BOOL(thing_is_crushable, is_crushable)
THING_BODY_GET_BOOL(thing_is_cursor_can_hover_over, is_cursor_can_hover_over)
THING_BODY_GET_BOOL(thing_is_cursor_can_hover_over_x2_click, is_cursor_can_hover_over_x2_click)
THING_BODY_GET_BOOL(thing_is_cursor, is_cursor)
THING_BODY_GET_BOOL(thing_is_cursor_path_hazard_for_player, is_cursor_path_hazard_for_player)
THING_BODY_GET_BOOL(thing_is_cursor_path, is_cursor_path)
THING_BODY_GET_BOOL(thing_is_dead_on_end_of_anim, is_dead_on_end_of_anim)
THING_BODY_GET_BOOL(thing_is_dead_or_dying, is_dead_or_dying)
THING_BODY_GET_BOOL(thing_is_dead_or_dying_on_shove, is_dead_on_shove)
THING_BODY_GET_BOOL(thing_is_debuff, is_debuff)
THING_BODY_GET_BOOL(thing_is_debug_path, is_debug_path)
THING_BODY_GET_BOOL(thing_is_debug_type, is_debug_type)
THING_BODY_GET_BOOL(thing_is_deep_water, is_deep_water)
THING_BODY_GET_BOOL(thing_is_descend_dungeon, is_descend_dungeon)
THING_BODY_GET_BOOL(thing_is_descend_sewer, is_descend_sewer)
THING_BODY_GET_BOOL(thing_is_described_when_hovering_over, is_described_when_hovering_over)
THING_BODY_GET_BOOL(thing_is_destroyed_on_hit_or_miss, is_destroyed_on_hit_or_miss)
THING_BODY_GET_BOOL(thing_is_destroyed_on_hitting, is_destroyed_on_hitting)
THING_BODY_GET_BOOL(thing_is_dir_bl, is_dir_bl)
THING_BODY_GET_BOOL(thing_is_dir_br, is_dir_br)
THING_BODY_GET_BOOL(thing_is_dir_down, is_dir_down)
THING_BODY_GET_BOOL(thing_is_dir_left, is_dir_left)
THING_BODY_GET_BOOL(thing_is_dir_none, is_dir_none)
THING_BODY_GET_BOOL(thing_is_dir_right, is_dir_right)
THING_BODY_GET_BOOL(thing_is_dirt, is_dirt)
THING_BODY_GET_BOOL(thing_is_dir_tl, is_dir_tl)
THING_BODY_GET_BOOL(thing_is_dir_tr, is_dir_tr)
THING_BODY_GET_BOOL(thing_is_dir_up, is_dir_up)
THING_BODY_GET_BOOL(thing_is_door, is_door)
THING_BODY_GET_BOOL(thing_is_droppable, is_droppable)
THING_BODY_GET_BOOL(thing_is_dry_grass, is_dry_grass)
THING_BODY_GET_BOOL(thing_is_enchantable, is_enchantable)
THING_BODY_GET_BOOL(thing_is_enchantstone, is_enchantstone)
THING_BODY_GET_BOOL(thing_is_engulfer, is_engulfer)
THING_BODY_GET_BOOL(thing_is_ethereal, is_ethereal)
THING_BODY_GET_BOOL(thing_is_ethereal_mob, is_ethereal_mob)
THING_BODY_GET_BOOL(thing_is_exit_finder, is_exit_finder)
THING_BODY_GET_BOOL(thing_is_explorer, is_explorer)
THING_BODY_GET_BOOL(thing_is_explosion, is_explosion)
THING_BODY_GET_BOOL(thing_is_fearless, is_fearless)
THING_BODY_GET_BOOL(thing_is_fire, is_fire)
THING_BODY_GET_BOOL(thing_is_floating, is_floating)
THING_BODY_GET_BOOL(thing_is_floor_deco, is_floor_deco)
THING_BODY_GET_BOOL(thing_is_floor, is_floor)
THING_BODY_GET_BOOL(thing_is_foilage, is_foilage)
THING_BODY_GET_BOOL(thing_is_food_eater, is_food_eater)
THING_BODY_GET_BOOL(thing_is_food, is_food)
THING_BODY_GET_BOOL(thing_is_gfx_anim_synced_with_owner, is_gfx_anim_synced_with_owner)
THING_BODY_GET_BOOL(thing_is_glass, is_glass)
THING_BODY_GET_BOOL(thing_is_gold, is_gold)
THING_BODY_GET_BOOL(thing_is_green_blooded, is_green_blooded)
THING_BODY_GET_BOOL(thing_is_green_splatter, is_green_splatter)
THING_BODY_GET_BOOL(thing_is_hazard, is_hazard)
THING_BODY_GET_BOOL(thing_is_health_booster, is_health_booster)
THING_BODY_GET_BOOL(thing_is_heavy, is_heavy)
THING_BODY_GET_BOOL(thing_is_hittable, is_hittable)
THING_BODY_GET_BOOL(thing_is_humanoid, is_humanoid)
THING_BODY_GET_BOOL(thing_is_indestructible, is_indestructible)
THING_BODY_GET_BOOL(thing_is_intelligent, is_intelligent)
THING_BODY_GET_BOOL(thing_is_interesting, is_interesting)
THING_BODY_GET_BOOL(thing_is_item_carrier, is_item_carrier)
THING_BODY_GET_BOOL(thing_is_item_collector, is_item_collector)
THING_BODY_GET_BOOL(thing_is_item_eater, is_item_eater)
THING_BODY_GET_BOOL(thing_is_item, is_item)
THING_BODY_GET_BOOL(thing_is_item_magical_eater, is_item_magical_eater)
THING_BODY_GET_BOOL(thing_is_item_magical, is_item_magical)
THING_BODY_GET_BOOL(thing_is_item_organic, is_item_organic)
THING_BODY_GET_BOOL(thing_is_jelly_baby_eater, is_jelly_baby_eater)
THING_BODY_GET_BOOL(thing_is_jelly_baby, is_jelly_baby)
THING_BODY_GET_BOOL(thing_is_jelly_eater, is_jelly_eater)
THING_BODY_GET_BOOL(thing_is_jelly, is_jelly)
THING_BODY_GET_BOOL(thing_is_jelly_parent, is_jelly_parent)
THING_BODY_GET_BOOL(thing_is_key, is_key)
THING_BODY_GET_BOOL(thing_is_laser, is_laser)
THING_BODY_GET_BOOL(thing_is_lava, is_lava)
THING_BODY_GET_BOOL(thing_is_light_blocker, is_light_blocker)
THING_BODY_GET_BOOL(thing_is_living, is_living)
THING_BODY_GET_BOOL(thing_is_loggable, is_loggable)
THING_BODY_GET_BOOL(thing_is_meat_eater, is_meat_eater)
THING_BODY_GET_BOOL(thing_is_meat, is_meat)
THING_BODY_GET_BOOL(thing_is_metal, is_metal)
THING_BODY_GET_BOOL(thing_is_mob, is_mob)
THING_BODY_GET_BOOL(thing_is_minion, is_minion)
THING_BODY_GET_BOOL(thing_is_monst, is_monst)
THING_BODY_GET_BOOL(thing_is_moveable, is_moveable)
THING_BODY_GET_BOOL(thing_is_msg, is_msg)
THING_BODY_GET_BOOL(thing_is_necrotic_danger_level, is_necrotic_danger_level)
THING_BODY_GET_BOOL(thing_is_no_tile, is_no_tile)
THING_BODY_GET_BOOL(thing_is_obs_destructable, is_obs_destructable)
THING_BODY_GET_BOOL(thing_is_obs_wall_or_door, is_obs_wall_or_door)
THING_BODY_GET_BOOL(thing_is_on_fire, is_on_fire)
THING_BODY_GET_BOOL(thing_is_openable, is_openable)
THING_BODY_GET_BOOL(thing_is_organic, is_organic)
THING_BODY_GET_BOOL(thing_is_pink_blooded, is_pink_blooded)
THING_BODY_GET_BOOL(thing_is_pink_splatter, is_pink_splatter)
THING_BODY_GET_BOOL(thing_is_player, is_player)
THING_BODY_GET_BOOL(thing_is_poisonous_danger_level, is_poisonous_danger_level)
THING_BODY_GET_BOOL(thing_is_potion_eater, is_potion_eater)
THING_BODY_GET_BOOL(thing_is_potion, is_potion)
THING_BODY_GET_BOOL(thing_is_projectile, is_projectile)
THING_BODY_GET_BOOL(thing_is_red_blooded, is_red_blooded)
THING_BODY_GET_BOOL(thing_is_removeable_if_out_of_slots, is_removeable_if_out_of_slots)
THING_BODY_GET_BOOL(thing_is_resurrectable, is_resurrectable)
THING_BODY_GET_BOOL(thing_is_ring, is_ring)
THING_BODY_GET_BOOL(thing_is_ripple, is_ripple)
THING_BODY_GET_BOOL(thing_is_rock, is_rock)
THING_BODY_GET_BOOL(thing_is_rusty, is_rusty)
THING_BODY_GET_BOOL(thing_is_secret_door, is_secret_door)
THING_BODY_GET_BOOL(thing_is_sewer_wall, is_sewer_wall)
THING_BODY_GET_BOOL(thing_is_shallow_water, is_shallow_water)
THING_BODY_GET_BOOL(thing_is_shovable, is_shovable)
THING_BODY_GET_BOOL(thing_is_skill, is_skill)
THING_BODY_GET_BOOL(thing_is_skillstone, is_skillstone)
THING_BODY_GET_BOOL(thing_is_smoke, is_smoke)
THING_BODY_GET_BOOL(thing_is_soft_body, is_soft_body)
THING_BODY_GET_BOOL(thing_is_spawner, is_spawner)
THING_BODY_GET_BOOL(thing_is_spider, is_spider)
THING_BODY_GET_BOOL(thing_is_spiderweb, is_spiderweb)
THING_BODY_GET_BOOL(thing_is_steal_item_chance_d1000, is_steal_item_chance_d1000)
THING_BODY_GET_BOOL(thing_is_sticky, is_sticky)
THING_BODY_GET_BOOL(thing_is_stone, is_stone)
THING_BODY_GET_BOOL(thing_is_sword, is_sword)
THING_BODY_GET_BOOL(thing_is_target_auto_select, is_target_auto_select)
THING_BODY_GET_BOOL(thing_is_throwable, is_throwable)
THING_BODY_GET_BOOL(thing_is_tickable, is_tickable)
THING_BODY_GET_BOOL(thing_is_tmp_thing, is_tmp_thing)
THING_BODY_GET_BOOL(thing_is_torch, is_torch)
THING_BODY_GET_BOOL(thing_is_treasure_chest, is_treasure_chest)
THING_BODY_GET_BOOL(thing_is_treasure_class_a, is_treasure_class_a)
THING_BODY_GET_BOOL(thing_is_treasure_class_b, is_treasure_class_b)
THING_BODY_GET_BOOL(thing_is_treasure_class_c, is_treasure_class_c)
THING_BODY_GET_BOOL(thing_is_treasure_eater, is_treasure_eater)
THING_BODY_GET_BOOL(thing_is_treasure_type, is_treasure_type)
THING_BODY_GET_BOOL(thing_is_undead, is_undead)
THING_BODY_GET_BOOL(thing_is_usable, is_usable)
THING_BODY_GET_BOOL(thing_is_used_when_thrown, is_used_when_thrown)
THING_BODY_GET_BOOL(thing_is_very_combustible, is_very_combustible)
THING_BODY_GET_BOOL(thing_is_visible, is_visible)
THING_BODY_GET_BOOL(thing_is_wall_dungeon, is_wall_dungeon)
THING_BODY_GET_BOOL(thing_is_wall, is_wall)
THING_BODY_GET_BOOL(thing_is_wand, is_wand)
THING_BODY_GET_BOOL(thing_is_water, is_water)
THING_BODY_GET_BOOL(thing_is_able_to_use_rings, is_able_to_use_rings)
THING_BODY_GET_BOOL(thing_is_weapon, is_weapon)
THING_BODY_GET_BOOL(thing_is_wooden, is_wooden)
THING_BODY_GET_BOOL(thing_spawn_group_radius, get_spawn_group_radius)
THING_BODY_GET_BOOL(thing_unused_flag1, unused_flag1)
THING_BODY_GET_BOOL(thing_unused_flag2, unused_flag2)
THING_BODY_GET_BOOL(thing_unused_flag3, unused_flag3)
THING_BODY_GET_BOOL(thing_unused_flag4, unused_flag4)
THING_BODY_GET_BOOL(thing_unused_flag5, unused_flag5)
THING_BODY_GET_BOOL(thing_unused_flag6, unused_flag6)
THING_BODY_GET_BOOL(thing_unused_flag7, unused_flag7)
THING_BODY_GET_BOOL(thing_is_able_to_use_wands, is_able_to_use_wands)
THING_BODY_GET_INT(thing_get_charge_count, get_charge_count)
THING_BODY_GET_INT(thing_get_current_damage, get_current_damage)
THING_BODY_GET_INT(thing_get_damage_acid, get_damage_acid)
THING_BODY_GET_INT(thing_get_damage_bite, get_damage_bite)
THING_BODY_GET_INT(thing_get_damage_crush, get_damage_crush)
THING_BODY_GET_INT(thing_get_damage_digest, get_damage_digest)
THING_BODY_GET_INT(thing_get_damage_energy, get_damage_energy)
THING_BODY_GET_INT(thing_get_damage_fire, get_damage_fire)
THING_BODY_GET_INT(thing_get_damage_future1, get_damage_future1)
THING_BODY_GET_INT(thing_get_damage_future2, get_damage_future2)
THING_BODY_GET_INT(thing_get_damage_future3, get_damage_future3)
THING_BODY_GET_INT(thing_get_damage_future4, get_damage_future4)
THING_BODY_GET_INT(thing_get_damage_lightning, get_damage_lightning)
THING_BODY_GET_INT(thing_get_damage_melee, get_damage_melee)
THING_BODY_GET_INT(thing_get_damage_necrosis, get_damage_necrosis)
THING_BODY_GET_INT(thing_get_damage_poison, get_damage_poison)
THING_BODY_GET_INT(thing_get_enchant, get_enchant)
THING_BODY_GET_INT(thing_get_enchant_max, get_enchant_max)
THING_BODY_GET_INT(thing_get_health, get_health)
THING_BODY_GET_INT(thing_get_health_max, get_health_max)
THING_BODY_GET_INT(thing_get_initial_charge_count, get_initial_charge_count)
THING_BODY_GET_INT(thing_get_necrotized_amount, get_necrotized_amount)
THING_BODY_GET_INT(thing_get_poisoned_amount, get_poisoned_amount)
THING_BODY_GET_INT(thing_get_stamina, get_stamina)
THING_BODY_GET_INT(thing_get_stamina_max, get_stamina_max)
THING_BODY_GET_STRING(thing_get_name, text_name)
THING_BODY_GET_THING(thing_get_immediate_manifestor_id, get_immediate_manifestor_id)
THING_BODY_GET_THING(thing_get_immediate_owner_id, get_immediate_owner_id)
THING_BODY_GET_THING(thing_get_immediate_spawned_owner_id, get_immediate_spawned_owner_id)
THING_BODY_GET_THING(thing_get_leader_id, get_leader_id)
THING_BODY_GET_THING(thing_get_top_owner_id, get_top_owner_id)
THING_BODY_SET_INT(thing_decr_charge_count, decr_charge_count)
THING_BODY_SET_INT(thing_decr_current_damage, decr_current_damage)
THING_BODY_SET_INT(thing_decr_enchant, decr_enchant)
THING_BODY_SET_INT(thing_decr_enchant_max, decr_enchant_max)
THING_BODY_SET_INT(thing_decr_health, decr_health)
THING_BODY_SET_INT(thing_decr_health_max, decr_health_max)
THING_BODY_SET_INT(thing_decr_necrotized_amount, decr_necrotized_amount)
THING_BODY_SET_INT(thing_decr_poisoned_amount, decr_poisoned_amount)
THING_BODY_SET_INT(thing_decr_stamina, decr_stamina)
THING_BODY_SET_INT(thing_decr_stamina_max, decr_stamina_max)
THING_BODY_SET_INT(thing_incr_charge_count, incr_charge_count)
THING_BODY_SET_INT(thing_incr_current_damage, incr_current_damage)
THING_BODY_SET_INT(thing_incr_enchant, incr_enchant)
THING_BODY_SET_INT(thing_incr_enchant_max, incr_enchant_max)
THING_BODY_SET_INT(thing_incr_health, incr_health)
THING_BODY_SET_INT(thing_incr_health_max, incr_health_max)
THING_BODY_SET_INT(thing_incr_necrotized_amount, incr_necrotized_amount)
THING_BODY_SET_INT(thing_incr_poisoned_amount, incr_poisoned_amount)
THING_BODY_SET_INT(thing_incr_stamina, incr_stamina)
THING_BODY_SET_INT(thing_incr_stamina_max, incr_stamina_max)
THING_BODY_SET_INT(thing_set_current_damage, set_current_damage)
THING_BODY_SET_INT(thing_set_enchant_max, set_enchant_max)
THING_BODY_SET_INT(thing_set_enchant, set_enchant)
THING_BODY_SET_INT(thing_set_health_max, set_health_max)
THING_BODY_SET_INT(thing_set_health, set_health)
THING_BODY_SET_INT(thing_set_necrotized_amount, set_necrotized_amount)
THING_BODY_SET_INT(thing_set_poisoned_amount, set_poisoned_amount)
THING_BODY_SET_INT(thing_set_stamina_max, set_stamina_max)
THING_BODY_SET_INT(thing_set_stamina, set_stamina)
THING_BODY_SET_THING(thing_skill_activate, skill_activate)
THING_BODY_SET_THING(thing_skill_deactivate, skill_deactivate)
