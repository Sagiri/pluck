pluck_move_script:
    bs_setmoveeffect EFFECT_EAT_BERRY
    bs_goto hit_move_script

pluck_move_eat_script:
    bs_setword extra_battle_string, pXateYsZ
    bs_printstring EXTRA_BATTLE_STRINGID
    bs_waitmessage 0x40
    bs_return

pluck_heal_hp_script:
    bs_playanimation 0x1, 0x7, 0x0
    bs_printstring 0x12A
    bs_waitmessage 0x40
    bs_orword 0x2023DD0, 0x100
    bs_healthbarupdate 0x1
    bs_datahpupdate 0x1
    bs_return

parlyz_heal_script:
    bs_playanimation 0xA, 0x7, 0x0
    bs_printstring 0x123
    // intentional fallthrough

heal_status_script:
    bs_waitmessage 0x40
    bs_updatestatusicon 0xA
    bs_return

poison_heal_script:
    bs_playanimation 0xA, 0x7, 0x0
    bs_printstring 0x124
    bs_goto heal_status_script

burn_heal_script:
    bs_playanimation 0xA, 0x7, 0x0
    bs_printstring 0x125
    bs_goto heal_status_script

freeze_heal_script:
    bs_playanimation 0xA, 0x7, 0x0
    bs_printstring 0x126
    bs_goto heal_status_script

sleep_heal_script:
    bs_playanimation 0xA, 0x7, 0x0
    bs_printstring 0x127
    bs_goto heal_status_script

confusion_heal_script:
    bs_playanimation 0xA, 0x7, 0x0
    bs_printstring 0x128
    bs_goto heal_status_script

all_heal_script:
    bs_playanimation 0xA, 0x7, 0x0
    bs_printfromtable 0x083FE634
    bs_goto heal_status_script

too_flavorful_script:
    bs_printstring 0x144
    bs_waitmessage 0x40
    bs_setmoveeffect 0x47       // confuses user
    bs_return

stat_buff_script:
    bs_playanimation 0x1, 0x7, 0x0
    bs_statbuffchange 0x41, 0x81D9686
    bs_setbyte 0x02023E87, 0x4
    bs_call 0x081D6BD1
    bs_return

crit_rate_buff_script:
    bs_playanimation 0x1, 0x7, 0x0
    bs_printstring 0x146
    bs_waitmessage 0x40
    bs_return

pp_restore_script:
    bs_playanimation 0x1, 0x7, 0x0
    bs_printstring 0x12B
    bs_waitmessage 0x40
    bs_return

pXateYsZ: .string "\v\h0F ate\n\v\h10's \v\h16!"