/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:16:11 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 15:36:51 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	parse_cmd_bonus2(t_pp *a, t_pp *b, char *s)
{
	if (!ft_strcmp("ra\n", s))
		a->l = a->l->next;
	else if (!ft_strcmp("rb\n", s))
		b->l = b->l->next;
	else if (!ft_strcmp("rr\n", s))
	{
		a->l = a->l->next;
		b->l = b->l->next;
	}
	else if (!ft_strcmp("rra\n", s))
		a->l = a->l->prev;
	else if (!ft_strcmp("rrb\n", s))
		b->l = b->l->prev;
	else if (!ft_strcmp("rrr\n", s))
	{
		a->l = a->l->prev;
		b->l = b->l->prev;
	}
	else
		return (-1);
	return (0);
}

static int	parse_cmd_bonus(t_pp *a, t_pp *b, char *s)
{
	if (!ft_strcmp("sa\n", s))
		pslstadd_front(&a->l, pslstext(&a->l, a->l->next));
	else if (!ft_strcmp("sb\n", s))
		pslstadd_front(&b->l, pslstext(&b->l, b->l->next));
	else if (!ft_strcmp("ss\n", s))
	{	
		pslstadd_front(&a->l, pslstext(&a->l, a->l->next));
		pslstadd_front(&b->l, pslstext(&b->l, b->l->next));
	}
	else if (!ft_strcmp("pa\n", s))
	{
		pslstadd_front(&a->l, pslstext(&b->l, b->l));
		a->count++;
		b->count--;
	}
	else if (!ft_strcmp("pb\n", s))
	{
		pslstadd_front(&b->l, pslstext(&a->l, a->l));
		a->count--;
		b->count++;
	}
	else
		return (parse_cmd_bonus2(a, b, s));
	return (0);
}

void	parse_cmds_bonus(t_pp *a, t_pp *b)
{
	char	*s;

	s = ft_gnl(0);
	while (s)
	{
		if (parse_cmd_bonus(a, b, s) < 0)
			ft_exit("Error\nBad instruction\n");
		s = ft_free(s);
		s = ft_gnl(0);
	}
}
