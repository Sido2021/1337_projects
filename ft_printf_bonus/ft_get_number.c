/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:15:36 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/19 02:59:09 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_calculate_len(int *flags, long num, int *len)
{
	*len = 0;
	if (num < 0 && ++(*len))
		num *= -1;
	else
	{
		if (ft_flags_contain(flags, ' '))
			(*len)++;
		if (ft_flags_contain(flags, '+'))
			(*len)++;
	}
	*len += ft_get_base_number_len(num, 10);
}

char	*ft_get_number(long num, int *flags)
{
	int		len;
	int		zeros;
	int		i;
	char	*str;

	ft_calculate_len(flags, num, &len);
	ft_calculate_zeros(flags, num, &len, &zeros);
	str = ft_malloc_plus(len + 1);
	i = 0;
	if (num < 0)
		str[i++] = '-';
	if (num >= 0 && ft_flags_contain(flags, ' '))
		str[i++] = ' ';
	if (num >= 0 && ft_flags_contain(flags, '+'))
		str[i++] = '+';
	while (zeros-- > 0)
		str[i++] = '0';
	if (num < 0)
		num *= -1;
	if (i < len)
		ft_fill_number_base(&str[len - 1], num, 10, 0);
	return (str);
}
