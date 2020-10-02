//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//
#include "my_main.h"

static const char *dict1_names[] = {
    "abnormal",
    "adventure",
    "alchemy",
    "allusion",
    "amulet",
    "awe",
    "banshee",
    "bats",
    "beast",
    "beauty",
    "behemoth",
    "belief",
    "berserk",
    "bestial",
    "bewitch",
    "bizarre",
    "blackcat",
    "blindfold",
    "bogeyman",
    "bones",
    "books",
    "brew",
    "brownies",
    "brutalize",
    "cackle",
    "captivate",
    "carvings",
    "cast",
    "castles",
    "cauldron",
    "cave",
    "caves",
    "cemetery",
    "centaur",
    "cerberus",
    "chalice",
    "charisma",
    "charming",
    "clarity",
    "classic",
    "cliffs",
    "clock",
    "collapse",
    "comic",
    "comics",
    "compare",
    "concoct",
    "conjure",
    "costumes",
    "creak",
    "creative",
    "creature",
    "creepy",
    "cringe",
    "crisis",
    "crone",
    "crow",
    "cruelty",
    "crypt",
    "crystal",
    "curious",
    "curse",
    "dancing",
    "daring",
    "dazzle",
    "death",
    "deeds",
    "deformity",
    "dejavu",
    "delirious",
    "demon",
    "detect",
    "detection",
    "detective",
    "devil",
    "devilfish",
    "disaster",
    "disembody",
    "disembowel",
    "disgusting",
    "disturbing",
    "djinn",
    "doomed",
    "dose",
    "dragon",
    "dramatic",
    "dread",
    "dream",
    "dress-up",
    "dwarf",
    "eek",
    "eerie",
    "elf",
    "empire",
    "entomb",
    "escapade",
    "event",
    "evil",
    "exhume",
    "exorcist",
    "fable",
    "fairy",
    "familiar",
    "fanciful",
    "fantastic",
    "fantasy",
    "favors",
    "fearsome",
    "feasting",
    "feral",
    "ferocious",
    "fiction",
    "fiend",
    "fiery",
    "figment",
    "flesh",
    "folklore",
    "forces",
    "forgery",
    "foul",
    "freak",
    "frozen",
    "garb",
    "gargantuan",
    "gasp",
    "gestures",
    "ghastly",
    "ghost",
    "giant",
    "gifts",
    "glimmer",
    "gnome",
    "goblin",
    "godmother",
    "gods",
    "gowns",
    "grateful",
    "graveyard",
    "green",
    "griffin",
    "griffon",
    "grimm",
    "grisly",
    "grotesque",
    "growling",
    "gruesome",
    "gryphon",
    "hackles",
    "hag",
    "harbinger",
    "haunt",
    "headless",
    "heinous",
    "hell-bent",
    "helpful",
    "herbs",
    "heroic",
    "hideous",
    "hobbit",
    "hollow",
    "horrible",
    "horror",
    "hover",
    "howls",
    "huge",
    "humongous",
    "humped",
    "hysteria",
    "idyll",
    "illusions",
    "image",
    "imagery",
    "imaginary",
    "imp",
    "improvise",
    "impulse",
    "incognito",
    "influence",
    "ingenious",
    "invisible",
    "jabber",
    "jargon",
    "jaunt",
    "jeer",
    "jiggle",
    "jinx",
    "joking",
    "karma",
    "keen",
    "keepsake",
    "kettle",
    "kidnap",
    "king",
    "kingdom",
    "kraken",
    "lands",
    "lantern",
    "legend",
    "leprechaun",
    "leviathan",
    "lore",
    "lucky",
    "lunacy",
    "lunar",
    "lycanth",
    "macabre",
    "maggots",
    "magic",
    "magical",
    "magician",
    "majesty",
    "malevolant",
    "maniac",
    "manifest",
    "maraud",
    "mask",
    "masked",
    "medieval",
    "medium",
    "medusa",
    "miasma",
    "miracle",
    "mischief",
    "misshapen",
    "moan",
    "moldy",
    "monster",
    "monstrous",
    "moon",
    "mummy",
    "muse",
    "musings",
    "mutilate",
    "mystery",
    "mystical",
    "myth",
    "mythical",
    "narration",
    "nature",
    "necromancy",
    "nemesis",
    "newt",
    "notion",
    "novels",
    "oberon",
    "obliterate",
    "obscure",
    "occult",
    "odd",
    "ogre",
    "oracle",
    "orc",
    "overpower",
    "overwhelm",
    "owl",
    "paralysis",
    "pattern",
    "perform",
    "petrify",
    "phantasm",
    "phantom",
    "phenomenon",
    "pixie",
    "plot",
    "poisonous",
    "possessed",
    "potent",
    "potion",
    "powder",
    "power",
    "prey",
    "prince",
    "prophet",
    "prowl",
    "quail",
    "quake",
    "quash",
    "quaver",
    "queen",
    "quest",
    "question",
    "quiver",
    "quizzical",
    "raconteur",
    "rage",
    "rasping",
    "rattle",
    "realm",
    "reasoning",
    "reference",
    "reign",
    "repel",
    "repugnant",
    "reveal",
    "ritual",
    "robe",
    "rule",
    "rune",
    "sage",
    "sandman",
    "sasquatch",
    "scare",
    "scared",
    "scold",
    "scream",
    "screech",
    "scroll",
    "seeking",
    "seer",
    "setting",
    "shaman",
    "shiver",
    "shrew",
    "shrieking",
    "sibyl",
    "sinister",
    "skeleton",
    "skitter",
    "skull",
    "slayer",
    "somber",
    "sorcerer",
    "sorcery",
    "specter",
    "spell",
    "spider",
    "spirit",
    "spirits",
    "spook",
    "spooked",
    "stalk",
    "stars",
    "story",
    "stupendous",
    "swarm",
    "talisman",
    "tarantula",
    "terror",
    "theory",
    "thrilling",
    "titan",
    "toad",
    "torch",
    "tragic",
    "traits",
    "transform",
    "tremors",
    "trickery",
    "tricks",
    "troll",
    "ugly",
    "unicorn",
    "unique",
    "unleash",
    "unmask",
    "unusual",
    "valiant",
    "valor",
    "vampire",
    "vanguard",
    "vanish",
    "vanquish",
    "variety",
    "venomous",
    "version",
    "vice",
    "vicious",
    "victim",
    "villains",
    "visionary",
    "vital",
    "vixen",
    "wail",
    "wand",
    "ward",
    "warlock",
    "warnings",
    "watchful",
    "weird",
    "werewolf",
    "western",
    "whim",
    "whimsical",
    "whine",
    "whisk",
    "whispers",
    "white",
    "wicked",
    "wild",
    "willies",
    "win",
    "wince",
    "wisdom",
    "wish",
    "witch",
    "wizard",
    "worry",
    "worship",
    "wrinkled",
    "xanadu",
    "yearn",
    "yelling",
    "yelp",
    "yeti",
    "youth",
    "yowl",
    "zealous",
    "zigzag",
};

const char * dict1_name(void) {
    return dict1_names[random_range(0, ARRAY_SIZE(dict1_names))];
}
