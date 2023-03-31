/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:25:39 by sbelyama          #+#    #+#             */
/*   Updated: 2022/11/29 17:12:50 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// typedef struct s_test
// {
// 	char flags;
// 	int width;
// 	int is_precesion;
// 	char specifier;
// } t_test;

// int main()
// {

// 	char *s = "0+- ";
// 	unsigned int rep_flags = 0;

// 	while (*s)
// 	{
// 		printf("%d\n",(unsigned int)(1 << (*s % 32)));
// 		rep_flags = rep_flags | (1 << (*s % 32));
// 		s++;
// 	}

// 	// t_test test;
// 	// int *tmp;

// 	// int i = 0;
// 	// tmp = &test;

// 	// tmp.width = 7257;

// 	// while (i < sizeof(test) / 4)
// 	// {
// 	// 	*(tmp + i) = i * 5;
// 	// 	i++;
// 	// }
// 	// i = 0;
// 	// while (i < sizeof(test) / 4)
// 	// {
// 	// 	printf("%d\n",*(tmp + i));
// 	// 	i++;
// 	// }
// }

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(){
	ft_printf("%a");
}