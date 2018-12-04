#pragma once
#include "types.h"

u8 itemid_get_heldeffect(u16 item);
u8 itemid_get_quality(u16 itemid);
u8 itemid_get_pocket_number(u16 item);

bool battle_side_get_owner(u8 slot);
void dp01_battle_side_mark_buffer_for_execution(u8 bank);
void b_movescr_stack_push(u8* cursor);
void dp01_build_cmdbuf_x02_a_b_varargs(u8 a1, u8 a2, u8 a3, u8 a4, void* a5);
void b_history__record_ability_usage_of_player(u8 bank, u8 ability);

bool dislikes_flavor(u32 personality, u8 flavor);
u8 move_get_pp_info(u16 move, u8 pp_bonuses, u8 id);
u32 pokemon_getattr(struct pokemon*, u8, void*);

u8* strcpy_xFF_terminated(u8* dst, u8* src);
u16 rand();

u32 umod(u32, u32);