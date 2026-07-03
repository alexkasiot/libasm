global ft_strdup

extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

section .text
ft_strdup:
	push rdi
	call ft_strlen
	inc rax
	mov rdi, rax
	call malloc
	test rax, rax
	jz .error
	mov rdi, rax
	mov rsi, [rsp]
	call ft_strcpy
	add rsp, 8
	ret
.error:	
	call __errno_location
	mov dword [rax], 12
	xor rax, rax
	add rsp, 8
	ret

section .note.GNU-stack noalloc noexec
