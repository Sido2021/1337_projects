#include "ft_printf.h"

void ft_put_char(char c){
	write(1, &c, 1);
}