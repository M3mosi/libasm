            global      _ft_atoi_base           ;int	ft_atoi_base(char *str, char *base)
            section     .text

_ft_atoi_base:
            cmp         rdi,            0
            je          ret_err
            push        rcx
            push        rbx
            push        r9
            push        r10
            xor         rbx,            rbx     ;reset (userò bl per le comparazioni)
            mov         rcx,            1       ;sign
            xor         rax,            rax     ;n=0
            xor         r9,             r9      ;i = 0;
            jmp         base_check
incr:
            inc         r9
base_check:
            cmp         byte[rsi + r9], 0       ;\0 check
            je          endbcheck
            cmp         byte[rsi + r9], 33      ; if (base[i] < 33 || base[i] >127)
            jl          ret_err                 ;       return -1
            cmp         byte[rsi + r9], 127
            jg          ret_err
            mov         r10,            r9      ;j=i   
check_dup:
            inc         r10                     ;j++
            cmp         byte[rsi + r10],0
            je          incr
            cmp         byte[rsi + r10],45
            je          ret_err
            cmp         byte[rsi + r10],43        
            mov         bl,             byte[rsi + r10]
            cmp         bl,             byte[rsi + r9]
            je          ret_err
            jmp         check_dup
ret_err:
            pop        r10
            pop        r9
            pop        rbx
            pop        rcx
            mov        rax,            0
            ret
endbcheck:
            mov         r11,            r9      ;base lenght stored in r11        
            xor         r9,             r9      ;i=0
            jmp         skipspace
incr2:
            inc         r9
skipspace:   
            cmp         byte[rdi + r9], 0
            je          end_scheck 
            cmp         byte[rdi + r9], 9
            je          incr2
            cmp         byte[rdi + r9], 10
            je          incr2 
            cmp         byte[rdi + r9], 11
            je          incr2 
            cmp         byte[rdi + r9], 12
            je          incr2   
            cmp         byte[rdi + r9], 13
            je          incr2
            cmp         byte[rdi + r9], 32
            je          incr2
            jmp         checksign
incr_sign:
            inc         r9
checksign:
            cmp         byte[rdi + r9], '-'
            je          signchange
            cmp         byte[rdi + r9], '+'
            je          incr_sign
            mov         r10,            -1
            jmp         is_in_base
incr3:
            mov         r10,            -1
            inc         r9
is_in_base:
            cmp         byte[rdi + r9], 0
            je          end_scheck        
            inc         r10
            cmp         byte[rsi + r10],    0
            je          end_scheck;
            mov         bl,             byte[rsi+r10]
            cmp         bl,             byte[rdi + r9]
            je          get_n
            jmp         is_in_base
get_n:
            imul        rax,            r11
            add         rax,            r10
            jmp         incr3
end_scheck:
            imul        rax,            rcx
            pop        rcx
            pop        rbx
            pop        r9
            pop        r10
            ret
signchange:
            imul        rcx,            -1
            jmp         incr_sign
