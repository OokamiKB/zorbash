//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_py_level.hpp"
#include "my_py_thing.hpp"
#include <frameobject.h>
#include <map>

#include "my_callstack.hpp"
#include "my_main.hpp"
#include "my_ptrcheck.hpp"
#include "my_python.hpp"

std::string py_obj_to_std_string(const PyObject *py_str)
{
  TRACE_AND_INDENT();
  PyObject   *py_encstr;
  std::string outstr;
  char       *str;

  py_encstr = 0;
  str       = 0;

  if (! PyUnicode_Check((PyObject *) py_str)) {
    ERR("Object is a %s, not a string object.", Py_TYPE((PyObject *) py_str)->tp_name);
    goto err_out;
  }

  py_encstr = PyUnicode_AsEncodedString((PyObject *) py_str, "utf-8", 0);
  if (! py_encstr) {
    goto err_out;
  }

  str = PyBytes_AS_STRING(py_encstr);
  if (! str) {
    goto err_out;
  }

  outstr = std::string(str);

err_out:

  if (py_encstr) {
    Py_XDECREF(py_encstr);
  }

  return (outstr);
}
