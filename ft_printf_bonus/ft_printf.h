/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:51:15 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/19 21:05:23 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(char const *s, ...);
void	ft_put_char(char c);
int		ft_put_nchar(char c, int n);
int		ft_print_arg(char format, va_list vars, int *flags);
int		ft_put_char_presu(char c, int *flags);
int		ft_put_string(char *s, int *flags);
char	*ft_get_number(long num, int *flags);
void	ft_fill_number_base(char *str, unsigned long n, int b, char x);
int		ft_get_base_number_len(unsigned long n, int base);
char	*ft_get_adress(unsigned long n);
char	*ft_get_unsigned_number(unsigned int num, int *flags);
char	*ft_get_hex_number(unsigned int num, int *flags, char x);
int		ft_flags_contain(int *flags, char flag);
int		ft_get_flag_count(int *flags, char flag);
void	ft_reset_flag(int *flags, char flag);
int		ft_get_flag_index(char c);
void	ft_clean_flags(int *flags);
int		ft_get_number_and_load_steps(const char *s, int *to);
char	*ft_malloc_plus(int len);
void	ft_calculate_zeros(int *flags, long num, int *len, int *zeros);

#endif
