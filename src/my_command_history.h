//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#pragma once
#ifndef _MY_COMMAND_HISTORY_H_
#define _MY_COMMAND_HISTORY_H_

//
// History for all text widgets.
//
#define HISTORY_MAX 16
extern std::array<std::wstring, HISTORY_MAX> history;
extern uint32_t g_history_at;
extern uint32_t g_history_walk;

#endif
