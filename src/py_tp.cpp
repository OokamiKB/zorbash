//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_python.h"
#include "my_thing_template.h"
#include "my_game.h"
#include "my_level.h"
#include "my_thing.h"

PyObject *tp_load_ (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    PyObject *py_class = 0;

    static char *kwlist[] = {(char*) "tp", 0};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O", kwlist, &py_class)) {
        Py_RETURN_NONE;
    }

    if (!py_class) {
        ERR("tp_load, missing name attr");
        Py_RETURN_NONE;
    }

    char *tp_name = py_obj_attr_str(py_class, "name");
    if (!tp_name) {
        ERR("tp_load, missing tp name");
        Py_RETURN_NONE;
    }

    char *tp_text_name = py_obj_attr_str(py_class, "text_name");
    if (!tp_text_name) {
        ERR("tp_load, missing tp text_name");
        Py_RETURN_NONE;
    }

    static int id;
    id++;
    tp_load(id, tp_name, tp_text_name);

    myfree(tp_name);
    myfree(tp_text_name);

    Py_RETURN_NONE;
}

#define TP_BODY_SET_STRING(__field__)                                           \
PyObject *tp_set_ ## __field__ (PyObject *obj, PyObject *args, PyObject *keywds)\
{                                                                               \
    PyObject *py_class = 0;                                                     \
    char *tp_name = 0;                                                          \
    char *value = 0;                                                            \
    Tpp tp;                                                                     \
                                                                                \
    static char *kwlist[] = {(char*) "class", (char*) "value", 0};              \
                                                                                \
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O|s", kwlist, &py_class,    \
                                     &value)) {                                 \
        return (0);                                                             \
    }                                                                           \
                                                                                \
    if (!py_class) {                                                            \
        ERR("%s, missing class", __FUNCTION__);                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    if (!value) {                                                               \
        ERR("%s, missing value", __FUNCTION__);                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    tp_name = py_obj_attr_str(py_class, "name");                                \
    if (!tp_name) {                                                             \
        ERR("%s, missing tp name", __FUNCTION__);                               \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    PY_DBG("%s(%s -> \"%s\")", __FUNCTION__, tp_name, value);         \
                                                                                \
    tp = tp_find(tp_name);                                                      \
    if (!tp) {                                                                  \
        ERR("%s, cannot find tp %s", __FUNCTION__, tp_name);                    \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    tp->set_ ## __field__(std::string(value ? value : ""));                     \
    value = 0;                                                                  \
                                                                                \
done:                                                                           \
    if (tp_name) {                                                              \
        myfree(tp_name);                                                        \
    }                                                                           \
                                                                                \
    Py_RETURN_NONE;                                                             \
}                                                                               \

#define TP_BODY_SET_STRING_FN(__field__, __fn__)                                \
PyObject *tp_set_ ## __field__ (PyObject *obj, PyObject *args, PyObject *keywds)\
{                                                                               \
    PyObject *py_class = 0;                                                     \
    char *tp_name = 0;                                                          \
    char *value = 0;                                                            \
    Tpp tp;                                                                     \
                                                                                \
    static char *kwlist[] = {(char*) "class", (char*) "value", 0};              \
                                                                                \
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O|s", kwlist, &py_class,    \
                                     &value)) {                                 \
        return (0);                                                             \
    }                                                                           \
                                                                                \
    if (!py_class) {                                                            \
        ERR("%s, missing class", __FUNCTION__);                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    if (!value) {                                                               \
        ERR("%s, missing value", __FUNCTION__);                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    tp_name = py_obj_attr_str(py_class, "name");                                \
    if (!tp_name) {                                                             \
        ERR("%s, missing tp name", __FUNCTION__);                               \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    PY_DBG("%s(%s -> \"%s\")", __FUNCTION__, tp_name, value);         \
                                                                                \
    tp = tp_find(tp_name);                                                      \
    if (!tp) {                                                                  \
        ERR("%s, cannot find tp %s", __FUNCTION__, tp_name);                    \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    tp->set_ ## __field__(std::string(value ? value : ""));                     \
    value = 0;                                                                  \
    (__fn__)(tp);                                                               \
                                                                                \
done:                                                                           \
    if (tp_name) {                                                              \
        myfree(tp_name);                                                        \
    }                                                                           \
                                                                                \
    Py_RETURN_NONE;                                                             \
}                                                                               \

#define TP_BODY_SET_ENUM(__field__, __str2val__)                                \
PyObject *tp_set_ ## __field__ (PyObject *obj, PyObject *args, PyObject *keywds)\
{                                                                               \
    PyObject *py_class = 0;                                                     \
    char *tp_name = 0;                                                          \
    char *value = 0;                                                            \
    Tpp tp;                                                                     \
                                                                                \
    static char *kwlist[] = {(char*) "class", (char*) "value", 0};              \
                                                                                \
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O|s", kwlist, &py_class,    \
                                     &value)) {                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    if (!py_class) {                                                            \
        ERR("%s, missing class", __FUNCTION__);                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    if (!value) {                                                               \
        ERR("%s, missing value", __FUNCTION__);                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    tp_name = py_obj_attr_str(py_class, "name");                                \
    if (!tp_name) {                                                             \
        ERR("%s, missing tp name", __FUNCTION__);                               \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    tp = tp_find(tp_name);                                                      \
    if (!tp) {                                                                  \
        ERR("%s, cannot find tp %s", __FUNCTION__, tp_name);                    \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    tp->set_ ## __field__((__str2val__)(value));                                \
    if (tp->__field__() == (int)(tp->__field__())-1) {                          \
        ERR("%s, cannot find enum %s", __FUNCTION__, value);                    \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    PY_DBG("%s(%s -> \"%s\"[%d])", __FUNCTION__, tp_name, value,      \
        tp->__field__());                                                       \
                                                                                \
    value = 0;                                                                  \
                                                                                \
done:                                                                           \
    if (tp_name) {                                                              \
        myfree(tp_name);                                                        \
    }                                                                           \
                                                                                \
    Py_RETURN_NONE;                                                             \
}                                                                               \

#define TP_BODY_SET_INT(__field__)                                              \
PyObject *tp_set_ ## __field__ (PyObject *obj, PyObject *args, PyObject *keywds)\
{                                                                               \
    PyObject *py_class = 0;                                                     \
    char *tp_name = 0;                                                          \
    int value = 0;                                                              \
    Tpp tp;                                                                     \
                                                                                \
    static char *kwlist[] = {(char*) "class", (char*) "value", 0};              \
                                                                                \
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O|i", kwlist, &py_class,    \
                                     &value)) {                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    if (!py_class) {                                                            \
        ERR("%s, missing class", __FUNCTION__);                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    tp_name = py_obj_attr_str(py_class, "name");                                \
    if (!tp_name) {                                                             \
        ERR("%s, missing tp name", __FUNCTION__);                               \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    PY_DBG("%s(%s -> %d)", __FUNCTION__, tp_name, value);             \
                                                                                \
    tp = tp_find(tp_name);                                                      \
    if (!tp) {                                                                  \
        ERR("%s, cannot find tp %s", __FUNCTION__, tp_name);                    \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    tp->set_ ## __field__(value);                                               \
                                                                                \
done:                                                                           \
    if (tp_name) {                                                              \
        myfree(tp_name);                                                        \
    }                                                                           \
                                                                                \
    Py_RETURN_NONE;                                                             \
}                                                                               \

#define TP_BODY_SET_DOUBLE(__field__)                                           \
PyObject *tp_set_ ## __field__ (PyObject *obj, PyObject *args, PyObject *keywds)\
{                                                                               \
    PyObject *py_class = 0;                                                     \
    char *tp_name = 0;                                                          \
    double value = 0;                                                           \
    Tpp tp;                                                                     \
                                                                                \
    static char *kwlist[] = {(char*) "class", (char*) "value", 0};              \
                                                                                \
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O|d", kwlist, &py_class,    \
                                     &value)) {                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    if (!py_class) {                                                            \
        ERR("%s, missing class", __FUNCTION__);                                 \
        Py_RETURN_NONE;                                                         \
    }                                                                           \
                                                                                \
    tp_name = py_obj_attr_str(py_class, (char*) "name");                        \
    if (!tp_name) {                                                             \
        ERR("%s, missing tp name", __FUNCTION__);                               \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    PY_DBG("%s(%s -> %g)", __FUNCTION__, tp_name, value);             \
                                                                                \
    tp = tp_find(tp_name);                                                      \
    if (!tp) {                                                                  \
        ERR("%s, cannot find tp %s", __FUNCTION__, tp_name);                    \
        goto done;                                                              \
    }                                                                           \
                                                                                \
    tp->set_ ## __field__(value);                                               \
                                                                                \
done:                                                                           \
    if (tp_name) {                                                              \
        myfree(tp_name);                                                        \
    }                                                                           \
                                                                                \
    Py_RETURN_NONE;                                                             \
}                                                                               \

static PyObject *tp_set_tile_dir (PyObject *obj,
                                  PyObject *args,
                                  PyObject *keywds,
                                  int dir,
                                  int level)
{
    PyObject *py_class = 0;
    char *tp_name = 0;
    char *fg = 0;
    char *bg = 0;
    char *fg_color = 0;
    char *bg_color = 0;
    int delay_ms = 0;
    int is_moving = 0;
    int is_jumping = 0;
    int begin_jump = 0;
    int is_outline = 0;
    int left = 0;
    int right = 0;
    int up = 0;
    int down = 0;
    int none = 0;
    int is_yyy5 = 0;
    int is_yyy6 = 0;
    int is_yyy7 = 0;
    int is_yyy8 = 0;
    int is_yyy9 = 0;
    int is_invisible = 0;
    int is_hp_25_percent = 0;
    int is_hp_50_percent = 0;
    int is_hp_75_percent = 0;
    int is_hp_100_percent = 0;
    int is_in_water = 0;
    int is_sleeping = 0;
    int is_open = 0;
    int is_dead = 0;
    int is_end_of_anim = 0;
    int is_dead_on_end_of_anim = 0;
    int is_alive_on_end_of_anim = 0;
    int is_resurrecting = 0;
    char *py_tile_name = nullptr;

    static char *kwlist[] = {
        (char*) "class",
        (char*) "tile",
        (char*) "fg",
        (char*) "bg",
        (char*) "fg_color",
        (char*) "bg_color",
        (char*) "delay_ms",
        (char*) "is_moving",
        (char*) "is_jumping",
        (char*) "begin_jump",
        (char*) "is_outline",
        (char*) "is_dir_left",
        (char*) "is_dir_right",
        (char*) "is_dir_up",
        (char*) "is_dir_down",
        (char*) "is_dir_none",
        (char*) "is_yyy5",
        (char*) "is_yyy6",
        (char*) "is_yyy7",
        (char*) "is_yyy8",
        (char*) "is_yyy9",
        (char*) "is_invisible",
        (char*) "is_hp_25_percent",
        (char*) "is_hp_50_percent",
        (char*) "is_hp_75_percent",
        (char*) "is_hp_100_percent",
        (char*) "is_in_water",
        (char*) "is_sleeping",
        (char*) "is_open",
        (char*) "is_dead",
        (char*) "is_end_of_anim",
        (char*) "is_dead_on_end_of_anim",
        (char*) "is_resurrecting",
        (char*) "is_alive_on_end_of_anim",
        0
    };

    if (!PyArg_ParseTupleAndKeywords(args, keywds,
                                     "O|sssssiiisiiiiiiiiiiiiiiiiiiiiiiii",
                                     kwlist, &py_class,
                                     &py_tile_name,
                                     &fg,
                                     &bg,
                                     &fg_color,
                                     &bg_color,
                                     &delay_ms,
                                     &is_moving,
                                     &is_jumping,
                                     &begin_jump,
                                     &is_outline,
                                     &left,
                                     &right,
                                     &up,
                                     &down,
                                     &none,
                                     &is_yyy5,
                                     &is_yyy6,
                                     &is_yyy7,
                                     &is_yyy8,
                                     &is_yyy9,
                                     &is_invisible,
                                     &is_hp_25_percent,
                                     &is_hp_50_percent,
                                     &is_hp_75_percent,
                                     &is_hp_100_percent,
                                     &is_in_water,
                                     &is_sleeping,
                                     &is_open,
                                     &is_dead,
                                     &is_end_of_anim,
                                     &is_dead_on_end_of_anim,
                                     &is_resurrecting,
                                     &is_alive_on_end_of_anim
                                     )) {
        return (0);
    }

    if (!py_class) {
        ERR("%s, missing class", __FUNCTION__);
        Py_RETURN_NONE;
    }

    Tpp tp;

    tp_name = py_obj_attr_str(py_class, "name");
    if (!tp_name) {
        ERR("%s, missing tp name", __FUNCTION__);
        Py_RETURN_NONE;
    }

    PY_DBG("%s(%s -> \"%s\")", __FUNCTION__, tp_name, py_tile_name);

    tp = tp_find(tp_name);
    if (!tp) {
        ERR("%s, cannot find tp %s", __FUNCTION__, tp_name);
        Py_RETURN_NONE;
    }

    Tilemap *tiles = nullptr;
    switch (dir) {
    case THING_DIR_NONE:
        tiles = &tp->tiles;
        break;
    case THING_DIR_DOWN:
        if (level == 1) {
            tiles = &tp->bot1_tiles;
        } else if (level == 2) {
            tiles = &tp->bot2_tiles;
        } else if (level == 3) {
            tiles = &tp->bot3_tiles;
        } else {
            DIE("bug");
        }
        break;
    case THING_DIR_UP:
        if (level == 1) {
            tiles = &tp->top1_tiles;
        } else if (level == 2) {
            tiles = &tp->top2_tiles;
        } else {
            DIE("bug");
        }
        break;
    case THING_DIR_LEFT:
        if (level == 1) {
            tiles = &tp->left1_tiles;
        } else if (level == 2) {
            tiles = &tp->left2_tiles;
        } else {
            DIE("bug");
        }
        break;
    case THING_DIR_RIGHT:
        if (level == 1) {
            tiles = &tp->right1_tiles;
        } else if (level == 2) {
            tiles = &tp->right2_tiles;
        } else {
            DIE("bug");
        }
        break;
    case THING_DIR_TL:
        if (level == 1) {
            tiles = &tp->tl1_tiles;
        } else if (level == 2) {
            tiles = &tp->tl2_tiles;
        } else {
            DIE("bug");
        }
        break;
    case THING_DIR_BL:
        if (level == 1) {
            tiles = &tp->bl1_tiles;
        } else if (level == 2) {
            tiles = &tp->bl2_tiles;
        } else {
            DIE("bug");
        }
        break;
    case THING_DIR_TR:
        if (level == 1) {
            tiles = &tp->tr1_tiles;
        } else if (level == 2) {
            tiles = &tp->tr2_tiles;
        } else {
            DIE("bug");
        }
        break;
    case THING_DIR_BR:
        if (level == 1) {
            tiles = &tp->br1_tiles;
        } else if (level == 2) {
            tiles = &tp->br2_tiles;
        } else {
            DIE("bug");
        }
        break;
    }

    if (!tiles) {
        ERR("no tiles for [%s]", py_tile_name);
        Py_RETURN_NONE;
    }

    {
        if (py_tile_name && *py_tile_name) {
            Tilep tile;

            tile = tile_find(std::string(py_tile_name));
            if (!tile) {
                ERR("%s, cannot find tile '%s' for tp %s",
                    __FUNCTION__, py_tile_name, tp_name);
                Py_RETURN_NONE;
            }

            //
            // Copy thie tile and make a unique copy if someone has grabbed it.
            //
            if (tile->in_use) {
                tile = new Tile(tile);
            }

            tile->index = (*tiles).size();
            (*tiles).push_back(tile);
            tile->in_use = true;

            tile->delay_ms = delay_ms;
            tile->is_moving = is_moving;

            tile->is_yyy5 = is_yyy5;
            tile->is_yyy6 = is_yyy6;
            tile->is_yyy7 = is_yyy7;
            tile->is_yyy8 = is_yyy8;
            tile->is_yyy9 = is_yyy9;
            tile->is_invisible = is_invisible;
            tile->is_hp_25_percent = is_hp_25_percent;
            tile->is_hp_50_percent = is_hp_50_percent;
            tile->is_hp_75_percent = is_hp_75_percent;
            tile->is_hp_100_percent = is_hp_100_percent;
            tile->is_sleeping = is_sleeping;
            tile->is_open = is_open;
            tile->is_dead = is_dead;
            tile->is_end_of_anim = is_end_of_anim;
            tile->is_dead_on_end_of_anim = is_dead_on_end_of_anim;
            tile->is_alive_on_end_of_anim = is_alive_on_end_of_anim;
            tile->is_resurrecting = is_resurrecting;

            if (tile->is_hp_25_percent ||
                tile->is_hp_50_percent ||
                tile->is_hp_75_percent ||
                tile->is_hp_100_percent ) {
                tp->set_internal_has_hp_anim(true);
            }

            if (up) {
                if (left) {
                    tile->dir = THING_DIR_TL;
                    tile->internal_has_dir_anim = true;
                } else if (right) {
                    tile->dir = THING_DIR_TR;
                    tile->internal_has_dir_anim = true;
                } else {
                    tile->dir = THING_DIR_UP;
                    tile->internal_has_dir_anim = true;
                }
            } else if (down) {
                if (left) {
                    tile->dir = THING_DIR_BL;
                    tile->internal_has_dir_anim = true;
                } else if (right) {
                    tile->dir = THING_DIR_BR;
                    tile->internal_has_dir_anim = true;
                } else {
                    tile->dir = THING_DIR_DOWN;
                    tile->internal_has_dir_anim = true;
                }
            } else if (left) {
                tile->dir = THING_DIR_LEFT;
                tile->internal_has_dir_anim = true;
            } else if (right) {
                tile->dir = THING_DIR_RIGHT;
                tile->internal_has_dir_anim = true;
            } else if (none) {
                tile->dir = THING_DIR_NONE;
                tile->internal_has_dir_anim = true;
            }

            if (tile->internal_has_dir_anim) {
                tp->set_internal_has_dir_anim(true);
            }
        } else {
            (*tiles).push_back(nullptr);
        }
    }

    if (tp_name) {
        myfree(tp_name);
    }

    Py_RETURN_NONE;
}

PyObject *tp_set_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_NONE, 1));
}
PyObject *tp_set_top1_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_UP, 1));
}
PyObject *tp_set_bot1_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_DOWN, 1));
}
PyObject *tp_set_left1_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_LEFT, 1));
}
PyObject *tp_set_right1_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_RIGHT, 1));
}
PyObject *tp_set_tl1_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_TL, 1));
}
PyObject *tp_set_tr1_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_TR, 1));
}
PyObject *tp_set_bl1_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_BL, 1));
}
PyObject *tp_set_br1_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_BR, 1));
}
PyObject *tp_set_top2_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_UP, 2));
}
PyObject *tp_set_bot2_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_DOWN, 2));
}
PyObject *tp_set_bot3_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_DOWN, 3));
}
PyObject *tp_set_left2_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_LEFT, 2));
}
PyObject *tp_set_right2_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_RIGHT, 2));
}
PyObject *tp_set_tl2_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_TL, 2));
}
PyObject *tp_set_tr2_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_TR, 2));
}
PyObject *tp_set_bl2_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_BL, 2));
}
PyObject *tp_set_br2_tile (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    return (tp_set_tile_dir(obj, args, keywds, THING_DIR_BR, 2));
}

