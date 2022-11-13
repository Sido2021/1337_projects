#include "ft_printf.h"

int ft_flags_contain(int *flags, char flag){
	return (ft_get_flag_count(flags, flag) != -1);
}