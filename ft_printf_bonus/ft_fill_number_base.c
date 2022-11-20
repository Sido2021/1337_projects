/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_number_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:01:09 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/19 19:12:28 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_number_base(char *str, unsigned long n, int b, char x)
{
	if (n / b)
		ft_fill_number_base(str - 1, n / b, b, x);
	if (b == 8)
		*str = "01234567"[n % b];
	else if (b == 16)
	{
		if (x != 'X')
			*str = "0123456789abcdef"[n % b];
		else
			*str = "0123456789ABCDEF"[n % b];
	}
	else
		*str = n % b + 48;
}
