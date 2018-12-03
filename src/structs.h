#pragma once
#include "types.h"

struct pokemon {
    u8 _[100];
};

struct battle_datum {
    /*0x00*/ u16 species;
    /*0x02*/ u16 attack;
    /*0x04*/ u16 defense;
    /*0x06*/ u16 speed;
    /*0x08*/ u16 spAttack;
    /*0x0A*/ u16 spDefense;
    /*0x0C*/ u16 moves[4];
    /*0x14*/ u32 hpIV:5;
    /*0x14*/ u32 attackIV:5;
    /*0x15*/ u32 defenseIV:5;
    /*0x15*/ u32 speedIV:5;
    /*0x16*/ u32 spAttackIV:5;
    /*0x17*/ u32 spDefenseIV:5;
    /*0x17*/ u32 isEgg:1;
    /*0x17*/ u32 altAbility:1;
    /*0x18*/ i8 statStages[BATTLE_STATS_NO];
    /*0x20*/ u8 ability;
    /*0x21*/ u8 type1;
    /*0x22*/ u8 type2;
    /*0x23*/ u8 unknown;
    /*0x24*/ u8 pp[4];
    /*0x28*/ u16 hp;
    /*0x2A*/ u8 level;
    /*0x2B*/ u8 friendship;
    /*0x2C*/ u16 max_hp;
    /*0x2E*/ u16 item;
    /*0x30*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x3B*/ u8 ppBonuses;
    /*0x3C*/ u8 otName[8];
    /*0x44*/ u32 experience;
    /*0x48*/ u32 personality;
    /*0x4C*/ u32 status1;
    /*0x50*/ u32 status2;
    /*0x54*/ u32 otId;
};

struct dp08 {
    u8 _[0xC8];
    u16 choicedMove[MAX_BATTLERS_COUNT];
    u8 __[0x130];
};

struct battle_enigma_berry {
    /*0x00*/ u8 name[BERRY_NAME_LENGTH + 1];
    /*0x07*/ u8 hold_effect;
    /*0x08*/ u8 item_effect[BERRY_ITEM_EFFECT_COUNT];
    /*0x1A*/ u8 quality;
    /*0x1B*/ u8 _;
};