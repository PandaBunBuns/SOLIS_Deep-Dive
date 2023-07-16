; Name: SOLIS, Frances Danielle B.
; Section: S11

section .text
bits 64
default rel
global process_SIMD_ASM

process_SIMD_ASM:
    shr ECX, 2
    
    xor RBX, RBX
    
    sum:
        ; init data
        vxorps YMM1, YMM1
        
        ; sum operation
        vmovdqu YMM1, [R8]
        vaddpd YMM1, YMM1, [R8+8]
        vaddpd YMM1, YMM1, [R8+16]
        vaddpd YMM1, YMM1, [R8+24]
        vaddpd YMM1, YMM1, [R8+32]
        vaddpd YMM1, YMM1, [R8+40]
        vaddpd YMM1, YMM1, [R8+48]
        
        vmovdqu [RDX], YMM1
        
        ADD R8, 32
        
        ADD RDX, 32
        
    LOOP sum

    ret