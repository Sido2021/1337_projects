#include "ft_printf.h"

int ft_print_number(long n){
	int sign = 0;
	if(n < 0)
	{
		ft_put_char('-');
		n *= -1;
		sign++;
	}
	return(ft_print_number_to_base(n, 10, 0, 0) + sign);
}
