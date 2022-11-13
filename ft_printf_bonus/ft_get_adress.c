#include "ft_printf.h"
 
char *ft_get_adress(unsigned long n)
{
	int len = 2;

	if(n < 0)
		n *= -1;
	len += ft_get_base_number_len(n, 16);
	char *str = malloc(len + 1);
	str[0] = '0';
	str[1] = 'x';
	str[len] = '\0';
	ft_fill_number_base(&str[len - 1], n, 16, 0);
	return (str);
}