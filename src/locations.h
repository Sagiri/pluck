#pragma once
#include "types.h"
#include "structs.h"

// extern struct pokemon party_player[6];
// extern struct pokemon party_opponent[6];
extern struct battle_datum battle_data[4];

extern u8 pXateYsZ[];
extern u8 pluck_move_eat_script[];
extern u8 ability_immunity_script[];
// extern u8 knockoff_move_removeitem_script[];
// extern u8 helditem_restorehp_script[];
extern u8 pluck_heal_hp_script[];
extern u8 pluck_parlyz_heal_script[];
extern u8 pluck_poison_heal_script[];
extern u8 pluck_burn_heal_script[];
extern u8 pluck_sleep_heal_script[];

extern u8* extra_battle_string;

extern u8 b_attacker;
extern u8 b_defender;
// extern u8 b_defender_partner;
extern u8 b_active_side;
// extern u16 b_pokemon_team_id_by_side[4];
// // extern u8 string_buffer_maybe[300];
// // extern u8 b_buffers_awaiting_execution_bitfield__copied_after_displaying_x_used_y_message;
extern u8* b_movescr_cursor;
extern u16 b_2023D68_held_item;
extern u8 b_last_copied_ability;
extern struct dp08* b_dp08_ptr;
extern i32 b_move_damage;