TP_BODY_SET_DOUBLE(collision_attack_radius)
TP_BODY_SET_DOUBLE(collision_radius)
TP_BODY_SET_INT(ai_delay_after_moving_ms)
TP_BODY_SET_INT(ai_obstacle)
TP_BODY_SET_INT(ai_scent_distance)
TP_BODY_SET_INT(blit_bot_off)
TP_BODY_SET_INT(blit_left_off)
TP_BODY_SET_INT(blit_right_off)
TP_BODY_SET_INT(blit_top_off)
TP_BODY_SET_INT(collision_attack)
TP_BODY_SET_INT(collision_box)
TP_BODY_SET_INT(collision_check)
TP_BODY_SET_INT(collision_circle)
TP_BODY_SET_INT(collision_hit_priority)
TP_BODY_SET_INT(gfx_an_animation_only)
TP_BODY_SET_INT(gfx_animated)
TP_BODY_SET_INT(gfx_animated_can_hflip)
TP_BODY_SET_INT(gfx_animated_can_vflip)
TP_BODY_SET_INT(gfx_animated_no_dir)
TP_BODY_SET_INT(gfx_attack_anim)
TP_BODY_SET_INT(gfx_bounce_always)
TP_BODY_SET_INT(gfx_bounce_on_move)
TP_BODY_SET_INT(gfx_dead_anim)
TP_BODY_SET_INT(gfx_on_fire_anim)
TP_BODY_SET_INT(gfx_oversized_but_sitting_on_the_ground)
TP_BODY_SET_INT(gfx_show_outlined)
TP_BODY_SET_INT(gfx_small_shadow_caster)
TP_BODY_SET_INT(gfx_weapon_carry_anim)
TP_BODY_SET_INT(is_rrr59)
TP_BODY_SET_INT(hunger_clock_freq_ms)
TP_BODY_SET_INT(is_able_to_change_levels)
TP_BODY_SET_INT(is_acid)
TP_BODY_SET_INT(is_acid_dweller)
TP_BODY_SET_INT(is_acid_hater)
TP_BODY_SET_INT(is_active)
TP_BODY_SET_INT(is_attack_eater)
TP_BODY_SET_INT(is_attack_lunge)
TP_BODY_SET_INT(is_attack_shove)
TP_BODY_SET_INT(is_attack_shove_chance_d1000)
TP_BODY_SET_INT(is_attackable_by_monst)
TP_BODY_SET_INT(is_attackable_by_player)
TP_BODY_SET_INT(is_bag)
TP_BODY_SET_INT(is_bleeder)
TP_BODY_SET_INT(is_blood)
TP_BODY_SET_INT(is_blood_splatter)
TP_BODY_SET_INT(is_chasm)
TP_BODY_SET_INT(is_collect_as_keys)
TP_BODY_SET_INT(is_collectable)
TP_BODY_SET_INT(is_combustible)
TP_BODY_SET_INT(on_death_is_corpse)
TP_BODY_SET_INT(is_corridor)
TP_BODY_SET_INT(is_cursor)
TP_BODY_SET_INT(is_cursor_can_hover_over)
TP_BODY_SET_INT(is_cursor_can_hover_over_but_needs_double_click)
TP_BODY_SET_INT(is_cursor_path)
TP_BODY_SET_INT(is_dead_on_shove)
TP_BODY_SET_INT(is_deep_water)
TP_BODY_SET_INT(is_dirt)
TP_BODY_SET_INT(is_door)
TP_BODY_SET_INT(is_double_damage_from_acid)
TP_BODY_SET_INT(is_double_damage_from_fire)
TP_BODY_SET_INT(is_double_damage_from_water)
TP_BODY_SET_INT(is_droppable)
TP_BODY_SET_INT(is_entrance)
TP_BODY_SET_INT(is_ethereal)
TP_BODY_SET_INT(is_exit)
TP_BODY_SET_INT(is_explosion)
TP_BODY_SET_INT(is_fire)
TP_BODY_SET_INT(is_fire_hater)
TP_BODY_SET_INT(is_flammable)
TP_BODY_SET_INT(is_floating)
TP_BODY_SET_INT(is_floor)
TP_BODY_SET_INT(is_floor_deco)
TP_BODY_SET_INT(is_food)
TP_BODY_SET_INT(is_generator)
TP_BODY_SET_INT(gfx_health_bar_shown)
TP_BODY_SET_INT(gfx_health_bar_shown_only_when_injured)
TP_BODY_SET_INT(gfx_moves_ahead_shown)
TP_BODY_SET_INT(is_gold)
TP_BODY_SET_INT(is_hazard)
TP_BODY_SET_INT(is_hunger_insatiable)
TP_BODY_SET_INT(is_intelligent)
TP_BODY_SET_INT(is_interesting)
TP_BODY_SET_INT(is_item_class_a)
TP_BODY_SET_INT(is_item_class_b)
TP_BODY_SET_INT(is_item_collected_as_gold)
TP_BODY_SET_INT(is_item_eater)
TP_BODY_SET_INT(is_item_not_stackable)
TP_BODY_SET_INT(is_jumper)
TP_BODY_SET_INT(is_jumper_chance_d1000)
TP_BODY_SET_INT(is_jumper_distance)
TP_BODY_SET_INT(is_jumper_on_low_hp_chance_d1000)
TP_BODY_SET_INT(is_key)
TP_BODY_SET_INT(is_killed_on_hit_or_miss)
TP_BODY_SET_INT(is_killed_on_hitting)
TP_BODY_SET_INT(is_lava)
TP_BODY_SET_INT(is_light_blocker)
TP_BODY_SET_INT(is_light_strength)
TP_BODY_SET_INT(is_loggable_for_important_stuff)
TP_BODY_SET_INT(is_loggable_for_unimportant_stuff)
TP_BODY_SET_INT(is_meat)
TP_BODY_SET_INT(is_meat_eater)
TP_BODY_SET_INT(is_monst)
TP_BODY_SET_INT(is_movable)
TP_BODY_SET_INT(is_movement_blocking_hard)
TP_BODY_SET_INT(is_movement_blocking_soft)
TP_BODY_SET_INT(is_msg)
TP_BODY_SET_INT(is_no_tile)
TP_BODY_SET_INT(on_death_is_open)
TP_BODY_SET_INT(is_player)
TP_BODY_SET_INT(is_potion)
TP_BODY_SET_INT(is_potion_eater)
TP_BODY_SET_INT(is_projectile)
TP_BODY_SET_INT(is_removable_if_out_of_slots)
TP_BODY_SET_INT(is_resurrectable)
TP_BODY_SET_INT(is_ripple)
TP_BODY_SET_INT(is_rock)
TP_BODY_SET_INT(is_rrr1)
TP_BODY_SET_INT(is_rrr10)
TP_BODY_SET_INT(is_rrr11)
TP_BODY_SET_INT(is_rrr12)
TP_BODY_SET_INT(is_rrr13)
TP_BODY_SET_INT(is_rrr14)
TP_BODY_SET_INT(is_rrr15)
TP_BODY_SET_INT(is_rrr16)
TP_BODY_SET_INT(is_rrr17)
TP_BODY_SET_INT(is_rrr18)
TP_BODY_SET_INT(is_rrr19)
TP_BODY_SET_INT(is_rrr2)
TP_BODY_SET_INT(is_rrr20)
TP_BODY_SET_INT(is_rrr21)
TP_BODY_SET_INT(is_rrr22)
TP_BODY_SET_INT(is_rrr23)
TP_BODY_SET_INT(is_rrr24)
TP_BODY_SET_INT(is_rrr25)
TP_BODY_SET_INT(is_rrr26)
TP_BODY_SET_INT(is_rrr27)
TP_BODY_SET_INT(is_rrr28)
TP_BODY_SET_INT(is_rrr29)
TP_BODY_SET_INT(is_rrr3)
TP_BODY_SET_INT(is_rrr30)
TP_BODY_SET_INT(is_rrr31)
TP_BODY_SET_INT(is_rrr32)
TP_BODY_SET_INT(is_rrr33)
TP_BODY_SET_INT(is_rrr34)
TP_BODY_SET_INT(is_rrr35)
TP_BODY_SET_INT(is_rrr36)
TP_BODY_SET_INT(is_rrr37)
TP_BODY_SET_INT(is_rrr38)
TP_BODY_SET_INT(is_rrr39)
TP_BODY_SET_INT(is_rrr4)
TP_BODY_SET_INT(is_rrr40)
TP_BODY_SET_INT(is_rrr41)
TP_BODY_SET_INT(is_rrr42)
TP_BODY_SET_INT(is_rrr43)
TP_BODY_SET_INT(is_rrr44)
TP_BODY_SET_INT(is_rrr45)
TP_BODY_SET_INT(is_rrr46)
TP_BODY_SET_INT(is_rrr47)
TP_BODY_SET_INT(is_rrr48)
TP_BODY_SET_INT(is_rrr49)
TP_BODY_SET_INT(is_rrr5)
TP_BODY_SET_INT(is_rrr50)
TP_BODY_SET_INT(is_rrr51)
TP_BODY_SET_INT(is_rrr52)
TP_BODY_SET_INT(is_rrr53)
TP_BODY_SET_INT(is_rrr54)
TP_BODY_SET_INT(bag_item_height)
TP_BODY_SET_INT(bag_item_width)
TP_BODY_SET_INT(bag_height)
TP_BODY_SET_INT(bag_width)
TP_BODY_SET_INT(rrr58)
TP_BODY_SET_INT(is_rrr6)
TP_BODY_SET_INT(rarity)
TP_BODY_SET_INT(gfx_is_rrr99)
TP_BODY_SET_INT(is_shown_uniquely_on_leftbar)
TP_BODY_SET_INT(is_stamina_check)
TP_BODY_SET_INT(gfx_shown_in_bg)
TP_BODY_SET_INT(on_death_drop_all_items)
TP_BODY_SET_INT(is_steal_item_chance_d1000)
TP_BODY_SET_INT(is_weapon_wielder)
TP_BODY_SET_INT(is_item)
TP_BODY_SET_INT(is_rrr7)
TP_BODY_SET_INT(is_rrr8)
TP_BODY_SET_INT(is_rrr9)
TP_BODY_SET_INT(is_secret_door)
TP_BODY_SET_INT(is_shovable)
TP_BODY_SET_INT(is_shown_on_leftbar)
TP_BODY_SET_INT(is_jelly)
TP_BODY_SET_INT(is_jelly_baby)
TP_BODY_SET_INT(is_jelly_baby_eater)
TP_BODY_SET_INT(is_jelly_eater)
TP_BODY_SET_INT(is_jelly_parent)
TP_BODY_SET_INT(is_smoke)
TP_BODY_SET_INT(is_the_grid)
TP_BODY_SET_INT(is_throwable)
TP_BODY_SET_INT(is_torch)
TP_BODY_SET_INT(is_treasure)
TP_BODY_SET_INT(is_treasure_eater)
TP_BODY_SET_INT(is_undead)
TP_BODY_SET_INT(is_usable)
TP_BODY_SET_INT(is_wall)
TP_BODY_SET_INT(is_wall_deco)
TP_BODY_SET_INT(is_water)
TP_BODY_SET_INT(is_water_dweller)
TP_BODY_SET_INT(is_water_hater)
TP_BODY_SET_INT(is_weapon)
TP_BODY_SET_INT(normal_placement_rules)
TP_BODY_SET_INT(stats01)
TP_BODY_SET_INT(stats02)
TP_BODY_SET_INT(stats03)
TP_BODY_SET_INT(stats04)
TP_BODY_SET_INT(stats05)
TP_BODY_SET_INT(stats06)
TP_BODY_SET_INT(stats07)
TP_BODY_SET_INT(stats08)
TP_BODY_SET_INT(stats09)
TP_BODY_SET_INT(stats10)
TP_BODY_SET_INT(stats11)
TP_BODY_SET_INT(stats12)
TP_BODY_SET_INT(stats13)
TP_BODY_SET_INT(stats14)
TP_BODY_SET_INT(stats15)
TP_BODY_SET_INT(stats16)
TP_BODY_SET_INT(stats17)
TP_BODY_SET_INT(stats18)
TP_BODY_SET_INT(stats_stamina)
TP_BODY_SET_INT(stats_defence)
TP_BODY_SET_INT(stats_health_hunger_pct)
TP_BODY_SET_INT(stats_health_initial)
TP_BODY_SET_INT(stats_health_starving_pct)
TP_BODY_SET_INT(stats_move_speed_ms)
TP_BODY_SET_INT(stats_strength)
TP_BODY_SET_INT(tick_catches_up_on_attack)
TP_BODY_SET_INT(tick_rate_tenths)
TP_BODY_SET_INT(weapon_damage)
TP_BODY_SET_INT(weapon_use_delay_hundredths)
TP_BODY_SET_INT(weapon_use_distance)
TP_BODY_SET_INT(z_depth)
TP_BODY_SET_INT(z_prio)
TP_BODY_SET_STRING(gold_value_dice)
TP_BODY_SET_STRING(lifespan_dice)
TP_BODY_SET_STRING(light_color)
TP_BODY_SET_STRING(name)
TP_BODY_SET_STRING(nutrition_dice)
TP_BODY_SET_STRING(on_birth_do)
TP_BODY_SET_STRING(on_death_do)
TP_BODY_SET_STRING(on_idle_dice_do)
TP_BODY_SET_STRING(resurrect_dice)
TP_BODY_SET_STRING(spawn_on_shoved)
TP_BODY_SET_STRING(stats_attack_dice)
TP_BODY_SET_STRING(str1)
TP_BODY_SET_STRING(str2)
TP_BODY_SET_STRING(str3)
TP_BODY_SET_STRING(str4)
TP_BODY_SET_STRING(str5)
TP_BODY_SET_STRING(str6)
TP_BODY_SET_STRING(str7)
TP_BODY_SET_STRING(long_text_description)
TP_BODY_SET_STRING(text_a_or_an)
TP_BODY_SET_STRING(text_description)
TP_BODY_SET_STRING(text_hits)
TP_BODY_SET_STRING(text_name)
TP_BODY_SET_STRING(text_title)
TP_BODY_SET_STRING(weapon_carry_anim)
TP_BODY_SET_STRING(gfx_anim_attack)

