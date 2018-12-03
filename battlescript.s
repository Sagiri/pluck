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

.macro bs_call, address
	.byte 0x41
	.word address
.endmacro

.macro bs_orword, pointer, value
	.byte 0x35
	.word pointer
	.word value
.endmacro

.macro bs_healthbarupdate, bank
	.byte 0x0b
	.byte bank
.endmacro

.macro bs_datahpupdate, bank
	.byte 0x0c
	.byte bank
.endmacro

.macro bs_updatestatusicon, battler
	.byte 0x98
	.byte battler
.endmacro