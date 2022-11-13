#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

int ft_printf(char const *s, ...);
void ft_put_char(char c);
int ft_put_nchar(char c, int n);
int ft_print_arg(char format, va_list vars, int *flags);
int ft_put_char_presu(char c, int *flags);
int ft_put_string(char *s, int *flags);
char *ft_get_number(long num, int *flags);
void ft_fill_number_base(char *str, unsigned long n, int base, int upper_case);
int ft_get_base_number_len(unsigned long n, int base);
char *ft_get_adress(unsigned long n);
char *ft_get_unsigned_number(unsigned int num, int *flags);
char *ft_get_hex_number(unsigned int num, int *flags, int upper_case);
int ft_flags_contain(int *flags, char flag);
char *ft_get_string(char *s, int *flags);
int ft_get_flag_count(int *flags, char flag);
void ft_reset_flag(int *flags, char flag);

#endif
