;Prints the multiplication table for num
;Code to print a number to the standard output
section .data
    num dq 12345 ; Saved the number here
    length dq 0; This will save the space occupied by the numbers
    st db "         ",0; The string where the number will be saved
    multiply db "X",0
    equals db "=",0
    newLine db 10,0
section .text
    global _start

_start:
xor r14,r14
inc r14
mov r9,[num];Now r9 contains the word
mov r10,r9
multiplication:
mov qword [num],r9
push r10
push r9

;First we print the operand
call beginPrinting

pop r9
pop r10
mov rax,1
mov rdi,1
lea rsi,multiply
mov rdx,1
syscall
mov qword [num],r14
push r10
push r9

call beginPrinting

pop r9
pop r10
mov rax,1
mov rdi,1
lea rsi,equals
mov rdx,1
syscall
mov [num],r10
push r10
push r9

call beginPrinting

pop r9
pop r10
inc r14
add r10,r9
cmp qword r14,11
;Now lets add a new line
mov rax,1
mov rdi,1
lea rsi,newLine
mov rdx,1
syscall


jne multiplication
je exit
; So first of all, lets add a number to dq
beginPrinting:
;Prereq before starting the procedure
mov rbx,10 ;Added 10,for division
mov rax,[num]
xor rcx,rcx
xor rdx,rdx
xor r10,r10
xor r9,r9

numToStr:
xor rdx, rdx
div rbx ;Divide `rax` by `rbx`, quotient in `rax`, remainder in `rdx`
add dl,'0'
mov byte [st+rcx],dl
inc rcx
cmp rax,0
jg numToStr
call lenFinder
call reverse
call printer
call clearStr
ret


reverse:

;Lets reverse it insitu, making the shit fkin hard
xor r10,r10

mov r10, [length]
;mov r10,4
mov rax,r10;This will start from the end

mov rbx,2
xor rdx,rdx
div rbx; Now rax is the center

xor r9,r9;This will start from the start
inc rax

rev_loop:
mov byte dl,[st+r9]
mov byte cl,[st+r10]
mov byte [st+r9],cl
mov byte [st+r10],dl
inc r9
dec r10
cmp rax,r9
jne rev_loop
mov r13, [length]
mov rsi,st
mov byte [rsi+r13+1] ,0x00
ret
lenFinder:
xor rdx,rdx
minilabel:
mov rax, [st+rdx]
inc rdx
cmp al," "
jne minilabel
je done

done:
mov [length],rdx
ret


printer:

    mov rax,1
    mov rdi,1
    lea rsi,[st]
    mov rdx,9
    syscall

    ret
clearStr:;This will set the string to 0
mov byte st[0],32
mov byte st[1],32
mov byte st[2],32
mov byte st[3],32
mov byte st[4],32
mov byte st[5],32
mov byte st[6],32
mov byte st[7],32
mov byte st[8],32
mov qword [length],0
ret


printLen:
    mov rax,1
    mov rdi,1
    lea rsi,[length]
    mov rdx,1
    syscall
    ret
exit:
    mov rax,60
    xor rdi,rdi
    syscall
    ret
