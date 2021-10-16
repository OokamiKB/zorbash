//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_array_bounds_check.h"
#include "my_game.h"
#include "my_monst.h"
#include "my_sdl.h"
#include "my_sys.h"
#include "my_thing.h"
#include "my_ui.h"
#include "my_vector_bounds_check.h"
#include "my_wid_bag.h"
#include "my_wid_buffbox.h"
#include "my_wid_thing_info.h"

void wid_buffbox_fini(void)
{
  TRACE_AND_INDENT();
  DBG3("buffbox: Fini");
}

uint8_t wid_buffbox_init(void)
{
  TRACE_AND_INDENT();
  return true;
}

void wid_buffbox_mouse_over_b(Widp w, int32_t relx, int32_t rely, int32_t wheelx, int32_t wheely)
{
  TRACE_AND_INDENT();
  DBG3("buffbox: Begin over buffbox");
  TRACE_AND_INDENT();
  if ((game->state == Game::STATE_CHOOSING_TARGET) || (game->state == Game::STATE_OPTIONS_FOR_ITEM_MENU) ||
      (game->state == Game::STATE_MOVING_ITEMS) || (game->state == Game::STATE_COLLECTING_ITEMS) ||
      (game->state == Game::STATE_WIELDING_ITEMS) || (game->state == Game::STATE_SAVE_MENU) ||
      (game->state == Game::STATE_LOAD_MENU) || (game->state == Game::STATE_QUIT_MENU) ||
      (game->state == Game::STATE_ENCHANTING_ITEMS)) {
    DBG3("buffbox: Moving items; ignore");
    return;
  }

  if (game->in_transit_item) {
    DBG3("buffbox: In transit item; ignore");
    return;
  }

  auto level = game->level;
  if (! level) {
    DBG3("buffbox: No level; ignore");
    return;
  }

  auto slot = wid_get_int_context(w);

  DBG3("buffbox: Begin over buffbox slot %d", slot);
  TRACE_AND_INDENT();
  if (! level->buffbox_over(slot)) {
    DBG3("buffbox: Not over anything");
    return;
  }

  level->buffbox_describe(slot);

  auto t = level->buffbox_get(slot);
  if (t) {
    game->wid_thing_info_create(t);
  }
}

void wid_buffbox_mouse_over_e(Widp w)
{
  TRACE_AND_INDENT();
  DBG3("buffbox: End over buffbox");
  TRACE_AND_INDENT();
  if ((game->state == Game::STATE_CHOOSING_TARGET) || (game->state == Game::STATE_OPTIONS_FOR_ITEM_MENU) ||
      (game->state == Game::STATE_MOVING_ITEMS) || (game->state == Game::STATE_COLLECTING_ITEMS) ||
      (game->state == Game::STATE_WIELDING_ITEMS) || (game->state == Game::STATE_SAVE_MENU) ||
      (game->state == Game::STATE_LOAD_MENU) || (game->state == Game::STATE_QUIT_MENU) ||
      (game->state == Game::STATE_ENCHANTING_ITEMS)) {
    DBG3("buffbox: Moving items; ignore");
    return;
  }

  if (game->in_transit_item) {
    DBG3("buffbox: In transit item; ignore");
    return;
  }

  auto level = game->level;
  if (! level) {
    DBG3("buffbox: No level; ignore");
    return;
  }

  auto slot = wid_get_int_context(w);

  DBG3("buffbox: Over buffbox slot %d", slot);
  TRACE_AND_INDENT();
  if (! level->buffbox_over(slot)) {
    return;
  }

  game->wid_thing_info_destroy_deferred();

  //
  // Do not create new wids in here
  //
}