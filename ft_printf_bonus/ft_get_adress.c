/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:03:32 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/19 22:33:47 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_adress(unsigned long n)
{
	int		len;
	char	*str;

	len = ft_get_base_number_len(n, 16) + 2;
	str = ft_malloc_plus(len + 1);
	str[0] = '0';
	str[1] = 'x';
	ft_fill_number_base(&str[len - 1], n, 16, 0);
	return (str);
}
