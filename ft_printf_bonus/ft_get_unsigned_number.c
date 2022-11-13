#include "ft_printf.h"

char *ft_get_unsigned_number(unsigned int num, int *flags){
	int len;
	int zeros = 0;

	len = ft_get_base_number_len(num, 10);
	if(ft_flags_contain(flags,'0') || ft_flags_contain(flags,'.')){
		int n = 0;
		if(ft_flags_contain(flags,'.'))
		{
			n = ft_get_flag_count(flags, '.');
			if(n == 0 && num == 0)
				return (ft_strdup(""));
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
	while(zeros--)
		str[i++] = '0';
	str[len] = '\0';
	ft_fill_number_base(&str[len - 1], num, 10, 0);
	return(str);
}