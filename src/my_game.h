//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#ifndef _MY_GAME_H_
#define _MY_GAME_H_

#include "my_sdl.h"
#include "my_dmap.h"
#include "my_terrain.h"
#include <array>
#include <unordered_map>

class Thing;
class Light;

typedef class Thing* Thingp;
typedef std::unordered_map< uint32_t, Thingp > Things;

typedef class Light* Lightp;
typedef std::unordered_map< uint32_t, Lightp > Lights;

typedef class World* Worldp;

#include "my_thing.h"

enum {
    MAP_DEPTH_FLOOR,
    MAP_DEPTH_WATER,
    MAP_DEPTH_LAVA,
    MAP_DEPTH_BLOOD,
#define MAP_DEPTH_LAST_FLOOR_TYPE MAP_DEPTH_BLOOD
    MAP_DEPTH_SOIL,
    MAP_DEPTH_GRASS,
    MAP_DEPTH_GRAVEL,
    MAP_DEPTH_SNOW,
    MAP_DEPTH_FLOOR_DECO,
    MAP_DEPTH_WALLS,
    MAP_DEPTH_WALLS_DECO,
    MAP_DEPTH_EXIT,
    MAP_DEPTH_ITEM,
    MAP_DEPTH_FOOD,
    MAP_DEPTH_MONST,
    MAP_DEPTH_PLAYER,
    MAP_DEPTH_WEAPON,
    MAP_DEPTH,
};

