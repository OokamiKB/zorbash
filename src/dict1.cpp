//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_random.h"
#include "my_random_name.h"
#include "my_sys.h"

static const char *dict1_names[] = {
    "alchemy", "amulet",   "banshee", "bats",     "beast",   "berserk", "bleak",   "blood",   "bloody",  "bogey",
    "castle",  "cave",     "centaur", "chalice",  "crow",    "crypt",   "crystal", "dank",    "dark",    "death",
    "demon",   "devil",    "dingy",   "dire",     "djinn",   "doomed",  "dragon",  "dwarf",   "eerie",   "elf",
    "elve",    "entombed", "evil",    "fairy",    "fear",    "feral",   "fiend",   "fiery",   "flesh",   "foul",
    "gargan",  "ghastly",  "ghost",   "giant",    "gloop",   "gnome",   "goblin",  "god",     "grave",   "griffin",
    "grim",    "grisly",   "grot",    "gryph",    "haunt",   "heinous", "hell",    "hideo",   "hobbit",  "hollow",
    "horror",  "howl",     "huge",    "imp",      "impish",  "jabber",  "karma",   "king",    "kraken",  "legend",
    "lore",    "lunar",    "lycanth", "macabre",  "maggot",  "maggots", "magic",   "magical", "maniac",  "maraud",
    "mask",    "masked",   "medusa",  "miasma",   "moan",    "moldy",   "monst",   "monster", "moon",    "mummy",
    "muse",    "myth",     "necro",   "nemesis",  "newt",    "oberon",  "occult",  "ogre",    "oracle",  "orc",
    "owl",     "pale",     "pixie",   "poison",   "potion",  "powder",  "power",   "prey",    "prince",  "prophet",
    "prowl",   "quail",    "quake",   "queen",    "rage",    "raven",   "realm",   "rose",    "rouge",   "rune",
    "sage",    "sandman",  "scared",  "scream",   "screech", "shaman",  "shriek",  "skele",   "skull",   "slate",
    "slayer",  "slime",    "sorcer",  "spell",    "spider",  "spirit",  "spook",   "stalk",   "stars",   "story",
    "swarm",   "talis",    "tarant",  "tarasque", "terror",  "titan",   "toad",    "tomb",    "brazier", "tragic",
    "tremor",  "troll",    "ugly",    "unicorn",  "unique",  "valiant", "valor",   "vampire", "vanish",  "vanqu",
    "poison",  "vice",     "vicious", "victim",   "villain", "vital",   "wail",    "wand",    "warlock", "weird",
    "were",    "wicked",   "wild",    "wish",     "witch",   "wizard",  "wolf",    "worry",   "worship", "xanadu",
    "yeti",
};

const char *dict1_name(void) { return dict1_names[ pcg_random_range(0, ARRAY_SIZE(dict1_names)) ]; }
