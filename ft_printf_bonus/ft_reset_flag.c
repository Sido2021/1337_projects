#include "ft_printf.h"

void ft_reset_flag(int *flags, char flag)
{
	if(flag == '-' )
		flags[1] = -1;
	else if(flag == '0' )
		flags[2] = -1;
	else if(flag == '.')
		flags[3] = -1;
	else if(flag == '#' )
		flags[4] = -1;
	else if(flag == ' ' )
		flags[5] = -1;
	else if(flag == '+')
		flags[6] = -1;
	else
		flags[0] = -1;
}