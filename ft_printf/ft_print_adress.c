#include "ft_printf.h"

int ft_print_adress(void *p)
{
	ft_put_string("0x");
	return (ft_print_number_to_base((long long)p, 16, 0, 0) + 2);
}
