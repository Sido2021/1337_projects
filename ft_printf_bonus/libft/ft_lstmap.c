/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelyama <sbelyama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:36 by sbelyama          #+#    #+#             */
/*   Updated: 2022/10/23 14:00:43 by sbelyama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_lst;
	void	*content;

	if (!lst)
		return (0);
	tmp = lst;
	new_lst = 0;
	while (tmp)
	{
		content = (*f)(tmp->content);
		if (!new_lst)
		{
			new_lst = ft_lstnew(content);
			if (!new_lst)
			{
				del(content);
				return (0);
			}
		}
		else
			ft_lstadd_back(&new_lst, ft_lstnew(content));
		tmp = tmp->next;
	}
	return (new_lst);
}
