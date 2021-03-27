        global      _ft_strlen
        section     .text

_ft_strlen:
        mov         r9, -1

lopo:   
        inc         r9
        mov         r11b, byte [rdi +r9]
        cmp         r11b, 0
        jne         lopo
        mov         rax, r9
        ret