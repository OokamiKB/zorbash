//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_game.hpp"
#include "my_level.hpp"
#include "my_sdl.hpp"
#include "my_sys.hpp"
#include "my_thing.hpp"

Game::Game(std::string appdata)
{
  TRACE_AND_INDENT();
  config.reset();

  this->appdata = appdata;

  saved_dir = appdata + DIR_SEP + "zorbash" + DIR_SEP;
  save_slot = 1;

  set_meta_data(nullptr);
  save_file = saved_dir + "saved-slot-" + std::to_string(save_slot);
}

void Game::set_meta_data(Levelp l)
{
  TRACE_AND_INDENT();
  save_meta = "";

  if (l && l->player) {
    save_meta += l->player->title() + ", ";
  }

  save_meta += "seed " + seed_name + ", ";

  if (l) {
    save_meta += l->to_string() + ", ";
  }

  save_meta += string_timestamp();
}

int Game::get_move_speed(void)
{
  TRACE_AND_INDENT();
  return current_move_speed;
}
