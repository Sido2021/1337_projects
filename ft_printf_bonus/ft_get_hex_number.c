/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:41:12 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/20 20:25:41 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_hex_number(unsigned int num, int *flags, char x)
{
	int		len;
	int		zeros;
	char	*str;
	int		i;

	len = ft_get_base_number_len(num, 16);
	if (ft_flags_contain(flags, '#') && num != 0)
		len += 2 ;
	ft_calculate_zeros(flags, num, &len, &zeros);
	str = ft_malloc_plus(len + 1);
	i = 0;
	if (i < len && ft_flags_contain(flags, '#') && num != 0)
		str[i++] = '0';
	if (i < len && ft_flags_contain(flags, '#') && num != 0)
		str[i++] = x;
	while (i < len && zeros-- > 0)
		str[i++] = '0';
	if (len > 0)
		ft_fill_number_base(&str[len - 1], num, 16, x);
	return (str);
}
