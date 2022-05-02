//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_array_bounds_check.hpp"
#include "my_ascii.hpp"
#include "my_game.hpp"
#include "my_gl.hpp"
#include "my_monst.hpp"
#include "my_thing.hpp"
#include "my_tile.hpp"
#include "my_ui.hpp"
#include "my_unicode.hpp"

void Thing::blit_ascii(point tl, point br, point p)
{
  TRACE_NO_INDENT();

  auto tpp  = tp();
  auto blit = true;

  if (unlikely(is_changing_level)) {
    blit = false;
  } else if (unlikely(is_hidden)) {
    blit = false;
  } else if (unlikely(tpp->gfx_attack_anim() || tpp->gfx_equip_carry_anim())) {
    //
    // Hide weapons that have swung
    //
    if (is_dead) {
      blit = false;
    }
  } else if (is_cursor() || is_cursor_path() || is_the_grid) {
    blit = true;
  }

  if (! blit) {
    return;
  }

  if (is_no_tile()) {
    return;
  }

  auto tile = tile_index_to_tile(tile_curr);
  if (! tile) {
    return;
  }

  if (! tile->ascii_char) {
    return;
  }

  int x = tl.x + (p.x - level->minx);
  int y = tl.y + (p.y - level->miny);

  if (tile->ascii_bg_col != COLOR_NONE) {
    ascii_set_bg(x, y, tile->ascii_bg_col);
    ascii_set_bg(x, y, UNICODE_BLOCK);
  }
  ascii_set_fg(x, y, tile->ascii_char);
  ascii_set_fg(x, y, tile->ascii_fg_col);
}