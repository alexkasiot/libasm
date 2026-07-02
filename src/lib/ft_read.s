global ft_read

section .text
ft_read:
	mov rax, 0
	syscall
	ret

section .note.GNU-stack noalloc noexec
