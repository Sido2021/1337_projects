#include "ft_printf.h"

int ft_print_number_to_base(unsigned long n, int base, int upper_case,int count){
	if(n / base)
		count += ft_print_number_to_base(n / base, base, upper_case, count);
	if(base == 8){
		ft_put_char("01234567"[n % base]);
		return (count + 1);
	}
	else if(base == 16)
	{
		if(!upper_case)
			ft_put_char("0123456789abcdef"[n % base]);
		else
			ft_put_char("0123456789ABCDEF"[n % base]);
		return (count + 1);
	} else {
		ft_put_char(n % base + 48);
		return (count + 1);
	}
	return(count);
}
