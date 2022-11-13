#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list vars;
	int count = 0;

	va_start(vars, s);
	while(*s)
	{
		if(*s == '%'){
			s++;
			if(*s == '%'){
				ft_put_char(*s);
				count++;
			}
			else
				count += ft_print_arg(*s, vars);
		}
		else{
			ft_put_char(*s);
			count++;
		}
		s++;
	}

	va_end(vars);
	return (count);
}
