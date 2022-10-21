/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:19:05 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/20 22:10:24 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	calculate_number_count(int n, int *count)
{
	if (n < 0)
		(*count)++;
	while (n / 10 && (*count)++)
		n /= 10;
}

char	*ft_itoa(int n)
{
	char	*string;
	int		count;
	int		sign;

	count = 1;
	sign = 1;
	calculate_number_count(n, &count);
	string = (char *) malloc(count + 1);
	if (!string)
		return (string);
	string[count--] = 0;
	if (n < 0)
	{
		string[0] = '-';
		sign = -1;
	}
	while (count >= 0 && !(!count && sign < 0))
	{
		string[count--] = (n % 10) * sign + 48;
		n /= 10;
	}
	return (string);
}
