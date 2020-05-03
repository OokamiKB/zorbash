//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

// REMOVED #include "my_main.h"
#include "my_globals.h"

class Game *game;
class World *world;
class Level *level;
struct Thing_ *player;

char *DATA_PATH;
char *EXEC_DIR;
char *EXEC_FULL_PATH_AND_NAME;
char *EXEC_PYTHONPATH;
char *GFX_PATH;
char *TTF_PATH;
char *WORLD_PATH;

FILE *g_log_stdout;
FILE *g_log_stderr;

bool g_croaked;
bool g_errored;
bool g_quitting;
bool g_need_restart;
bool g_render_black_and_white;
bool g_opt_new_game;
bool g_opt_fast_start;
bool g_opt_debug_mode;
bool g_do_screenshot;
bool g_grab_next_key;

int TILES_ACROSS;
int TILES_DOWN;
