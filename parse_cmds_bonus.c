/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:16:11 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/11 15:57:43 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	parse_cmd_bonus4(t_pp *a, t_pp *b, char *s)
{
	if (!ft_strcmp("rrb\n", s))
	{
		if (b->count)
			b->l = b->l->prev;
	}
	else if (!ft_strcmp("rrr\n", s))
	{
		if (a->count)
			a->l = a->l->prev;
		if (b->count)
			b->l = b->l->prev;
	}
	else
		return (-1);
	return (0);
}

static int	parse_cmd_bonus3(t_pp *a, t_pp *b, char *s)
{
	if (!ft_strcmp("ra\n", s))
	{
		if (a->count)
			a->l = a->l->next;
	}
	else if (!ft_strcmp("rb\n", s))
	{
		if (b->count)
			b->l = b->l->next;
	}
	else if (!ft_strcmp("rr\n", s))
	{
		if (a->count)
			a->l = a->l->next;
		if (b->count)
			b->l = b->l->next;
	}
	else if (!ft_strcmp("rra\n", s))
	{
		if (a->count)
			a->l = a->l->prev;
	}
	else
		return (parse_cmd_bonus4(a, b, s));
	return (0);
}

static int	parse_cmd_bonus2(t_pp *a, t_pp *b, char *s)
{
	if (!ft_strcmp("pa\n", s))
	{
		if (b->count)
		{
			pslstadd_front(&a->l, pslstext(&b->l, b->l));
			a->count++;
			b->count--;
		}
	}
	else if (!ft_strcmp("pb\n", s))
	{
		if (a->count)
		{
			pslstadd_front(&b->l, pslstext(&a->l, a->l));
			a->count--;
			b->count++;
		}
	}
	else
		return (parse_cmd_bonus3(a, b, s));
	return (0);
}

static int	parse_cmd_bonus(t_pp *a, t_pp *b, char *s)
{
	if (!ft_strcmp("sa\n", s))
	{
		if (a->count)
			pslstadd_front(&a->l, pslstext(&a->l, a->l->next));
	}
	else if (!ft_strcmp("sb\n", s))
	{
		if (b->count)
			pslstadd_front(&b->l, pslstext(&b->l, b->l->next));
	}
	else if (!ft_strcmp("ss\n", s))
	{	
		if (a->count)
			pslstadd_front(&a->l, pslstext(&a->l, a->l->next));
		if (b->count)
			pslstadd_front(&b->l, pslstext(&b->l, b->l->next));
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
