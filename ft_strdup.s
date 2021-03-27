    			global      _ft_strdup

				extern		_write
                extern      _malloc
                extern      _ft_strcpy
                extern      _ft_strlen

				section     .text
_ft_strdup:
                push        rdi
                call        _ft_strlen
                mov         rdi,        rax
                call        _malloc
                pop         rdi
                mov         rsi,        rdi
                mov         rdi,         rax
                call        _ft_strcpy
                ret

                