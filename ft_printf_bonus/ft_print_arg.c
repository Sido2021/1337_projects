/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:23:23 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/19 03:08:08 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char f, va_list vars, int *flags)
{
	char	*s;
	int		c;

	c = 0;
	if (f == 'c')
		return (ft_put_char_presu(va_arg(vars, int), flags));
	else if (f == 's')
		return (ft_put_string(va_arg(vars, char *), flags));
	else if (f == '%')
		return (ft_put_char_presu('%', flags));
	else if (f == 'd' || f == 'i' || f == 'p'
		|| f == 'u' || f == 'x' || f == 'X')
	{
		if (f == 'd' || f == 'i')
			s = ft_get_number(va_arg(vars, int), flags);
		else if (f == 'p')
			s = ft_get_adress((unsigned long) va_arg(vars, void *));
		else if (f == 'u')
			s = ft_get_number(va_arg(vars, unsigned int), flags);
		else
			s = ft_get_hex_number(va_arg(vars, unsigned int), flags, f);
		c = ft_put_string(s, flags);
		free(s);
	}
	return (c);
}
