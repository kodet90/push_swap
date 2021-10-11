/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:52:53 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 09:04:34 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_malloc(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	new_lst = NULL;
	while (lst)
	{
		new_elem = ft_lstnew_malloc(f(lst->content));
		if (new_elem)
			ft_lstadd_back(&new_lst, new_elem);
		else
			ft_lstclear_malloc(&new_lst, del);
		lst = lst->next;
	}
	return (new_lst);
}
