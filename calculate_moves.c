/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:36:09 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 13:49:12 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_moves(int am, int bm)
{
	int	m;

	if (am >= 0 && bm >= 0)
	{
		return (ft_max(am, bm));
	}
	else if (am <= 0 && bm <= 0)
	{
		return (ft_abs(ft_min(am, bm)));
	}
	else
		m = ft_abs(am) + ft_abs(bm);
	return (m);
}

static int	calculate_a_moves(t_pp *a_start, int b)
{
	int		aa;
	t_ps	*a;

	a = a_start->l;
	aa = 0;
	while (aa < a_start->count / 2 + a_start->count % 2)
	{
		if (b < a->val && b > a->prev->val)
			return (aa);
		a = a->next;
		aa++;
	}
	a = a_start->l->prev;
	aa = 1;
	while (aa < a_start->count / 2 + 1)
	{
		if (b < a->val && b > a->prev->val)
			return (-aa);
		a = a->prev;
		aa++;
	}
	return (888);
}

void	calculate_moves(t_pp *a_start, t_pp *b_start)
{
	int		bb;
	t_ps	*b;

	if (!b_start->l)
		return ;
	b = b_start->l;
	bb = 0;
	while (bb < b_start->count / 2 + b_start->count % 2)
	{
		b->a_moves = calculate_a_moves(a_start, b->val);
		b->b_moves = bb;
		b->t_moves = total_moves(b->a_moves, b->b_moves);
		b = b->next;
		bb++;
	}
	b = b_start->l->prev;
	bb = 1;
	while (bb < b_start->count / 2 + 1)
	{
		b->a_moves = calculate_a_moves(a_start, b->val);
		b->b_moves = -bb;
		b->t_moves = total_moves(b->a_moves, b->b_moves);
		b = b->prev;
		bb++;
	}
}
