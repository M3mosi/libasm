				global		_ft_strcmp
				section		.text
_ft_strcmp:
				push		r8
				push		rbx
				mov			r8,		-1
				xor			rbx,	rbx
				xor			rax,	rax

loop:			
				inc			r8
				mov			al,		byte[rdi + r8]
				mov			bl,		byte[rsi + r8]
				cmp			al, 	0
				je 			fine
				cmp			bl,		0
				je			fine
				cmp			al,		bl
				je 			loop
fine:					
				sub			rax,	rbx
				pop			rbx
				pop			r8
				ret	

					