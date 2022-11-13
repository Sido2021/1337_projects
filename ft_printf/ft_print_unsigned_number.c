#include "ft_printf.h"

int ft_print_unsigned_number(unsigned long n){
	return(ft_print_number_to_base(n, 10, 0, 0));
}