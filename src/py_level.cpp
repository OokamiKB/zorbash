//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_depth.hpp"
#include "my_game.hpp"
#include "my_level.hpp"
#include "my_level_static.hpp"
#include "my_main.hpp"
#include "my_ptrcheck.hpp"
#include "my_python.hpp"
#include "my_sys.hpp"
#include "my_thing.hpp"
#include "my_vector_bounds_check.hpp"
#include <array>

PyObject *level_add_(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  char     *level_name    = 0;
  PyObject *py_level_data = 0;

  static char *kwlist[] = {(char *) "level_data", (char *) "level_name", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "|Os", kwlist, &py_level_data, &level_name)) {
    ERR("map_load: Bad args");
    Py_RETURN_FALSE;
  }

  if (! py_level_data) {
    ERR("Map_load_level, missing floor data");
    Py_RETURN_FALSE;
  }

  int level_data_elems = PyList_Size(py_level_data);
  if (level_data_elems % MAP_HEIGHT) {
    ERR("map_load: Level elems needs to be evenly dividable by level height %d, got %d elems when loading %s",
        (int) MAP_HEIGHT, (int) PyList_Size(py_level_data), level_name);
    Py_RETURN_FALSE;
  }

  auto l = LevelStatic::level_new();
  for (auto n = 0; n < MAP_WIDTH; n++) {
    for (auto y = 0; y < MAP_HEIGHT; y++) {
      auto o = PyList_GetItem(py_level_data, y); /* Can't fail */
      if (! o) {
        continue;
      }

      std::string floor_string;
      std::string floor2_string;
      std::string water_string;
      std::string lava_string;
      std::string chasm_string;
      std::string walls_string;
      std::string obj_strings;

      for (auto &c : py_obj_to_string(o)) {
        auto m = get(Charmap::all_charmaps, c);

        if (m.is_floor || m.is_bridge || m.is_corridor || m.is_secret_corridor || m.is_dirt) {
          floor_string += c;
        } else if (m.is_blood || m.is_deep_water || m.is_door || m.is_ascend_dungeon || m.is_descend_dungeon ||
                   m.is_descend_sewer || m.is_floor_deco || m.is_food || m.is_minion_generator_easy ||
                   m.is_minion_generator_hard || m.is_gold || m.is_key || m.is_lava || m.is_monst_easy ||
                   m.is_monst_med || m.is_monst_hard || m.is_enchantstone || m.is_skillstone ||
                   m.is_treasure_class_a || m.is_treasure_class_b || m.is_treasure_class_c || m.is_potion ||
                   m.is_wand || m.is_ring || m.is_secret_door || m.is_brazier || m.is_barrel || m.is_trap ||
                   m.is_shallow_water || m.is_deep_water || m.is_floor_deco) {
          floor_string += Charmap::FLOOR;
        } else {
          floor_string += Charmap::SPACE;
        }

        if (m.is_foilage || m.is_spiderweb || m.is_dry_grass) {
          floor2_string += c;
        } else {
          floor2_string += Charmap::SPACE;
        }

        if (m.is_shallow_water || m.is_deep_water) {
          water_string += c;
        } else {
          water_string += Charmap::SPACE;
        }

        if (m.is_lava) {
          lava_string += c;
        } else {
          lava_string += Charmap::SPACE;
        }

        if (m.is_chasm) {
          chasm_string += c;
        } else {
          chasm_string += Charmap::SPACE;
        }

        if (m.is_wall || m.is_secret_door || m.is_door) {
          walls_string += c;
        } else if (m.is_descend_sewer) {
          walls_string += Charmap::WALL;
        } else {
          walls_string += Charmap::SPACE;
        }

        if (m.is_blood || m.is_ascend_dungeon || m.is_descend_dungeon || m.is_descend_sewer || m.is_floor_deco ||
            m.is_food || m.is_minion_generator_easy || m.is_minion_generator_hard || m.is_gold || m.is_key ||
            m.is_monst_easy || m.is_monst_med || m.is_monst_hard || m.is_enchantstone || m.is_skillstone ||
            m.is_treasure_class_a || m.is_treasure_class_b || m.is_treasure_class_c || m.is_potion || m.is_wand ||
            m.is_ring || m.is_brazier || m.is_barrel || m.is_trap || m.is_descend_sewer) {
          obj_strings += c;
        } else {
          obj_strings += Charmap::SPACE;
        }
      }

      if (floor_string.size() != MAP_WIDTH) {
        DIE("Level floor width mismatch, %d, expected %d", (int) floor_string.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }
      if (floor2_string.size() != MAP_WIDTH) {
        DIE("Room floor2 width mismatch, %d, expected %d", (int) floor2_string.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }
      if (water_string.size() != MAP_WIDTH) {
        DIE("Level water width mismatch, %d, expected %d", (int) water_string.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }
      if (lava_string.size() != MAP_WIDTH) {
        DIE("Level lava width mismatch, %d, expected %d", (int) lava_string.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }
      if (chasm_string.size() != MAP_WIDTH) {
        DIE("Level chasm width mismatch, %d, expected %d", (int) chasm_string.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }
      if (walls_string.size() != MAP_WIDTH) {
        DIE("Level walls width mismatch, %d, expected %d", (int) walls_string.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }
      if (obj_strings.size() != MAP_WIDTH) {
        DIE("Level items width mismatch, %d, expected %d", (int) obj_strings.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }

      for (auto x = 0; x < MAP_WIDTH; x++) {
        if (floor_string[ x ] != ' ') {
          set(l->data, x, y, MAP_DEPTH_FLOOR, floor_string[ x ]);
        }
        if (floor2_string[ x ] != ' ') {
          set(l->data, x, y, MAP_DEPTH_FLOOR2, floor2_string[ x ]);
        }
        if (water_string[ x ] != ' ') {
          set(l->data, x, y, MAP_DEPTH_WATER, water_string[ x ]);
        }
        if (lava_string[ x ] != ' ') {
          set(l->data, x, y, MAP_DEPTH_LAVA, lava_string[ x ]);
        }
        if (chasm_string[ x ] != ' ') {
          set(l->data, x, y, MAP_DEPTH_CHASM, chasm_string[ x ]);
        }
        if (walls_string[ x ] != ' ') {
          set(l->data, x, y, MAP_DEPTH_OBJ, walls_string[ x ]);
        }
        if (obj_strings[ x ] != ' ') {
          set(l->data, x, y, MAP_DEPTH_OBJ, obj_strings[ x ]);
        }
      }

      if (floor_string.size() != MAP_WIDTH) {
        ERR("Level floor width mismatch, %d, expected %d", (int) floor_string.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }
      if (water_string.size() != MAP_WIDTH) {
        ERR("Level water width mismatch, %d, expected %d", (int) water_string.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }
      if (walls_string.size() != MAP_WIDTH) {
        ERR("Level walls width mismatch, %d, expected %d", (int) walls_string.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }
      if (obj_strings.size() != MAP_WIDTH) {
        ERR("Level items width mismatch, %d, expected %d", (int) obj_strings.size(), MAP_WIDTH);
        Py_RETURN_FALSE;
      }

      for (auto x = 0; x < MAP_WIDTH; x++) {
        set(l->data, x, y, MAP_DEPTH_FLOOR, floor_string[ x ]);
        set(l->data, x, y, MAP_DEPTH_WATER, water_string[ x ]);
        set(l->data, x, y, MAP_DEPTH_LAVA, lava_string[ x ]);
        set(l->data, x, y, MAP_DEPTH_CHASM, chasm_string[ x ]);
        set(l->data, x, y, MAP_DEPTH_OBJ, walls_string[ x ]);
      }
    }
  }
  l->finalize();

  Py_RETURN_TRUE;
}

PyObject *level_get_all(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     id       = 0;
  int          x        = -1;
  int          y        = -1;
  static char *kwlist[] = {(char *) "id", (char *) "x", (char *) "y", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Iii", kwlist, &id, &x, &y)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_FALSE;
  }

  if (! id) {
    ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);
    Py_RETURN_FALSE;
  }

  Thingp t = game->thing_find(id);
  if (unlikely(! t)) {
    ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);
    Py_RETURN_NONE;
  }

  if (t->level->is_oob(x, y)) {
    PyObject *lst = PyList_New(0);
    return (lst);
  }

  auto items = 0;
  FOR_ALL_THINGS(t->level, t, x, y)
  {
    //
    // Don't include carried things else lasers will destroy all items carried!
    //
    if (t->get_immediate_owner()) {
      continue;
    }
    items++;
  }
  FOR_ALL_THINGS_END()

  PyObject *lst  = PyList_New(items);
  auto      item = 0;
  FOR_ALL_THINGS(t->level, t, x, y)
  {
    //
    // Don't include carried things else lasers will destroy all items carried!
    //
    if (t->get_immediate_owner()) {
      continue;
    }
    PyList_SetItem(lst, item, Py_BuildValue("I", t->id));
    item++;
  }
  FOR_ALL_THINGS_END()

  return (lst);
}

PyObject *level_flood_fill_get_all_things(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  uint32_t     id       = 0;
  int          x        = -1;
  int          y        = -1;
  static char *kwlist[] = {(char *) "id", (char *) "x", (char *) "y", (char *) "filter", 0};
  char        *filter   = nullptr;

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "Iiis", kwlist, &id, &x, &y, &filter)) {
    ERR("%s: Failed parsing keywords", __FUNCTION__);
    Py_RETURN_FALSE;
  }

  if (! id) {
    ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);
    Py_RETURN_FALSE;
  }

  if (! filter) {
    ERR("%s: No filter specified %u", __FUNCTION__, id);
    Py_RETURN_FALSE;
  }

  Thingp t = game->thing_find(id);
  if (unlikely(! t)) {
    ERR("%s: Cannot find thing ID %u", __FUNCTION__, id);
    Py_RETURN_NONE;
  }

  if (t->level->is_oob(x, y)) {
    PyObject *lst = PyList_New(0);
    return (lst);
  }

  auto      things = t->level->flood_fill_things(point(x, y), Thing::matches_to_func(filter));
  auto      items  = things.size();
  PyObject *lst    = PyList_New(items);
  auto      item   = 0;
  for (auto t : things) {
    PyList_SetItem(lst, item, Py_BuildValue("I", t->id));
    item++;
  }

  return (lst);
}

#define LEVEL_BODY_GET_BOOL_AT(__func__, __api__)                                                                    \
  PyObject *__func__(PyObject * obj, PyObject * args, PyObject * keywds)                                             \
  {                                                                                                                  \
    TRACE_AND_INDENT();                                                                                              \
    uint32_t     id       = 0;                                                                                       \
    int          x        = -1;                                                                                      \
    int          y        = -1;                                                                                      \
    static char *kwlist[] = {(char *) "id", (char *) "x", (char *) "y", 0};                                          \
                                                                                                                     \
    if (! PyArg_ParseTupleAndKeywords(args, keywds, "Iii", kwlist, &id, &x, &y)) {                                   \
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
    if (t->level->is_oob(x, y)) {                                                                                    \
      Py_RETURN_FALSE;                                                                                               \
    }                                                                                                                \
                                                                                                                     \
    FOR_ALL_THINGS(t->level, t, x, y)                                                                                \
    {                                                                                                                \
      if (t->__api__()) {                                                                                            \
        Py_RETURN_TRUE;                                                                                              \
      }                                                                                                              \
    }                                                                                                                \
    FOR_ALL_THINGS_END()                                                                                             \
                                                                                                                     \
    Py_RETURN_FALSE;                                                                                                 \
  }

LEVEL_BODY_GET_BOOL_AT(level_aggression_level_pct_at, aggression_level_pct)
LEVEL_BODY_GET_BOOL_AT(level_ai_detect_secret_doors_at, ai_detect_secret_doors)
LEVEL_BODY_GET_BOOL_AT(level_ai_resent_count_at, ai_resent_count)
LEVEL_BODY_GET_BOOL_AT(level_ai_wanderer_at, ai_wanderer)
LEVEL_BODY_GET_BOOL_AT(level_attack_blood_at, attack_blood)
LEVEL_BODY_GET_BOOL_AT(level_attack_engulf_chance_d1000_at, attack_engulf_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_attack_undead_at, attack_undead)
LEVEL_BODY_GET_BOOL_AT(level_damage_necrosis_chance_d1000_at, damage_necrosis_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_poison_chance_d1000_at, damage_poison_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_future1_chance_d1000_at, damage_future1_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_future2_chance_d1000_at, damage_future2_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_future3_chance_d1000_at, damage_future3_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_future4_chance_d1000_at, damage_future4_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_fire_chance_d1000_at, damage_fire_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_crush_chance_d1000_at, damage_crush_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_lightning_chance_d1000_at, damage_lightning_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_energy_chance_d1000_at, damage_energy_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_acid_chance_d1000_at, damage_acid_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_damage_digest_chance_d1000_at, damage_digest_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_enchant_level_at, enchant_level)
LEVEL_BODY_GET_BOOL_AT(level_enchant_max_at, enchant_max)
LEVEL_BODY_GET_BOOL_AT(level_environ_avoids_acid_at, environ_avoids_acid)
LEVEL_BODY_GET_BOOL_AT(level_environ_avoids_fire_at, environ_avoids_fire)
LEVEL_BODY_GET_BOOL_AT(level_environ_avoids_necrosis_at, environ_avoids_necrosis)
LEVEL_BODY_GET_BOOL_AT(level_environ_avoids_poison_at, environ_avoids_poison)
LEVEL_BODY_GET_BOOL_AT(level_environ_avoids_water_at, environ_avoids_water)
LEVEL_BODY_GET_BOOL_AT(level_environ_prefers_acid_at, environ_prefers_acid)
LEVEL_BODY_GET_BOOL_AT(level_environ_prefers_fire_at, environ_prefers_fire)
LEVEL_BODY_GET_BOOL_AT(level_environ_prefers_necrosis_at, environ_prefers_necrosis)
LEVEL_BODY_GET_BOOL_AT(level_environ_prefers_poison_at, environ_prefers_poison)
LEVEL_BODY_GET_BOOL_AT(level_environ_prefers_spiderwebs_at, environ_prefers_spiderwebs)
LEVEL_BODY_GET_BOOL_AT(level_environ_prefers_water_at, environ_prefers_water)
LEVEL_BODY_GET_BOOL_AT(level_gfx_flickers_at, gfx_flickers)
LEVEL_BODY_GET_BOOL_AT(level_gfx_long_shadow_caster_at, gfx_long_shadow_caster)
LEVEL_BODY_GET_BOOL_AT(level_gfx_solid_shadow_at, gfx_solid_shadow)
LEVEL_BODY_GET_BOOL_AT(level_gfx_very_short_shadow_caster_at, gfx_very_short_shadow_caster)
LEVEL_BODY_GET_BOOL_AT(level_gfx_water_at, gfx_water)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_attack_generators_at, is_able_to_attack_generators)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_break_down_doors_at, is_able_to_break_down_doors)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_break_out_of_webs_at, is_able_to_break_out_of_webs)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_change_levels_at, is_able_to_change_levels)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_collect_keys_at, is_able_to_collect_keys)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_enchant_items_at, is_able_to_enchant_items)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_fall_at, is_able_to_fall)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_fire_at_at, is_able_to_fire_at)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_jump_at, is_able_to_jump)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_jump_attack_at, is_able_to_jump_attack)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_jump_attack_chance_d1000_at, is_able_to_jump_attack_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_jump_onto_at, is_able_to_jump_onto)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_jump_onto_chance_d1000_at, is_able_to_jump_onto_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_jump_on_low_hp_chance_d1000_at, is_able_to_jump_on_low_hp_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_jump_randomly_chance_d1000_at, is_able_to_jump_randomly_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_learn_skills_at, is_able_to_learn_skills)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_open_doors_at, is_able_to_open_doors)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_see_in_the_dark_at, is_able_to_see_in_the_dark)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_see_through_doors_at, is_able_to_see_through_doors)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_tire_at, is_able_to_tire)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_walk_through_walls_at, is_able_to_walk_through_walls)
LEVEL_BODY_GET_BOOL_AT(level_is_acid_at, is_acid)
LEVEL_BODY_GET_BOOL_AT(level_is_alive_monst_at, is_alive_monst)
LEVEL_BODY_GET_BOOL_AT(level_is_alive_on_end_of_anim_at, is_alive_on_end_of_anim)
LEVEL_BODY_GET_BOOL_AT(level_is_always_hit_at, is_always_hit)
LEVEL_BODY_GET_BOOL_AT(level_is_ascend_dungeon_at, is_ascend_dungeon)
LEVEL_BODY_GET_BOOL_AT(level_is_ascend_sewer_at, is_ascend_sewer)
LEVEL_BODY_GET_BOOL_AT(level_is_attackable_by_monst_at, is_attackable_by_monst)
LEVEL_BODY_GET_BOOL_AT(level_is_attackable_by_player_at, is_attackable_by_player)
LEVEL_BODY_GET_BOOL_AT(level_is_auto_collect_item_at, is_auto_collect_item)
LEVEL_BODY_GET_BOOL_AT(level_is_auto_equipped_at, is_auto_equipped)
LEVEL_BODY_GET_BOOL_AT(level_is_auto_throw_at, is_auto_throw)
LEVEL_BODY_GET_BOOL_AT(level_is_auto_use_at, is_auto_use)
LEVEL_BODY_GET_BOOL_AT(level_is_bag_at, is_bag)
LEVEL_BODY_GET_BOOL_AT(level_is_bag_item_at, is_bag_item)
LEVEL_BODY_GET_BOOL_AT(level_is_bag_item_container_at, is_bag_item_container)
LEVEL_BODY_GET_BOOL_AT(level_is_bag_item_not_stackable_at, is_bag_item_not_stackable)
LEVEL_BODY_GET_BOOL_AT(level_is_barrel_at, is_barrel)
LEVEL_BODY_GET_BOOL_AT(level_is_bleeder_at, is_bleeder)
LEVEL_BODY_GET_BOOL_AT(level_is_blood_at, is_blood)
LEVEL_BODY_GET_BOOL_AT(level_is_blood_eater_at, is_blood_eater)
LEVEL_BODY_GET_BOOL_AT(level_is_bloodied_at, is_bloodied)
LEVEL_BODY_GET_BOOL_AT(level_is_blood_splatter_at, is_blood_splatter)
LEVEL_BODY_GET_BOOL_AT(level_is_bones_at, is_bones)
LEVEL_BODY_GET_BOOL_AT(level_is_brazier_at, is_brazier)
LEVEL_BODY_GET_BOOL_AT(level_is_bridge_at, is_bridge)
LEVEL_BODY_GET_BOOL_AT(level_is_buff_at, is_buff)
LEVEL_BODY_GET_BOOL_AT(level_is_burnable_at, is_burnable)
LEVEL_BODY_GET_BOOL_AT(level_is_carrier_of_treasure_class_a_at, is_carrier_of_treasure_class_a)
LEVEL_BODY_GET_BOOL_AT(level_is_carrier_of_treasure_class_b_at, is_carrier_of_treasure_class_b)
LEVEL_BODY_GET_BOOL_AT(level_is_carrier_of_treasure_class_c_at, is_carrier_of_treasure_class_c)
LEVEL_BODY_GET_BOOL_AT(level_is_carrying_item_at, is_carrying_item)
LEVEL_BODY_GET_BOOL_AT(level_is_carrying_treasure_at, is_carrying_treasure)
LEVEL_BODY_GET_BOOL_AT(level_is_chasm_at, is_chasm)
LEVEL_BODY_GET_BOOL_AT(level_is_collectable_at, is_collectable)
LEVEL_BODY_GET_BOOL_AT(level_is_collect_as_keys_at, is_collect_as_keys)
LEVEL_BODY_GET_BOOL_AT(level_is_collected_as_gold_at, is_collected_as_gold)
LEVEL_BODY_GET_BOOL_AT(level_is_combustible_at, is_combustible)
LEVEL_BODY_GET_BOOL_AT(level_is_corpse_at, is_corpse)
LEVEL_BODY_GET_BOOL_AT(level_is_corpse_on_death_at, is_corpse_on_death)
LEVEL_BODY_GET_BOOL_AT(level_is_corridor_at, is_corridor)
LEVEL_BODY_GET_BOOL_AT(level_is_critical_to_level_at, is_critical_to_level)
LEVEL_BODY_GET_BOOL_AT(level_is_cursor_at, is_cursor)
LEVEL_BODY_GET_BOOL_AT(level_is_cursor_can_hover_over_at, is_cursor_can_hover_over)
LEVEL_BODY_GET_BOOL_AT(level_is_cursor_can_hover_over_x2_click_at, is_cursor_can_hover_over_x2_click)
LEVEL_BODY_GET_BOOL_AT(level_is_cursor_path_at, is_cursor_path)
LEVEL_BODY_GET_BOOL_AT(level_is_cursor_path_hazard_for_player_at, is_cursor_path_hazard_for_player)
LEVEL_BODY_GET_BOOL_AT(level_is_heavy_at, is_heavy)
LEVEL_BODY_GET_BOOL_AT(level_is_dead_on_end_of_anim_at, is_dead_on_end_of_anim)
LEVEL_BODY_GET_BOOL_AT(level_is_dead_on_shove_at, is_dead_on_shove)
LEVEL_BODY_GET_BOOL_AT(level_is_debuff_at, is_debuff)
LEVEL_BODY_GET_BOOL_AT(level_is_debug_path_at, is_debug_path)
LEVEL_BODY_GET_BOOL_AT(level_is_debug_type_at, is_debug_type)
LEVEL_BODY_GET_BOOL_AT(level_is_deep_water_at, is_deep_water)
LEVEL_BODY_GET_BOOL_AT(level_is_descend_dungeon_at, is_descend_dungeon)
LEVEL_BODY_GET_BOOL_AT(level_is_descend_sewer_at, is_descend_sewer)
LEVEL_BODY_GET_BOOL_AT(level_is_described_when_hovering_over_at, is_described_when_hovering_over)
LEVEL_BODY_GET_BOOL_AT(level_is_destroyed_on_hit_or_miss_at, is_destroyed_on_hit_or_miss)
LEVEL_BODY_GET_BOOL_AT(level_is_destroyed_on_hitting_at, is_destroyed_on_hitting)
LEVEL_BODY_GET_BOOL_AT(level_is_dir_bl_at, is_dir_bl)
LEVEL_BODY_GET_BOOL_AT(level_is_dir_br_at, is_dir_br)
LEVEL_BODY_GET_BOOL_AT(level_is_dir_down_at, is_dir_down)
LEVEL_BODY_GET_BOOL_AT(level_is_dir_left_at, is_dir_left)
LEVEL_BODY_GET_BOOL_AT(level_is_dir_none_at, is_dir_none)
LEVEL_BODY_GET_BOOL_AT(level_is_dir_right_at, is_dir_right)
LEVEL_BODY_GET_BOOL_AT(level_is_dirt_at, is_dirt)
LEVEL_BODY_GET_BOOL_AT(level_is_dir_tl_at, is_dir_tl)
LEVEL_BODY_GET_BOOL_AT(level_is_dir_tr_at, is_dir_tr)
LEVEL_BODY_GET_BOOL_AT(level_is_dir_up_at, is_dir_up)
LEVEL_BODY_GET_BOOL_AT(level_is_door_at, is_door)
LEVEL_BODY_GET_BOOL_AT(level_is_droppable_at, is_droppable)
LEVEL_BODY_GET_BOOL_AT(level_is_dry_grass_at, is_dry_grass)
LEVEL_BODY_GET_BOOL_AT(level_is_enchantable_at, is_enchantable)
LEVEL_BODY_GET_BOOL_AT(level_is_enchantstone_at, is_enchantstone)
LEVEL_BODY_GET_BOOL_AT(level_is_engulfer_at, is_engulfer)
LEVEL_BODY_GET_BOOL_AT(level_is_ethereal_at, is_ethereal)
LEVEL_BODY_GET_BOOL_AT(level_is_ethereal_minion_generator_at, is_ethereal_minion_generator)
LEVEL_BODY_GET_BOOL_AT(level_is_exit_finder_at, is_exit_finder)
LEVEL_BODY_GET_BOOL_AT(level_is_explosion_at, is_explosion)
LEVEL_BODY_GET_BOOL_AT(level_is_fearless_at, is_fearless)
LEVEL_BODY_GET_BOOL_AT(level_is_fire_at, is_fire)
LEVEL_BODY_GET_BOOL_AT(level_is_floating_at, is_floating)
LEVEL_BODY_GET_BOOL_AT(level_is_floor_at, is_floor)
LEVEL_BODY_GET_BOOL_AT(level_is_floor_deco_at, is_floor_deco)
LEVEL_BODY_GET_BOOL_AT(level_is_foilage_at, is_foilage)
LEVEL_BODY_GET_BOOL_AT(level_is_food_at, is_food)
LEVEL_BODY_GET_BOOL_AT(level_is_food_eater_at, is_food_eater)
LEVEL_BODY_GET_BOOL_AT(level_is_gfx_anim_synced_with_owner_at, is_gfx_anim_synced_with_owner)
LEVEL_BODY_GET_BOOL_AT(level_is_glass_at, is_glass)
LEVEL_BODY_GET_BOOL_AT(level_is_gold_at, is_gold)
LEVEL_BODY_GET_BOOL_AT(level_is_hazard_at, is_hazard)
LEVEL_BODY_GET_BOOL_AT(level_is_health_booster_at, is_health_booster)
LEVEL_BODY_GET_BOOL_AT(level_is_hittable_at, is_hittable)
LEVEL_BODY_GET_BOOL_AT(level_is_humanoid_at, is_humanoid)
LEVEL_BODY_GET_BOOL_AT(level_is_hunger_insatiable_at, is_hunger_insatiable)
LEVEL_BODY_GET_BOOL_AT(level_is_indestructible_at, is_indestructible)
LEVEL_BODY_GET_BOOL_AT(level_is_intelligent_at, is_intelligent)
LEVEL_BODY_GET_BOOL_AT(level_is_interesting_at, is_interesting)
LEVEL_BODY_GET_BOOL_AT(level_is_item_at, is_item)
LEVEL_BODY_GET_BOOL_AT(level_is_item_carrier_at, is_item_carrier)
LEVEL_BODY_GET_BOOL_AT(level_is_item_collector_at, is_item_collector)
LEVEL_BODY_GET_BOOL_AT(level_is_item_eater_at, is_item_eater)
LEVEL_BODY_GET_BOOL_AT(level_is_item_magical_at, is_item_magical)
LEVEL_BODY_GET_BOOL_AT(level_is_item_magical_eater_at, is_item_magical_eater)
LEVEL_BODY_GET_BOOL_AT(level_is_item_organic_at, is_item_organic)
LEVEL_BODY_GET_BOOL_AT(level_is_jelly_at, is_jelly)
LEVEL_BODY_GET_BOOL_AT(level_is_jelly_baby_at, is_jelly_baby)
LEVEL_BODY_GET_BOOL_AT(level_is_jelly_baby_eater_at, is_jelly_baby_eater)
LEVEL_BODY_GET_BOOL_AT(level_is_jelly_eater_at, is_jelly_eater)
LEVEL_BODY_GET_BOOL_AT(level_is_jelly_parent_at, is_jelly_parent)
LEVEL_BODY_GET_BOOL_AT(level_is_key_at, is_key)
LEVEL_BODY_GET_BOOL_AT(level_is_laser_at, is_laser)
LEVEL_BODY_GET_BOOL_AT(level_is_lava_at, is_lava)
LEVEL_BODY_GET_BOOL_AT(level_is_explorer_at, is_explorer)
LEVEL_BODY_GET_BOOL_AT(level_is_light_blocker_at, is_light_blocker)
LEVEL_BODY_GET_BOOL_AT(level_is_living_at, is_living)
LEVEL_BODY_GET_BOOL_AT(level_is_loggable_at, is_loggable)
LEVEL_BODY_GET_BOOL_AT(level_is_meat_at, is_meat)
LEVEL_BODY_GET_BOOL_AT(level_is_meat_eater_at, is_meat_eater)
LEVEL_BODY_GET_BOOL_AT(level_is_metal_at, is_metal)
LEVEL_BODY_GET_BOOL_AT(level_is_minion_at, is_minion)
LEVEL_BODY_GET_BOOL_AT(level_is_minion_generator_at, is_minion_generator)
LEVEL_BODY_GET_BOOL_AT(level_is_monst_at, is_monst)
LEVEL_BODY_GET_BOOL_AT(level_is_moveable_at, is_moveable)
LEVEL_BODY_GET_BOOL_AT(level_is_msg_at, is_msg)
LEVEL_BODY_GET_BOOL_AT(level_is_necrotic_danger_level_at, is_necrotic_danger_level)
LEVEL_BODY_GET_BOOL_AT(level_is_no_tile_at, is_no_tile)
LEVEL_BODY_GET_BOOL_AT(level_is_obs_destructable_at, is_obs_destructable)
LEVEL_BODY_GET_BOOL_AT(level_is_obs_wall_or_door_at, is_obs_wall_or_door)
LEVEL_BODY_GET_BOOL_AT(level_is_on_firing_at_something, is_on_fire)
LEVEL_BODY_GET_BOOL_AT(level_is_openable_at, is_openable)
LEVEL_BODY_GET_BOOL_AT(level_is_organic_at, is_organic)
LEVEL_BODY_GET_BOOL_AT(level_is_player_at, is_player)
LEVEL_BODY_GET_BOOL_AT(level_is_poisonous_danger_level_at, is_poisonous_danger_level)
LEVEL_BODY_GET_BOOL_AT(level_is_potion_at, is_potion)
LEVEL_BODY_GET_BOOL_AT(level_is_potion_eater_at, is_potion_eater)
LEVEL_BODY_GET_BOOL_AT(level_is_projectile_at, is_projectile)
LEVEL_BODY_GET_BOOL_AT(level_is_removeable_if_out_of_slots_at, is_removeable_if_out_of_slots)
LEVEL_BODY_GET_BOOL_AT(level_is_resurrectable_at, is_resurrectable)
LEVEL_BODY_GET_BOOL_AT(level_is_ring_at, is_ring)
LEVEL_BODY_GET_BOOL_AT(level_is_ripple_at, is_ripple)
LEVEL_BODY_GET_BOOL_AT(level_is_rock_at, is_rock)
LEVEL_BODY_GET_BOOL_AT(level_is_rusty_at, is_rusty)
LEVEL_BODY_GET_BOOL_AT(level_is_secret_door_at, is_secret_door)
LEVEL_BODY_GET_BOOL_AT(level_is_sewer_wall_at, is_sewer_wall)
LEVEL_BODY_GET_BOOL_AT(level_is_shallow_water_at, is_shallow_water)
LEVEL_BODY_GET_BOOL_AT(level_is_shovable_at, is_shovable)
LEVEL_BODY_GET_BOOL_AT(level_is_skill_at, is_skill)
LEVEL_BODY_GET_BOOL_AT(level_is_skillstone_at, is_skillstone)
LEVEL_BODY_GET_BOOL_AT(level_is_smoke_at, is_smoke)
LEVEL_BODY_GET_BOOL_AT(level_is_soft_body_at, is_soft_body)
LEVEL_BODY_GET_BOOL_AT(level_is_spawner_at, is_spawner)
LEVEL_BODY_GET_BOOL_AT(level_is_spiderweb_at, is_spiderweb)
LEVEL_BODY_GET_BOOL_AT(level_is_steal_item_chance_d1000_at, is_steal_item_chance_d1000)
LEVEL_BODY_GET_BOOL_AT(level_is_sticky_at, is_sticky)
LEVEL_BODY_GET_BOOL_AT(level_is_stone_at, is_stone)
LEVEL_BODY_GET_BOOL_AT(level_is_sword_at, is_sword)
LEVEL_BODY_GET_BOOL_AT(level_is_target_auto_select_at, is_target_auto_select)
LEVEL_BODY_GET_BOOL_AT(level_is_throwable_at, is_throwable)
LEVEL_BODY_GET_BOOL_AT(level_is_tickable_at, is_tickable)
LEVEL_BODY_GET_BOOL_AT(level_is_tmp_thing_at, is_tmp_thing)
LEVEL_BODY_GET_BOOL_AT(level_is_torch_at, is_torch)
LEVEL_BODY_GET_BOOL_AT(level_is_treasure_class_a_at, is_treasure_class_a)
LEVEL_BODY_GET_BOOL_AT(level_is_treasure_class_b_at, is_treasure_class_b)
LEVEL_BODY_GET_BOOL_AT(level_is_treasure_class_c_at, is_treasure_class_c)
LEVEL_BODY_GET_BOOL_AT(level_is_treasure_type_at, is_treasure_type)
LEVEL_BODY_GET_BOOL_AT(level_is_treasure_type_chest_at, is_treasure_type_chest)
LEVEL_BODY_GET_BOOL_AT(level_is_treasure_type_eater_at, is_treasure_type_eater)
LEVEL_BODY_GET_BOOL_AT(level_is_undead_at, is_undead)
LEVEL_BODY_GET_BOOL_AT(level_is_usable_at, is_usable)
LEVEL_BODY_GET_BOOL_AT(level_is_used_when_thrown_at, is_used_when_thrown)
LEVEL_BODY_GET_BOOL_AT(level_is_very_combustible_at, is_very_combustible)
LEVEL_BODY_GET_BOOL_AT(level_is_visible_at, is_visible)
LEVEL_BODY_GET_BOOL_AT(level_is_wall_at, is_wall)
LEVEL_BODY_GET_BOOL_AT(level_is_wall_dungeon_at, is_wall_dungeon)
LEVEL_BODY_GET_BOOL_AT(level_is_wand_at, is_wand)
LEVEL_BODY_GET_BOOL_AT(level_is_water_at, is_water)
LEVEL_BODY_GET_BOOL_AT(level_is_weapon_at, is_weapon)
LEVEL_BODY_GET_BOOL_AT(level_is_weapon_equiper_at, is_weapon_equiper)
LEVEL_BODY_GET_BOOL_AT(level_is_wooden_at, is_wooden)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag10_at, unused_flag10)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag11_at, unused_flag11)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_follow_at, is_able_to_follow)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_use_weapons_at, is_able_to_use_weapons)
LEVEL_BODY_GET_BOOL_AT(level_is_bony_at, is_bony)
LEVEL_BODY_GET_BOOL_AT(level_is_pink_blooded_at, is_pink_blooded)
LEVEL_BODY_GET_BOOL_AT(level_is_pink_splatter_at, is_pink_splatter)
LEVEL_BODY_GET_BOOL_AT(level_is_green_splatter_at, is_green_splatter)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag1_at, unused_flag1)
LEVEL_BODY_GET_BOOL_AT(level_is_red_blooded_at, is_red_blooded)
LEVEL_BODY_GET_BOOL_AT(level_is_green_blooded_at, is_green_blooded)
LEVEL_BODY_GET_BOOL_AT(level_is_able_to_jump_without_tiring_at, is_able_to_jump_without_tiring)
LEVEL_BODY_GET_BOOL_AT(level_is_spider_at, is_spider)
LEVEL_BODY_GET_BOOL_AT(level_is_crushable_at, is_crushable)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag2_at, unused_flag2)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag3_at, unused_flag3)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag4_at, unused_flag4)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag5_at, unused_flag5)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag6_at, unused_flag6)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag7_at, unused_flag7)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag8_at, unused_flag8)
LEVEL_BODY_GET_BOOL_AT(level_unused_flag9_at, unused_flag9)
