global ft_strcmp

section .text
ft_strcmp:
	xor rax, rax
.loop:
	mov al, [rdi]	
	mov dl, [rsi]
	cmp al, dl
	jne .done

	cmp al, 0
	je .done

	inc rdi
	inc rsi
	jmp .loop
.done:
	movzx eax, al
	movzx edx, dl
	sub eax, edx
	ret

section .note.GNU-stack noalloc noexec
