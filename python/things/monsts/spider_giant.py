import my
import tp

def on_you_bite_attack(me, x, y):
    sound = "growl{}".format(my.non_pcg_randint(1, 10))
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, sound)

def on_you_are_hit_but_still_alive(me, hitter, real_hitter, x, y, crit, damage):
    sound = "hiss{}".format(my.non_pcg_randint(1, 10))
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, sound)

def on_you_miss_do(me, hitter, x, y):
    sound = "hiss{}".format(my.non_pcg_randint(1, 10))
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, sound)

def on_death(me, x, y):
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, "squelch"):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, "squelch")

def on_born(me, x, y):
    it = my.level_spawn_at_thing(me, "spiderweb")
    if it != 0:
        my.thing_set_minion_owner(me, it)

def tp_init(name, text_name):
    mytp = tp.Tp(name, text_name)
    mytp.set_ai_aggression_level_pct(100)
    mytp.set_ai_avoid_distance(5)
    mytp.set_ai_resent_count(10)
    mytp.set_ai_vision_distance(5)
    mytp.set_attack_eater(True)
    mytp.set_attack_lunge(True)
    mytp.set_collision_check(True)
    mytp.set_collision_hit_priority(10)
    mytp.set_damage_bite_chance_d1000(900)
    mytp.set_damage_bite_dice("1d8+3")
    mytp.set_damage_poison_chance_d1000(100)
    mytp.set_damage_poison_dice("2d8+2")
    mytp.set_damage_received_doubled_from_fire(True)
    mytp.set_environ_avoids_fire(100)
    mytp.set_environ_avoids_fire(True)
    mytp.set_environ_avoids_water(100)
    mytp.set_environ_prefers_spiderwebs(True)
    mytp.set_gfx_animated_can_hflip(True)
    mytp.set_gfx_animated(True)
    mytp.set_gfx_anim_use("attack_claws")
    mytp.set_gfx_bounce_on_move(True)
    mytp.set_gfx_health_bar_shown(True)
    mytp.set_gfx_oversized_and_on_floor(True)
    mytp.set_gfx_short_shadow_caster(True)
    mytp.set_gfx_show_outlined(True)
    mytp.set_health_hunger_pct(95)
    mytp.set_health_initial_dice("4d15+4")
    mytp.set_is_able_to_fall(True)
    mytp.set_is_able_to_jump_attack_chance_d1000(800)
    mytp.set_is_green_blooded(True)
    mytp.set_is_able_to_jump_attack(True)
    mytp.set_is_able_to_jump_distance(2)
    mytp.set_is_able_to_jump_onto_chance_d1000(100)
    mytp.set_is_able_to_jump_onto(True)
    mytp.set_is_able_to_jump_randomly_chance_d1000(20)
    mytp.set_is_able_to_jump(True)
    mytp.set_is_able_to_jump_without_tiring(True)
    mytp.set_is_able_to_see_in_the_dark(True)
    mytp.set_is_able_to_tire(True)
    mytp.set_is_attackable_by_monst(True)
    mytp.set_is_attackable_by_player(True)
    mytp.set_is_bleeder(True)
    mytp.set_is_corpse_on_death(True)
    mytp.set_is_crushable(True)
    mytp.set_is_described_when_hovering_over(True)
    mytp.set_is_food_eater(True)
    mytp.set_is_heavy(True)
    mytp.set_is_hittable(True)
    mytp.set_is_hunger_insatiable(True)
    mytp.set_is_living(True)
    mytp.set_is_loggable(True)
    mytp.set_is_meat_eater(True)
    mytp.set_is_monst(True)
    mytp.set_is_moveable(True)
    mytp.set_is_poisonous_danger_level(2) # danger level
    mytp.set_is_shovable(True)
    mytp.set_is_spider(True)
    mytp.set_is_tickable(True)
    mytp.set_long_text_description("An enormous spider. Ichor drips from its glistening fangs. Watch out for its web and poisonous bite.")
    mytp.set_minion_leash_distance(5)
    mytp.set_monst_size(my.MONST_SIZE_GIANT)
    mytp.set_normal_placement_rules(True)
    mytp.set_nutrition_dice("1d6")
    mytp.set_on_born_do("spider_giant.on_born()")
    mytp.set_on_death_do("spider_giant.on_death()")
    mytp.set_on_you_are_hit_but_still_alive_do("spider_giant.on_you_are_hit_but_still_alive()")
    mytp.set_on_you_bite_attack_do("spider_giant.on_you_bite_attack()")
    mytp.set_on_you_miss_do("spider_giant.on_you_miss_do()")
    mytp.set_rarity(my.RARITY_COMMON)
    mytp.set_stamina(100)
    mytp.set_stat_armor_class(14)
    mytp.set_stat_attack_bonus(20) # 10, means no bonus
    mytp.set_stat_constitution(12)
    mytp.set_stat_dexterity(16)
    mytp.set_stat_strength(14)
    mytp.set_text_a_or_an("a")
    mytp.set_text_description("%%fg=brown$A giant spider.")
    mytp.set_text_hits("gores")
    mytp.set_z_depth(my.MAP_DEPTH_OBJ)
    mytp.set_z_prio(my.MAP_PRIO_NORMAL)

    delay=150
    mytp.set_tile("spider_giant.1", delay_ms=delay)
    mytp.set_tile("spider_giant.2", delay_ms=delay)
    mytp.set_tile("spider_giant.dead", is_dead=True, delay_ms=delay)

    mytp.update()

def init():
    tp_init(name="spider_giant", text_name="giant spider")

init()

