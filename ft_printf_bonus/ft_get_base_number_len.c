#include "ft_printf.h"

int ft_get_base_number_len(unsigned long n, int base)
{
	int count = 1;
	while(n / base){
		n /= base;
		count++;
	}
	return(count);
}