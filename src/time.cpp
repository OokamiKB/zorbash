/*
 * Copyright (C) 2011-2020 goblinhack@gmail.com
 *
 * See the README file for license info for license.
 */

#include "my_main.h"
#include "my_string.h"
#include "my_game.h"
#include "my_time_util.h"

uint32_t time_now;
uint32_t base_time_in_mill;

const char *time2str (uint32_t ms, char *buf, int32_t len)
{_
    static char buf_[MAXSTR];

    int32_t log_msec = ms;
    int32_t log_secs = log_msec / ONESEC;
    int32_t log_mins = log_secs / 60;
    int32_t log_hrs = log_mins / 60;

    log_msec = log_msec % ONESEC;
    log_secs = log_secs % 60;
    log_mins = log_mins % 60;

    if (!buf) {
        buf = buf_;
        len = sizeof(buf_);
    }

    buf[0] = '\0';
    snprintf(buf, len, "%02d:%02d:%02d.%03d: ",
             log_hrs, log_mins, log_secs, log_msec);

    if (buf) {
        return (buf);
    }

    return (buf_);
}

const char *timestamp (char *buf, int32_t len)
{_
    static char buf_[200];

    int32_t log_msec = time_get_time_ms();
    int32_t log_secs = log_msec / ONESEC;
    int32_t log_mins = log_secs / 60;
    int32_t log_hrs = log_mins / 60;

    log_msec = log_msec % ONESEC;
    log_secs = log_secs % 60;
    log_mins = log_mins % 60;

    if (!buf) {
        buf = buf_;
        len = sizeof(buf_);
    }

    buf[0] = '\0';
    snprintf(buf, len, "%02d:%02d:%02d.%03d: ",
             log_hrs, log_mins, log_secs, log_msec);

    if (buf) {
        return (buf);
    }

    return (buf_);
}

uint8_t time_have_x_hundredths_passed_since (uint32_t val, uint32_t since)
{_
    time_get_time_ms();

    /*
     * Cater for negative future times.
     */
    int32_t delay = time_now - since;

    return ((int32_t)(delay / 10) > (int32_t)val);
}

uint8_t time_have_x_thousandths_passed_since (uint32_t val, uint32_t since)
{_
    time_get_time_ms();

    /*
     * Cater for negative future times.
     */
    int32_t delay = time_now - since;

    return ((int32_t)(delay) >= (int32_t)val);
}

uint8_t time_have_x_tenths_passed_since (uint32_t val, uint32_t since)
{_
    time_get_time_ms();

    /*
     * Cater for negative future times.
     */
    int32_t delay = time_now - since;

    return ((int32_t)(delay / 100) >= (int32_t)val);
}

uint8_t time_have_x_secs_passed_since (uint32_t val, uint32_t since)
{_
    time_get_time_ms();

    /*
     * Cater for negative future times.
     */
    int32_t delay = time_now - since;

    return ((int32_t)(delay / ONESEC) >= (int32_t)val);
}
