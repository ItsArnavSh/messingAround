int main(){
    int a = 10;
    return 0;
}
/*
; Disassembly of file: hello.o
; Sun Nov  3 09:33:48 2024
; Type: ELF64
; Syntax: NASM
; Instruction set: 8086, x64

default rel

global main: function


SECTION .text   align=1 exec                            ; section number 1, code

main:   ; Function begin
        endbr64                                         ; 0000 _ F3: 0F 1E. FA
        push    rbp                                     ; 0004 _ 55
        mov     rbp, rsp                                ; 0005 _ 48: 89. E5
        mov     dword [rbp-4H], 10                      ; 0008 _ C7. 45, FC, 0000000A
        mov     eax, 0                                  ; 000F _ B8, 00000000
        pop     rbp                                     ; 0014 _ 5D
        ret                                             ; 0015 _ C3
; main End of function


SECTION .data   align=1 noexec                          ; section number 2, data


SECTION .bss    align=1 noexec                          ; section number 3, bss


SECTION .note.gnu.property align=8 noexec               ; section number 4, const

        db 04H, 00H, 00H, 00H, 10H, 00H, 00H, 00H       ; 0000 _ ........
        db 05H, 00H, 00H, 00H, 47H, 4EH, 55H, 00H       ; 0008 _ ....GNU.
        db 02H, 00H, 00H, 0C0H, 04H, 00H, 00H, 00H      ; 0010 _ ........
        db 03H, 00H, 00H, 00H, 00H, 00H, 00H, 00H       ; 0018 _ ........


