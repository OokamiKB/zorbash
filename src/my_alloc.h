//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
// Please use spaces indent of 2, no tabs and column width of 120 to view.
//
#pragma once

#ifndef _MY_ALLOC_H
#define _MY_ALLOC_H

#if defined(__MINGW32__)
// https://stackoverflow.com/questions/10862121/undefined-reference-to-posix-memalign-using-mingw32
#define HEAP_ALLOC(var, size)                                                                                          \
  void *var;                                                                                                           \
  var = _aligned_malloc(sizeof(lzo_align_t), size + size / 16 + 64 + 3);                                               \
  if (! var) {                                                                                                         \
    ERR("posix_memalign failed for size %" PRIu32, (uint32_t) size);                                                   \
  }
#else
#define HEAP_ALLOC(var, size)                                                                                          \
  void *var;                                                                                                           \
  if (posix_memalign(&var, sizeof(lzo_align_t), size + size / 16 + 64 + 3)) {                                          \
    ERR("posix_memalign failed for size %" PRIu32, (uint32_t) size);                                                   \
  }
#endif

#endif
