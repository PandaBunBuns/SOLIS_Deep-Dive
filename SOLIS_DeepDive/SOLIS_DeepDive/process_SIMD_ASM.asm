; Name: SOLIS, Frances Danielle B.
; Section: S11

section .text
bits 64
default rel
global process_SIMD_ASM

process_SIMD_ASM:
    shr rcx, 3 
    
    sum:
        ; init data
        vxorps ymm1, ymm1
        
        ; sum operation
        vmovdqu ymm1, [r8]
        vaddpd ymm1, ymm1, [r8+8]
        vaddpd ymm1, ymm1, [r8+16]
        vaddpd ymm1, ymm1, [r8+24]
        vaddpd ymm1, ymm1, [r8+32]
        vaddpd ymm1, ymm1, [r8+40]
        vaddpd ymm1, ymm1, [r8+48]
        
        vmovdqu [rdx], ymm1
        
        add r8, 32
        add rdx, 32
        
    LOOP sum

    ret