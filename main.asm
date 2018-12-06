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
        cmp     r0, #AFTEREFFECT_PAYDAY
        beq     @@aftereffect_continue
        cmp     r0, #AFTEREFFECT_STEAL_ITEM
        beq     @@aftereffect_continue
        cmp     r0, #AFTEREFFECT_EAT_BERRY
        beq     @@aftereffect_continue
        ldr r0, =0x08020042 |1
        bx r0
    @@aftereffect_continue:
        ldr r0, =0x08020046 |1
        bx r0

    .pool

    // have to be in ARM mode for C code to directly access it
    .arm
    .include "scripts.asm"
    .thumb
.endarea

.org move_scripts + (PLUCK_MOVE_SCRIPTID) *4
.word pluck_move_script

.org jpt_80206D8 + (AFTEREFFECT_EAT_BERRY -7) *4
.word case_eat_berry

.org 0x08020038
.area 0xA, 0xFE
    ldr r3, =faint_effects_hook |1
    bx r3
    .pool
.endarea

.close