#include "ft_printf.h"

void ft_fill_number_base(char *str, unsigned long n, int base, int upper_case){
	if(n / base)
		ft_fill_number_base(str - 1, n / base, base, upper_case);
	if(base == 8){
		*str = "01234567"[n % base];
	}
	else if(base == 16)
	{
		if(!upper_case)
			*str = "0123456789abcdef"[n % base];
		else
			*str = "0123456789ABCDEF"[n % base];
	} else
		*str = n % base + 48;
}
