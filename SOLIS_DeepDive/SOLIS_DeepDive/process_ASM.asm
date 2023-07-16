; Name: SOLIS, Frances Danielle B.
; Section: S11

section .text
bits 64
default rel
global process_ASM

process_ASM:
    sub ECX, 6
    
    sum:
        ; init data
        xor RAX, RAX
        
        ; sum operation
        mov RAX, [R8]
        add RAX, qword[R8+8]
        add RAX, qword[R8+16]
        add RAX, qword[R8+24]
        add RAX, qword[R8+32]
        add RAX, qword[R8+40]
        add RAX, qword[R8+48]
        
        mov [RDX], RAX 
        
        ADD R8, 8
        ADD RDX, 8
        
    LOOP sum

    ret