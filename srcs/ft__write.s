global		ft__write
extern		__errno_location

ft__write:
	mov	rax, 1			;initalization
	syscall				;call write() function result is stocked in rax
	cmp	rax, 0			;if the returned value is lower than 0 then
	jl	finish			;go to finish
	je	end			;if we reach here, everything went well so ->go to end

end:
	mov	rax, rdx		;put the size to write in rax
	ret				;return

finish:
	mov	rcx, rax		;to keep the return value of write (rax), a copy is made in rcx
	call	__errno_location	;call errno to give the error code
	neg	rcx			;rcx * -1 = error code to stock in errno address
	mov	[rax], rcx		;stock the error code to errno address location
	mov	rax, -1			;write has to return -1 in case of error.
	ret				;return rax = -1
