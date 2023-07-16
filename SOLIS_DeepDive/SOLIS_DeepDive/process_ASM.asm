; Name: SOLIS, Frances Danielle B.
; Section: S11

section .text
bits 64
default rel
global process_ASM

process_ASM:
    mov rcx, rax
    
    sum:
       ; sum operation
       mov rbx, [r8]
       add rbx, [r8 + 4]
       add rbx, [r8 + 8]
       add rbx, [r8 + 12]
       add rbx, [r8 + 16]
       add rbx, [r8 + 20]
       add rbx, [r8 + 24]

       mov [rdx], ebx
       add r8, 4
       add rdx, 4

    LOOP sum

    ret