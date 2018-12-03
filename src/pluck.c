#include "global.h"

void pluck_restore_hp(struct battle_datum* attacker, u8 quality) {
    if (attacker->hp < attacker->max_hp) {
        u16 final_hp = min(attacker->max_hp, attacker->hp + quality);
        b_move_damage = attacker->hp - final_hp;

        b_movescr_stack_push(b_movescr_cursor);
        b_movescr_cursor = pluck_heal_hp_script;
    }
}

void pluck_heal_status(u32* status, u32 mask, u8* sucess_script, bool upload) {
    if (*status & mask) {
        *status &= ~mask;

        if (upload) {
            b_active_side = b_attacker;
            dp01_build_cmdbuf_x02_a_b_varargs(
                0,
                REQ_BTL_STATUS,
                0,
                sizeof(*status),
                status
            );
            dp01_battle_side_mark_buffer_for_execution(b_attacker);
        }

        b_movescr_stack_push(b_movescr_cursor);
        b_movescr_cursor = sucess_script;
    }
}

void pluck_heal_all(struct battle_datum* attacker) {
    u8* bo_status;
    bool run_script = false;

    // the lack of else is very much intentional
    if (attacker->status1 && STATUS1_ANY) {
        if (attacker->status1 && STATUS1_PARALYSIS) {
            attacker->status1 &= ~STATUS1_PARALYSIS;
            bo_status = bo_paralysis;

        } if (attacker->status1 && STATUS1_PSN_ANY) {
            attacker->status1 &= ~STATUS1_PSN_ANY;
            bo_status = bo_poison;

        } if (attacker->status1 && STATUS1_BURN) {
            attacker->status1 &= ~STATUS1_BURN;
            bo_status = bo_burn;

        } if (attacker->status1 && STATUS1_SLEEP) {
            attacker->status2 &= ~STATUS2_NIGHTMARE;
            attacker->status1 &= ~STATUS1_SLEEP;
            bo_status = bo_sleep;
        }

        b_active_side = b_attacker;
        dp01_build_cmdbuf_x02_a_b_varargs(
            0,
            REQ_BTL_STATUS,
            0,
            sizeof(attacker->status1),
            &attacker->status1
        );
        dp01_battle_side_mark_buffer_for_execution(b_attacker);

        run_script = true;

    } if (attacker->status2 && STATUS2_CONFUSION) {
        attacker->status2 &= ~STATUS2_CONFUSION;
        bo_status = bo_confusion;
        run_script = true;

    } if (run_script) {
        strcpy_xFF_terminated(battle_outcome_A, bo_status);
        b_movescr_stack_push(b_movescr_cursor);
        b_movescr_cursor = all_heal_script;
    }
}

void pluck_flavor_hp(struct battle_datum* attacker, u8 flavor, u8 denominator) {
    if (dislikes_flavor(attacker->personality, flavor)) {
        PREPARE_FLAVOR_BUFFER(battle_outcome_A, flavor);
        b_movescr_stack_push(b_movescr_cursor);
        b_movescr_cursor = too_flavorful_script;
    }

    pluck_restore_hp(attacker, attacker->max_hp / denominator);
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

        switch(effect) {
            case HOLD_EFFECT_RESTORE_HP:
                pluck_restore_hp(attacker, quality);
                break;

            case HOLD_EFFECT_CURE_PAR:
                pluck_heal_status(&attacker->status1, STATUS1_PARALYSIS, parlyz_heal_script, true);
                break;

            case HOLD_EFFECT_CURE_PSN:
                pluck_heal_status(&attacker->status1, STATUS1_PSN_ANY, poison_heal_script, true);
                break;

            case HOLD_EFFECT_CURE_BRN:
                pluck_heal_status(&attacker->status1, STATUS1_BURN, burn_heal_script, true);
                break;

            case HOLD_EFFECT_CURE_SLP:
                attacker->status2 &= ~STATUS2_NIGHTMARE;
                pluck_heal_status(&attacker->status1, STATUS1_SLEEP, sleep_heal_script, true);
                break;

            case HOLD_EFFECT_CURE_CONFUSION:
                pluck_heal_status(&attacker->status2, STATUS2_CONFUSION, confusion_heal_script, false);
                break;

            case HOLD_EFFECT_CURE_ALL:
                pluck_heal_all(attacker);
                break;

            case HOLD_EFFECT_SPICY_HP:
            case HOLD_EFFECT_DRY_HP:
            case HOLD_EFFECT_SWEET_HP:
            case HOLD_EFFECT_BITTER_HP:
            case HOLD_EFFECT_SOUR_HP:
                pluck_flavor_hp(attacker, effect - HOLD_EFFECT_SPICY_HP, quality);
                break;
        }

        b_movescr_stack_push(b_movescr_cursor);
        b_movescr_cursor = pluck_move_eat_script;

        // *(u8*)((u8*)(&b_dp08_ptr->choicedMove[b_defender]) + 0) = 0;
        // *(u8*)((u8*)(&b_dp08_ptr->choicedMove[b_defender]) + 1) = 0;

        extra_battle_string = pXateYsZ;
    }
}