#include "ft_printf.h"

int ft_get_flag_count(int *flags, char flag)
{
	if(flag == '-' )
		return (flags[1]);
	else if(flag == '0' )
		return (flags[2]);
	else if(flag == '.')
		return (flags[3]);
	else if(flag == '#' )
		return (flags[4]);
	else if(flag == ' ' )
		return (flags[5]);
	else if(flag == '+')
		return (flags[6]);
	else
		return (flags[0]);
}