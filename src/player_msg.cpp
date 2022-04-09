//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_game.hpp"
#include "my_log.hpp"
#include "my_ptrcheck.hpp"
#include "my_sys.hpp"
#include "my_thing.hpp"
#include <stdarg.h>

//
// A message generated for the console. Check if we should print it.
//
bool Thing::player_is_ready_for_messages(void)
{
  verify(MTYPE_THING, this);

  if (! level) {
    return false;
  }

  if (! level->player) {
    return false;
  }

  if (game->tick_current <= 1) {
    if (game->tick_requested.empty()) {
      if ((time_ms() - game->tick_begin_ms) < 50) {
        return false;
      }
    }
  }

  if (level->is_starting || level->is_being_destroyed) {
    return false;
  }
  return true;
}

bool Thing::player_is_ready_for_messages(std::string &why)
{
  verify(MTYPE_THING, this);

  if (! level) {
    why = "no level";
    return false;
  }

  if (! level->player) {
    why = "no player";
    return false;
  }

  if (game->tick_current <= 1) {
    if (game->tick_requested.empty()) {
      if ((time_ms() - game->tick_begin_ms) < 50) {
        why = "first tick";
        return false;
      }
    }
  }

  if (level->is_starting) {
    why = "level is starting";
    return false;
  }

  if (level->is_being_destroyed) {
    why = "level is being destroyed";
    return false;
  }
  return true;
}

bool Thing::player_is_ready_for_thing_info(void)
{
  verify(MTYPE_THING, this);

  if (! level) {
    return false;
  }

  if (level->ts_fade_out_begin) {
    return false;
  }

  if (level->ts_fade_in_begin) {
    return false;
  }

  if (is_changing_level) {
    return false;
  }

  //
  // No popups before the first tick
  //
  if (game->tick_current <= 1) {
    if (game->tick_requested.empty()) {
      if ((time_game_ms() - game->tick_begin_ms) < 50) {
        if (! game->cursor_moved) {
          dbg("Not ready for thing info: too soon %ums", time_ms() - game->tick_begin_ms);
          return false;
        }
      }
    }
  }

  if (! level->player) {
    dbg("Not ready for thing info; no level");
    return false;
  }

  if (level->player->is_dead || level->player->is_dying) {
    dbg("Not ready for thing info; dead");
    return false;
  }

  if (level->is_starting || level->is_being_destroyed) {
    dbg("Not ready for thing info; level starting");
    return false;
  }
  return true;
}

//
// A message generated for the console. Check if we should print it.
//
void Thing::msg(const char *fmt, ...)
{
  TRACE_NO_INDENT();
  verify(MTYPE_THING, this);

  std::string why = fmt;
  va_list     args;

  auto player = level->player;
  if (! player) {
    dbg("No player for msg: %s", why.c_str());
    TRACE_AND_INDENT();
    va_start(args, fmt);
    log_(fmt, args);
    va_end(args);
    return;
  }

  if (! player_is_ready_for_messages(why)) {
    dbg("Player not ready for msg: %s", why.c_str());
    TRACE_AND_INDENT();
    va_start(args, fmt);
    log_(fmt, args);
    va_end(args);
    return;
  }

  if (! is_player()) {
    int distance = distance_to_player();
    if (distance >= DMAP_IS_PASSABLE) {
      dbg("Too far to see msg: %s", why.c_str());
      TRACE_AND_INDENT();
      va_start(args, fmt);
      log_(fmt, args);
      va_end(args);
      return;
    }

    if (! level->can_see_unimpeded(player->curr_at.x, player->curr_at.y, curr_at.x, curr_at.y)) {
      dbg("Cannot directly see for msg: %s", why.c_str());
      TRACE_AND_INDENT();
      va_start(args, fmt);
      log_(fmt, args);
      va_end(args);
      return;
    }
  }

  va_start(args, fmt);
  log_(fmt, args);
  va_end(args);

  va_start(args, fmt);
  ::topcon_(fmt, args);
  va_end(args);
}
