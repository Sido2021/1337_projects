/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:45:16 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/21 00:44:04 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = 0;
	srclen = 0;
	if (dst)
		dstlen = ft_strlen(dst);
	if (src)
		srclen = ft_strlen(src);
	while (*src && (i + dstlen + 1) < dstsize)
		dst[dstlen + i++] = *src++;
	if (!(dstsize && dstlen <= dstsize))
		return (dstsize + srclen);
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
