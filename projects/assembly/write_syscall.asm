section .data
    msg db 'Hi', 0x0a
    msgLen equ $ - msg

section .text
    global _start

_start:
    ; TODO: Set up and call the write syscall to print msg
    ; Use rax=1, rdi=1, rsi=msg, rdx=msgLen
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msgLen
    syscall

    ; Exit the program
    mov rax, 60
    mov rdi, 0
    syscall