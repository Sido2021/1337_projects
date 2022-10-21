/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:49:11 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/19 20:20:23 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = NULL;
	if (!s)
		return (str);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
			len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (str);
	s += start;
	start = 0;
	while (start < len)
		str[start++] = *(s++);
	str[start] = '\0';
	return (str);
}
