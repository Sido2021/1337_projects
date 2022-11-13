#include "ft_printf.h"
int ft_print_arg(char format, va_list vars, int *flags){
	if(format == 'c'){
		return(ft_put_char_presu(va_arg(vars, int), flags));
	}
	else if(format == 's'){
		return (ft_put_string(va_arg(vars, char *), flags));
	}
	else if(format == 'd' || format == 'i'){
		int num = va_arg(vars, int);
		char *s = ft_get_number(num, flags);
		int c = ft_put_string(s, flags);
		free(s);
		return (c);
	}
	else if(format == 'p'){
		char *s = ft_get_adress((unsigned long) va_arg(vars, void *));
		int c = ft_put_string(s, flags);
		free(s);
		return(c);
	}
	else if(format == 'u'){
		char *s = ft_get_unsigned_number(va_arg(vars, unsigned int), flags);
		int c = ft_put_string(s, flags);
		free(s);
		return (c);
	}
	else if(format == 'x' || format == 'X'){
		char *s = ft_get_hex_number(va_arg(vars, unsigned int), flags , format == 'X');
		int c = ft_put_string(s, flags);
		free(s);
		return(c);
	}
	else if(format == '%'){
		return(ft_put_char_presu('%', flags));
	}
	return(0);
}
