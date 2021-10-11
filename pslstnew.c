/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslstnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:09:11 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 06:01:55 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*pslstnew(int val)
{
	t_ps	*list;

	list = ft_malloc(sizeof(t_ps));
	if (!list)
		return (list);
	list->val = val;
	list->a_moves = 0;
	list->b_moves = 0;
	list->t_moves = 0;
	list->next = list;
	list->prev = list;
	return (list);
}
