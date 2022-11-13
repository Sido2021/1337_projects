/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:25:06 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/21 01:26:59 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		if (!s1[i -1] || (unsigned char)s1[i -1] != (unsigned char)s2[i -1])
			return ((unsigned char)s1[i -1] - (unsigned char)s2[i -1]);
	return (0);
}
