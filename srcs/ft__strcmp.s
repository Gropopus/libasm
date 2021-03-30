global ft__strcmp

ft__strcmp:
	mov	rax, 0			;init return value
        cmp     rdi, 0          	;if dest == NULL return (rax = 0) 0    
        je	finish_zero
        cmp     rsi, 0          	;if src == NULL return 0
        je	finish_zero

while:
	mov	al, byte [rdi]		;put -> s1[i] in char c
	mov	bl, byte [rsi]		;put -> s2[i] in char d 
	cmp	al, 0			;if s1[i] == '\0'
	je	finish			;go to exit
	cmp	al, bl			;if al != bl (s1[i] != 2[i])
	jne	finish
	inc	rdi			;s1++
	inc	rsi			;s2++
	jmp	while			;back to the begening (loop)


finish_zero:
	ret

finish:
	sub	al, bl
	mov	cl, al
	movsx	rax, cl
	ret
