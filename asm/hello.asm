section .data
    nl db 10            ; Newline character

section .text
    global _start

_start:
    mov rcx, 65         ; Starting ASCII value for 'A'
    mov r9, 90          ; Upper limit ASCII value for 'Z'

loop_label:
    ; Print the current character (ASCII)
    mov rdi, 1          ; File descriptor (stdout)
    mov rsi, rcx        ; Load the current ASCII value to print
    mov rdx, 1          ; Number of bytes to write (1 byte)
    syscall             ; Perform the syscall to write

    ; Print a newline character
    mov rdi, 1          ; File descriptor (stdout)
    lea rsi, [nl]       ; Load the address of newline
    mov rdx, 1          ; Number of bytes to write (1 byte)
    syscall             ; Perform the syscall to write newline

    inc rcx             ; Increment rcx
    cmp rcx, r9         ; Compare rcx with the upper limit
    jle loop_label      ; Jump back to loop_label if rcx <= 90

    ; Exit the program
    mov rax, 60         ; Exit syscall number
    xor rdi, rdi        ; Exit code 0
    syscall
