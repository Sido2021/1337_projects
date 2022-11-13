#include "ft_printf.h"

int ft_print_hex_number(unsigned long n, int upper_case){
	return(ft_print_number_to_base(n, 16, upper_case, 0));
}