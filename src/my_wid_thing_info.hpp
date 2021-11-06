//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#pragma once
void    wid_thing_info_fini(void);
uint8_t wid_thing_info_init(void);

#include "my_wid.hpp"
#include "my_wid_popup.hpp"

//
// Global widgets.
//
extern std::list< WidPopup * > wid_thing_info_window;