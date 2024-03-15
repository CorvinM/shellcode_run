BITS 32

_start:
    mov eax, 4
    mov ebx, 1
    call _next
_next:
    pop ecx ; ecx = address of _next
    add ecx, msg - _next
    mov edx, msg_len
    int 0x80
exit:
    mov eax, 1
    mov ebx, 0
    int 0x80
msg:
    db  `Hello Shellcode!\n`
msg_len: equ $ - msg