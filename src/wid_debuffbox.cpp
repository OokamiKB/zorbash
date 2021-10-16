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
#include "my_wid_debuffbox.h"
#include "my_wid_thing_info.h"

void wid_debuffbox_fini(void)
{
  TRACE_AND_INDENT();
  DBG3("debuffbox: Fini");
}

uint8_t wid_debuffbox_init(void)
{
  TRACE_AND_INDENT();
  return true;
}

void wid_debuffbox_mouse_over_b(Widp w, int32_t relx, int32_t rely, int32_t wheelx, int32_t wheely)
{
  TRACE_AND_INDENT();
  DBG3("debuffbox: Begin over debuffbox");
  TRACE_AND_INDENT();
  if ((game->state == Game::STATE_CHOOSING_TARGET) || (game->state == Game::STATE_OPTIONS_FOR_ITEM_MENU) ||
      (game->state == Game::STATE_MOVING_ITEMS) || (game->state == Game::STATE_COLLECTING_ITEMS) ||
      (game->state == Game::STATE_WIELDING_ITEMS) || (game->state == Game::STATE_SAVE_MENU) ||
      (game->state == Game::STATE_LOAD_MENU) || (game->state == Game::STATE_QUIT_MENU) ||
      (game->state == Game::STATE_ENCHANTING_ITEMS)) {
    DBG3("debuffbox: Moving items; ignore");
    return;
  }

  if (game->in_transit_item) {
    DBG3("debuffbox: In transit item; ignore");
    return;
  }

  auto level = game->level;
  if (! level) {
    DBG3("debuffbox: No level; ignore");
    return;
  }

  auto slot = wid_get_int_context(w);

  DBG3("debuffbox: Begin over debuffbox slot %d", slot);
  TRACE_AND_INDENT();
  if (! level->debuffbox_over(slot)) {
    DBG3("debuffbox: Not over anything");
    return;
  }

  level->debuffbox_describe(slot);

  auto t = level->debuffbox_get(slot);
  if (t) {
    game->wid_thing_info_create(t);
  }
}

void wid_debuffbox_mouse_over_e(Widp w)
{
  TRACE_AND_INDENT();
  DBG3("debuffbox: End over debuffbox");
  TRACE_AND_INDENT();
  if ((game->state == Game::STATE_CHOOSING_TARGET) || (game->state == Game::STATE_OPTIONS_FOR_ITEM_MENU) ||
      (game->state == Game::STATE_MOVING_ITEMS) || (game->state == Game::STATE_COLLECTING_ITEMS) ||
      (game->state == Game::STATE_WIELDING_ITEMS) || (game->state == Game::STATE_SAVE_MENU) ||
      (game->state == Game::STATE_LOAD_MENU) || (game->state == Game::STATE_QUIT_MENU) ||
      (game->state == Game::STATE_ENCHANTING_ITEMS)) {
    DBG3("debuffbox: Moving items; ignore");
    return;
  }

  if (game->in_transit_item) {
    DBG3("debuffbox: In transit item; ignore");
    return;
  }

  auto level = game->level;
  if (! level) {
    DBG3("debuffbox: No level; ignore");
    return;
  }

  auto slot = wid_get_int_context(w);

  DBG3("debuffbox: Over debuffbox slot %d", slot);
  TRACE_AND_INDENT();
  if (! level->debuffbox_over(slot)) {
    return;
  }

  game->wid_thing_info_destroy_deferred();

  //
  // Do not create new wids in here
  //
}