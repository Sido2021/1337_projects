#include "ft_printf.h"

char *ft_get_number(long num, int *flags){
	int sign = 1;
	int len = 0;
	int zeros = 0;
	if(num < 0)
	{
		num *= -1;
		sign = -1;
		len = 1;
	}
	else{
		if(ft_flags_contain(flags,' '))
			len++;
		if(ft_flags_contain(flags,'+'))
			len++;
	}
	len += ft_get_base_number_len(num, 10);
	if(ft_flags_contain(flags,'0') || ft_flags_contain(flags,'.')){
		int n = 0;
		if(ft_flags_contain(flags,'.'))
		{
			n = ft_get_flag_count(flags, '.');
			if(n == 0 && num == 0)
				len--;
			if(ft_flags_contain(flags,' '))
				n++;
			if(sign < 0 && !ft_flags_contain(flags,' '))
				n++;
			else if(ft_flags_contain(flags,'+'))
				n++;
			//this is because the put_string function will treat agean the string returned
			//by this function and we dont't want that when the number is negative
			//because the - sing will not counted, not like 0 flag.
			ft_reset_flag(flags, '.');
		}
		else
			n = ft_get_flag_count(flags, 'n');
		
		if(len < n){
			zeros = n - len;
			len = n;
		}
	}
	char *str = malloc(len + 1);
	int i = 0;
	if(sign < 0)
		str[i++] = '-';
	else{
		if(ft_flags_contain(flags,' '))
			str[i++] = ' ';
		if(ft_flags_contain(flags,'+'))
			str[i++] = '+';
	}
	while(zeros-- > 0)
		str[i++] = '0';
	str[len] = '\0';
	if(i < len)
		ft_fill_number_base(&str[len - 1], num, 10, 0);
	return(str);
}
