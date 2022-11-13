/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:38:17 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/18 21:23:39 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst && src > dst - len)
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
