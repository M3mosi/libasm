                                           
                    global          _ft_list_size		 ;int		ft_list_size(t_list *lst);
					section         .text
_ft_list_size:
                    cmp             rdi,                0
                    je              err
                    mov             rax,                1
                    jmp             check_next
incr:
                    inc             rax
check_next:            
                    cmp             dword[rdi +8],      0
                    je              end
                    mov             rdi,                [rdi+8]
                    jmp             incr
err:           
                    mov             rax,                 0
end:
                    ret

