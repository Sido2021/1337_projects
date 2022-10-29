/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:11:55 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/29 00:38:22 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_words_count(char *s, char c, size_t *count)
{
	while (*s)
		if (*(s++) != c && (!(*count) || *(s -2) == c))
			(*count)++;
}

static void	fill_array(char **strings, char *s, char c, int count)
{
	size_t	len;
	int		j;

	j = 0;
	while (j < count)
	{
		if (*++s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			strings[j++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	strings[j] = 0;
}

char	**ft_split(char *const s, char c)
{
	char	**strings;
	size_t	count;

	if (!s)
		return (0);
	strings = NULL;
	count = 0;
	get_words_count((char *)s, c, &count);
	strings = (char **) malloc(sizeof(char *) * (count + 1));
	if (strings)
		fill_array(strings, (char *)s -1, c, count);
	return (strings);
}
