import my
import tp

mytp = None


def on_enchant(me, x, y):
    owner = my.thing_get_top_owner_id(me)
    if my.thing_is_player(owner):
        my.topcon("The shield shines a woody wood color.")
    my.thing_incr_stat_def(me, 1)


def tp_init(name, text_name, short_text_name):
    global mytp
    mytp = tp.Tp(name, text_name, short_text_name)
    mytp.set_break_chance_d10000(20)
    mytp.set_enchant_max(5)
    mytp.set_equip_carry_anim("shield_wooden_carry")
    mytp.set_gfx_short_shadow_caster(True)
    mytp.set_gold_value_dice("10")
    mytp.set_is_able_to_fall(True)
    mytp.set_is_shield(True)
    mytp.set_is_auto_equipped(True)
    mytp.set_is_bag_item(True)
    mytp.set_is_collectable(True)
    mytp.set_is_described_when_hovering_over(True)
    mytp.set_is_droppable(True)
    mytp.set_is_enchantable(True)
    mytp.set_is_wooden(True)
    mytp.set_is_interesting(True)
    mytp.set_is_item(True)
    mytp.set_is_loggable(True)
    mytp.set_is_treasure_class_a(True)
    mytp.set_is_treasure_type(True)
    mytp.set_item_height(4)
    mytp.set_item_width(4)
    mytp.set_long_text_description("An actual very rare wooden shield. I know, I can hardly believe it myself. Gives a staggering +2 to armor class.")
    mytp.set_normal_placement_rules(True)
    mytp.set_on_enchant_do("me.on_enchant()")
    mytp.set_rarity(my.RARITY_COMMON)
    mytp.set_stat_def_mod(2)
    mytp.set_text_a_or_an("a")
    mytp.set_text_description("Wooden shield.")
    mytp.set_text_enchant("+1 AC")
    mytp.set_z_depth(my.MAP_DEPTH_OBJ)
    mytp.set_z_prio(my.MAP_PRIO_BEHIND)

    mytp.set_tile(tile=name)

    mytp.update()


def init():
    tp_init(
        name="shield_wooden",
        text_name="wooden shield",
        short_text_name="wooden shield",
    )


init()