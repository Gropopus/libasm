global ft__strcpy

ft__strcpy:
	mov	rax, 0		;init counter

check_null:
        cmp     rdi, 0          ;if dest == NULL got to null    
        je      null
        cmp     rsi, 0          ;if src == NULL got to null
        je      null

while:
	mov	dl, byte [rsi + rax]	;put char in a buff[0]
	mov	byte [rdi + rax], dl	;dst[i] -> buff[0]
	cmp	dl, 0			;if buffer = 0 --> got to finish
	je	finish
	inc	rax			;i++;
	jmp	while			;back to the beginning of while (loop)

null:
	mov	rax, 0			;return NULL
	ret

finish:
	mov	rax, rdi		;->return dst
	ret
