; Name: SOLIS, Frances Danielle B.
; Section: S11

section .text
bits 64
default rel
global process_SIMD_ASM

process_SIMD_ASM:
    shr ECX, 2
    
    xor EBX, EBX
    
    sum:
        ; init data
        vxorps YMM1, YMM1
        
        ; sum operation
        vmovdqu YMM1, [R8D]
        vaddpd YMM1, YMM1, [R8D+8]
        vaddpd YMM1, YMM1, [R8D+16]
        vaddpd YMM1, YMM1, [R8D+24]
        vaddpd YMM1, YMM1, [R8D+32]
        vaddpd YMM1, YMM1, [R8D+40]
        vaddpd YMM1, YMM1, [R8D+48]
        
        vmovdqu [EDX], YMM1
        
        ADD R8D, 32
        
        ADD EDX, 32
        
    LOOP sum

    ret