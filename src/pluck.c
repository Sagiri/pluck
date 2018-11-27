#include "defines.h"

u8* pluck_restore_hp(struct battle_datum* attacker, u8 quality) {
    if (attacker->hp < attacker->max_hp) {
        u16 final_hp = min(attacker->max_hp, attacker->hp + quality);
        b_move_damage = attacker->hp - final_hp;
        return pluck_heal_hp_script;
    } else {
        return pluck_move_eat_script;
    }
}

u8* pluck_heal_status(struct battle_datum* attacker, u32 mask, u8* sucess_script) {
    if (attacker->status1 & mask) {
        attacker->status1 &= ~mask;

        b_active_side = b_attacker;
        dp01_build_cmdbuf_x02_a_b_varargs(
            0,
            REQ_BTL_STATUS,
            0,
            sizeof(attacker->status1),
            &attacker->status1
        );
        dp01_battle_side_mark_buffer_for_execution(b_attacker);

        return sucess_script;
    } else {
        return pluck_move_eat_script;
    }
}

void pluck() {
    struct battle_datum* defender = &battle_data[b_defender];
    struct battle_datum* attacker = &battle_data[b_attacker];

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

        b_active_side = b_defender;
        dp01_build_cmdbuf_x02_a_b_varargs(
            0,
            REQ_BTL_HELDITEM,
            0,
            sizeof(battle_data[b_defender].item),
            &battle_data[b_defender].item
        );
        dp01_battle_side_mark_buffer_for_execution(b_defender);

        u8 effect = itemid_get_heldeffect(berry);
        u8 quality = itemid_get_quality(berry);

        u8* script;

        switch(effect) {
            case HOLD_EFFECT_RESTORE_HP:
                script = pluck_restore_hp(attacker, quality);
                break;

            case HOLD_EFFECT_CURE_PAR:
                script = pluck_heal_status(attacker, STATUS1_PARALYSIS, pluck_parlyz_heal_script);
                break;

            case HOLD_EFFECT_CURE_PSN:
                script = pluck_heal_status(attacker, STATUS1_PSN_ANY, pluck_poison_heal_script);
                break;

            case HOLD_EFFECT_CURE_BRN:
                script = pluck_heal_status(attacker, STATUS1_BURN, pluck_burn_heal_script);
                break;

            default:
                script = pluck_move_eat_script;
                break;
        }

        b_movescr_stack_push(b_movescr_cursor +1);
        b_movescr_cursor = script;

        // *(u8*)((u8*)(&b_dp08_ptr->choicedMove[b_defender]) + 0) = 0;
        // *(u8*)((u8*)(&b_dp08_ptr->choicedMove[b_defender]) + 1) = 0;

        extra_battle_string = pXateYsZ;
    }
}