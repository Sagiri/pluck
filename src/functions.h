#pragma once
#include "types.h"

// // bool do_itemeffect(struct pokemon* pokemon, u16 item, u8 partyid, u8 attackid);
u8 itemid_get_heldeffect(u16 item);
u8 itemid_get_pocket_number(u16 item);
u8 itemid_get_quality(u16 itemid);

// // u32 pokemon_getattr(struct pokemon*, u8, void*);
// void pokemon_setattr(struct pokemon*, u8, void*);

// // u8 item_battle_effects(u8 caseid, u8 bank, bool moveTurn);

// // // true: opponent
// // // false: player
// bool battle_side_get_owner(u8 slot);

// // void expand_battle_string(u8* fmt);
void dp01_battle_side_mark_buffer_for_execution(u8 bank);
// // void battle_show_message_maybe(u8* str, u8 unk);
void b_movescr_stack_push(u8* cursor);
void dp01_build_cmdbuf_x02_a_b_varargs(u8 a1, u8 a2, u8 a3, u8 a4, void* a5);
void b_history__record_ability_usage_of_player(u8 bank, u8 ability);