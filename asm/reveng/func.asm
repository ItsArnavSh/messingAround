; Disassembly of file: func.o
; Sun Nov  3 09:42:25 2024
; Type: ELF64
; Syntax: NASM
; Instruction set: 8086, x64

default rel

global func: function
global main: function


SECTION .text   align=1 exec                            ; section number 1, code

func:   ; Function begin
        endbr64                                         ; 0000 _ F3: 0F 1E. FA
        push    rbp                                     ; 0004 _ 55
        mov     rbp, rsp                                ; 0005 _ 48: 89. E5
        mov     dword [rbp-4H], edi                     ; 0008 _ 89. 7D, FC
        mov     eax, dword [rbp-4H]                     ; 000B _ 8B. 45, FC
        add     eax, eax                                ; 000E _ 01. C0
        pop     rbp                                     ; 0010 _ 5D
        ret                                             ; 0011 _ C3
; func End of function

main:   ; Function begin
        endbr64                                         ; 0012 _ F3: 0F 1E. FA
        push    rbp                                     ; 0016 _ 55
        mov     rbp, rsp                                ; 0017 _ 48: 89. E5
        sub     rsp, 16                                 ; 001A _ 48: 83. EC, 10
        mov     dword [rbp-8H], 5                       ; 001E _ C7. 45, F8, 00000005
        mov     eax, dword [rbp-8H]                     ; 0025 _ 8B. 45, F8
        mov     edi, eax                                ; 0028 _ 89. C7
        call    func                                    ; 002A _ E8, 00000000(PLT r)
        mov     dword [rbp-4H], eax                     ; 002F _ 89. 45, FC
        mov     eax, 0                                  ; 0032 _ B8, 00000000
        leave                                           ; 0037 _ C9
        ret                                             ; 0038 _ C3
; main End of function


SECTION .data   align=1 noexec                          ; section number 2, data


SECTION .bss    align=1 noexec                          ; section number 3, bss


SECTION .note.gnu.property align=8 noexec               ; section number 4, const

        db 04H, 00H, 00H, 00H, 10H, 00H, 00H, 00H       ; 0000 _ ........
        db 05H, 00H, 00H, 00H, 47H, 4EH, 55H, 00H       ; 0008 _ ....GNU.
        db 02H, 00H, 00H, 0C0H, 04H, 00H, 00H, 00H      ; 0010 _ ........
        db 03H, 00H, 00H, 00H, 00H, 00H, 00H, 00H       ; 0018 _ ........


