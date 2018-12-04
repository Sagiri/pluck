#pragma once
#include "types.h"
#include "structs.h"

extern struct pokemon party_player[6];
extern struct pokemon party_opponent[6];

extern struct battle_datum battle_data[4];
extern u8 b_active_side;
extern u8 b_attacker;
extern u8 b_defender;
extern u8 b_defender_partner;

extern u8* b_movescr_cursor;
extern u16 b_2023D68_held_item;
extern u8 b_last_copied_ability;
extern i32 b_move_damage;
extern u8 stat_modification_spec;

extern u8 battle_outcome_A[];
extern u8 battle_outcome_B[];

extern u8 eat_opponent_berry_script[];
extern u8 hp_restore_script[];
extern u8 parlyz_heal_script[];
extern u8 poison_heal_script[];
extern u8 burn_heal_script[];
extern u8 freeze_heal_script[];
extern u8 sleep_heal_script[];
extern u8 confusion_heal_script[];
extern u8 all_heal_script[];
extern u8 too_flavorful_script[];
extern u8 stat_buff_script[];
extern u8 crit_rate_buff_script[];
extern u8 pp_restore_script[];

extern u8 ability_immunity_script[];
extern u8 bo_paralysis[];
extern u8 bo_poison[];
extern u8 bo_burn[];
extern u8 bo_sleep[];
extern u8 bo_confusion[];
extern u8 bo_ice[];

extern struct dp08* b_dp08_ptr;
extern u8 byte_2023FD4;
extern u8 byte_2023FD5;