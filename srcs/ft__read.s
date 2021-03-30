global		ft__read
extern		__errno_location

ft__read:
	mov	rax, 0			;initialization
	syscall				;-> read() return value stocked in rax
	cmp	rax, 0			;if ret < 0 then
	jl	quit			;go to quit fonction to handle errno error code and return -1
	ret				; everything went well, rax contains size of read

quit:
	mov	rcx, rax		;stock rax into rcx to keep read returned value
	call	__errno_location	;call errno
	neg	rcx			;rcx * -1 = errno code
	mov	[rax], rcx		;stock error code in the errno address
	mov	rax, -1			;read return -1 in case of error
	ret				;return rax (-1)
