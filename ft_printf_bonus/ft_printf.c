/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:38:44 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/20 20:17:16 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_digit_or_flag(char c)
{
	return (c == '-' || c == '.' || c == '#'
		|| c == ' ' || c == '+' || ft_isdigit(c));
}

int	ft_fill_flags(const char *s, int *flags)
{
	int	to;
	int	i;
	int	index;

	ft_clean_flags(flags);
	i = 0;
	while (is_digit_or_flag(*s))
	{
		index = ft_get_flag_index(*s);
		flags[index] = 0;
		if (index && index != ft_get_flag_index('.') && s++ && ++i)
			continue ;
		if (index == ft_get_flag_index('.') && s++)
			i++;
		flags[index] = ft_get_number_and_load_steps(s, &to);
		s += to;
		i += to;
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	vars;
	int		count;
	int		flags[7];

	count = 0;
	va_start(vars, s);
	while (*s)
	{
		if (*s++ == '%')
		{
			s += ft_fill_flags(s, flags);
			count += ft_print_arg(*s, vars, flags);
			s++;
			continue ;
		}
		ft_put_char(*(s - 1));
		count++;
	}
	va_end(vars);
	return (count);
}
