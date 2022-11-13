/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:44:20 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/21 12:33:27 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!needle && !haystack && !len)
		return ("");
	if (!haystack && !len)
		return (0);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[k] == needle[j++] && k++ < len)
		{
			if (!needle[j])
				return ((char *)haystack + i);
			continue ;
		}
		j = 0;
		k = ++i;
	}
	return (0);
}
