//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include "my_main.h"
#include "my_tile.h"
#include "my_gfx.h"

static void gfx_init_ui_box (void)
{
    {
        std::initializer_list<std::string> tiles = {
            "ui0,0,0", "ui0,1,0", "ui0,2,0", "ui0,3,0", "ui0,4,0", "ui0,5,0", "ui0,6,0", "ui0,7,0", "ui0,8,0", "ui0,9,0", "ui0,10,0", "ui0,11,0", "ui0,12,0", "ui0,13,0", "ui0,14,0", "ui0,15,0",
            "ui0,0,1", "ui0,1,1", "ui0,2,1", "ui0,3,1", "ui0,4,1", "ui0,5,1", "ui0,6,1", "ui0,7,1", "ui0,8,1", "ui0,9,1", "ui0,10,1", "ui0,11,1", "ui0,12,1", "ui0,13,1", "ui0,14,1", "ui0,15,1",
            "ui0,0,2", "ui0,1,2", "ui0,2,2", "ui0,3,2", "ui0,4,2", "ui0,5,2", "ui0,6,2", "ui0,7,2", "ui0,8,2", "ui0,9,2", "ui0,10,2", "ui0,11,2", "ui0,12,2", "ui0,13,2", "ui0,14,2", "ui0,15,2",
            "ui0,0,3", "ui0,1,3", "ui0,2,3", "ui0,3,3", "ui0,4,3", "ui0,5,3", "ui0,6,3", "ui0,7,3", "ui0,8,3", "ui0,9,3", "ui0,10,3", "ui0,11,3", "ui0,12,3", "ui0,13,3", "ui0,14,3", "ui0,15,3",
            "ui0,0,4", "ui0,1,4", "ui0,2,4", "ui0,3,4", "ui0,4,4", "ui0,5,4", "ui0,6,4", "ui0,7,4", "ui0,8,4", "ui0,9,4", "ui0,10,4", "ui0,11,4", "ui0,12,4", "ui0,13,4", "ui0,14,4", "ui0,15,4",
            "ui0,0,5", "ui0,1,5", "ui0,2,5", "ui0,3,5", "ui0,4,5", "ui0,5,5", "ui0,6,5", "ui0,7,5", "ui0,8,5", "ui0,9,5", "ui0,10,5", "ui0,11,5", "ui0,12,5", "ui0,13,5", "ui0,14,5", "ui0,15,5",
            "ui0,0,6", "ui0,1,6", "ui0,2,6", "ui0,3,6", "ui0,4,6", "ui0,5,6", "ui0,6,6", "ui0,7,6", "ui0,8,6", "ui0,9,6", "ui0,10,6", "ui0,11,6", "ui0,12,6", "ui0,13,6", "ui0,14,6", "ui0,15,6",
            "ui0,0,7", "ui0,1,7", "ui0,2,7", "ui0,3,7", "ui0,4,7", "ui0,5,7", "ui0,6,7", "ui0,7,7", "ui0,8,7", "ui0,9,7", "ui0,10,7", "ui0,11,7", "ui0,12,7", "ui0,13,7", "ui0,14,7", "ui0,15,7",
            "ui0,0,8", "ui0,1,8", "ui0,2,8", "ui0,3,8", "ui0,4,8", "ui0,5,8", "ui0,6,8", "ui0,7,8", "ui0,8,8", "ui0,9,8", "ui0,10,8", "ui0,11,8", "ui0,12,8", "ui0,13,8", "ui0,14,8", "ui0,15,8",
            "ui0,0,9", "ui0,1,9", "ui0,2,9", "ui0,3,9", "ui0,4,9", "ui0,5,9", "ui0,6,9", "ui0,7,9", "ui0,8,9", "ui0,9,9", "ui0,10,9", "ui0,11,9", "ui0,12,9", "ui0,13,9", "ui0,14,9", "ui0,15,9",
            "ui0,0,10", "ui0,1,10", "ui0,2,10", "ui0,3,10", "ui0,4,10", "ui0,5,10", "ui0,6,10", "ui0,7,10", "ui0,8,10", "ui0,9,10", "ui0,10,10", "ui0,11,10", "ui0,12,10", "ui0,13,10", "ui0,14,10", "ui0,15,10",
            "ui0,0,11", "ui0,1,11", "ui0,2,11", "ui0,3,11", "ui0,4,11", "ui0,5,11", "ui0,6,11", "ui0,7,11", "ui0,8,11", "ui0,9,11", "ui0,10,11", "ui0,11,11", "ui0,12,11", "ui0,13,11", "ui0,14,11", "ui0,15,11",
            "ui0,0,12", "ui0,1,12", "ui0,2,12", "ui0,3,12", "ui0,4,12", "ui0,5,12", "ui0,6,12", "ui0,7,12", "ui0,8,12", "ui0,9,12", "ui0,10,12", "ui0,11,12", "ui0,12,12", "ui0,13,12", "ui0,14,12", "ui0,15,12",
            "ui0,0,13", "ui0,1,13", "ui0,2,13", "ui0,3,13", "ui0,4,13", "ui0,5,13", "ui0,6,13", "ui0,7,13", "ui0,8,13", "ui0,9,13", "ui0,10,13", "ui0,11,13", "ui0,12,13", "ui0,13,13", "ui0,14,13", "ui0,15,13",
            "ui0,0,14", "ui0,1,14", "ui0,2,14", "ui0,3,14", "ui0,4,14", "ui0,5,14", "ui0,6,14", "ui0,7,14", "ui0,8,14", "ui0,9,14", "ui0,10,14", "ui0,11,14", "ui0,12,14", "ui0,13,14", "ui0,14,14", "ui0,15,14",
            "ui0,0,15", "ui0,1,15", "ui0,2,15", "ui0,3,15", "ui0,4,15", "ui0,5,15", "ui0,6,15", "ui0,7,15", "ui0,8,15", "ui0,9,15", "ui0,10,15", "ui0,11,15", "ui0,12,15", "ui0,13,15", "ui0,14,15", "ui0,15,15",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_box0.tga", "ui_box0", 8, 8, arr);
    }

    {
        std::initializer_list<std::string> tiles = {
            "ui1,0,0", "ui1,1,0", "ui1,2,0", "ui1,3,0", "ui1,4,0", "ui1,5,0", "ui1,6,0", "ui1,7,0", "ui1,8,0", "ui1,9,0", "ui1,10,0", "ui1,11,0", "ui1,12,0", "ui1,13,0", "ui1,14,0", "ui1,15,0",
            "ui1,0,1", "ui1,1,1", "ui1,2,1", "ui1,3,1", "ui1,4,1", "ui1,5,1", "ui1,6,1", "ui1,7,1", "ui1,8,1", "ui1,9,1", "ui1,10,1", "ui1,11,1", "ui1,12,1", "ui1,13,1", "ui1,14,1", "ui1,15,1",
            "ui1,0,2", "ui1,1,2", "ui1,2,2", "ui1,3,2", "ui1,4,2", "ui1,5,2", "ui1,6,2", "ui1,7,2", "ui1,8,2", "ui1,9,2", "ui1,10,2", "ui1,11,2", "ui1,12,2", "ui1,13,2", "ui1,14,2", "ui1,15,2",
            "ui1,0,3", "ui1,1,3", "ui1,2,3", "ui1,3,3", "ui1,4,3", "ui1,5,3", "ui1,6,3", "ui1,7,3", "ui1,8,3", "ui1,9,3", "ui1,10,3", "ui1,11,3", "ui1,12,3", "ui1,13,3", "ui1,14,3", "ui1,15,3",
            "ui1,0,4", "ui1,1,4", "ui1,2,4", "ui1,3,4", "ui1,4,4", "ui1,5,4", "ui1,6,4", "ui1,7,4", "ui1,8,4", "ui1,9,4", "ui1,10,4", "ui1,11,4", "ui1,12,4", "ui1,13,4", "ui1,14,4", "ui1,15,4",
            "ui1,0,5", "ui1,1,5", "ui1,2,5", "ui1,3,5", "ui1,4,5", "ui1,5,5", "ui1,6,5", "ui1,7,5", "ui1,8,5", "ui1,9,5", "ui1,10,5", "ui1,11,5", "ui1,12,5", "ui1,13,5", "ui1,14,5", "ui1,15,5",
            "ui1,0,6", "ui1,1,6", "ui1,2,6", "ui1,3,6", "ui1,4,6", "ui1,5,6", "ui1,6,6", "ui1,7,6", "ui1,8,6", "ui1,9,6", "ui1,10,6", "ui1,11,6", "ui1,12,6", "ui1,13,6", "ui1,14,6", "ui1,15,6",
            "ui1,0,7", "ui1,1,7", "ui1,2,7", "ui1,3,7", "ui1,4,7", "ui1,5,7", "ui1,6,7", "ui1,7,7", "ui1,8,7", "ui1,9,7", "ui1,10,7", "ui1,11,7", "ui1,12,7", "ui1,13,7", "ui1,14,7", "ui1,15,7",
            "ui1,0,8", "ui1,1,8", "ui1,2,8", "ui1,3,8", "ui1,4,8", "ui1,5,8", "ui1,6,8", "ui1,7,8", "ui1,8,8", "ui1,9,8", "ui1,10,8", "ui1,11,8", "ui1,12,8", "ui1,13,8", "ui1,14,8", "ui1,15,8",
            "ui1,0,9", "ui1,1,9", "ui1,2,9", "ui1,3,9", "ui1,4,9", "ui1,5,9", "ui1,6,9", "ui1,7,9", "ui1,8,9", "ui1,9,9", "ui1,10,9", "ui1,11,9", "ui1,12,9", "ui1,13,9", "ui1,14,9", "ui1,15,9",
            "ui1,0,10", "ui1,1,10", "ui1,2,10", "ui1,3,10", "ui1,4,10", "ui1,5,10", "ui1,6,10", "ui1,7,10", "ui1,8,10", "ui1,9,10", "ui1,10,10", "ui1,11,10", "ui1,12,10", "ui1,13,10", "ui1,14,10", "ui1,15,10",
            "ui1,0,11", "ui1,1,11", "ui1,2,11", "ui1,3,11", "ui1,4,11", "ui1,5,11", "ui1,6,11", "ui1,7,11", "ui1,8,11", "ui1,9,11", "ui1,10,11", "ui1,11,11", "ui1,12,11", "ui1,13,11", "ui1,14,11", "ui1,15,11",
            "ui1,0,12", "ui1,1,12", "ui1,2,12", "ui1,3,12", "ui1,4,12", "ui1,5,12", "ui1,6,12", "ui1,7,12", "ui1,8,12", "ui1,9,12", "ui1,10,12", "ui1,11,12", "ui1,12,12", "ui1,13,12", "ui1,14,12", "ui1,15,12",
            "ui1,0,13", "ui1,1,13", "ui1,2,13", "ui1,3,13", "ui1,4,13", "ui1,5,13", "ui1,6,13", "ui1,7,13", "ui1,8,13", "ui1,9,13", "ui1,10,13", "ui1,11,13", "ui1,12,13", "ui1,13,13", "ui1,14,13", "ui1,15,13",
            "ui1,0,14", "ui1,1,14", "ui1,2,14", "ui1,3,14", "ui1,4,14", "ui1,5,14", "ui1,6,14", "ui1,7,14", "ui1,8,14", "ui1,9,14", "ui1,10,14", "ui1,11,14", "ui1,12,14", "ui1,13,14", "ui1,14,14", "ui1,15,14",
            "ui1,0,15", "ui1,1,15", "ui1,2,15", "ui1,3,15", "ui1,4,15", "ui1,5,15", "ui1,6,15", "ui1,7,15", "ui1,8,15", "ui1,9,15", "ui1,10,15", "ui1,11,15", "ui1,12,15", "ui1,13,15", "ui1,14,15", "ui1,15,15",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_box1.tga", "ui_box", 8, 8, arr);
    }

    {
        std::initializer_list<std::string> tiles = {
            "ui2,0,0", "ui2,1,0", "ui2,2,0", "ui2,3,0", "ui2,4,0", "ui2,5,0", "ui2,6,0", "ui2,7,0", "ui2,8,0", "ui2,9,0", "ui2,10,0", "ui2,11,0", "ui2,12,0", "ui2,13,0", "ui2,14,0", "ui2,15,0",
            "ui2,0,1", "ui2,1,1", "ui2,2,1", "ui2,3,1", "ui2,4,1", "ui2,5,1", "ui2,6,1", "ui2,7,1", "ui2,8,1", "ui2,9,1", "ui2,10,1", "ui2,11,1", "ui2,12,1", "ui2,13,1", "ui2,14,1", "ui2,15,1",
            "ui2,0,2", "ui2,1,2", "ui2,2,2", "ui2,3,2", "ui2,4,2", "ui2,5,2", "ui2,6,2", "ui2,7,2", "ui2,8,2", "ui2,9,2", "ui2,10,2", "ui2,11,2", "ui2,12,2", "ui2,13,2", "ui2,14,2", "ui2,15,2",
            "ui2,0,3", "ui2,1,3", "ui2,2,3", "ui2,3,3", "ui2,4,3", "ui2,5,3", "ui2,6,3", "ui2,7,3", "ui2,8,3", "ui2,9,3", "ui2,10,3", "ui2,11,3", "ui2,12,3", "ui2,13,3", "ui2,14,3", "ui2,15,3",
            "ui2,0,4", "ui2,1,4", "ui2,2,4", "ui2,3,4", "ui2,4,4", "ui2,5,4", "ui2,6,4", "ui2,7,4", "ui2,8,4", "ui2,9,4", "ui2,10,4", "ui2,11,4", "ui2,12,4", "ui2,13,4", "ui2,14,4", "ui2,15,4",
            "ui2,0,5", "ui2,1,5", "ui2,2,5", "ui2,3,5", "ui2,4,5", "ui2,5,5", "ui2,6,5", "ui2,7,5", "ui2,8,5", "ui2,9,5", "ui2,10,5", "ui2,11,5", "ui2,12,5", "ui2,13,5", "ui2,14,5", "ui2,15,5",
            "ui2,0,6", "ui2,1,6", "ui2,2,6", "ui2,3,6", "ui2,4,6", "ui2,5,6", "ui2,6,6", "ui2,7,6", "ui2,8,6", "ui2,9,6", "ui2,10,6", "ui2,11,6", "ui2,12,6", "ui2,13,6", "ui2,14,6", "ui2,15,6",
            "ui2,0,7", "ui2,1,7", "ui2,2,7", "ui2,3,7", "ui2,4,7", "ui2,5,7", "ui2,6,7", "ui2,7,7", "ui2,8,7", "ui2,9,7", "ui2,10,7", "ui2,11,7", "ui2,12,7", "ui2,13,7", "ui2,14,7", "ui2,15,7",
            "ui2,0,8", "ui2,1,8", "ui2,2,8", "ui2,3,8", "ui2,4,8", "ui2,5,8", "ui2,6,8", "ui2,7,8", "ui2,8,8", "ui2,9,8", "ui2,10,8", "ui2,11,8", "ui2,12,8", "ui2,13,8", "ui2,14,8", "ui2,15,8",
            "ui2,0,9", "ui2,1,9", "ui2,2,9", "ui2,3,9", "ui2,4,9", "ui2,5,9", "ui2,6,9", "ui2,7,9", "ui2,8,9", "ui2,9,9", "ui2,10,9", "ui2,11,9", "ui2,12,9", "ui2,13,9", "ui2,14,9", "ui2,15,9",
            "ui2,0,10", "ui2,1,10", "ui2,2,10", "ui2,3,10", "ui2,4,10", "ui2,5,10", "ui2,6,10", "ui2,7,10", "ui2,8,10", "ui2,9,10", "ui2,10,10", "ui2,11,10", "ui2,12,10", "ui2,13,10", "ui2,14,10", "ui2,15,10",
            "ui2,0,11", "ui2,1,11", "ui2,2,11", "ui2,3,11", "ui2,4,11", "ui2,5,11", "ui2,6,11", "ui2,7,11", "ui2,8,11", "ui2,9,11", "ui2,10,11", "ui2,11,11", "ui2,12,11", "ui2,13,11", "ui2,14,11", "ui2,15,11",
            "ui2,0,12", "ui2,1,12", "ui2,2,12", "ui2,3,12", "ui2,4,12", "ui2,5,12", "ui2,6,12", "ui2,7,12", "ui2,8,12", "ui2,9,12", "ui2,10,12", "ui2,11,12", "ui2,12,12", "ui2,13,12", "ui2,14,12", "ui2,15,12",
            "ui2,0,13", "ui2,1,13", "ui2,2,13", "ui2,3,13", "ui2,4,13", "ui2,5,13", "ui2,6,13", "ui2,7,13", "ui2,8,13", "ui2,9,13", "ui2,10,13", "ui2,11,13", "ui2,12,13", "ui2,13,13", "ui2,14,13", "ui2,15,13",
            "ui2,0,14", "ui2,1,14", "ui2,2,14", "ui2,3,14", "ui2,4,14", "ui2,5,14", "ui2,6,14", "ui2,7,14", "ui2,8,14", "ui2,9,14", "ui2,10,14", "ui2,11,14", "ui2,12,14", "ui2,13,14", "ui2,14,14", "ui2,15,14",
            "ui2,0,15", "ui2,1,15", "ui2,2,15", "ui2,3,15", "ui2,4,15", "ui2,5,15", "ui2,6,15", "ui2,7,15", "ui2,8,15", "ui2,9,15", "ui2,10,15", "ui2,11,15", "ui2,12,15", "ui2,13,15", "ui2,14,15", "ui2,15,15",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_box2.tga", "ui_box2", 8, 8, arr);
    }

    {
        std::initializer_list<std::string> tiles = {
            "ui3,0,0", "ui3,1,0", "ui3,2,0", "ui3,3,0", "ui3,4,0", "ui3,5,0", "ui3,6,0", "ui3,7,0", "ui3,8,0", "ui3,9,0", "ui3,10,0", "ui3,11,0", "ui3,12,0", "ui3,13,0", "ui3,14,0", "ui3,15,0",
            "ui3,0,1", "ui3,1,1", "ui3,2,1", "ui3,3,1", "ui3,4,1", "ui3,5,1", "ui3,6,1", "ui3,7,1", "ui3,8,1", "ui3,9,1", "ui3,10,1", "ui3,11,1", "ui3,12,1", "ui3,13,1", "ui3,14,1", "ui3,15,1",
            "ui3,0,2", "ui3,1,2", "ui3,2,2", "ui3,3,2", "ui3,4,2", "ui3,5,2", "ui3,6,2", "ui3,7,2", "ui3,8,2", "ui3,9,2", "ui3,10,2", "ui3,11,2", "ui3,12,2", "ui3,13,2", "ui3,14,2", "ui3,15,2",
            "ui3,0,3", "ui3,1,3", "ui3,2,3", "ui3,3,3", "ui3,4,3", "ui3,5,3", "ui3,6,3", "ui3,7,3", "ui3,8,3", "ui3,9,3", "ui3,10,3", "ui3,11,3", "ui3,12,3", "ui3,13,3", "ui3,14,3", "ui3,15,3",
            "ui3,0,4", "ui3,1,4", "ui3,2,4", "ui3,3,4", "ui3,4,4", "ui3,5,4", "ui3,6,4", "ui3,7,4", "ui3,8,4", "ui3,9,4", "ui3,10,4", "ui3,11,4", "ui3,12,4", "ui3,13,4", "ui3,14,4", "ui3,15,4",
            "ui3,0,5", "ui3,1,5", "ui3,2,5", "ui3,3,5", "ui3,4,5", "ui3,5,5", "ui3,6,5", "ui3,7,5", "ui3,8,5", "ui3,9,5", "ui3,10,5", "ui3,11,5", "ui3,12,5", "ui3,13,5", "ui3,14,5", "ui3,15,5",
            "ui3,0,6", "ui3,1,6", "ui3,2,6", "ui3,3,6", "ui3,4,6", "ui3,5,6", "ui3,6,6", "ui3,7,6", "ui3,8,6", "ui3,9,6", "ui3,10,6", "ui3,11,6", "ui3,12,6", "ui3,13,6", "ui3,14,6", "ui3,15,6",
            "ui3,0,7", "ui3,1,7", "ui3,2,7", "ui3,3,7", "ui3,4,7", "ui3,5,7", "ui3,6,7", "ui3,7,7", "ui3,8,7", "ui3,9,7", "ui3,10,7", "ui3,11,7", "ui3,12,7", "ui3,13,7", "ui3,14,7", "ui3,15,7",
            "ui3,0,8", "ui3,1,8", "ui3,2,8", "ui3,3,8", "ui3,4,8", "ui3,5,8", "ui3,6,8", "ui3,7,8", "ui3,8,8", "ui3,9,8", "ui3,10,8", "ui3,11,8", "ui3,12,8", "ui3,13,8", "ui3,14,8", "ui3,15,8",
            "ui3,0,9", "ui3,1,9", "ui3,2,9", "ui3,3,9", "ui3,4,9", "ui3,5,9", "ui3,6,9", "ui3,7,9", "ui3,8,9", "ui3,9,9", "ui3,10,9", "ui3,11,9", "ui3,12,9", "ui3,13,9", "ui3,14,9", "ui3,15,9",
            "ui3,0,10", "ui3,1,10", "ui3,2,10", "ui3,3,10", "ui3,4,10", "ui3,5,10", "ui3,6,10", "ui3,7,10", "ui3,8,10", "ui3,9,10", "ui3,10,10", "ui3,11,10", "ui3,12,10", "ui3,13,10", "ui3,14,10", "ui3,15,10",
            "ui3,0,11", "ui3,1,11", "ui3,2,11", "ui3,3,11", "ui3,4,11", "ui3,5,11", "ui3,6,11", "ui3,7,11", "ui3,8,11", "ui3,9,11", "ui3,10,11", "ui3,11,11", "ui3,12,11", "ui3,13,11", "ui3,14,11", "ui3,15,11",
            "ui3,0,12", "ui3,1,12", "ui3,2,12", "ui3,3,12", "ui3,4,12", "ui3,5,12", "ui3,6,12", "ui3,7,12", "ui3,8,12", "ui3,9,12", "ui3,10,12", "ui3,11,12", "ui3,12,12", "ui3,13,12", "ui3,14,12", "ui3,15,12",
            "ui3,0,13", "ui3,1,13", "ui3,2,13", "ui3,3,13", "ui3,4,13", "ui3,5,13", "ui3,6,13", "ui3,7,13", "ui3,8,13", "ui3,9,13", "ui3,10,13", "ui3,11,13", "ui3,12,13", "ui3,13,13", "ui3,14,13", "ui3,15,13",
            "ui3,0,14", "ui3,1,14", "ui3,2,14", "ui3,3,14", "ui3,4,14", "ui3,5,14", "ui3,6,14", "ui3,7,14", "ui3,8,14", "ui3,9,14", "ui3,10,14", "ui3,11,14", "ui3,12,14", "ui3,13,14", "ui3,14,14", "ui3,15,14",
            "ui3,0,15", "ui3,1,15", "ui3,2,15", "ui3,3,15", "ui3,4,15", "ui3,5,15", "ui3,6,15", "ui3,7,15", "ui3,8,15", "ui3,9,15", "ui3,10,15", "ui3,11,15", "ui3,12,15", "ui3,13,15", "ui3,14,15", "ui3,15,15",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_box3.tga", "ui_box3", 8, 8, arr);
    }

    {
        std::initializer_list<std::string> tiles = {
            "ui4,0,0", "ui4,1,0", "ui4,2,0", "ui4,3,0", "ui4,4,0", "ui4,5,0", "ui4,6,0", "ui4,7,0", "ui4,8,0", "ui4,9,0", "ui4,10,0", "ui4,11,0", "ui4,12,0", "ui4,13,0", "ui4,14,0", "ui4,15,0",
            "ui4,0,1", "ui4,1,1", "ui4,2,1", "ui4,3,1", "ui4,4,1", "ui4,5,1", "ui4,6,1", "ui4,7,1", "ui4,8,1", "ui4,9,1", "ui4,10,1", "ui4,11,1", "ui4,12,1", "ui4,13,1", "ui4,14,1", "ui4,15,1",
            "ui4,0,2", "ui4,1,2", "ui4,2,2", "ui4,3,2", "ui4,4,2", "ui4,5,2", "ui4,6,2", "ui4,7,2", "ui4,8,2", "ui4,9,2", "ui4,10,2", "ui4,11,2", "ui4,12,2", "ui4,13,2", "ui4,14,2", "ui4,15,2",
            "ui4,0,3", "ui4,1,3", "ui4,2,3", "ui4,3,3", "ui4,4,3", "ui4,5,3", "ui4,6,3", "ui4,7,3", "ui4,8,3", "ui4,9,3", "ui4,10,3", "ui4,11,3", "ui4,12,3", "ui4,13,3", "ui4,14,3", "ui4,15,3",
            "ui4,0,4", "ui4,1,4", "ui4,2,4", "ui4,3,4", "ui4,4,4", "ui4,5,4", "ui4,6,4", "ui4,7,4", "ui4,8,4", "ui4,9,4", "ui4,10,4", "ui4,11,4", "ui4,12,4", "ui4,13,4", "ui4,14,4", "ui4,15,4",
            "ui4,0,5", "ui4,1,5", "ui4,2,5", "ui4,3,5", "ui4,4,5", "ui4,5,5", "ui4,6,5", "ui4,7,5", "ui4,8,5", "ui4,9,5", "ui4,10,5", "ui4,11,5", "ui4,12,5", "ui4,13,5", "ui4,14,5", "ui4,15,5",
            "ui4,0,6", "ui4,1,6", "ui4,2,6", "ui4,3,6", "ui4,4,6", "ui4,5,6", "ui4,6,6", "ui4,7,6", "ui4,8,6", "ui4,9,6", "ui4,10,6", "ui4,11,6", "ui4,12,6", "ui4,13,6", "ui4,14,6", "ui4,15,6",
            "ui4,0,7", "ui4,1,7", "ui4,2,7", "ui4,3,7", "ui4,4,7", "ui4,5,7", "ui4,6,7", "ui4,7,7", "ui4,8,7", "ui4,9,7", "ui4,10,7", "ui4,11,7", "ui4,12,7", "ui4,13,7", "ui4,14,7", "ui4,15,7",
            "ui4,0,8", "ui4,1,8", "ui4,2,8", "ui4,3,8", "ui4,4,8", "ui4,5,8", "ui4,6,8", "ui4,7,8", "ui4,8,8", "ui4,9,8", "ui4,10,8", "ui4,11,8", "ui4,12,8", "ui4,13,8", "ui4,14,8", "ui4,15,8",
            "ui4,0,9", "ui4,1,9", "ui4,2,9", "ui4,3,9", "ui4,4,9", "ui4,5,9", "ui4,6,9", "ui4,7,9", "ui4,8,9", "ui4,9,9", "ui4,10,9", "ui4,11,9", "ui4,12,9", "ui4,13,9", "ui4,14,9", "ui4,15,9",
            "ui4,0,10", "ui4,1,10", "ui4,2,10", "ui4,3,10", "ui4,4,10", "ui4,5,10", "ui4,6,10", "ui4,7,10", "ui4,8,10", "ui4,9,10", "ui4,10,10", "ui4,11,10", "ui4,12,10", "ui4,13,10", "ui4,14,10", "ui4,15,10",
            "ui4,0,11", "ui4,1,11", "ui4,2,11", "ui4,3,11", "ui4,4,11", "ui4,5,11", "ui4,6,11", "ui4,7,11", "ui4,8,11", "ui4,9,11", "ui4,10,11", "ui4,11,11", "ui4,12,11", "ui4,13,11", "ui4,14,11", "ui4,15,11",
            "ui4,0,12", "ui4,1,12", "ui4,2,12", "ui4,3,12", "ui4,4,12", "ui4,5,12", "ui4,6,12", "ui4,7,12", "ui4,8,12", "ui4,9,12", "ui4,10,12", "ui4,11,12", "ui4,12,12", "ui4,13,12", "ui4,14,12", "ui4,15,12",
            "ui4,0,13", "ui4,1,13", "ui4,2,13", "ui4,3,13", "ui4,4,13", "ui4,5,13", "ui4,6,13", "ui4,7,13", "ui4,8,13", "ui4,9,13", "ui4,10,13", "ui4,11,13", "ui4,12,13", "ui4,13,13", "ui4,14,13", "ui4,15,13",
            "ui4,0,14", "ui4,1,14", "ui4,2,14", "ui4,3,14", "ui4,4,14", "ui4,5,14", "ui4,6,14", "ui4,7,14", "ui4,8,14", "ui4,9,14", "ui4,10,14", "ui4,11,14", "ui4,12,14", "ui4,13,14", "ui4,14,14", "ui4,15,14",
            "ui4,0,15", "ui4,1,15", "ui4,2,15", "ui4,3,15", "ui4,4,15", "ui4,5,15", "ui4,6,15", "ui4,7,15", "ui4,8,15", "ui4,9,15", "ui4,10,15", "ui4,11,15", "ui4,12,15", "ui4,13,15", "ui4,14,15", "ui4,15,15",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_box4.tga", "ui_box4", 8, 8, arr);
    }

    {
        std::initializer_list<std::string> tiles = {
            "ui5,0,0", "ui5,1,0", "ui5,2,0", "ui5,3,0", "ui5,4,0", "ui5,5,0", "ui5,6,0", "ui5,7,0", "ui5,8,0", "ui5,9,0", "ui5,10,0", "ui5,11,0", "ui5,12,0", "ui5,13,0", "ui5,14,0", "ui5,15,0",
            "ui5,0,1", "ui5,1,1", "ui5,2,1", "ui5,3,1", "ui5,4,1", "ui5,5,1", "ui5,6,1", "ui5,7,1", "ui5,8,1", "ui5,9,1", "ui5,10,1", "ui5,11,1", "ui5,12,1", "ui5,13,1", "ui5,14,1", "ui5,15,1",
            "ui5,0,2", "ui5,1,2", "ui5,2,2", "ui5,3,2", "ui5,4,2", "ui5,5,2", "ui5,6,2", "ui5,7,2", "ui5,8,2", "ui5,9,2", "ui5,10,2", "ui5,11,2", "ui5,12,2", "ui5,13,2", "ui5,14,2", "ui5,15,2",
            "ui5,0,3", "ui5,1,3", "ui5,2,3", "ui5,3,3", "ui5,4,3", "ui5,5,3", "ui5,6,3", "ui5,7,3", "ui5,8,3", "ui5,9,3", "ui5,10,3", "ui5,11,3", "ui5,12,3", "ui5,13,3", "ui5,14,3", "ui5,15,3",
            "ui5,0,4", "ui5,1,4", "ui5,2,4", "ui5,3,4", "ui5,4,4", "ui5,5,4", "ui5,6,4", "ui5,7,4", "ui5,8,4", "ui5,9,4", "ui5,10,4", "ui5,11,4", "ui5,12,4", "ui5,13,4", "ui5,14,4", "ui5,15,4",
            "ui5,0,5", "ui5,1,5", "ui5,2,5", "ui5,3,5", "ui5,4,5", "ui5,5,5", "ui5,6,5", "ui5,7,5", "ui5,8,5", "ui5,9,5", "ui5,10,5", "ui5,11,5", "ui5,12,5", "ui5,13,5", "ui5,14,5", "ui5,15,5",
            "ui5,0,6", "ui5,1,6", "ui5,2,6", "ui5,3,6", "ui5,4,6", "ui5,5,6", "ui5,6,6", "ui5,7,6", "ui5,8,6", "ui5,9,6", "ui5,10,6", "ui5,11,6", "ui5,12,6", "ui5,13,6", "ui5,14,6", "ui5,15,6",
            "ui5,0,7", "ui5,1,7", "ui5,2,7", "ui5,3,7", "ui5,4,7", "ui5,5,7", "ui5,6,7", "ui5,7,7", "ui5,8,7", "ui5,9,7", "ui5,10,7", "ui5,11,7", "ui5,12,7", "ui5,13,7", "ui5,14,7", "ui5,15,7",
            "ui5,0,8", "ui5,1,8", "ui5,2,8", "ui5,3,8", "ui5,4,8", "ui5,5,8", "ui5,6,8", "ui5,7,8", "ui5,8,8", "ui5,9,8", "ui5,10,8", "ui5,11,8", "ui5,12,8", "ui5,13,8", "ui5,14,8", "ui5,15,8",
            "ui5,0,9", "ui5,1,9", "ui5,2,9", "ui5,3,9", "ui5,4,9", "ui5,5,9", "ui5,6,9", "ui5,7,9", "ui5,8,9", "ui5,9,9", "ui5,10,9", "ui5,11,9", "ui5,12,9", "ui5,13,9", "ui5,14,9", "ui5,15,9",
            "ui5,0,10", "ui5,1,10", "ui5,2,10", "ui5,3,10", "ui5,4,10", "ui5,5,10", "ui5,6,10", "ui5,7,10", "ui5,8,10", "ui5,9,10", "ui5,10,10", "ui5,11,10", "ui5,12,10", "ui5,13,10", "ui5,14,10", "ui5,15,10",
            "ui5,0,11", "ui5,1,11", "ui5,2,11", "ui5,3,11", "ui5,4,11", "ui5,5,11", "ui5,6,11", "ui5,7,11", "ui5,8,11", "ui5,9,11", "ui5,10,11", "ui5,11,11", "ui5,12,11", "ui5,13,11", "ui5,14,11", "ui5,15,11",
            "ui5,0,12", "ui5,1,12", "ui5,2,12", "ui5,3,12", "ui5,4,12", "ui5,5,12", "ui5,6,12", "ui5,7,12", "ui5,8,12", "ui5,9,12", "ui5,10,12", "ui5,11,12", "ui5,12,12", "ui5,13,12", "ui5,14,12", "ui5,15,12",
            "ui5,0,13", "ui5,1,13", "ui5,2,13", "ui5,3,13", "ui5,4,13", "ui5,5,13", "ui5,6,13", "ui5,7,13", "ui5,8,13", "ui5,9,13", "ui5,10,13", "ui5,11,13", "ui5,12,13", "ui5,13,13", "ui5,14,13", "ui5,15,13",
            "ui5,0,14", "ui5,1,14", "ui5,2,14", "ui5,3,14", "ui5,4,14", "ui5,5,14", "ui5,6,14", "ui5,7,14", "ui5,8,14", "ui5,9,14", "ui5,10,14", "ui5,11,14", "ui5,12,14", "ui5,13,14", "ui5,14,14", "ui5,15,14",
            "ui5,0,15", "ui5,1,15", "ui5,2,15", "ui5,3,15", "ui5,4,15", "ui5,5,15", "ui5,6,15", "ui5,7,15", "ui5,8,15", "ui5,9,15", "ui5,10,15", "ui5,11,15", "ui5,12,15", "ui5,13,15", "ui5,14,15", "ui5,15,15",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_box5.tga", "ui_box5", 8, 8, arr);
    }

    {
        std::initializer_list<std::string> tiles = {
            "ui_popup",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_popup.tga", "ui_popup", 80, 152, arr);
    }

    {
        std::initializer_list<std::string> tiles = {
            "ui_popup_short",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_popup_short.tga", "ui_popup_short", 80, 34, arr);
    }

    {
        std::initializer_list<std::string> tiles = {
            "ui_popup_notice",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_popup_notice.tga", "ui_popup_notice", 80, 34, arr);
    }

    {
        std::initializer_list<std::string> tiles = {
            "ui_popup_wide",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_popup_wide.tga", "ui_popup_wide", 120, 152, arr);
    }

    {
        std::initializer_list<std::string> tiles = {
            "ui_popup_widest",
        };
        std::vector<std::string> arr(tiles);
        tile_load_arr("data/gfx/ui_popup_widest.tga", "ui_popup_widest", 160, 152, arr);
    }
}

static void gfx_init_text (void)
{
    std::initializer_list<std::string> tiles = {
        //////////////////////////////////////////////////////////////////
        // sp     !       "       #       $       %       &       '
        //////////////////////////////////////////////////////////////////
        "C0",   "C1",   "C2",   "C3",   "C4",   "C5",   "C6",   "C7",
        //////////////////////////////////////////////////////////////////
        //  (     )       *       +       ,       -       .       /
        //////////////////////////////////////////////////////////////////
        "C8",   "C9",   "C10",  "C11",  "C12",  "C13",  "C14",  "C15",
        //////////////////////////////////////////////////////////////////
        //  0     1       2       3       4       5       6       7
        //////////////////////////////////////////////////////////////////
        "C16",  "C17",  "C18",  "C19",  "C20",  "C21",  "C22",  "C23",
        //////////////////////////////////////////////////////////////////
        //  8     9       :       ;       <       =       >       ?
        //////////////////////////////////////////////////////////////////
        "C24",  "C25",  "C26",  "C27",  "C28",  "C29",  "C30",  "C31",
        //////////////////////////////////////////////////////////////////
        //  @     A       B       C       D       E       F       G
        //////////////////////////////////////////////////////////////////
        "C32",  "C33",  "C34",  "C35",  "C36",  "C37",  "C38",  "C39",
        //////////////////////////////////////////////////////////////////
        //  H     I       J       K       L       M       N       O
        //////////////////////////////////////////////////////////////////
        "C40",  "C41",  "C42",  "C43",  "C44",  "C45",  "C46",  "C47",
        //////////////////////////////////////////////////////////////////
        //  P     Q       R       S       T       U       V       W
        //////////////////////////////////////////////////////////////////
        "C48",  "C49",  "C50",  "C51",  "C52",  "C53",  "C54",  "C55",
        //////////////////////////////////////////////////////////////////
        //  X     Y       Z       [       \       ]       ^       _
        //////////////////////////////////////////////////////////////////
        "C56",  "C57",  "C58",  "C59",  "C60",  "C61",  "C62",  "C63",
        //////////////////////////////////////////////////////////////////
        //  `     a       b       c       d       e       f       g
        //////////////////////////////////////////////////////////////////
        "C64",  "C65",  "C66",  "C67",  "C68",  "C69",  "C70",  "C71",
        //////////////////////////////////////////////////////////////////
        //  h     i       j       k       l       m       n       o
        //////////////////////////////////////////////////////////////////
        "C72",  "C73",  "C74",  "C75",  "C76",  "C77",  "C78",  "C79",
        //////////////////////////////////////////////////////////////////
        //  p     q       r       s       t       u       v       w
        //////////////////////////////////////////////////////////////////
        "C80",  "C81",  "C82",  "C83",  "C84",  "C85",  "C86",  "C87",
        //////////////////////////////////////////////////////////////////
        //  x     y       z       {       |       }       ~       del
        //////////////////////////////////////////////////////////////////
        "C88",  "C89",  "C90",  "C91",  "C92",  "C93",  "C94",  "C95",
        //////////////////////////////////////////////////////////////////
        //  blk  [$]     lbs    arrow
        //////////////////////////////////////////////////////////////////
        "C96",  "C97",  "C98",  "C99", "C100", "", "", "",
    };

    std::vector<std::string> arr(tiles);
    tile_load_arr("data/ttf/loresfont.tga", "text", 
                  FONT_WIDTH, FONT_HEIGHT, arr);
}

void gfx_init (void)
{
    gfx_init_text();
    gfx_init_ui_box();
}

void gfx_fini (void)
{
}
