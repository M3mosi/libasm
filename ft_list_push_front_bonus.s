					global              _ft_list_push_front		; int ft_list_push_front(t_list **begin_list, void *data)
					extern				_malloc					;

					section             .text
_ft_list_push_front:												
					push				rdi						; Saving to Ram **begin_list && *data
					push				rsi						
					push 				rbx
					mov					rdi, 			16		; sizeof(int)
					call				_malloc					; malloc(16)
					pop 				rbx
					pop					rsi						
					pop					rdi						
					cmp					rax,			0		; if ret == NULL
					je					end						; then return
					mov					[rax],			rsi		; newlst = data
					mov					rcx,			[rdi]	;
					mov					[rax+8],		rcx		; lst->next = list_start
					mov					[rdi],			rax		; list_start = lst
end:
					ret