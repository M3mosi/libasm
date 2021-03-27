				global      _ft_strcpy
				;extern		_write
				section     .text
_ft_strcpy:
				xor			rcx, 				rcx ;cleaning registers
				xor			rdx,				rdx	
				cmp			rsi,				0	;!rsi?
				jz			end						;-1
				jmp			copy
increment: 		
				inc			rcx
copy:
				mov			dl,					byte[rsi + rcx]
				mov			byte[rdi + rcx],	dl
				cmp			dl,					0
				jnz			increment
end:
				mov			rax,				rdi
				ret