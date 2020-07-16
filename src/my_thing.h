//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#pragma once
#ifndef _MY_THING_H_
#define _MY_THING_H_

#include <set>
#include <list>
#include "my_time.h"
#include "my_light.h"
#include "my_thing_ai.h"
#include "my_thing_id.h"

constexpr uint32_t THING_MAGIC_BEGIN = 11221122;
constexpr uint32_t THING_MAGIC_END   = 22112211;
constexpr uint32_t THING_MAGIC_FINAL = 33333333;

typedef struct {
    uint16_t tile_outline;
    uint16_t bl1_tile;
    uint16_t bot1_tile;
    uint16_t br1_tile;
    uint16_t left1_tile;
    uint16_t right1_tile;
    uint16_t tl1_tile;
    uint16_t top1_tile;
    uint16_t tr1_tile;
    uint16_t bl2_tile;
    uint16_t bot2_tile;
    uint16_t br2_tile;
    uint16_t left2_tile;
    uint16_t right2_tile;
    uint16_t tl2_tile;
    uint16_t top2_tile;
    uint16_t tr2_tile;
} ThingTiles;

typedef enum {
    THING_SHOVE_TRIED_AND_FAILED,
    THING_SHOVE_TRIED_AND_PASSED,
    THING_SHOVE_NEVER_TRIED,
} ThingShoved;

typedef struct Monst_ {
public:
    AgeMap       *_age_map = {};             // How old a cell is
    Dmap         *_dmap_scent = {};
    std::vector<Lightp> light = {};          // Has light sources?

    /////////////////////////////////////////////////////////////////////////
    // Keep these sorted alphabetically to make it easier to see additions
    // and always update game_load.cpp and game_save.cpp
    //
    // | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
    // v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v
    /////////////////////////////////////////////////////////////////////////
    ThingId      on_fire_id_anim {};
    ThingId      owner_id {};                // Who created this thing?
    ThingId      weapon_id {};               // Current weapon
    ThingId      weapon_id_carry_anim {};
    ThingId      weapon_id_use_anim {};
    color        light_col {};
    float        bounce_fade = {};           // 0.1; rapid, 0.9 slow
    float        bounce_height = {};         // Percentage of tile height.
    float        fadeup_fade = {};           // 0.1; rapid, 0.9 slow
    float        fadeup_height = {};         // Percentage of tile height.
    float        fall_height = {};           // y offset for falling
    float        wobble = {};                // Fades when set
    fpoint       interpolated_mid_at;
    fpoint       lunge_to;                   // When a monst attacks something
    int          bounce_count = {};
    int          gold = {};
    int          keys = {};
    int          lifespan = {};              // How many things this thing owns.
    int          light_quality {};
    int          light_strength {};
    int          owned_count = {};           // How many things this thing owns.
    int          stats01 = {};
    int          stats02 = {};
    int          stats03 = {};
    int          stats04 = {};
    int          stats05 = {};
    int          stats06 = {};
    int          stats07 = {};
    int          stats08 = {};
    int          stats09 = {};
    int          stats10 = {};
    int          stats11 = {};
    int          stats12 = {};
    int          stats13 = {};
    int          stats14 = {};
    int          stats15 = {};
    int          stats16 = {};
    int          stats17 = {};
    int          stats18 = {};
    int          stats19 = {};
    int          stats_defence = {};
    int          stats_defence_max = {};
    int          stats_health = {};
    int          stats_health_max = {};
    int          stats_strength = {};
    int          submerged_offset = {};      // GL co-orids
    int          tick_rate_tenths = {};
    int          tick_resurrect_when = {};
    point        wander_target;
    std::list<ThingId>   carrying;
    std::string          msg;                // Text that floats on screen
    std::vector<ThingId> actionbar_id;
    std::vector<ThingId> enemies;            // List of things that wronged us
    std::vector<point>   move_path;
    timestamp_t  timestamp_born {};
    timestamp_t  timestamp_bounce_begin {};
    timestamp_t  timestamp_bounce_end {};
    timestamp_t  timestamp_fadeup_begin {};
    timestamp_t  timestamp_fadeup_end {};
    timestamp_t  timestamp_fall_begin {};
    timestamp_t  timestamp_fall_end {};
    timestamp_t  timestamp_flip_start {};    // Used for animating the steps.
    timestamp_t  timestamp_hunger_tick {};   // Ticks every time does something. Used from memory aging
    timestamp_t  timestamp_last_tick {};
    timestamp_t  timestamp_last_ticked {};
    timestamp_t  timestamp_last_wander_try {};
    timestamp_t  timestamp_lunge_begin {};
    timestamp_t  timestamp_lunge_end {};
    timestamp_t  timestamp_move_begin {};
    timestamp_t  timestamp_move_end {};
    uint32_t     tick = {};                  // Increments on completion of move
    uint32_t     tick_last_did_something {};
    uint32_t     tick_last_escape {};
    uint32_t     tick_last_level_change {};
    /////////////////////////////////////////////////////////////////////////
    // ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^
    // | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
    //
    // Keep these sorted alphabetically to make it easier to see additions
    // and always update game_load.cpp and game_save.cpp
    /////////////////////////////////////////////////////////////////////////
} Monst;
std::ostream& operator<<(std::ostream &out, Bits<const Monst & > const my);
std::istream& operator>>(std::istream &in, Bits<Monst &> my);

