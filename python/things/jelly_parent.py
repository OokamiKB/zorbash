import builtins
import zx
import tp

def on_hit(me, hitter, real_hitter, x, y, crit, bite, damage):
    if not zx.thing_sound_play_channel(me, zx.CHANNEL_MONST, "squelch"):
        zx.thing_sound_play_channel(me, zx.CHANNEL_MONST_DEATH, "squelch")

def on_death(me, x, y):
    zx.level_spawn_at_thing(me, "pink_splatter")
    zx.level_spawn_next_to(me, "jelly_baby")
    zx.level_spawn_next_to(me, "jelly_baby")
    zx.level_spawn_next_to(me, "jelly_baby")
    zx.thing_sound_play_channel(me, zx.CHANNEL_MONST, "slime{}".format(zx.non_pcg_randint(1, 9)))

def tp_init(name, text_name):
    mytp = tp.Tp(name, text_name)
    mytp.set_ai_enemy_memory(10)
    mytp.set_ai_scent_distance(5)
    mytp.set_attack_eater(True)
    mytp.set_attack_lunge(True)
    mytp.set_collision_attack_radius(0.60)
    mytp.set_collision_attack(True)
    mytp.set_collision_check(True)
    mytp.set_collision_circle(True)
    mytp.set_collision_hit_priority(10)
    mytp.set_collision_radius(0.40)
    mytp.set_damage_doubled_from_fire(True)
    mytp.set_damage_melee_dice("1d5")
    mytp.set_gfx_animated_can_hflip(True)
    mytp.set_gfx_animated(True)
    mytp.set_gfx_anim_attack("pink_splatter")
    mytp.set_gfx_bounce_on_move(True)
    mytp.set_gfx_health_bar_shown(True)
    mytp.set_gfx_oversized_but_sitting_on_the_ground(True)
    mytp.set_gfx_short_shadow_caster(True)
    mytp.set_gfx_show_outlined(True)
    mytp.set_hates_fire(100)
    mytp.set_health_hunger_pct(95)
    mytp.set_health_initial_dice("10")
    mytp.set_is_able_to_fall(True)
    mytp.set_is_acid(True)
    mytp.set_is_active(True)
    mytp.set_is_attackable_by_monst(True)
    mytp.set_is_attackable_by_player(True)
    mytp.set_is_described_when_hovering_over(True)
    mytp.set_is_hittable(True)
    mytp.set_is_hunger_insatiable(True)
    mytp.set_is_jelly_baby_eater(True)
    mytp.set_is_jelly_eater(True)
    mytp.set_is_jelly_parent(True)
    mytp.set_is_jelly(True)
    mytp.set_is_jumper_chance_d1000(2)
    mytp.set_is_jumper_distance(5)
    mytp.set_is_jumper_on_low_hp_chance_d1000(500)
    mytp.set_is_jumper(True)
    mytp.set_is_living(True)
    mytp.set_is_loggable_for_important_stuff(True)
    mytp.set_is_loggable_for_unimportant_stuff(True)
    mytp.set_is_meat_eater(True)
    mytp.set_is_monst(True)
    mytp.set_is_moveable(True)
    mytp.set_is_soft_body(True)
    mytp.set_long_text_description("Jelly jumpers are numerous, bouncy and carnivorous. They will eat almost anything, including their own. They have the annoying habit of jumping when threatened and dividing when killed. This is an adult. It will eat its own children!")
    mytp.set_monst_size(zx.MONST_SIZE_LARGE)
    mytp.set_normal_placement_rules(True)
    mytp.set_nutrition_dice("1d4")
    mytp.set_on_death_do("jelly_parent.on_death()")
    mytp.set_on_hit_do("jelly_parent.on_hit()")
    mytp.set_rarity(zx.RARITY_COMMON)
    mytp.set_stamina(100)
    mytp.set_stat_attack(10) # 10, means no bonus
    mytp.set_stat_constitution(14)
    mytp.set_stat_defence(8)
    mytp.set_stat_strength(15)
    mytp.set_text_a_or_an("a")
    mytp.set_text_description("%%fg=limegreen$A gargantuan pile of sentient jelly.")
    mytp.set_text_hits("splats")
    mytp.set_z_depth(zx.MAP_DEPTH_OBJ)
    mytp.set_z_prio(zx.MAP_PRIO_NORMAL)

    delay = 200
    mytp.set_tile(tile=name + ".1.100", is_hp_100_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".2.100", is_hp_100_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".3.100", is_hp_100_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".4.100", is_hp_100_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".5.100", is_hp_100_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".6.100", is_hp_100_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".7.100", is_hp_100_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".8.100", is_hp_100_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".1.75", is_hp_75_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".2.75", is_hp_75_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".3.75", is_hp_75_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".4.75", is_hp_75_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".5.75", is_hp_75_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".6.75", is_hp_75_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".7.75", is_hp_75_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".8.75", is_hp_75_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".1.50", is_hp_50_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".2.50", is_hp_50_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".3.50", is_hp_50_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".4.50", is_hp_50_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".5.50", is_hp_50_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".6.50", is_hp_50_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".7.50", is_hp_50_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".8.50", is_hp_50_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".1.25", is_hp_25_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".2.25", is_hp_25_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".3.25", is_hp_25_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".4.25", is_hp_25_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".5.25", is_hp_25_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".6.25", is_hp_25_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".7.25", is_hp_25_percent=True, delay_ms=delay)
    mytp.set_tile(tile=name + ".8.25", is_hp_25_percent=True, delay_ms=delay)

    mytp.update()

def init():
    tp_init(name="jelly_parent", text_name="jelly jumper")

init()
