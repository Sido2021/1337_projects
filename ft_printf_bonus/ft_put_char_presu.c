/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char_presu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:52:00 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/19 22:37:42 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char_presu(char c, int *flags)
{
	int	count;
	int	n;

	count = 0;
	n = ft_get_flag_count(flags, 'n');
	if (!ft_flags_contain(flags, '-'))
		count = ft_put_nchar(' ', n - 1);
	ft_put_char(c);
	count++;
	if (ft_flags_contain(flags, '-'))
		count += ft_put_nchar(' ', n - 1);
	return (count);
}
