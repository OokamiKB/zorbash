import zx
import tp

def on_use(owner, item, target, x, y):
    #zx.con("owner   {} {:08X}".format(zx.thing_get_name(owner), owner))
    #zx.con("item    {} {:08X}".format(zx.thing_get_name(item), item))
    #zx.con("target  {} {:08X}".format(zx.thing_get_name(target), target))
    zx.thing_sound_play_channel(owner, zx.CHANNEL_WEAPON, "sword_swing{}".format(zx.non_pcg_randint(1,3)))
    damage = zx.thing_get_damage_melee(item)
    enchant = zx.thing_get_enchant(item)
    zx.thing_set_current_damage(owner, damage + enchant)

def tp_init(name, text_name, short_text_name):
    mytp = tp.Tp(name, text_name, short_text_name)
    mytp.set_collision_attack(True)
    mytp.set_collision_check(True)
    mytp.set_collision_circle(True)
    mytp.set_collision_hit_priority(10)
    mytp.set_collision_radius(0.40)
    mytp.set_damage_melee_dice("3d6+1")
    mytp.set_gfx_animated_can_hflip(True)
    mytp.set_gfx_animated(True)
    mytp.set_gfx_anim_use("scythe_swing")
    mytp.set_gfx_oversized_and_on_floor(True)
    mytp.set_gfx_short_shadow_caster(True)
    mytp.set_gfx_show_outlined(False)
    mytp.set_gold_value_dice("250")
    mytp.set_is_able_to_fall(True)
    mytp.set_is_bag_item(True)
    mytp.set_is_collectable(True)
    mytp.set_is_described_when_hovering_over(True)
    mytp.set_is_droppable(True)
    mytp.set_is_enchantable(True)
    mytp.set_is_interesting(True)
    mytp.set_is_item(True)
    mytp.set_is_metal(True)
    mytp.set_is_loggable(True)
    mytp.set_is_loggable(True)
    mytp.set_is_moveable(True)
    mytp.set_is_treasure_class_b(True)
    mytp.set_is_treasure_type(True)
    mytp.set_is_usable(True)
    mytp.set_is_weapon(True)
    mytp.set_is_auto_equipped(True)
    mytp.set_item_height(8)
    mytp.set_item_width(8)
    mytp.set_long_text_description("A huge gleaming scythe. Ideal for gardening and other uses.")
    mytp.set_on_use_do("scythe.on_use()")
    mytp.set_stat_attack(10) # 10, means no bonus
    mytp.set_stat_constitution(0)
    mytp.set_stat_defence(0)
    mytp.set_stat_strength(0)
    mytp.set_text_a_or_an("a")
    mytp.set_text_description("Thy swingy means of justice.")
    mytp.set_text_enchant("+1 damage")
    mytp.set_text_enchant("increase damage by 1")
    mytp.set_equip_carry_anim("scythe_carry")
    mytp.set_z_depth(zx.MAP_DEPTH_OBJ)
    mytp.set_z_prio(zx.MAP_PRIO_BEHIND)

    mytp.set_tile(tile=name + ".1")

    mytp.update()

def init():
    tp_init(name="scythe", text_name="single headed scythe", short_text_name="short scythe")

init()
