/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_base_number_len.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:06:11 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/18 23:42:40 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_base_number_len(unsigned long n, int base)
{
	int	count;

	count = 1;
	while (n / base && count++)
		n /= base;
	return (count);
}