typedef struct Thing_ {
public:
    Thing_ (void);
    ~Thing_ (void);
    Monst       *monstp              {};
    Level       *level               {};
    int16_t     tp_id                {-1};  // Common settings
    ThingId     id                   {};    // Unique per thing.
    ThingTiles  tiles                {};
    fpoint      last_mid_at;         // Previous hop where we were.
    fpoint      mid_at;              // Grid coordinates.
    point       last_attached;
    point       last_blit_br;
    point       last_blit_tl;        // Last blit coords
    timestamp_t timestamp_next_frame {};
    uint16_t    tile_curr            {};
    uint8_t     alpha                {255}; // For fading
    uint32_t    dir:4                {};    // Direction

    /////////////////////////////////////////////////////////////////////////
    // Keep these sorted alphabetically to make it easier to see additions
    // and always update game_load.cpp and game_save.cpp
    //
    // | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
    // v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v v
    /////////////////////////////////////////////////////////////////////////
    uint32_t has_ever_moved:1     {};
    uint32_t has_light:1          {};
    uint32_t inited_tiles:1       {};
    uint32_t is_attached:1        {};
    uint32_t is_being_destroyed:1 {};
    uint32_t is_blitted:1         {};
    uint32_t is_bouncing:1        {};
    uint32_t is_dead:1            {};
    uint32_t is_facing_left:1     {};
    uint32_t is_fadeup:1          {};
    uint32_t is_falling:1         {};
    uint32_t is_hidden:1          {};
    uint32_t is_hungry:1          {};
    uint32_t is_in_lava:1         {};
    uint32_t is_in_water:1        {};
    uint32_t is_jumping:1         {};
    uint32_t is_moving:1          {};
    uint32_t is_open:1            {};
    uint32_t is_resurrected:1     {};
    uint32_t is_resurrecting:1    {};
    uint32_t is_sleeping:1        {};
    uint32_t is_starving:1        {};
    uint32_t is_tick_done:1       {}; // has moved/hit and finished its move
    /////////////////////////////////////////////////////////////////////////
    // ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^
    // | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
    //
    // Keep these sorted alphabetically to make it easier to see additions
    // and always update game_load.cpp and game_save.cpp
    /////////////////////////////////////////////////////////////////////////
private:
    //
    // As this is called a lot, probably worth the memory
    //
    Tpp      mytp                 {};

public:
    const Tpp tp_or_update(void)
    {
        if (likely(mytp != nullptr)) {
            return (mytp);
        }
        if (unlikely(tp_id == -1)) {
            return (nullptr);
        }
        mytp = tp_id_map[tp_id - 1];
        return (mytp);
    }

    const Tpp tp(void) const
    {
        if (likely(mytp != nullptr)) {
            return (mytp);
        }
        if (unlikely(tp_id == -1)) {
            err("no tp set for tp_id %d", tp_id);
            return (nullptr);
        }

        //
        // Means a missing call to tp_or_update
        //
        if (tp_id_map[tp_id - 1]) {
            ERR("no tp has been set yet for tp_id %d", tp_id);
        } else {
            DIE("no tp has been set for invalid tp_id %d", tp_id);
        }
        return (nullptr);
    }

    uint8_t z_depth (void) const
    {
        return (tp()->z_depth);
    }

    uint8_t z_prio (void) const
    {
        return (tp()->z_prio);
    }

    std::size_t get_light_count (void) const
    {
        if (monstp) {
            verify(monstp);
            return (monstp->light.size());
        } else {
            return (0);
        }
    }

    void new_monst(void);
    void get_tiles(void);

    AgeMap *get_age_map(void);
    void new_age_map(void);
    void delete_age_map(void);
    void clear_age_map(void);

    Dmap *get_dmap_scent(void);
    void new_dmap_scent(void);
    void delete_dmap_scent(void);
    void clear_dmap_scent(void);

    std::vector<Lightp> & get_light(void);
    void new_light(fpoint at, fpoint offset, float strength, color col = WHITE);
    void new_light(fpoint at, float strength, color col = WHITE);
    void delete_light(void);

    void set_lunge_to(fpoint);
    fpoint get_lunge_to(void) const;

    void set_bounce_height(float);
    float get_bounce_height(void) const;

    void set_bounce_fade(float);
    float get_bounce_fade(void) const;

    void set_bounce_count(int);
    int get_bounce_count(void) const;

    void set_fadeup_height(float);
    float get_fadeup_height(void) const;

    void set_fadeup_fade(float);
    float get_fadeup_fade(void) const;

    void set_fall_height(float);
    float get_fall_height(void) const;

    void set_wobble(float);
    float get_wobble(void) const;
    float update_wobble(void);
    void wobble(float wobble);

    void set_msg(const std::string&);
    std::string get_msg(void) const;

    void set_submerged_offset(int);
    int get_submerged_offset(void) const;
    uint32_t set_tick(uint32_t);
    uint32_t get_tick(void);
    uint32_t decr_tick(uint32_t);
    uint32_t incr_tick(uint32_t);
    uint32_t decr_tick(void);
    uint32_t incr_tick(void);
    uint32_t set_max_tick_difference();

    int set_gold(int);
    int get_gold(void) const;
    int decr_gold(int);
    int incr_gold(int);
    int decr_gold(void);
    int incr_gold(void);

    int set_keys(int);
    int get_keys(void) const;
    int decr_keys(int);
    int incr_keys(int);
    int decr_keys(void);
    int incr_keys(void);

    int set_stats_health(int);
    int get_stats_health(void) const;
    int decr_stats_health(int);
    int incr_stats_health(int);
    int decr_stats_health(void);
    int incr_stats_health(void);

    int set_stats_health_max(int);
    int get_stats_health_max(void) const;
    int decr_stats_health_max(int);
    int incr_stats_health_max(int);
    int decr_stats_health_max(void);
    int incr_stats_health_max(void);

    float get_stats_health_pct(void);
    bool is_bloodied(void);

    int set_stats_defence(int);
    int get_stats_defence(void) const;
    int decr_stats_defence(int);
    int incr_stats_defence(int);
    int decr_stats_defence(void);
    int incr_stats_defence(void);

    int set_stats_defence_max(int);
    int get_stats_defence_max(void) const;
    int decr_stats_defence_max(int);
    int incr_stats_defence_max(int);
    int decr_stats_defence_max(void);
    int incr_stats_defence_max(void);

    int set_tick_rate_tenths(int);
    int get_tick_rate_tenths(void) const;
    int decr_tick_rate_tenths(int);
    int incr_tick_rate_tenths(int);
    int decr_tick_rate_tenths(void);
    int incr_tick_rate_tenths(void);

    uint32_t set_tick_resurrect_when(int);
    uint32_t get_tick_resurrect_when(void) const;
    uint32_t decr_tick_resurrect_when(int);
    uint32_t incr_tick_resurrect_when(int);
    uint32_t decr_tick_resurrect_when(void);
    uint32_t incr_tick_resurrect_when(void);

    int set_stats01(int);
    int get_stats01(void) const;
    int decr_stats01(int);
    int incr_stats01(int);
    int decr_stats01(void);
    int incr_stats01(void);

    int set_stats02(int);
    int get_stats02(void) const;
    int decr_stats02(int);
    int incr_stats02(int);
    int decr_stats02(void);
    int incr_stats02(void);

    int set_stats03(int);
    int get_stats03(void) const;
    int decr_stats03(int);
    int incr_stats03(int);
    int decr_stats03(void);
    int incr_stats03(void);

    int set_stats04(int);
    int get_stats04(void) const;
    int decr_stats04(int);
    int incr_stats04(int);
    int decr_stats04(void);
    int incr_stats04(void);

    int set_stats05(int);
    int get_stats05(void) const;
    int decr_stats05(int);
    int incr_stats05(int);
    int decr_stats05(void);
    int incr_stats05(void);

    int set_stats06(int);
    int get_stats06(void) const;
    int decr_stats06(int);
    int incr_stats06(int);
    int decr_stats06(void);
    int incr_stats06(void);

    int set_stats07(int);
    int get_stats07(void) const;
    int decr_stats07(int);
    int incr_stats07(int);
    int decr_stats07(void);
    int incr_stats07(void);

    int set_stats08(int);
    int get_stats08(void) const;
    int decr_stats08(int);
    int incr_stats08(int);
    int decr_stats08(void);
    int incr_stats08(void);

    int set_stats09(int);
    int get_stats09(void) const;
    int decr_stats09(int);
    int incr_stats09(int);
    int decr_stats09(void);
    int incr_stats09(void);

    int set_stats10(int);
    int get_stats10(void) const;
    int decr_stats10(int);
    int incr_stats10(int);
    int decr_stats10(void);
    int incr_stats10(void);

    int set_stats11(int);
    int get_stats11(void) const;
    int decr_stats11(int);
    int incr_stats11(int);
    int decr_stats11(void);
    int incr_stats11(void);

    int set_stats12(int);
    int get_stats12(void) const;
    int decr_stats12(int);
    int incr_stats12(int);
    int decr_stats12(void);
    int incr_stats12(void);

    int set_stats13(int);
    int get_stats13(void) const;
    int decr_stats13(int);
    int incr_stats13(int);
    int decr_stats13(void);
    int incr_stats13(void);

    int set_stats14(int);
    int get_stats14(void) const;
    int decr_stats14(int);
    int incr_stats14(int);
    int decr_stats14(void);
    int incr_stats14(void);

    int set_stats15(int);
    int get_stats15(void) const;
    int decr_stats15(int);
    int incr_stats15(int);
    int decr_stats15(void);
    int incr_stats15(void);

    int set_stats16(int);
    int get_stats16(void) const;
    int decr_stats16(int);
    int incr_stats16(int);
    int decr_stats16(void);
    int incr_stats16(void);

    int set_stats17(int);
    int get_stats17(void) const;
    int decr_stats17(int);
    int incr_stats17(int);
    int decr_stats17(void);
    int incr_stats17(void);

    int set_stats18(int);
    int get_stats18(void) const;
    int decr_stats18(int);
    int incr_stats18(int);
    int decr_stats18(void);
    int incr_stats18(void);

    int set_stats19(int);
    int get_stats19(void) const;
    int decr_stats19(int);
    int incr_stats19(int);
    int decr_stats19(void);
    int incr_stats19(void);

    int set_stats_strength(int);
    int get_stats_strength(void) const;
    int decr_stats_strength(int);
    int incr_stats_strength(int);
    int decr_stats_strength(void);
    int incr_stats_strength(void);

    int set_owned_count(int);
    int get_owned_count(void) const;
    int decr_owned_count(int);
    int incr_owned_count(int);
    int decr_owned_count(void);
    int incr_owned_count(void);

    int set_lifespan(int);
    int get_lifespan_initial(void) const;
    int decr_lifespan(int);
    int incr_lifespan(int);
    int decr_lifespan(void);
    int incr_lifespan(void);

    timestamp_t set_timestamp_lunge_begin(timestamp_t);
    timestamp_t get_timestamp_lunge_begin(void) const;
    timestamp_t decr_timestamp_lunge_begin(timestamp_t);
    timestamp_t incr_timestamp_lunge_begin(timestamp_t);
    timestamp_t decr_timestamp_lunge_begin(void);
    timestamp_t incr_timestamp_lunge_begin(void);

    timestamp_t set_timestamp_lunge_end(timestamp_t);
    timestamp_t get_timestamp_lunge_end(void) const;
    timestamp_t decr_timestamp_lunge_end(timestamp_t);
    timestamp_t incr_timestamp_lunge_end(timestamp_t);
    timestamp_t decr_timestamp_lunge_end(void);
    timestamp_t incr_timestamp_lunge_end(void);

    timestamp_t set_timestamp_bounce_begin(timestamp_t);
    timestamp_t get_timestamp_bounce_begin(void) const;
    timestamp_t decr_timestamp_bounce_begin(timestamp_t);
    timestamp_t incr_timestamp_bounce_begin(timestamp_t);
    timestamp_t decr_timestamp_bounce_begin(void);
    timestamp_t incr_timestamp_bounce_begin(void);

    timestamp_t set_timestamp_bounce_end(timestamp_t);
    timestamp_t get_timestamp_bounce_end(void) const;
    timestamp_t decr_timestamp_bounce_end(timestamp_t);
    timestamp_t incr_timestamp_bounce_end(timestamp_t);
    timestamp_t decr_timestamp_bounce_end(void);
    timestamp_t incr_timestamp_bounce_end(void);

    timestamp_t set_timestamp_fadeup_begin(timestamp_t);
    timestamp_t get_timestamp_fadeup_begin(void) const;
    timestamp_t decr_timestamp_fadeup_begin(timestamp_t);
    timestamp_t incr_timestamp_fadeup_begin(timestamp_t);
    timestamp_t decr_timestamp_fadeup_begin(void);
    timestamp_t incr_timestamp_fadeup_begin(void);

    timestamp_t set_timestamp_fadeup_end(timestamp_t);
    timestamp_t get_timestamp_fadeup_end(void) const;
    timestamp_t decr_timestamp_fadeup_end(timestamp_t);
    timestamp_t incr_timestamp_fadeup_end(timestamp_t);
    timestamp_t decr_timestamp_fadeup_end(void);
    timestamp_t incr_timestamp_fadeup_end(void);

    timestamp_t set_timestamp_last_ticked(timestamp_t);
    timestamp_t get_timestamp_last_ticked(void) const;
    timestamp_t decr_timestamp_last_ticked(timestamp_t);
    timestamp_t incr_timestamp_last_ticked(timestamp_t);
    timestamp_t decr_timestamp_last_ticked(void);
    timestamp_t incr_timestamp_last_ticked(void);

    timestamp_t set_timestamp_last_tick(timestamp_t);
    timestamp_t get_timestamp_last_tick(void) const;
    timestamp_t decr_timestamp_last_tick(timestamp_t);
    timestamp_t incr_timestamp_last_tick(timestamp_t);
    timestamp_t decr_timestamp_last_tick(void);
    timestamp_t incr_timestamp_last_tick(void);

    timestamp_t set_timestamp_flip_start(timestamp_t);
    timestamp_t get_timestamp_flip_start(void) const;
    timestamp_t decr_timestamp_flip_start(timestamp_t);
    timestamp_t incr_timestamp_flip_start(timestamp_t);
    timestamp_t decr_timestamp_flip_start(void);
    timestamp_t incr_timestamp_flip_start(void);

    timestamp_t set_timestamp_move_begin(timestamp_t);
    timestamp_t get_timestamp_move_begin(void) const;
    timestamp_t decr_timestamp_move_begin(timestamp_t);
    timestamp_t incr_timestamp_move_begin(timestamp_t);
    timestamp_t decr_timestamp_move_begin(void);
    timestamp_t incr_timestamp_move_begin(void);

    timestamp_t set_timestamp_move_end(timestamp_t);
    timestamp_t get_timestamp_move_end(void) const;
    timestamp_t decr_timestamp_move_end(timestamp_t);
    timestamp_t incr_timestamp_move_end(timestamp_t);
    timestamp_t decr_timestamp_move_end(void);
    timestamp_t incr_timestamp_move_end(void);

    timestamp_t set_timestamp_last_wander_try(timestamp_t);
    timestamp_t get_timestamp_last_wander_try(void) const;
    timestamp_t decr_timestamp_last_wander_try(timestamp_t);
    timestamp_t incr_timestamp_last_wander_try(timestamp_t);
    timestamp_t decr_timestamp_last_wander_try(void);
    timestamp_t incr_timestamp_last_wander_try(void);

    timestamp_t set_timestamp_born(timestamp_t);
    timestamp_t get_timestamp_born(void) const;
    timestamp_t decr_timestamp_born(timestamp_t);
    timestamp_t incr_timestamp_born(timestamp_t);
    timestamp_t decr_timestamp_born(void);
    timestamp_t incr_timestamp_born(void);

    timestamp_t set_timestamp_hunger_tick(timestamp_t);
    timestamp_t get_timestamp_hunger_tick(void) const;
    timestamp_t decr_timestamp_hunger_tick(timestamp_t);
    timestamp_t incr_timestamp_hunger_tick(timestamp_t);
    timestamp_t decr_timestamp_hunger_tick(void);
    timestamp_t incr_timestamp_hunger_tick(void);

    timestamp_t set_timestamp_fall_begin(timestamp_t);
    timestamp_t get_timestamp_fall_begin(void) const;
    timestamp_t decr_timestamp_fall_begin(timestamp_t);
    timestamp_t incr_timestamp_fall_begin(timestamp_t);
    timestamp_t decr_timestamp_fall_begin(void);
    timestamp_t incr_timestamp_fall_begin(void);

    timestamp_t set_timestamp_fall_end(timestamp_t);
    timestamp_t get_timestamp_fall_end(void) const;
    timestamp_t decr_timestamp_fall_end(timestamp_t);
    timestamp_t incr_timestamp_fall_end(timestamp_t);
    timestamp_t decr_timestamp_fall_end(void);
    timestamp_t incr_timestamp_fall_end(void);

    uint32_t set_tick_last_did_something(uint32_t);
    uint32_t get_tick_last_did_something(void) const;
    uint32_t decr_tick_last_did_something(uint32_t);
    uint32_t incr_tick_last_did_something(uint32_t);
    uint32_t decr_tick_last_did_something(void);
    uint32_t incr_tick_last_did_something(void);

    uint32_t set_tick_last_escape(uint32_t);
    uint32_t get_tick_last_escape(void) const;
    uint32_t decr_tick_last_escape(uint32_t);
    uint32_t incr_tick_last_escape(uint32_t);
    uint32_t decr_tick_last_escape(void);
    uint32_t incr_tick_last_escape(void);

    uint32_t set_tick_last_level_change(uint32_t);
    uint32_t get_tick_last_level_change(void) const;
    uint32_t decr_tick_last_level_change(uint32_t);
    uint32_t incr_tick_last_level_change(uint32_t);
    uint32_t decr_tick_last_level_change(void);
    uint32_t incr_tick_last_level_change(void);

    ThingId set_on_fire_anim_id(ThingId);
    ThingId get_on_fire_anim_id(void) const;

    void unset_on_fire(void);
    bool set_on_fire(void);

    ThingId set_owner_id(ThingId);
    ThingId get_owner_id(void) const;

    ThingId set_weapon_id_carry_anim(ThingId);
    ThingId get_weapon_id_carry_anim(void) const;

    ThingId set_weapon_id_use_anim(ThingId);
    ThingId get_weapon_id_use_anim(void) const;

    ThingId set_weapon_id(ThingId);
    ThingId get_weapon_id(void) const;

    void actionbar_particle(Thingp what, uint32_t slot);
    void actionbar_particle(Thingp what, uint32_t slot, Thingp target);
    bool actionbar_id_remove(Thingp what);
    bool actionbar_id_remove(Thingp what, Thingp target);
    bool actionbar_id_insert(Thingp what);
    int actionbar_id_slot_count(const uint32_t slot);

    //
    // Dice
    //
    const std::string& get_nutrition_dice_str(void) const;
    int get_nutrition(void) const;
    const Dice& get_nutrition_dice(void) const;

    const std::string& get_on_idle_dice_do_str(void) const;
    int get_idle_tick(void) const;
    const Dice& get_on_idle_dice_do(void) const;

    const std::string& get_lifespan_dice_str(void) const;
    int get_lifespan(void) const;
    const Dice& get_lifespan_dice(void) const;

    const std::string& get_stats_attack_dice_str(void) const;
    int get_stats_attack(void) const;
    const Dice& get_stats_attack_dice(void) const;

    const std::string& get_gold_value_dice_str(void) const;
    int get_gold_value(void) const;
    const Dice& get_gold_value_dice(void) const;

    const std::string& get_resurrect_dice_str(void) const;
    int get_resurrect(void) const;
    const Dice& get_resurrect_dice(void) const;

    bool try_to_jump(void);
    bool try_to_jump(point p);
    bool try_to_escape(void);
    void jump_end(void);

    ThingShoved try_to_shove(Thingp it, fpoint delta);
    ThingShoved try_to_shove(fpoint future_pos);
    ThingShoved try_to_shove_into_hazard(Thingp it, fpoint delta);
    Thingp nearby_most_dangerous_thing_get(void);
    Thingp owner_get() const;
    Thingp weapon_get() const;
    Thingp weapon_get_carry_anim(void);
    Thingp weapon_get_use_anim(void) const;
    bool achieve_goals_in_death();
    bool achieve_goals_in_life();
    bool ai_blocked(void);
    bool ai_choose_wander(point& nh);
    bool ai_create_on_fire_path(point &nh, const point start, const point end);
    bool ai_create_path(point &nh, const point start, const point end);
    bool ai_escape(void);
    bool ai_on_fire(void);
    bool ai_on_fire_choose_target (point& nh);
    bool ai_wander(void);
    bool ascend(void);
    bool attack(fpoint future_pos);
    bool attack(Thingp it);
    bool chasm_tick();
    bool collision_add_candidates(Thingp it, fpoint future_pos, int x, int y, int dx, int dy);
    bool collision_check_and_handle(Thingp it, fpoint future_pos, int x, int y, int dx, int dy);
    bool collision_check_and_handle(fpoint, bool *, bool *, float radius);
    bool collision_check_and_handle_at(bool *, bool *);
    bool collision_check_and_handle_at(fpoint, bool *, bool *);
    bool collision_check_and_handle_nearby(fpoint, bool *, bool *);
    bool collision_check_only(Thingp it, fpoint future_pos, int x, int y);
    bool collision_check_only(Thingp it, int x, int y, int dx, int dy);
    bool collision_check_only(fpoint);
    bool collision_check_only(void);
    bool collision_find_best_target(bool *, bool *);
    bool collision_obstacle(Thingp);
    bool collision_obstacle(fpoint);
    bool cursor_path_pop_next_and_move(void);
    bool descend(void);
    bool eat(Thingp it);
    bool entrance_tick();
    bool exit_tick();
    bool fall(void);
    bool fall_to_next_level(void);
    bool get_coords(point &blit_tl, point &blit_br, point &pre_effect_blit_tl, point &pre_effect_blit_br, Tilep &tile, bool reflection);
    bool get_map_offset_coords(point &blit_tl, point &blit_br, Tilep &tile, bool reflection);
    bool get_pre_effect_map_offset_coords(point &blit_tl, point &blit_br, Tilep &tile, bool reflection);
    bool is_blocking_terrain(const Thingp it);
    bool is_enemy(Thingp attacker) const;
    bool is_obstacle_for_me(const point&);
    bool is_on_fire(void);
    bool location_check();
    bool move(fpoint future_pos);
    bool move(fpoint future_pos, uint8_t up, uint8_t down, uint8_t left, uint8_t right, uint8_t fire, uint8_t idle, bool shove_allowed);
    bool move_no_shove(fpoint future_pos);
    bool move_to_check(const point&, const bool escaping);
    bool move_to_or_attack(const point&);
    bool move_to_or_escape(const point&);
    bool open_door(Thingp door);
    bool possible_to_attack(const Thingp it);
    bool spawn_fire(const std::string& what);
    bool spawn_next_to(const std::string& what);
    bool spawn_next_to_or_on_monst(const std::string& what);
    bool spawn_under(const std::string& what);
    bool use(Thingp w);
    bool will_avoid(const Thingp it) const;
    bool will_avoid(const point p) const;
    bool will_eat(const Thingp it);
    bool will_prefer_terrain(const Thingp it);
    const char *to_cstring(void) const;
    const std::string& light_color(void) const;
    const std::string& on_death_do(void) const;
    const std::string& spawn_on_shoved(void) const;
    const std::string& str1(void) const;
    const std::string& str10(void) const;
    const std::string& str12(void) const;
    const std::string& str2(void) const;
    const std::string& str3(void) const;
    const std::string& str4(void) const;
    const std::string& str5(void) const;
    const std::string& str6(void) const;
    const std::string& str7(void) const;
    const std::string& str8(void) const;
    const std::string& str9(void) const;
    const std::string& text_hits(void) const;
    const std::string& text_name(void) const;
    const std::string& weapon_carry_anim(void) const;
    const std::string& weapon_use_anim(void) const;
    float get_bounce(void);
    float get_fadeup(void);
    float get_fall(void);
    float get_lunge(void);
    fpoint get_interpolated_mid_at(void) const;
    fpoint set_interpolated_mid_at(fpoint);
    int ai_choose_goal(void);
    int ai_delay_after_moving_ms(void);
    int ai_hit_actual(Thingp hitter, Thingp real_hitter, int damage);
    int is_hit_by(Thingp hitter);
    int is_hit_by(Thingp hitter, int damage);
    int ai_obstacle(void) const;
    int ai_scent_distance(void) const;
    int attack(void) const;
    int collectable(void) const;
    int collision_attack(void) const;
    int collision_box(void) const;
    int collision_check(void) const;
    int collision_circle(void) const;
    int collision_hit_priority(void) const;
    int defence(void) const;
    int gfx_an_animation_only(void) const;
    int gfx_animated(void) const;
    int gfx_animated_can_hflip(void) const;
    int gfx_animated_can_vflip(void) const;
    int gfx_animated_no_dir(void) const;
    int gfx_attack_anim(void) const;
    int gfx_bounce_always(void) const;
    int gfx_bounce_on_move(void) const;
    int gfx_dead_anim(void) const;
    int gfx_on_fire_anim(void) const;
    int gfx_oversized_but_sitting_on_the_ground(void) const;
    int gfx_show_outlined(void) const;
    int gfx_small_shadow_caster(void) const;
    int gfx_weapon_carry_anim(void) const;
    int has_capacity(void) const;
    int health_hunger_pct(void) const;
    int health_initial(void) const;
    int health_starving_pct(void) const;
    int hunger_clock_freq_ms(void) const;
    int is_able_to_change_levels(void) const;
    int is_acid(void) const;
    int is_acid_dweller(void) const;
    int is_acid_hater(void) const;
    int is_active(void) const;
    int is_alive_monst(void) const;
    int is_attack_eater(void) const;
    int is_attack_lunge(void) const;
    int is_attack_shove(void) const;
    int is_attack_shove_chance_d1000(void) const;
    int is_attackable(void) const;
    int is_bag(void) const;
    int is_bleeder(void) const;
    int is_blood(void) const;
    int is_blood_splatter(void) const;
    int is_chasm(void) const;
    int is_collect_as_keys(void) const;
    int is_collected_as_gold(void) const;
    int is_combustible(void) const;
    int is_corpse(void) const;
    int is_corpse_on_death(void) const;
    int is_corridor(void) const;
    int is_cursor(void) const;
    int is_cursor_can_hover_over(void) const;
    int is_cursor_path(void) const;
    int is_dead_on_shove(void) const;
    int is_deep_water(void) const;
    int is_dirt(void) const;
    int is_door(void) const;
    int is_double_damage_from_acid(void) const;
    int is_double_damage_from_fire(void) const;
    int is_double_damage_from_water(void) const;
    int is_droppable(void) const;
    int is_entrance(void) const;
    int is_ethereal(void) const;
    int is_exit(void) const;
    int is_explosion(void) const;
    int is_fire(void) const;
    int is_fire_hater(void) const;
    int is_flammable(void) const;
    int is_floating(void) const;
    int is_floor(void) const;
    int is_floor_deco(void) const;
    int is_food(void) const;
    int is_generator(void) const;
    int is_gold(void) const;
    int is_hazard(void) const;
    int is_hunger_insatiable(void) const;
    int is_intelligent(void) const;
    int is_interesting(void) const;
    int is_jumper(void) const;
    int is_jumper_chance_d1000(void) const;
    int is_jumper_distance(void) const;
    int is_jumper_on_low_hp_chance_d1000(void) const;
    int is_key(void) const;
    int is_lava(void) const;
    int is_light_blocker(void) const;
    int is_light_strength(void) const;
    int is_loggable_for_important_stuff(void) const;
    int is_loggable_for_unimportant_stuff(void) const;
    int is_meat(void) const;
    int is_meat_eater(void) const;
    int is_monst(void) const;
    int is_movable(void) const;
    int is_movement_blocking(void) const;
    int is_msg(void) const;
    int is_mundane_item(void) const;
    int is_no_tile(void) const;
    int is_not_stackable(void) const;
    int is_player(void) const;
    int is_potion(void) const;
    int is_potion_eater(void) const;
    int is_projectile(void) const;
    int is_resurrectable(void) const;
    int is_ripple(void) const;
    int is_rock(void) const;
    int is_rrr1(void) const;
    int is_rrr10(void) const;
    int is_rrr11(void) const;
    int is_rrr12(void) const;
    int is_rrr13(void) const;
    int is_rrr14(void) const;
    int is_rrr15(void) const;
    int is_rrr16(void) const;
    int is_rrr17(void) const;
    int is_rrr18(void) const;
    int is_rrr19(void) const;
    int is_rrr2(void) const;
    int is_rrr20(void) const;
    int is_rrr21(void) const;
    int is_rrr22(void) const;
    int is_rrr23(void) const;
    int is_rrr24(void) const;
    int is_rrr25(void) const;
    int is_rrr26(void) const;
    int is_rrr27(void) const;
    int is_rrr28(void) const;
    int is_rrr29(void) const;
    int is_rrr3(void) const;
    int is_rrr30(void) const;
    int is_rrr31(void) const;
    int is_rrr32(void) const;
    int is_rrr33(void) const;
    int is_rrr34(void) const;
    int is_rrr35(void) const;
    int is_rrr36(void) const;
    int is_rrr37(void) const;
    int is_rrr38(void) const;
    int is_rrr39(void) const;
    int is_rrr4(void) const;
    int is_rrr40(void) const;
    int is_rrr41(void) const;
    int is_rrr42(void) const;
    int is_rrr43(void) const;
    int is_rrr44(void) const;
    int is_rrr45(void) const;
    int is_rrr46(void) const;
    int is_rrr47(void) const;
    int is_rrr48(void) const;
    int is_rrr49(void) const;
    int is_rrr5(void) const;
    int is_rrr50(void) const;
    int is_rrr51(void) const;
    int is_rrr52(void) const;
    int is_rrr53(void) const;
    int is_rrr54(void) const;
    int is_rrr55(void) const;
    int is_rrr56(void) const;
    int is_rrr57(void) const;
    int is_rrr58(void) const;
    int is_rrr59(void) const;
    int is_rrr6(void) const;
    int is_rrr60(void) const;
    int is_rrr61(void) const;
    int is_rrr62(void) const;
    int is_rrr63(void) const;
    int is_rrr64(void) const;
    int is_rrr65(void) const;
    int is_rrr66(void) const;
    int is_rrr67(void) const;
    int is_rrr68(void) const;
    int is_rrr69(void) const;
    int is_rrr7(void) const;
    int is_rrr70(void) const;
    int is_rrr71(void) const;
    int is_rrr72(void) const;
    int is_rrr73(void) const;
    int is_rrr74(void) const;
    int is_rrr75(void) const;
    int is_rrr76(void) const;
    int is_rrr77(void) const;
    int is_open_on_death(void) const;
    int is_killed_on_hit_or_miss(void) const;
    int is_rrr8(void) const;
    int is_killed_on_hitting(void) const;
    int is_rrr9(void) const;
    int is_secret_door(void) const;
    int is_shovable(void) const;
    int is_sidebar_item(void) const;
    int is_slime(void) const;
    int is_slime_baby(void) const;
    int is_slime_baby_eater(void) const;
    int is_slime_eater(void) const;
    int is_slime_parent(void) const;
    int is_smoke(void) const;
    int is_temporary(void) const;
    int is_throwable(void) const;
    int is_torch(void) const;
    int is_treasure(void) const;
    int is_treasure_eater(void) const;
    int is_undead(void) const;
    int is_usable(void) const;
    int is_wall(void) const;
    int is_wall_deco(void) const;
    int is_water(void) const;
    int is_water_dweller(void) const;
    int is_water_hater(void) const;
    int is_weapon(void) const;
    int normal_placement_rules(void) const;
    int tick_catches_up_on_attack(void) const;
    int weapon_damage(void) const;
    int weapon_use_delay_hundredths(void) const;
    int weapon_use_distance(void) const;
    point dir_to_direction() const;
    point get_random_scent_target(void);
    std::string text_The(void) const;
    std::string text_a_or_an(void) const;
    std::string text_the(void) const;
    std::string to_string(void) const;
    uint8_t blit_begin_reflection_submerged(void) const;
    uint8_t blit_begin_submerged(void) const;
    uint8_t is_dir_bl(void) const;
    uint8_t is_dir_br(void) const;
    uint8_t is_dir_down(void) const;
    uint8_t is_dir_left(void) const;
    uint8_t is_dir_none(void) const;
    uint8_t is_dir_right(void) const;
    uint8_t is_dir_tl(void) const;
    uint8_t is_dir_tr(void) const;
    uint8_t is_dir_up(void) const;
    uint8_t is_less_preferred_terrain(point p) const;
    uint8_t is_visible() const;
    void acid_tick();
    void add_enemy(Thingp attacker);
    void ai_get_next_hop(void);
    void animate();
    void blit();
    void blit_end_reflection_submerged(uint8_t submerged) const;
    void blit_end_submerged(uint8_t submerged) const;
    void blit_internal(point &blit_tl, point &blit_br, const Tilep tile, color c, const bool reflection);
    void blit_non_player_owned_shadow(const Tpp &tp, const Tilep &tile, const point &tl, const point &br);
    void blit_player_owned_shadow(const Tpp &tp, const Tilep &tile, const point &tl, const point &br);
    void blit_shadow(const Tpp &tp, const Tilep &tile, const point &tl, const point &br);
    void blit_text(std::string const&, color c, point tl, point br);
    void blit_upside_down();
    void blit_wall_cladding(point &tl, point &br, const ThingTiles *tiles);
    void blit_wall_shadow(point &tl, point &br, const ThingTiles *tiles);
    void botcon(const char *fmt, ...) const __attribute__ ((format (printf, 2, 3)));
    void botcon_(const char *fmt, va_list args) const; // compile error without
    void bounce(float bounce_height, float bounce_fade, timestamp_t ms, int bounce_count);
    void carry(Thingp w);
    void collision_check_do();
    void con(const char *fmt, ...) const __attribute__ ((format (printf, 2, 3)));
    void con_(const char *fmt, va_list args) const; // compile error without
    void cursor_hover_over_check(void);
    void cursor_path_pop_first_move(void);
    void cursor_path_stop(void);
    void dbg(const char *fmt, ...) const __attribute__ ((format (printf, 2, 3)));
    void dead(Thingp killer, const char *fmt, ...) __attribute__ ((format (printf, 3, 4)));
    void dead(Thingp killer, std::string &);
    void dead(const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));
    void dead(std::string &);
    void dead_(Thingp killer, const char *fmt, va_list args); // compile error without
    void dead_(const char *fmt, va_list args); // compile error without
    void destroy();
    void destroyed(void);
    void die(const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));
    void die_(const char *fmt, va_list args); // compile error without
    void dir_set_bl(void);
    void dir_set_br(void);
    void dir_set_down(void);
    void dir_set_left(void);
    void dir_set_none(void);
    void dir_set_right(void);
    void dir_set_tl(void);
    void dir_set_tr(void);
    void dir_set_up(void);
    void drop(Thingp w);
    void drop_all(void);
    void dump(std::string prefix, std::ostream &out);
    void err(const char *fmt, ...) const __attribute__ ((format (printf, 2, 3)));
    void err_(const char *fmt, va_list args) const; // compile error without
    void fadeup(float fadeup_height, float fadeup_fade, timestamp_t ms);
    void fall(float fall_height, timestamp_t ms);
    void health_boost(int v);
    void hide();
    void hooks_remove();
    void hunger_clock();
    void inherit_from(Thingp it);
    void init(Levelp, const std::string& name, fpoint at, fpoint jitter);
    void init_lights(void);
    void kill(Thingp killer, const char *reason);
    void kill(Thingp killer, std::string &reason);
    void lava_tick();
    void level_change(Levelp);
    void level_enter(void);
    void level_leave(void);
    void level_pop(void);
    void level_push(void);
    void lifespan_tick();
    void log(const char *fmt, ...) const __attribute__ ((format (printf, 2, 3)));
    void log_(const char *fmt, va_list args) const; // compile error without
    void lunge(fpoint tt);
    void minicon(const char *fmt, ...) const __attribute__ ((format (printf, 2, 3)));
    void minicon_(const char *fmt, va_list args) const; // compile error without
    void move_carried_items(void);
    void move_delta(fpoint);
    void move_finish(void);
    void move_set_dir_from_delta(fpoint);
    void move_to(fpoint to);
    void move_to_immediately(fpoint to);
    void move_to_immediately_delta(fpoint delta);
    void msg(const std::string&);
    void reinit(void);
    void remove_owner(void);
    void resurrect_tick();
    void set_owner(Thingp owner);
    void sheath(void);
    void tick();
    void torch_tick();
    void unwield(const char *why);
    void update_interpolated_position(void);
    void update_light(void);
    void update_pos(fpoint, bool immediately);
    void use(void);
    void used(Thingp w, Thingp target);
    void visible();
    void water_tick();
    void weapon_get_use_offset(float *dx, float *dy) const;
    void weapon_set_carry_anim(Thingp weapon_carry_anim);
    void weapon_set_carry_anim_id(ThingId weapon_carry_anim_id);
    void weapon_set_placement(void);
    void weapon_set_use_anim(Thingp weapon_use_anim);
    void weapon_set_use_anim_id(ThingId weapon_use_anim_id);
    void weapon_sheath(void);
    void wield(Thingp w);
} Thing;

//std::ostream& operator<<(std::ostream &out, Bits<const Thing & > const my);
//std::istream& operator>>(std::istream &in, Bits<Thing &> my);

bool things_overlap(Thingp t, Thingp o);
bool things_overlap(Thingp t, fpoint t_at, Thingp o);
bool things_overlap_attack(Thingp t, fpoint t_at, Thingp o);

#endif // _MY_THING_H_
