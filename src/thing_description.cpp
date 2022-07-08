//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_game.hpp"
#include "my_monst.hpp"
#include "my_python.hpp"
#include "my_random.hpp"
#include "my_thing.hpp"

//
// Python callback upon being tick
//
std::list< std::string > Thing::on_get_description(void)
{
  std::list< std::string > out;

  auto on_get_description = tp()->on_get_description_do();
  if (std::empty(on_get_description)) {
    return out;
  }

  auto t = split_tokens(on_get_description, '.');
  if (t.size() == 2) {
    auto        mod   = t[ 0 ];
    auto        fn    = t[ 1 ];
    std::size_t found = fn.find("()");
    if (found != std::string::npos) {
      fn = fn.replace(found, 2, "");
    }

    if (mod == "me") {
      mod = name();
    }

    auto owner = top_owner();
    dbg("Call %s.%s(owner=%s, item=%s, %d, %d)", mod.c_str(), fn.c_str(), owner ? owner->to_string().c_str() : "<>",
        to_string().c_str(), (unsigned int) curr_at.x, (unsigned int) curr_at.y);
    return py_call_std_list_string_fn(mod.c_str(), fn.c_str(), owner ? owner->id.id : 0, id.id,
                                      (unsigned int) curr_at.x, (unsigned int) curr_at.y);
  }

  ERR("Bad on_get_description call [%s] expected mod:function, got %d elems", on_get_description.c_str(),
      (int) on_get_description.size());

  return out;
}
