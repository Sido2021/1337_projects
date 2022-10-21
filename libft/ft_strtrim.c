/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:04:32 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/18 20:11:16 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_index(char *str, char *set, size_t index, int forward)
{
	while (((str[index] && forward) || (!forward && index > 0))
		&& ft_strchr(set, str[index]))
	{
		if (forward)
			index++;
		else
			index--;
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_at;
	size_t	end_at;

	start_at = 0;
	end_at = 0;
	if (s1)
	{
		start_at = get_index((char *)s1, (char *)set, 0, 1);
		end_at = ft_strlen(s1);
		if (end_at > 0)
			end_at--;
		end_at = get_index((char *)s1, (char *)set, end_at, 0);
		return (ft_substr((char *)s1, start_at, end_at - start_at + 1));
	}
	return (0);
}