class World {
private:
    uint8_t                    _is_wall[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_solid[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_gfx_large_shadow_caster[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_door[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_light[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_floor[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_lava[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_blood[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_water[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_deep_water[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_corridor[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_dirt[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_grass[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_soil[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_gravel[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_snow[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_monst[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_food[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_rock[MAP_WIDTH][MAP_HEIGHT] = {};
    uint8_t                    _is_key[MAP_WIDTH][MAP_HEIGHT] = {};
public:
    //
    // World map
    //
    Terrainp                   terrain;

    //
    // Global all things
    //
    Things                     all_things;

    //
    // Global all things that move
    //
    Things                     all_active_things;

    //
    // All things
    //
    std::array<
      std::array<
        std::array<uint32_t, MAP_THINGS_PER_CELL>, MAP_HEIGHT>, MAP_WIDTH> 
          all_thing_ids_at;

    Thingp get_first_thing(point p);
    Thingp get_first_thing(int x, int y);
    void remove_thing(int x, int y, uint32_t id);
    void put_thing(int x, int y, uint32_t id);
    void remove_thing(point p, uint32_t id);
    void put_thing(point p, uint32_t id);
    std::vector<Thingp> get_all_things_at_depth(int x, int y, int z);

    //
    // Things that move around
    //
    std::unordered_map<uint32_t, Thingp> all_active_things_at[MAP_WIDTH][MAP_HEIGHT];

    //
    // Things that move around and things that do not, but are interesting,
    // like food
    //
    std::unordered_map<uint32_t, Thingp> all_interesting_things_at[MAP_WIDTH][MAP_HEIGHT];

    //
    // Things that block progress
    //
    std::unordered_map<uint32_t, Thingp> all_obstacle_things_at[MAP_WIDTH][MAP_HEIGHT];

    //
    // The player!
    //
    Thingp                     player = {};

    //
    // Global lights
    //
    Lights                     all_lights;

    //
    // Where we're looking in the map
    //
    fpoint                     map_at;
    fpoint                     map_wanted_at;
    point                      map_tile_over;

    //
    // All lights at a map cell
    //
    std::unordered_map<uint32_t, Lightp> lights[MAP_WIDTH][MAP_HEIGHT];

    bool is_anything_at(const point &p);
    bool is_anything_at(const int x, const int y);
    bool is_lava(const point &p);
    bool is_lava(const int x, const int y);
    void set_lava(const int x, const int y);
    void unset_lava(const int x, const int y);
    bool is_blood(const point &p);
    bool is_blood(const int x, const int y);
    void set_blood(const int x, const int y);
    void unset_blood(const int x, const int y);
    bool is_water(const point &p);
    bool is_water(const int x, const int y);
    void set_water(const int x, const int y);
    void unset_water(const int x, const int y);
    bool is_deep_water(const point &p);
    bool is_deep_water(const int x, const int y);
    void set_deep_water(const int x, const int y);
    void unset_deep_water(const int x, const int y);
    bool is_wall(const point &p);
    bool is_wall(const int x, const int y);
    void set_wall(const int x, const int y);
    void unset_wall(const int x, const int y);
    bool is_solid(const point &p);
    bool is_solid(const int x, const int y);
    void set_solid(const int x, const int y);
    void unset_solid(const int x, const int y);
    bool is_light(const point &p);
    bool is_light(const int x, const int y);
    void set_light(const int x, const int y);
    void unset_light(const int x, const int y);
    bool is_corridor(const point &p);
    bool is_corridor(const int x, const int y);
    void set_corridor(const int x, const int y);
    void unset_corridor(const int x, const int y);
    bool is_dirt(const point &p);
    bool is_dirt(const int x, const int y);
    void dir_sett(const int x, const int y);
    void undir_sett(const int x, const int y);
    bool is_grass(const point &p);
    bool is_grass(const int x, const int y);
    void set_grass(const int x, const int y);
    void unset_grass(const int x, const int y);
    bool is_soil(const point &p);
    bool is_soil(const int x, const int y);
    void set_soil(const int x, const int y);
    void unset_soil(const int x, const int y);
    bool is_gravel(const point &p);
    bool is_gravel(const int x, const int y);
    void set_gravel(const int x, const int y);
    void unset_gravel(const int x, const int y);
    bool is_snow(const point &p);
    bool is_snow(const int x, const int y);
    void set_snow(const int x, const int y);
    void unset_snow(const int x, const int y);
    bool is_floor(const point &p);
    bool is_floor(const int x, const int y);
    void set_floor(const int x, const int y);
    void unset_floor(const int x, const int y);
    bool is_monst(const point &p);
    bool is_monst(const int x, const int y);
    void set_monst(const int x, const int y);
    void unset_monst(const int x, const int y);
    bool is_food(const int x, const int y);
    void set_food(const int x, const int y);
    void unset_food(const int x, const int y);
    bool is_rock(const point &p);
    bool is_rock(const int x, const int y);
    void set_rock(const int x, const int y);
    void unset_rock(const int x, const int y);
    bool is_key(const point &p);
    bool is_key(const int x, const int y);
    void set_key(const int x, const int y);
    void unset_key(const int x, const int y);
    bool is_gfx_large_shadow_caster(const point &p);
    bool is_gfx_large_shadow_caster(const int x, const int y);
    void set_gfx_large_shadow_caster(const int x, const int y);
    void unset_gfx_large_shadow_caster(const int x, const int y);
    bool is_door(const point &p);
    bool is_door(const int x, const int y);
    void set_door(const int x, const int y);
    void unset_door(const int x, const int y);
    void clear(void);
    bool is_oob(const int x, const int y, const int z);
    bool is_oob(const int x, const int y);
    bool is_oob(const fpoint p);
    bool is_oob(const point p);
};

class Config {
public:
    bool               fps_counter                  = true;
    uint32_t           sound_volume                 = {};
    uint32_t           music_volume                 = {};
    bool               vsync_enable                 = true;
    bool               full_screen                  = false;
    int32_t            video_pix_width              = {};
    int32_t            video_pix_height             = {};
    double             video_gl_width               = {};
    double             video_gl_height              = {};
    double             video_w_h_ratio              = {};
    int32_t            drawable_gl_width            = {};
    int32_t            drawable_gl_height           = {};
    double             tile_gl_width                = {};
    double             tile_gl_height               = {};
    double             one_pixel_gl_width           = {};
    double             one_pixel_gl_height          = {};
    double             ascii_gl_width               = {};
    double             ascii_gl_height              = {};
    double             tile_pixel_width             = {};
    double             tile_pixel_height            = {};
    uint32_t           sdl_delay                    = 1;
};

class Game {
public:
    Config             config;
    World              world;
    uint32_t           fps_count = {};
};

extern class Game *game;
extern class World *world;

uint8_t game_mouse_motion(int32_t x, int32_t y, int32_t wheelx, int32_t wheely);
void game_mouse_over(int32_t x, int32_t y, int32_t wheelx, int32_t wheely);
uint8_t game_mouse_down(int32_t x, int32_t y, uint32_t button);
uint8_t game_key_down(const struct SDL_KEYSYM *key);
void game_display(void);
void game_init(void);
void game_fini(void);
void player_tick(void);

#endif
