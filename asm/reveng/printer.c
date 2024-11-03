#include <stdio.h>
int main(){
    printf("Hello World");
    return 0;
}
/*
; Disassembly of file: printer.o
; Sun Nov  3 09:35:18 2024
; Type: ELF64
; Syntax: NASM
; Instruction set: 8086, x64

default rel

global main: function

extern printf                                           ; near


SECTION .text   align=1 exec                            ; section number 1, code

main:   ; Function begin
        endbr64                                         ; 0000 _ F3: 0F 1E. FA
        push    rbp                                     ; 0004 _ 55
        mov     rbp, rsp                                ; 0005 _ 48: 89. E5
        lea     rax, [rel ?_001]                        ; 0008 _ 48: 8D. 05, 00000000(rel)
        mov     rdi, rax                                ; 000F _ 48: 89. C7
        mov     eax, 0                                  ; 0012 _ B8, 00000000
        call    printf                                  ; 0017 _ E8, 00000000(PLT r)
        mov     eax, 0                                  ; 001C _ B8, 00000000
        pop     rbp                                     ; 0021 _ 5D
        ret                                             ; 0022 _ C3
; main End of function


SECTION .data   align=1 noexec                          ; section number 2, data


SECTION .bss    align=1 noexec                          ; section number 3, bss


SECTION .rodata align=1 noexec                          ; section number 4, const

?_001:                                                  ; byte
        db 48H, 65H, 6CH, 6CH, 6FH, 20H, 57H, 6FH       ; 0000 _ Hello Wo
        db 72H, 6CH, 64H, 00H                           ; 0008 _ rld.


SECTION .note.gnu.property align=8 noexec               ; section number 5, const

        db 04H, 00H, 00H, 00H, 10H, 00H, 00H, 00H       ; 0000 _ ........
        db 05H, 00H, 00H, 00H, 47H, 4EH, 55H, 00H       ; 0008 _ ....GNU.
        db 02H, 00H, 00H, 0C0H, 04H, 00H, 00H, 00H      ; 0010 _ ........
        db 03H, 00H, 00H, 00H, 00H, 00H, 00H, 00H       ; 0018 _ ........


