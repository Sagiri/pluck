// .definelabel move_scripts, 0x081D65A8        // vanilla
.definelabel move_scripts, 0x08903B70           // mrds
PLUCK_MOVE_SCRIPTID equ 255

.definelabel jpt_80206D8, 0x080206E4
EFFECT_EAT_BERRY equ 0x3A
EFFECT_STEAL_ITEM equ 0x1F
EFFECT_PAYDAY equ 0xB

.definelabel party_player, 0x02024284
.definelabel party_opponent, 0x0202402C

.definelabel battle_data, 0x02023BE4
.definelabel b_attacker, 0x02023D6B
.definelabel b_defender, 0x02023D6C
.definelabel b_movescr_cursor, 0x02023D74
.definelabel effect_to_apply, 0x02023E85
.definelabel hit_move_script, 0x081D6900
.definelabel b_active_side, 0x02023BC4
.definelabel b_2023D68_held_item, 0x02023D68
.definelabel b_last_copied_ability, 0x02023D6A
.definelabel ability_immunity_script, 0x081D948E
.definelabel b_dp08_ptr, 0x02023FE8
.definelabel b_move_damage, 0x02023D50

.definelabel extra_battle_string, 0x0203C020
EXTRA_BATTLE_STRINGID equ 0x184

// .definelabel battle_strings, 0x08A00000
// PLUCK_BATTLE_STRINGID equ 374
// .definelabel b_pokemon_team_id_by_side, 0x02023BCE
// .definelabel string_buffer_maybe, 0x0202298C
// .definelabel b_buffers_awaiting_execution_bitfield__copied_after_displaying_x_used_y_message, 0x02023E89
// .definelabel knockoff_move_removeitem_script, 0x081D8F86
// .definelabel helditem_restorehp_script, 0x081D95EF
// .definelabel thief_move_steal_script, 0x081D9271
.definelabel b_defender_partner, 0x02023D6E

// .definelabel parlyz_heal_script, 0x081D9537
// .definelabel poison_heal_script, 0x081D954F
// .definelabel burn_heal_script, 0x081D9567
// .definelabel sleep_heal_script, 0x081D9597
// .definelabel confusion_heal_script, 0x081D95AF

.definelabel battle_outcome_A, 0x02022AB8
.definelabel battle_outcome_B, 0x02022AC8

.definelabel bo_paralysis, 0x082500A4
.definelabel bo_poison, 0x08250094
.definelabel bo_burn, 0x082500AC
.definelabel bo_sleep, 0x0825009C
.definelabel bo_confusion, 0x082500BC
.definelabel bo_ice, 0x082500B4

.definelabel stat_modification_spec, 0x02023FDE

.definelabel byte_2023FD4, 0x02023FD4
.definelabel byte_2023FD5, 0x02023FD5