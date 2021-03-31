	global ft__strlen

ft__strlen:
	mov	rax, 0			;initialize value (i = 0)
	cmp	rdi, 0
	je	exit
	jmp	while			;go to the loop

while:
	cmp	BYTE[rdi + rax], 0	; if str + i == '\0'
	je	exit			; jump to exit
	inc	rax			; i++;
	jmp	while			; go back to while (loop)

exit:
	ret				; return
