/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:44:13 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 13:54:41 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_pp *a)
{
	int	v;
	int	n;
	int	p;

	if (a->count == 3)
	{
		v = a->l->val;
		n = a->l->next->val;
		p = a->l->prev->val;
		if (n > v && n > p && p > v)
			cmd_sa(a);
		if (p > v && p > n && v > n)
			cmd_sa(a);
		if (v > n && v > p && n > p)
			cmd_sa(a);
	}
}
