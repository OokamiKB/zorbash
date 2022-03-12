import my
import tp


def on_death_of_a_follower(me, leader, x, y):
    if not my.thing_is_dead_or_dying(leader):
        my.thing_msg(me, "The mummy necromancer begins muttering some unknown words!")


def on_born(me, x, y):
    my.thing_msg(me, "Hello mortal!")
    my.thing_carry(me, "staff_lightning")


def on_tick(owner, me, x, y):
    if my.pcg_randint(1, 100) < 90:
        return False

    risen = 0
    if my.thing_stat_con(me) > 1:
        followers = my.thing_all_followers_get(me)
        if followers is None:
            return False

        for follower in followers:
            if my.thing_is_dead_or_dying(follower):
                my.thing_polymorph(follower, "mummy")
                my.thing_resurrect(follower, "arise")
                my.thing_stat_con_decr(me, 1)
                my.thing_msg(me, "Arise my minion!")
                my.thing_msg(follower, "Groan!")
                if my.thing_stat_con(me) <= 1:
                    return True
                risen += 1

    if risen > 0:
        return True
    return False


def on_death(me, x, y):
    followers = my.thing_all_followers_get(me)
    if followers is None:
        return False

    for follower in followers:
        if my.thing_is_resurrected_or_resurrecting(follower):
            my.thing_msg(follower, "Free at last!")
            my.thing_perma_death(follower, "Leader died!")


def tp_init(name, text_name):
    self = tp.Tp(name, text_name)

    my.aggression_level_pct(self, 100)
    my.ai_resent_count(self, 100)
    my.ai_shove_chance_d1000(self, 200)
    my.ai_wanderer(self, True)
    my.attack_eater(self, True)
    my.attack_humanoid(self, True)
    my.attack_living(self, True)
    my.attack_lunge(self, True)
    my.attack_meat(self, True)
    my.collision_check(self, True)
    my.collision_hit_priority(self, 10)
    my.damage_natural_attack_chance_d1000(self, 950)
    my.damage_natural_attack_type(self, "gore")
    my.damage_natural_dice(self, "1d6+10")
    my.damage_necrosis_chance_d1000(self, 50)
    my.damage_necrosis_dice(self, "1")
    my.damage_received_doubled_from_fire(self, True)
    my.damage_received_doubled_from_water(self, True)
    my.distance_vision(self, 5)
    my.environ_avoids_fire(self, 100)
    my.environ_avoids_water(self, 100)
    my.gfx_animated_can_hflip(self, True)
    my.gfx_animated(self, True)
    my.gfx_anim_use(self, "attack_claws")
    my.gfx_bounce_on_move(self, True)
    my.gfx_health_bar_shown(self, True)
    my.gfx_short_shadow_caster(self, True)
    my.gfx_show_outlined(self, True)
    my.health_initial_dice(self, "2d20")
    my.hunger_clock_tick_freq(self, 50)
    my.hunger_health_pct(self, 95)
    my.hunger_is_insatiable(self, True)
    my.is_able_to_change_levels(self, True)
    my.is_able_to_fall(self, True)
    my.is_able_to_see_in_the_dark(self, True)
    my.is_able_to_shove(self, True)
    my.is_able_to_use_rings(self, True)
    my.is_able_to_use_wands_or_staffs(self, True)
    my.is_attackable_by_monst(self, True)
    my.is_attackable_by_player(self, True)
    my.is_biome_dungeon(self, True)
    my.is_burnable(self, True)
    # my.is_carrier_of_treasure_class_b(self, True)
    my.is_corpse_on_death(self, True)
    my.is_crushable(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_fearless(self, True)
    my.is_green_blooded(self, True)
    my.is_hittable(self, True)
    my.is_immune_to_cold(self, True)
    my.is_immune_to_necrosis(self, True)
    my.is_immune_to_poison(self, True)
    my.is_intelligent(self, True)
    my.is_loggable(self, True)
    my.is_monst_class_c(self, True)
    my.is_monst(self, True)
    my.is_moveable(self, True)
    my.is_necrotic_danger_level(self, 1)  # danger level
    my.is_red_blood_eater(self, True)
    my.is_resurrectable(self, True)
    my.is_shovable(self, True)
    my.is_tickable(self, True)
    my.is_undead(self, True)
    my.long_text_description_extra(self, "This particular mummy is learned in the dark arts. Withered of body, but sharp of mind, beware the abilities of this mummy.")
    my.long_text_description(self, "Possibly the corpse of one who ventured into this dungeon before. All life is gone now, and what remains is a corpse wrapped in rags. Death is no release for this poor creature. Watch out for its necrotic touch!")
    my.monst_size(self, my.MONST_SIZE_NORMAL)
    my.move_speed(self, 100)
    my.noise_decibels_hearing(self, 50)
    my.noise_on_moving_or_being_carried(self, 5)
    my.normal_placement_rules(self, True)
    my.on_born_do(self, "me.on_born()")
    my.on_death_do(self, "me.on_death()")
    my.on_death_of_a_follower_do(self, "me.on_death_of_a_follower()")
    my.on_tick_do(self, "me.on_tick()")
    my.on_you_are_hit_but_still_alive_do(self, "me.on_you_are_hit_but_still_alive()")
    my.on_you_miss_do(self, "me.on_you_miss_do()")
    my.on_you_natural_attack_do(self, "me.on_you_natural_attack()")
    my.rarity(self, my.RARITY_COMMON)
    my.resurrect_dice(self, "1d10+30")
    my.stat_con(self, 15)
    my.stat_def(self, 11)
    my.stat_dex(self, 10)
    my.stat_luck(self, 10)
    my.stat_str(self, 16)
    my.text_a_or_an(self, "a")
    my.text_description(self, "A master of the darkest arts.")
    my.text_description(self, "A staggering corpse, covered in tissue paper.")
    my.text_hits(self, "claws")
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_PRIO_NORMAL)

    delay = 300
    my.tile(self, tile=name + ".1", delay_ms=delay, frame=1)
    my.tile(self, tile=name + ".2", delay_ms=delay, frame=2)
    my.tile(self, tile=name + ".3", delay_ms=delay, frame=3)
    my.tile(self, tile=name + ".4", delay_ms=delay, frame=4)

    my.tile(self, tile=name + ".1.dead", is_dead=True, delay_ms=delay)
    my.tile(self, tile=name + ".2.dead", is_dead=True, delay_ms=delay)
    my.tile(self, tile=name + ".3.dead", is_dead=True, delay_ms=delay)
    my.tile(self, tile=name + ".4.dead", is_dead=True, is_end_of_anim=True)

    my.tp_update(self)


def init():
    tp_init(name="mummy_necro", text_name="mummu necromancer")


init()
