.gba

.arm
.include "constants.s"

.thumb
.include "functions.s"

.loadtable "character-encoding.tbl"
.include "battlescript.s"

.open "test.gba", 0x08000000

.org allocation

.area allocation_size
    .importobj "obj/relocatable.o"

    .align 2

    case_eat_berry:
    @@main:
        ldr r3, =pluck |1
        bl @@call
        ldr r3, =0x0802110A |1
    @@call:
        bx r3

    faint_effects_hook:
    @@main:
        ldrb    r0, [r0, #3]
        cmp     r0, #EFFECT_PAYDAY
        beq     @@effect_continue
        cmp     r0, #EFFECT_STEAL_ITEM
        beq     @@effect_continue
        cmp     r0, #EFFECT_EAT_BERRY
        beq     @@effect_continue
        ldr r0, =0x08020042 |1
        bx r0
    @@effect_continue:
        ldr r0, =0x08020046 |1
        bx r0

    .pool

    // have to be in ARM mode for C code to directly access it
    .arm
        pluck_move_script:
            bs_setmoveeffect EFFECT_EAT_BERRY
            bs_goto hit_move_script

        pluck_move_eat_script:
            // bs_playanimation 0x0, 0x10, 0x0
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

        pXateYsZ: .string "\v\h0F ate\n\v\h10's \v\h16!"
    .thumb
.endarea

.org move_scripts + (PLUCK_MOVE_SCRIPTID) *4
.word pluck_move_script

.org jpt_80206D8 + (EFFECT_EAT_BERRY -7) *4
.word case_eat_berry

.org 0x08020038
.area 0xA, 0xFE
    ldr r3, =faint_effects_hook |1
    bx r3
    .pool
.endarea

.close