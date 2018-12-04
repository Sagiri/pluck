#pragma once
#include "types.h"

// #define UPDATED_SITRUSBERRY_EFFECT

#define POKEMON_NAME_LENGTH 10
#define BATTLE_STATS_NO 8
#define MAX_BATTLERS_COUNT  4
#define PARTY_SIZE 6

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

#define battle_side_get_party_owner(bank) (battle_side_get_owner(bank) ? party_opponent : party_player)
#define min(x, y) ((x < y) ? x : y)

#define SET_STATCHANGER(stat, stage, goesDown) (stat_modification_spec = (stat) + (stage << 4) + (goesDown << 7))