#include "ft_printf.h"

char *ft_get_hex_number(unsigned int num, int *flags , int upper_case){
	int len = 0;
	int zeros = 0;

	len += ft_get_base_number_len(num, 16);
	if(ft_flags_contain(flags,'0') || ft_flags_contain(flags,'.')){
		int n = 0;
		if(ft_flags_contain(flags,'.'))
		{
			n = ft_get_flag_count(flags, '.');
			if(n == 0 && num == 0)
				return (ft_strdup(""));
		}
		else{
			n = ft_get_flag_count(flags, 'n');
			if(ft_flags_contain(flags,'#') && num != 0)
				len +=2 ;
		}
		if(len < n){
			zeros = n - len;
			len = n; 
		}
	}
	if(ft_flags_contain(flags,'.')){
		if(ft_flags_contain(flags,'#') && num != 0)
			len +=2 ;
		ft_reset_flag(flags, '.');
	} else if(!ft_flags_contain(flags,'0')){
		if(ft_flags_contain(flags,'#') && num != 0)
			len +=2 ;
	}
	
	char *str = malloc(len + 1);
	int i = 0;
	if(ft_flags_contain(flags,'#') && num != 0){
		str[i++] = '0';
		if(upper_case)
			str[i++] = 'X';
		else
			str[i++] = 'x';
	}
	while(zeros-- > 0)
		str[i++] = '0';
	str[len] = '\0';
	ft_fill_number_base(&str[len - 1], num, 16, upper_case);
	return (str);
}