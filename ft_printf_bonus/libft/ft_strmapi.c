/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:04:55 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/21 01:24:52 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*string;

	i = 0;
	if (!s)
		return (0);
	string = (char *) malloc(ft_strlen(s)+1);
	if (!string)
		return (string);
	while (s[i++])
		string[i -1] = (*f)(i -1, s[i -1]);
	string[i -1] = '\0';
	return (string);
}
