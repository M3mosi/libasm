				global _ft_list_remove_if						;ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()
				extern _free
				section .text									;t_list *current

_ft_list_remove_if:
				mov 	r8,				[rdi]					;r8 = current = *begin_list
				mov		r12,			rdi
cycle:
				cmp		r8,				0						;r8 = current != NULL
				je		retu
				mov		r9,				[r8 + 8]				;r9 = current->next
				cmp		r9,				0						;r9	= current->next != NULL
				je		retu									;
				push	rdi										;Push args
				push	rsi										;Push args
				push	rdx
				push	r8
				push	r9										;Push args
				push	r12
				mov		rdi,			[r9]					;*cmp(arg1 = current->next->data, arg2 = data_ref )
				call	rdx										;call to cmp(current,data_ref)
				pop		r12
				pop		r9
				pop		r8
				pop		rdx
				pop		rsi
				pop		rdi
				cmp		rax,			0						;!cmp(current,data_ref) ?
				je		remove									; : remove
moveon:
				mov 	r8,				r9						; current = current->next
				jmp		cycle									;
remove:
				mov		r10,			[r9]					; r10 = remove = current->next (to be removed)
				mov		r11,			[r9 + 8]				; r11 = current->next->next
				mov 	[r8 + 8],		r11						; current->next = current->next->next
				mov		r9,				r11						;r9 = current->next
				push	rdi
				push	rsi
				push	r8
				push	r9
				push	rdx
				push	r12
				mov		rdi,			r10						;free(arg1 = remove = current->next)
				call	_free
				pop		r12
				pop		rdx
				pop		r9
				pop		r8
				pop		rsi
				pop		rdi
				jmp		cycle
retu:
				mov 	r8,				[rdi]					;current = *begin_list
				cmp		r8,				 0						;!current ? exit : continue
				je		fret
				push	rdi
				push	rsi
				push	rdx
				push	r11
				push	r8
				push	r9
				push	r12
				mov		r9,				[r8]
				mov		rdi,			r9						;*cmp(arg1 = current->next->data, arg2 = data_ref )
				call	rdx
				pop		r12
				pop		r9
				pop		r8
				pop		r11
				pop		rdx
				pop		rsi
				pop		rdi										;call to cmp(current,data_ref)
				cmp		rax,			0
				jne		fret
				;jmp		fret
behead:
				mov		r9,				[r8 + 8]			;r9 = current->next
				mov		r10,			[r8]				;
				mov		[r8],			r9
				mov		rdi,				r10
				push	rdi
				push	rsi
				push	rdx
				push	r11
				push	r8
				push	r9
				push	r12
				call	_free
				pop		r12
				pop		r9
				pop		r8
				pop		r11
				pop		rdx
				pop		rsi
				pop		rdi										;call to cmp(current,data_ref)
				mov		[r12], r9

fret:
				ret
