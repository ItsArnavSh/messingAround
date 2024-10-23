; We will make a simple print function, and then call it
section .data
    printThis db "Hello World",0
section .text
global _start

_start:
    call printer
    jmp exit
printer:
    mov rax,1
    mov rdi,1
    lea rsi,[printThis]
    mov rdx,5
    syscall
    ret
exit:
    mov rax,60
    xor rdi,rdi
    syscall
    ret
