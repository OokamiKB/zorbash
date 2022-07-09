//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_py_level.hpp"
#include "my_py_thing.hpp"
#include "my_py_tp.hpp"
#include <frameobject.h>
#include <map>

#include "my_ascii.hpp"
#include "my_callstack.hpp"
#include "my_main.hpp"
#include "my_ptrcheck.hpp"
#include "my_python.hpp"
#include "my_random.hpp"

PyObject *pcg_randint(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  int x = 0;
  int y = 0;

  static char *kwlist[] = {(char *) "x", (char *) "y", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "ii", kwlist, &x, &y)) {
    return 0;
  }

  //
  // Python style. We don't use pythons so we can get consistent random
  // numbers with the one C uses.
  //
  return (Py_BuildValue("i", pcg_random_range_inclusive(x, y)));
}

PyObject *non_pcg_randint(PyObject *obj, PyObject *args, PyObject *keywds)
{
  TRACE_AND_INDENT();
  int x = 0;
  int y = 0;

  static char *kwlist[] = {(char *) "x", (char *) "y", 0};

  if (! PyArg_ParseTupleAndKeywords(args, keywds, "ii", kwlist, &x, &y)) {
    return 0;
  }

  //
  // Python style. We don't use pythons so we can get consistent random
  // numbers with the one C uses.
  //
  return (Py_BuildValue("i", non_pcg_random_range_inclusive(x, y)));
}
