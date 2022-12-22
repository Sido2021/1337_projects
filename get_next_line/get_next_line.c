/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:23:56 by sbelyama          #+#    #+#             */
/*   Updated: 2022/12/22 14:21:22 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_str_concat(char ***dst, char *s2, int len)
{
	char	*tmp;
	int		n;

	n = len;
	len = -1;
	if (n < 0)
		n = ft_strlen(**dst);
	tmp = ft_strdup(**dst);
	if (tmp)
	{
		n += ft_strlen(s2);
		free(**dst);
		**dst = malloc(n + 1);
		if (**dst)
		{
			(**dst)[n] = '\0';
			while (tmp[++len])
				(**dst)[len] = tmp[len];
			while (*s2)
				(**dst)[len++] = *s2++;
		}
		free(tmp);
	}
	return (n);
}

void	ft_laod(int fd, int *rd, char	*str, int extra_space)
{
	char	*ptr;

	ptr = str;
	*ptr = 0;
	while (*rd > 0 && ptr - str <= extra_space)
	{
		*rd = read(fd, ptr, BUFFER_SIZE);
		if (*rd > 0)
			ptr[*rd] = 0;
		if (ft_strchr(ptr, '\n'))
			*rd = 0;
		if (*rd > 0)
			ptr += *rd;
	}
}

void	read_line(int fd, char	**s, int extra_space)
{
	char	buffer[BUFFER_SIZE + extra_space + 1];
	int		rd;
	int		len;

	rd = 1;
	len = -1;
	while (rd > 0)
	{
		ft_laod(fd, &rd, buffer, extra_space);
		if (*buffer)
		{
			if (!*s)
				*s = ft_strdup(buffer);
			else
				len = ft_str_concat(&s, buffer, len);
		}
		if (rd < 0 && *s)
		{
			free(*s);
			*s = NULL;
		}
	}
}

void	check_line(char **s, char **remainder)
{
	char	*new_line_at;
	char	*tmp;

	if (*s)
	{
		new_line_at = ft_strchr(*s, '\n');
		if (new_line_at && new_line_at[1])
		{
			*remainder = ft_strdup(new_line_at +1);
			new_line_at[1] = 0;
			tmp = ft_strdup(*s);
			free(*s);
			*s = ft_strdup(tmp);
			if (!*s)
			{
				if (*remainder)
				{
					free(*remainder);
					*remainder = NULL;
				}
			}
			free(tmp);
		}
	}
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*remainder;
	int			extra_space;

	s = NULL;
	extra_space = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (remainder)
	{
		s = ft_strdup(remainder);
		free(remainder);
		remainder = 0;
	}
	if (BUFFER_SIZE < 1000)
		extra_space = 1000 - BUFFER_SIZE;
	if (!ft_strchr(s, '\n'))
		read_line(fd, &s, extra_space);
	check_line(&s, &remainder);
	return (s);
}
