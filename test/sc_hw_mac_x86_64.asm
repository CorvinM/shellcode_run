BITS 64

_start:
    mov rax, 4     ; write
    mov rdi, 1
    lea rsi, [rel msg]
    mov rdx, msg_len
    syscall
exit:
    mov rdi, 0
    mov rax, 1     ; exit
    syscall
msg:
    db  `Hello Shellcode!\n`
msg_len: equ $ - msg