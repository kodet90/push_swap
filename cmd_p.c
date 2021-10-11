/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:27:58 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 09:28:01 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_pa(t_pp *a, t_pp *b)
{
	pslstadd_front(&a->l, pslstext(&b->l, b->l));
	a->count++;
	b->count--;
	write(1, "pa\n", 3);
}

void	cmd_pb(t_pp *a, t_pp *b)
{
	pslstadd_front(&b->l, pslstext(&a->l, a->l));
	a->count--;
	b->count++;
	write(1, "pb\n", 3);
}
