/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:17:46 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/29 00:38:06 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_number(long n, int fd)
{
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n)
	{
		write_number(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (!n)
		ft_putchar_fd('0', fd);
	else
		write_number(n, fd);
}
