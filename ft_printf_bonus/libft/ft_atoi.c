/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:58:00 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/20 21:48:06 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*str < 14 && *str > 8) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - 48);
	return (num * sign);
}
