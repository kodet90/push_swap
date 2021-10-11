/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslstadd_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:36:47 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 13:36:48 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pslstadd_front(t_ps **lst, t_ps *new)
{
	if (*lst)
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		if ((*lst)->next == (*lst))
			(*lst)->next = new;
		(*lst)->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	*lst = new;
}
