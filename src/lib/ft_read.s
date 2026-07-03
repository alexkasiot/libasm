global ft_read

extern __errno_location

section .text
ft_read:
	mov rax, 0
	syscall
	test rax, rax
	js .error
	ret
.error:
	neg rax
	mov rdi, rax
	call __errno_location
	mov [rax], rdi
	mov rax, -1
	ret

section .note.GNU-stack noalloc noexec
