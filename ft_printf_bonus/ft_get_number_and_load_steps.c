/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number_and_load_steps.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:15:43 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/14 18:17:20 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_number_and_load_steps(const char *s, int *to)
{
	int		n;
	char	*sb;

	*to = 0;
	while (ft_isdigit(s[*to]))
		(*to)++;
	if (!*to)
		return (0);
	sb = ft_substr(s, 0, *to);
	n = ft_atoi(sb);
	free(sb);
	return (n);
}
