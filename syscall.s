%define SYS_WRITE			1
%define SYS_EXIT 			60
%define STDOUT				1


section .data
hello:
	.string db "Hello World!", 10, 0
	.len equ $ - hello.string

section .text
	global _start
	global main

_start:
	call main
	
	mov eax, SYS_EXIT
	xor edi, edi
	syscall

main:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	mov rdi, STDOUT
	lea rsi, [rel hello.string]
	mov rdx, hello.len
	mov rax, SYS_WRITE
	syscall

	leave
	ret
