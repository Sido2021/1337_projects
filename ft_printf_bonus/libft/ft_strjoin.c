/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:56:35 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/19 18:39:59 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n;

	n = 0;
	if (s1)
		n = ft_strlen(s1);
	if (s2)
		n += ft_strlen(s2);
	str = malloc(n + 1);
	if (!str)
		return (str);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	str -= n;
	return (str);
}
