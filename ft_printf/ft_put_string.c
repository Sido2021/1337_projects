#include "ft_printf.h"

int ft_put_string(char *s){
	int i = -1;
	if(!s)
		s = "(null)";
	while(s[++i])
		ft_put_char(s[i]);
	return (i);
}