                global          _ft_list_sort       ; ft_list_sort(t_list **begin_list, int (*cmp)())
				section         .text               ; *cmp(lst->data, lst->next->data)
_ft_list_sort:
                push            rbx
                push            r12

		        cmp		        rdi, 0				; if list_begin == NULL
		        je		        return				; return
		        mov             r9, qword[rdi]		; r9 = *list_begin
		        mov             r10, rsi			; r10 = cmp

check:
		        mov		        rbx, qword[r9 + 8]	; rbx = rdi->next
		        cmp		        rbx, 0				; if list->next = NULL
		        je		        return				; return
		        push	        rdi					; save list_begin
		        push	        rsi					; save camp
		        mov		        rdi, qword[r9]			; rdi = rdi.data
		        mov		        rsi, qword[rbx]			; rsx = rbx.data
		        call	        r10					; call compare
		        pop		        rsi					; pop rsi
		        pop		        rdi					; pop rdi
		        cmp		        rax, 0				; if cmp > 0
		        jg		        sortme				; need to sort
		        jmp		        sorted				; else is sort

sortme:
		        mov		        r11, [r9]			; r11 = rdi->data
		        mov		        r12, [rbx]			; r12 = rdi->next->data
		        mov		        [r9], r12			; r9 = r11
		        mov		        [rbx], r11			; rbx = rdi->next->data
		        mov		        r9, [rdi]			; r9 = *begin_lst
		        jmp		        check				; jump to check

sorted:
		        mov		        r8, [r9 + 8]		; r8 = rdi->next
		        cmp		        r8, 0				; if rdi->next = NULL
		        je		        return				; return
		        mov		        r9, r8				; rdi = rdi->next
		        jmp		        check				; jump to check

return:
                pop             r12
                pop             rbx
		        ret							        ; return