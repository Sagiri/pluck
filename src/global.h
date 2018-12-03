#pragma once
#include "types.h"

#define POKEMON_NAME_LENGTH 10
#define BATTLE_STATS_NO 8

#include "defines/items.h"
#include "defines/pockets.h"
#include "defines/pokemon_attributes.h"
#include "defines/abilities.h"
#include "defines/hold_effects.h"
#include "defines/status_constants.h"

#include "structs.h"
#include "locations.h"
#include "functions.h"

// #define battle_side_get_party_owner(bank) (battle_side_get_owner(bank) ? party_opponent : party_player)
#define min(x, y) ((x < y) ? x : y)

#define PREPARE_FLAVOR_BUFFER(textVar, flavorId) {                          \
    textVar[0] = 0xFD;                                                      \
    textVar[1] = 8;                                                         \
    textVar[2] = flavorId;                                                  \
    textVar[3] = 0xFF;                                                      \
}
