/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:24:28 by sbelyama          #+#    #+#             */
/*   Updated: 2022/12/22 14:20:29 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
		if (*s++ == (char)c)
			return ((char *)--s);
	if (s && !((char)c))
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (ptr)
	{
		ptr[len] = 0;
		while (ptr && len--)
			ptr[len] = s1[len];
	}
	return (ptr);
}
