/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:29:05 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 09:29:24 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rra(t_pp *a)
{
	a->l = a->l->prev;
	write(1, "rra\n", 4);
}

void	cmd_rrb(t_pp *b)
{
	b->l = b->l->prev;
	write(1, "rrb\n", 4);
}

void	cmd_rrr(t_pp *a, t_pp *b)
{
	a->l = a->l->prev;
	b->l = b->l->prev;
	write(1, "rrr\n", 4);
}
