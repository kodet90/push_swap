/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:27:20 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 09:33:10 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_sa(t_pp *a)
{
	pslstadd_front(&a->l, pslstext(&a->l, a->l->next));
	write(1, "sa\n", 3);
}

void	cmd_sb(t_pp *b)
{
	pslstadd_front(&b->l, pslstext(&b->l, b->l->next));
	write(1, "sb\n", 3);
}

void	cmd_ss(t_pp *a, t_pp *b)
{
	pslstadd_front(&a->l, pslstext(&a->l, a->l->next));
	pslstadd_front(&b->l, pslstext(&b->l, b->l->next));
	write(1, "ss\n", 3);
}
