            global      _ft_write
            extern      ___error
            section     .text
_ft_write:  
            cmp         rsi,    0
            je          err
            mov         r9,     rdx
            mov         rax,    0x02000004  ;syscall per writare
            syscall
            jc          err
            jmp         end
err:
            push        rax
            call        ___error
            pop         r9
            mov         [rax],  r9
            mov         rax,    -1
            ret
end:  
            mov         rax,    r9
            ret