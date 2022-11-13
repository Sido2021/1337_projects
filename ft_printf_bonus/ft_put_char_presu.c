#include "ft_printf.h"

int ft_put_char_presu(char c, int *flags){
	int count = 0;
	int n = 0;
	if(!ft_flags_contain(flags, '-'))
	{
		n = ft_get_flag_count(flags, 'n');
		/*if(ft_flags_contain(flags, '+')){
			n = ft_get_flag_count(flags, '+');
		}*/
		count = ft_put_nchar(' ', n - 1);
	}
	ft_put_char(c);
	count++;
	if(ft_flags_contain(flags, '-'))
	{
		n = ft_get_flag_count(flags, 'n');
		count += ft_put_nchar(' ', n - 1);
	}
	return(count);
}