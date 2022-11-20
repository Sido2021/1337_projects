/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:02:24 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/19 21:03:46 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_allocate_and_set_len( char *s, int *flags, int *strlen)
{
	char	*str;
	char	*ss;
	int		n;

	*strlen = 0;
	if (s)
		str = ft_strdup(s);
	else
		str = ft_strdup("(null)");
	*strlen = ft_strlen(str);
	if (ft_flags_contain(flags, '.'))
	{
		n = ft_get_flag_count(flags, '.');
		if (n < *strlen)
		{
			ss = ft_strdup(str);
			free(str);
			str = ft_substr(ss, 0, n);
			free(ss);
			*strlen = n;
		}
	}
	return (str);
}

int	ft_put_string(char *s, int *flags)
{
	int		n;
	int		strlen;
	int		count;
	char	*str;

	count = 0;
	str = ft_allocate_and_set_len(s, flags, &strlen);
	n = ft_get_flag_count(flags, 'n');
	if (!ft_flags_contain(flags, '-'))
		count = ft_put_nchar(' ', n - strlen);
	n = 0;
	while (str[n])
		ft_put_char(str[n++]);
	count += n;
	n = ft_get_flag_count(flags, 'n');
	if (ft_flags_contain(flags, '-'))
		count += ft_put_nchar(' ', n - strlen);
	free(str);
	return (count);
}
