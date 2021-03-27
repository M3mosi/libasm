            global      _ft_read
            extern      ___error
            section     .text
_ft_read:  
            mov         r9,     rdx           
            mov         rax,    0x02000003  ;syscall per leggere
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