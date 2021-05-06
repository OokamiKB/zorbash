//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
//

#include "my_sys.h"
#include "my_level.h"
#include "my_thing.h"
#include "my_hiscore.h"
#include "my_monst.h"
#include "my_ptrcheck.h"

HiScores::HiScores (void)
{_
    if ((int)hiscores.size() > HiScore::max) {
        hiscores.resize(HiScore::max);
    } else {
        while ((int)hiscores.size() < HiScore::max) {
            hiscores.push_back(HiScore("Thy place awaits thee",
                                       0, // score
                                       0, // level_reached
                                       ""));
        }
    }
}

HiScores::~HiScores (void)
{_
}

void HiScores::add_new_hiscore (Thingp player, 
                                const std::string &name, 
                                const std::string &killed_by)
{_
    std::vector<HiScore>::iterator h = hiscores.begin();

    while (h != hiscores.end()) {
        if (player->get_score() > h->score) {
            hiscores.insert(h,
                HiScore(
                    name,
                    player->get_score(),
                    (player->level->world_at.z + 1) / 2,
                    player->title() + ", " + killed_by));

            hiscores.resize(HiScore::max);

            return;
        }

        h++;
    }
}

bool HiScores::is_new_hiscore (Thingp player)
{_
    std::vector<HiScore>::iterator h = hiscores.begin();

    if (!player->get_score()) {
        //
        // Poor player.
        //
        return (false);
    }

    while (h != hiscores.end()) {
        if (player->get_score() > h->score) {
            return (true);
        }
        h++;
    }

    return (false);
}

bool HiScores::is_new_highest_hiscore (Thingp player)
{
    std::vector<HiScore>::iterator h = hiscores.begin();

    if (!player->get_score()) {
        //
        // Poor player.
        //
        return (false);
    }

    while (h != hiscores.end()) {
        if (player->get_score() > h->score) {
            return (true);
        }
        return (false);
    }
    return (false);
}

const char *HiScores::place_str (Thingp player)
{
    const char *which[HiScore::max_displayed] = {
        "First!",
        "Second",
        "Third",
        "Fourth",
        "Fifth",
        "Sixth",
        "Seventh",
        "Eighth",
        "Nineth",
        "Tenth",
    };

    if (!player->get_score()) {
        //
        // Poor player.
        //
        return ("");
    }

    std::vector<HiScore>::iterator h = hiscores.begin();

    while (h != hiscores.end()) {
        if (player->get_score() > h->score) {
            return (which[h-hiscores.begin()]);
        }
        h++;
    }
    return ("");
}

std::istream& operator>>(std::istream &in, Bits<HiScore &> my)
{_
    in >> bits(my.t.name);
    in >> bits(my.t.killed_by);
    in >> bits(my.t.score);
    in >> bits(my.t.level_reached);
    return in;
}

std::ostream& operator<<(std::ostream &out, Bits<const HiScore & > const my)
{_
    out << bits(my.t.name);
    out << bits(my.t.killed_by);
    out << bits(my.t.score);
    out << bits(my.t.level_reached);
    return (out);
}

std::istream& operator>>(std::istream &in, Bits<HiScores &> my)
{_
    in >> bits(my.t.hiscores);
    return in;
}

std::ostream& operator<<(std::ostream &out, Bits<const HiScores & > const my)
{_
    out << bits(my.t.hiscores);
    return (out);
}

