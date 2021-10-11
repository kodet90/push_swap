/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:31:21 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 13:49:33 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_a_moves_final(t_pp *a_start, int b)
{
	int		aa;
	t_ps	*a;

	a = a_start->l;
	aa = 0;
	while (aa < a_start->count / 2 + a_start->count % 2)
	{
		if (b == a->val)
			return (aa);
		a = a->next;
		aa++;
	}
	a = a_start->l->prev;
	aa = 1;
	while (aa < a_start->count / 2 + 1)
	{
		if (b == a->val)
			return (-aa);
		a = a->prev;
		aa++;
	}
	return (888);
}

void	final_rotate_a(t_ss *t, t_pp *a)
{
	int	am;

	am = calculate_a_moves_final(a, t->min);
	while (am > 0)
	{
		am--;
		cmd_ra(a);
	}
	while (am < 0)
	{
		am++;
		cmd_rra(a);
	}
}
