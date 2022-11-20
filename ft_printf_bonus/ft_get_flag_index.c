/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:15:04 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/14 18:15:27 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_flag_index(char c)
{
	int	index;

	index = 0;
	while (index++ < 6)
		if ("n-0.# +"[index] == c)
			return (index);
	return (0);
}
