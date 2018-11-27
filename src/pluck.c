#include "defines.h"

void pluck() {
    struct battle_datum* defender = &battle_data[b_defender];
    u16 berry = defender->item;
    u8 ability = defender->ability;

    if (berry == ITEM_NONE || itemid_get_pocket_number(berry) != PCKT_BERRIES) {
        ++b_movescr_cursor;
        return;
    }

    if (ability == ABILITY_STICKYHOLD) {
        b_last_copied_ability = ability;
        b_movescr_cursor = ability_immunity_script;
        b_history__record_ability_usage_of_player(b_defender, ABILITY_STICKYHOLD);
    } else {
        b_2023D68_held_item = berry;
        defender->item = ITEM_NONE;

        // b_active_side = b_attacker;
        // dp01_build_cmdbuf_x02_a_b_varargs(0, 2, 0, 2, &b_2023D68_held_item);
        // dp01_battle_side_mark_buffer_for_execution(b_attacker);

        b_active_side = b_defender;
        dp01_build_cmdbuf_x02_a_b_varargs(0, 2, 0, 2, &battle_data[b_defender].item);
        dp01_battle_side_mark_buffer_for_execution(b_defender);

        b_movescr_stack_push(b_movescr_cursor + 1);
        b_movescr_cursor = pluck_move_eat_script;

        // *(u8*)((u8*)(&b_dp08_ptr->choicedMove[b_defender]) + 0) = 0;
        // *(u8*)((u8*)(&b_dp08_ptr->choicedMove[b_defender]) + 1) = 0;

        extra_battle_string = pXateYsZ;
    }
}