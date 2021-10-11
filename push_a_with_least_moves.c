/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_with_least_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:27:59 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 13:55:57 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a_with_least_moves_fwd(t_pp *x, int xm, void (*f)(t_pp *))
{
	while (xm-- > 0)
		f(x);
}

static void	push_a_with_least_moves_rev(t_pp *x, int xm, void (*f)(t_pp *))
{
	while (xm++ < 0)
		f(x);
}

static t_ps	*find_b_best(t_pp *b)
{
	int		bb;
	int		min;
	t_ps	*b_best;

	min = INT_MAX;
	bb = 0;
	while (bb < b->count)
	{
		if (b->l->t_moves < min)
		{
			min = b->l->t_moves;
			b_best = b->l;
		}
		b->l = b->l->next;
		bb++;
	}
	return (b_best);
}

void	push_a_with_least_moves(t_pp *a, t_pp *b)
{
	t_ps	*b_best;
	int		am;
	int		bm;

	b_best = find_b_best(b);
	am = b_best->a_moves;
	bm = b_best->b_moves;
	while (am > 0 && bm > 0)
	{
		am--;
		bm--;
		cmd_rr(a, b);
	}
	while (am < 0 && bm < 0)
	{
		am++;
		bm++;
		cmd_rrr(a, b);
	}
	push_a_with_least_moves_fwd(a, am, cmd_ra);
	push_a_with_least_moves_fwd(b, bm, cmd_rb);
	push_a_with_least_moves_rev(a, am, cmd_rra);
	push_a_with_least_moves_rev(b, bm, cmd_rrb);
	cmd_pa(a, b);
}
