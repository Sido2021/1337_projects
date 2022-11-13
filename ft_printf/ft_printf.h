#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
#include <stdarg.h>

int ft_printf(char const *s, ...);
void ft_put_char(char c);
int ft_put_string(char *s);
int ft_print_unsigned_number(unsigned long n);
int ft_print_number(long n);
int ft_print_number_to_base(unsigned long n, int base, int upper_case,int count);
int ft_print_hex_number(unsigned long n, int upper_case);
int ft_print_arg(char format, va_list vars);
int ft_print_adress(void *p);

#endif
