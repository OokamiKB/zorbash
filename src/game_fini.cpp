//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include "my_game.h"

void Config::fini (void)
{_
}

void Game::fini (void)
{_
    fps_value = 0;
    started = false;
    things_are_moving = false;
    tick_completed = 0;
    tick_current = 0;

    config.fini();

    world.fini();

    delete player_dmap;
    player_dmap = nullptr;
}
