section .text
	global _start
	global _main

_start:
	call _main

	mov rax, 60
	xor rdi, rdi
	syscall

_main:
	ret