#pragma once
#include "types.h"

// #define UPDATED_SITRUSBERRY_EFFECT

#define POKEMON_NAME_LENGTH 10
#define BATTLE_STATS_NO 8

#include "defines/items.h"
#include "defines/pockets.h"
#include "defines/pokemon_attributes.h"
#include "defines/abilities.h"
#include "defines/hold_effects.h"
#include "defines/status_constants.h"
#include "defines/battle_message.h"
#include "defines/stats.h"

#include "structs.h"
#include "locations.h"
#include "functions.h"

#define min(x, y) ((x < y) ? x : y)

#define PREPARE_FLAVOR_BUFFER(buffer, flavor) PREPARE_SIMPLE_BUFFER(buffer, B_BUFF_NEGATIVE_FLAVOR, flavor)
#define PREPARE_STAT_BUFFER(buffer, flavor) PREPARE_SIMPLE_BUFFER(buffer, B_BUFF_STAT, flavor)

#define PREPARE_SIMPLE_BUFFER(buffer, variable, value) {    \
    buffer[0] = B_BUFF_PLACEHOLDER_BEGIN;                   \
    buffer[1] = variable;                                   \
    buffer[2] = value;                                      \
    buffer[3] = B_BUFF_EOS;                                 \
}

#define PREPARE_STRING_BUFFER(buffer, string) { \
    buffer[0] = B_BUFF_PLACEHOLDER_BEGIN;       \
    buffer[1] = B_BUFF_STRING;                  \
    buffer[2] = string;                         \
    buffer[3] = (string & 0xFF00) >> 8;         \
    buffer[4] = B_BUFF_EOS;                     \
}

#define SET_STATCHANGER(stat, stage, goesDown) (stat_modification_spec = (stat) + (stage << 4) + (goesDown << 7))