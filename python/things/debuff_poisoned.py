import my
import tp

mytp = None

def on_tick(owner, item, x, y):
    poison = my.thing_get_poison(owner)
    if poison == 0:
        my.topcon("You are no longer poisoned.")
        my.thing_defeated(item, "end of debuff")
        return True
    # Too noisy
    # my.topcon("%%fg=yellow$You are poisoned!")
    return True

def debuff_poisoned_init(name, text_name):
    global mytp
    mytp = tp.Tp(name, text_name)
    mytp.set_is_loggable(True)
    mytp.set_is_debuff(True)
    mytp.set_text_debuff("You are poisoned");
    mytp.set_long_text_description("Poison courses through your unlucky veins.")
    mytp.set_on_tick_do("debuff_poisoned.on_tick()")
    mytp.set_text_description("Poisoned debuff.")
    mytp.set_tile(tile="debuff_poisoned")
    mytp.update()

def init():
    debuff_poisoned_init(name="debuff_poisoned", text_name="poisoned")

init()
