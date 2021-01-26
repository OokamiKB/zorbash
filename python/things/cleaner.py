import builtins
import zx
import tp

def on_idle(me, x, y):
    zx.tp_spawn_under(me, "acid1")

def tp_init(name, text_name, short_text_name):
    x = tp.Tp(name, text_name, short_text_name)
    x.set_ai_delay_after_moving_ms(1000)
    x.set_ai_scent_distance(5)
    x.set_attack_eater(True)
    x.set_attack_lunge(True)
    x.set_attackable(True)
    x.set_avoids_fire(100)
    x.set_collision_attack(True)
    x.set_collision_attack_radius(0.60)
    x.set_collision_check(True)
    x.set_collision_circle(True)
    x.set_collision_hit_priority(10)
    x.set_collision_radius(0.40)
    x.set_damage_doubled_from_fire(True)
    x.set_damage_melee_dice("1d5")
    x.set_gfx_anim_attack("green_splatter")
    x.set_gfx_animated(True)
    x.set_gfx_animated_can_hflip(True)
    x.set_gfx_bounce_on_move(True)
    x.set_gfx_health_bar_shown(True)
    x.set_gfx_moves_ahead_shown(True)
    x.set_gfx_oversized_but_sitting_on_the_ground(True)
    x.set_gfx_show_outlined(True)
    x.set_gfx_small_shadow_caster(True)
    x.set_health_hunger_pct(95)
    x.set_health_initial_dice("6d6")
    x.set_is_able_to_fall(True)
    x.set_is_acid(True)
    x.set_is_acid_lover(True)
    x.set_is_active(True)
    x.set_is_combustible(True)
    x.set_is_critical_to_level(True)
    x.set_is_described_when_hovering_over(True)
    x.set_is_hunger_insatiable(True)
    x.set_is_interesting(True)
    x.set_is_item_eater(True)
    x.set_is_jelly_baby_eater(True)
    x.set_is_jelly_eater(True)
    x.set_is_light_strength(2)
    x.set_is_loggable_for_important_stuff(True)
    x.set_is_loggable_for_unimportant_stuff(True)
    x.set_is_meat_eater(True)
    x.set_is_monst(True)
    x.set_is_moveable(True)
    x.set_is_potion_eater(True)
    x.set_is_shown_on_leftbar(True)
    x.set_is_steal_item_chance_d1000(200)
    x.set_is_treasure_eater(True)
    x.set_light_color("green")
    x.set_long_text_description("Dungeon cleaners have evolved to scrub their domain of all messy organic matter. That means you. Cleaners leave a trail of corrosive slime in their wake. Avoid this. Cleaners also have a habit of eating your hard fought items.")
    x.set_modifier_attack(14)
    x.set_modifier_constitution(20)
    x.set_modifier_defence(14)
    x.set_modifier_strength(14)
    x.set_monst_size(zx.MONST_SIZE_LARGE)
    x.set_move_speed_ms(1000)
    x.set_normal_placement_rules(True)
    x.set_nutrition_dice("1d4")
    x.set_on_death_drop_all_items(True)
    x.set_on_death_is_corpse(True)
    x.set_on_idle_dice("1d0:cleaner.on_idle()")
    x.set_rarity(zx.RARITY_COMMON)
    x.set_stamina(100)
    x.set_text_a_or_an("a");
    x.set_text_description("A dungeon auto cleaner jelly thingy")
    x.set_text_hits("burns");
    x.set_tick_rate_tenths(3)
    x.set_z_depth(zx.MAP_DEPTH_OBJ)
    x.set_z_prio(zx.MAP_PRIO_NORMAL)

    delay = 200
    x.set_tile(tile=name + ".1.100", is_hp_100_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".2.100", is_hp_100_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".1.75", is_hp_75_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".2.75", is_hp_75_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".1.50", is_hp_50_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".2.50", is_hp_50_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".1.25", is_hp_25_percent=True, delay_ms=delay)
    x.set_tile(tile=name + ".1.25", is_hp_25_percent=True, delay_ms=delay)

    delay=10
    x.set_tile("green_splatter.1", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.2", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.3", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.4", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.5", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.6", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.7", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.8", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.9", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.10", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.11", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.12", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.13", is_dead=True, delay_ms=delay)
    x.set_tile("green_splatter.14", is_dead=True, delay_ms=delay, is_end_of_anim = True)

    x.update()

def init():
    tp_init(name="cleaner", text_name="dungeon cleaner", short_text_name="cleaner")

init()
