/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_zeros.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:43:00 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/19 19:54:37 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_calculate_zeros(int *flags, long num, int *len, int *zeros)
{
	int	n;

	n = 0;
	*zeros = 0;
	if (!ft_flags_contain(flags, '.') && !ft_flags_contain(flags, '0'))
		return ;
	n = ft_get_flag_count(flags, 'n');
	if (ft_flags_contain(flags, '.'))
	{
		n = ft_get_flag_count(flags, '.');
		if (n == 0 && num == 0)
			(*len)--;
		if (ft_flags_contain(flags, ' '))
			n++;
		if (num < 0 && !ft_flags_contain(flags, ' '))
			n++;
		else if (ft_flags_contain(flags, '+'))
			n++;
		if (ft_flags_contain(flags, '#') && num != 0)
			n += 2;
		ft_reset_flag(flags, '.');
	}
	*zeros = n - *len;
	if (*len < n)
		*len = n;
}
