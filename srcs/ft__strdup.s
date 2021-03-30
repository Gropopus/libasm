global	ft__strdup
extern	malloc
extern	ft__strlen
extern	ft__strcpy

ft__strdup:
	mov	rax, 0		;init return value
	mov	rbx, 0		;init str

	cmp	rdi, 0		;if src == NULL
	je	null_str	;got to null_str to quit

	call	ft__strlen	;put the length of src in rax
	inc	rax		;add +1 for the '\0' 

	mov	rbx, rdi	;copy the src in rbx
	mov	rdi, rax	;copy src length

	call	malloc		;malloc
	cmp	rax, 0		;if allocation failed, rax is 0
	je	null_str	;go to null_str

	mov	rsi, rbx	;copy srcs (rbx) in the rsi register (used for string movements)
	mov	rdi, rax
	call	ft__strcpy
	ret
	
null_str:
	mov	rax, 0		; return NULL
	ret