PyObject *tp_update_ (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    PyObject *py_class = 0;
    char *tp_name = 0;
    int value = 0;
    Tpp tp;

    static char *kwlist[] = {(char*) "class", (char*) "value", 0};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O|i", kwlist, &py_class,
                                     &value)) {
        Py_RETURN_NONE;
    }

    if (!py_class) {
        ERR("%s, missing class", __FUNCTION__);
        Py_RETURN_NONE;
    }

    tp_name = py_obj_attr_str(py_class, "name");
    if (!tp_name) {
        ERR("%s, missing tp name", __FUNCTION__);
        goto done;
    }

    PY_DBG("%s(%s -> %d)", __FUNCTION__, tp_name, value);

    tp = tp_find(tp_name);
    if (!tp) {
        ERR("%s, cannot find tp %s", __FUNCTION__, tp_name);
        goto done;
    }

done:
    if (tp_name) {
        myfree(tp_name);
    }

    Py_RETURN_NONE;
}

PyObject *tp_spawn_next_to_ (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    char *what = nullptr;
    uint32_t id = 0;

    static char *kwlist[] = {(char*) "id", (char*) "what", 0};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &id, &what)) {
        Py_RETURN_NONE;
    }

    if (!id) {
        ERR("%s, missing 'id'", __FUNCTION__);
        Py_RETURN_NONE;
    }

    if (!what) {
        ERR("%s, missing 'what'", __FUNCTION__);
        Py_RETURN_NONE;
    }

    PY_DBG("%s(%x, %s)", __FUNCTION__, id, what);

    auto level = game->level;
    if (!level) {
        Py_RETURN_NONE;
    }

    auto t = level->thing_find(ThingId(id));
    if (!t) {
        ERR("%s, cannot find thing %" PRIx32 "", __FUNCTION__, id);
        Py_RETURN_NONE;
    }

    t->spawn_next_to(std::string(what));

    Py_RETURN_NONE;
}

