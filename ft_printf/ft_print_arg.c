#include "ft_printf.h"

int ft_print_arg(char format, va_list vars){
	if(format == 'c'){
		ft_put_char(va_arg(vars, int));
		return(1);
	}
	else if(format == 's'){
		return (ft_put_string(va_arg(vars, char *)));
	}
	else if(format == 'd' || format == 'i'){
		return(ft_print_number(va_arg(vars, int)));
	}
	else if(format == 'p'){
		return(ft_print_adress(va_arg(vars, void *)));
	}
	else if(format == 'u'){
		return(ft_print_unsigned_number(va_arg(vars, unsigned int)));
	}
	else if(format == 'x' || format == 'X'){
		return(ft_print_hex_number((long)va_arg(vars, unsigned int), format == 'X'));
	}
	return(0);
}
