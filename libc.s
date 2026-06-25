section .data
hello:
	.string db "Hello World!", 10, 0
	.len equ $ - hello.string

section .text
	global _start
	global main
	extern printf

_start:
	call main

	mov eax, 60
    xor edi, edi
    syscall

main:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	lea rdi, [rel hello.string]
	xor eax, eax
	call printf
	leave
	ret