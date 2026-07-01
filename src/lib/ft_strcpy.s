global ft_strcpy

section .text
ft_strcpy:
	mov rax, rdi
.loop:
	mov dl, [rsi]
	mov [rdi], dl
	cmp dl, 0
	je .done
	inc rsi
	inc rdi
	jmp .loop
.done:
	ret

section .note.GNU-stack noalloc noexec
