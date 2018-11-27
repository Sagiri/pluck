.macro bs_goto, addr
    .byte 0x28
    .word addr
.endmacro

.macro bs_setmoveeffect, effect
    .byte 0x2E
    .word effect_to_apply
    .byte effect
.endmacro

.macro bs_playanimation, bank, animation, var_address
    .byte 0x45
    .byte bank
    .byte animation
    .word var_address
.endmacro

.macro bs_printstring, stringid
    .byte 0x10
    .halfword stringid
.endmacro

.macro bs_waitmessage, delay_
    .byte 0x12
    .halfword delay_
.endmacro

.macro bs_return
	.byte 0x3c
.endmacro