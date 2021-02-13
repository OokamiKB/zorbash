//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#pragma once
#include "my_main.h"
#include "my_point.h"
#include "my_size.h"

void wid_topcon_fini(void);
uint8_t wid_topcon_init(void);
void wid_topcon_log(std::wstring s);
void wid_topcon_log(std::string s);
void wid_topcon_flush(void);

#include "my_wid.h"

//
// Global widgets.
//
extern Widp wid_topcon_input_line;
extern Widp wid_topcon_window;
extern Widp wid_topcon_container;

std::vector<std::wstring> wid_topcon_serialize(void);
void wid_topcon_deserialize(std::vector<std::wstring> r);
