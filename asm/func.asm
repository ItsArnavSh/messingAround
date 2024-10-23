section .data ;line 1
    msg db  "Sum is: "
    len equ $ - msg

section .bss
    num1 resb 1
    eol1 resb 1
    num2 resb 1
    eol2 resb 1
    sum resb 2

section .text
global _start

print_int:
    mov eax, 4  ;defining routine print_int
    mov ebx, 1  ;file descriptor (stdout)
    int 0x80    ;system call number (sys_write)
    ret     ;return back

_start:
    ;Read and store user input for num1
mov eax, 3
mov ebx, 0
mov ecx, num1
mov edx, 2  ;2 bytes of info
int 80h

mov byte [eol1], 0xA ; value of first end of line

;Read and store user input for num2
mov eax, 3
mov ebx, 0
mov ecx, num2
mov edx, 2  ;2 bytes of info
int 80h

mov byte [eol2], 0xA ;value of 2nd end of line

;Add num1 and  num2
mov eax, num1
sub eax, '0'    ;this is so that the value in 3 is set to 3 because
        ;'3' and '0' actually are ASCII values
mov ebx, num2
sub ebx, '0'
add eax, ebx    ;Move the sum of 0x3 and 0x4 into eax
add eax, '0'    ;Set eax to be the ASCII value for the result of the sum


mov [sum], eax  ;Set this ascii value of the sum to sum

mov ecx, msg    ;Move msg ('Sum is: ') into eax
mov edx, len    ;Move len (length of msh) into edx
call print_int  ; call routine print_int above

;load sum to to be printed
mov ecx, sum
mov edx, 2 ;size in bytes of sum
call print_int


mov eax, 1  ;system call number (sys_exit)
xor ebx, ebx
int 0x80    ;line 43
