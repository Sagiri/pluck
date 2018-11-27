// https://github.com/devkitpro/gcc/blob/master/libgcc/config/arm/lib1funcs.S
// License at: https://github.com/devkitPro/gcc/blob/master/COPYING

// Necessary for compiling large switches with -Os
// TODO: Locate in ROM or find out how to remove call to it.

__gnu_thumb1_case_uqi:
    push {r1}
    mov r1, lr
    lsr r1, r1, #1
    lsl r1, r1, #1
    ldrb r1, [r1, r0]
    lsl r1, r1, #1
    add lr, r1
    pop {r1}
    bx lr