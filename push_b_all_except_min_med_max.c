/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_all_except_min_med_max.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:41:08 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 13:41:12 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_all_except_min_med_max(t_ss *t, t_pp *a, t_pp *b)
{
	int	i;

	i = 0;
	while (i < t->count && a->count > 3)
	{
		if (a->l->val == t->min || a->l->val == t->med || a->l->val == t->max)
			cmd_ra(a);
		else if (a->l->val > t->med)
			cmd_pb(a, b);
		else
		{
			cmd_pb(a, b);
			cmd_rb(b);
		}
		i++;
	}
}
