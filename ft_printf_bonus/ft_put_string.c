#include "ft_printf.h"

int ft_put_string(char *s, int *flags){
	int i = 0;
	int strlen = 0;
	int count = 0;
	char *str ;
	if(s)
		str = ft_strdup(s);
	else
		str = ft_strdup("(null)");
	strlen = ft_strlen(str);

	if(ft_flags_contain(flags, '.'))
	{
		int n = ft_get_flag_count(flags, '.');
		if(n < strlen)
		{
			char *ss = ft_strdup(str);

			free(str);
			str = ft_substr(ss , 0, n);
			free(ss);
			strlen = n;
		}
	}
	if(!ft_flags_contain(flags, '-'))
	{
		int n = ft_get_flag_count(flags, 'n');
		
		/*if(ft_flags_contain(flags, '+')){
			n = ft_get_flag_count(flags, '+');
		}*/
		count = ft_put_nchar(' ', n - strlen);
	}
	while(str[i])
		ft_put_char(str[i++]);
	count +=i;
	if(ft_flags_contain(flags, '-')){
		count += ft_put_nchar(' ', ft_get_flag_count(flags, 'n') - strlen);
	}
	free(str);
	return (count);
}