#include "ft_printf.h"

int ft_put_nchar(char c, int n){
	int i = 0;
	while(n-- > 0)
	{
		ft_put_char(c);
		i++;
	}
	return(i);
}