global ft_write

extern __errno_location

section .text
ft_write:
	mov rax, 1
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