PyObject *tp_spawn_next_to_or_on_monst_ (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    char *what = nullptr;
    uint32_t id = 0;

    static char *kwlist[] = {(char*) "id", (char*) "what", 0};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &id, &what)) {
        Py_RETURN_NONE;
    }

    if (!id) {
        ERR("%s, missing 'id'", __FUNCTION__);
        Py_RETURN_NONE;
    }

    if (!what) {
        ERR("%s, missing 'what'", __FUNCTION__);
        Py_RETURN_NONE;
    }

    PY_DBG("%s(%x, %s)", __FUNCTION__, id, what);

    auto level = game->level;
    if (!level) {
        Py_RETURN_NONE;
    }

    auto t = level->thing_find(ThingId(id));
    if (!t) {
        ERR("%s, cannot find thing %" PRIx32 "", __FUNCTION__, id);
        Py_RETURN_NONE;
    }

    t->spawn_next_to_or_on_monst(std::string(what));

    Py_RETURN_NONE;
}

PyObject *tp_spawn_fire (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    char *what = nullptr;
    uint32_t id = 0;

    static char *kwlist[] = {(char*) "id", (char*) "what", 0};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &id, &what)) {
        Py_RETURN_NONE;
    }

    if (!id) {
        ERR("%s, missing 'id'", __FUNCTION__);
        Py_RETURN_NONE;
    }

    if (!what) {
        ERR("%s, missing 'what'", __FUNCTION__);
        Py_RETURN_NONE;
    }

    PY_DBG("%s(%x, %s)", __FUNCTION__, id, what);

    auto level = game->level;
    if (!level) {
        Py_RETURN_NONE;
    }

    auto t = level->thing_find(ThingId(id));
    if (!t) {
        ERR("%s, cannot find thing %" PRIx32 "", __FUNCTION__, id);
        Py_RETURN_NONE;
    }

    t->spawn_fire(std::string(what));

    Py_RETURN_NONE;
}

PyObject *tp_spawn_under (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    char *what = nullptr;
    uint32_t id = 0;

    static char *kwlist[] = {(char*) "id", (char*) "what", 0};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "Is", kwlist, &id, &what)) {
        Py_RETURN_NONE;
    }

    if (!id) {
        ERR("%s, missing 'id'", __FUNCTION__);
        Py_RETURN_NONE;
    }

    if (!what) {
        ERR("%s, missing 'what'", __FUNCTION__);
        Py_RETURN_NONE;
    }

    PY_DBG("%s(%x, %s)", __FUNCTION__, id, what);

    auto level = game->level;
    if (!level) {
        Py_RETURN_NONE;
    }

    auto t = level->thing_find(ThingId(id));
    if (!t) {
        ERR("%s, cannot find thing %" PRIx32 "", __FUNCTION__, id);
        Py_RETURN_NONE;
    }

    t->spawn_under(std::string(what));

    Py_RETURN_NONE;
}
