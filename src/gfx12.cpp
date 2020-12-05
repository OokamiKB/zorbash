//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_tile.h"

void gfx_init12 (void)
{
    std::initializer_list<std::string> tiles = {
        "ui12,0,0", "ui12,1,0", "ui12,2,0", "ui12,3,0", "ui12,4,0", "ui12,5,0", "ui12,6,0", "ui12,7,0", "ui12,8,0", "ui12,9,0", "ui12,10,0", "ui12,11,0", "ui12,12,0", "ui12,13,0", "ui12,14,0", "ui12,15,0",
        "ui12,0,1", "ui12,1,1", "ui12,2,1", "ui12,3,1", "ui12,4,1", "ui12,5,1", "ui12,6,1", "ui12,7,1", "ui12,8,1", "ui12,9,1", "ui12,10,1", "ui12,11,1", "ui12,12,1", "ui12,13,1", "ui12,14,1", "ui12,15,1",
        "ui12,0,2", "ui12,1,2", "ui12,2,2", "ui12,3,2", "ui12,4,2", "ui12,5,2", "ui12,6,2", "ui12,7,2", "ui12,8,2", "ui12,9,2", "ui12,10,2", "ui12,11,2", "ui12,12,2", "ui12,13,2", "ui12,14,2", "ui12,15,2",
        "ui12,0,3", "ui12,1,3", "ui12,2,3", "ui12,3,3", "ui12,4,3", "ui12,5,3", "ui12,6,3", "ui12,7,3", "ui12,8,3", "ui12,9,3", "ui12,10,3", "ui12,11,3", "ui12,12,3", "ui12,13,3", "ui12,14,3", "ui12,15,3",
        "ui12,0,4", "ui12,1,4", "ui12,2,4", "ui12,3,4", "ui12,4,4", "ui12,5,4", "ui12,6,4", "ui12,7,4", "ui12,8,4", "ui12,9,4", "ui12,10,4", "ui12,11,4", "ui12,12,4", "ui12,13,4", "ui12,14,4", "ui12,15,4",
        "ui12,0,5", "ui12,1,5", "ui12,2,5", "ui12,3,5", "ui12,4,5", "ui12,5,5", "ui12,6,5", "ui12,7,5", "ui12,8,5", "ui12,9,5", "ui12,10,5", "ui12,11,5", "ui12,12,5", "ui12,13,5", "ui12,14,5", "ui12,15,5",
        "ui12,0,6", "ui12,1,6", "ui12,2,6", "ui12,3,6", "ui12,4,6", "ui12,5,6", "ui12,6,6", "ui12,7,6", "ui12,8,6", "ui12,9,6", "ui12,10,6", "ui12,11,6", "ui12,12,6", "ui12,13,6", "ui12,14,6", "ui12,15,6",
        "ui12,0,7", "ui12,1,7", "ui12,2,7", "ui12,3,7", "ui12,4,7", "ui12,5,7", "ui12,6,7", "ui12,7,7", "ui12,8,7", "ui12,9,7", "ui12,10,7", "ui12,11,7", "ui12,12,7", "ui12,13,7", "ui12,14,7", "ui12,15,7",
        "ui12,0,8", "ui12,1,8", "ui12,2,8", "ui12,3,8", "ui12,4,8", "ui12,5,8", "ui12,6,8", "ui12,7,8", "ui12,8,8", "ui12,9,8", "ui12,10,8", "ui12,11,8", "ui12,12,8", "ui12,13,8", "ui12,14,8", "ui12,15,8",
        "ui12,0,9", "ui12,1,9", "ui12,2,9", "ui12,3,9", "ui12,4,9", "ui12,5,9", "ui12,6,9", "ui12,7,9", "ui12,8,9", "ui12,9,9", "ui12,10,9", "ui12,11,9", "ui12,12,9", "ui12,13,9", "ui12,14,9", "ui12,15,9",
        "ui12,0,10", "ui12,1,10", "ui12,2,10", "ui12,3,10", "ui12,4,10", "ui12,5,10", "ui12,6,10", "ui12,7,10", "ui12,8,10", "ui12,9,10", "ui12,10,10", "ui12,11,10", "ui12,12,10", "ui12,13,10", "ui12,14,10", "ui12,15,10",
        "ui12,0,11", "ui12,1,11", "ui12,2,11", "ui12,3,11", "ui12,4,11", "ui12,5,11", "ui12,6,11", "ui12,7,11", "ui12,8,11", "ui12,9,11", "ui12,10,11", "ui12,11,11", "ui12,12,11", "ui12,13,11", "ui12,14,11", "ui12,15,11",
        "ui12,0,12", "ui12,1,12", "ui12,2,12", "ui12,3,12", "ui12,4,12", "ui12,5,12", "ui12,6,12", "ui12,7,12", "ui12,8,12", "ui12,9,12", "ui12,10,12", "ui12,11,12", "ui12,12,12", "ui12,13,12", "ui12,14,12", "ui12,15,12",
        "ui12,0,13", "ui12,1,13", "ui12,2,13", "ui12,3,13", "ui12,4,13", "ui12,5,13", "ui12,6,13", "ui12,7,13", "ui12,8,13", "ui12,9,13", "ui12,10,13", "ui12,11,13", "ui12,12,13", "ui12,13,13", "ui12,14,13", "ui12,15,13",
        "ui12,0,14", "ui12,1,14", "ui12,2,14", "ui12,3,14", "ui12,4,14", "ui12,5,14", "ui12,6,14", "ui12,7,14", "ui12,8,14", "ui12,9,14", "ui12,10,14", "ui12,11,14", "ui12,12,14", "ui12,13,14", "ui12,14,14", "ui12,15,14",
        "ui12,0,15", "ui12,1,15", "ui12,2,15", "ui12,3,15", "ui12,4,15", "ui12,5,15", "ui12,6,15", "ui12,7,15", "ui12,8,15", "ui12,9,15", "ui12,10,15", "ui12,11,15", "ui12,12,15", "ui12,13,15", "ui12,14,15", "ui12,15,15",
    };
    const std::vector<std::string> arr(tiles);
    tile_load_arr("data/gfx/ui_bag.tga", "ui_box12", 8, 8, arr);
}