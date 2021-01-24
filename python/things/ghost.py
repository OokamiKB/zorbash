import zx
import tp

def on_death(me, x, y):
    zx.tp_spawn_under(me, "ghost_explosion")

def tp_init(name, text_name):
    x = tp.Tp(name, text_name)
    x.set_ai_delay_after_moving_ms(10)
    x.set_ai_scent_distance(10)
    x.set_attack_humanoid(True)
    x.set_attack_lunge(True)
    x.set_attackable_by_monst(True)
    x.set_attackable_by_player(True)
    x.set_collision_attack(True)
    x.set_collision_check(True)
    x.set_collision_circle(True)
    x.set_collision_hit_priority(10)
    x.set_collision_radius(0.40)
    x.set_damage_melee_dice("1")
    x.set_gfx_anim_attack("attack_claws")
    x.set_gfx_animated(True)
    x.set_gfx_animated_can_hflip(True)
    x.set_gfx_health_bar_shown(True)
    x.set_gfx_moves_ahead_shown(True)
    x.set_gfx_small_shadow_caster(True)
    x.set_health_hunger_pct(95)
    x.set_health_initial_dice("1")
    x.set_is_able_to_change_levels(True)
    x.set_is_able_to_fall(False)
    x.set_is_able_to_walk_through_walls(True)
    x.set_is_active(True)
    x.set_attackable(True)
    x.set_is_ethereal(True)
    x.set_is_fearless(True)
    x.set_is_floating(True)
    x.set_is_hunger_insatiable(True)
    x.set_is_intelligent(True)
    x.set_is_interesting(True)
    x.set_is_loggable_for_important_stuff(True)
    x.set_is_loggable_for_unimportant_stuff(True)
    x.set_is_monst(True)
    x.set_is_moveable(True)
    x.set_is_shown_on_leftbar(True)
    x.set_is_undead(True)
    x.set_is_described_when_hovering_over(True)
    x.set_long_text_description("A spirit of one less fortunate than you. Beware, ghosts can traverse chasms that you cannot.")
    x.set_modifier_attack(7)
    x.set_modifier_constitution(20)
    x.set_modifier_defence(12)
    x.set_modifier_strength(7)
    x.set_monst_size(zx.MONST_SIZE_NORMAL)
    x.set_move_speed_ms(1000)
    x.set_normal_placement_rules(True)
    x.set_on_death_do("ghost.on_death()")
    x.set_rarity(zx.RARITY_COMMON)
    x.set_text_a_or_an("a");
    x.set_is_described_when_hovering_over(True)
    x.set_text_description("The angry spirit of one long passed")
    x.set_text_hits("chills");
    x.set_tick_rate_tenths(3)
    x.set_z_depth(zx.MAP_DEPTH_OBJ)
    x.set_z_prio(zx.MAP_PRIO_BEHIND)

    delay = 200
    x.set_tile("ghost.1", delay_ms=delay)
    x.set_tile("ghost.2", delay_ms=delay)
    x.set_tile("ghost.3", delay_ms=delay)
    x.set_tile("ghost.4", delay_ms=delay)
    x.set_tile("ghost.5", delay_ms=delay)
    x.set_tile("ghost.6", delay_ms=delay)
    x.set_tile("ghost.7", delay_ms=delay, is_invisible=True)
    x.set_tile("ghost.8", delay_ms=delay, is_invisible=True)
    x.set_tile("ghost.9", delay_ms=delay, is_invisible=True)
    x.set_tile("ghost.10", delay_ms=delay, is_invisible=True)
    x.set_tile("ghost.11", delay_ms=delay, is_invisible=True)

    x.update()

def init():
    tp_init(name="ghost", text_name="ghost")

init()
