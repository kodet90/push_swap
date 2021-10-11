/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 01:22:07 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 13:53:43 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_ss
{
	int		count;
	int		*array;
	int		*sorted;
	int		min;
	int		med;
	int		max;
}	t_ss;

typedef struct s_ps
{
	int				val;
	int				a_moves;
	int				b_moves;
	int				t_moves;
	struct s_ps		*next;
	struct s_ps		*prev;
}	t_ps;

typedef struct s_pp
{
	int		count;
	t_ps	*l;
}	t_pp;

void	cmd_sa(t_pp *a);
void	cmd_sb(t_pp *b);
void	cmd_ss(t_pp *a, t_pp *b);
void	cmd_pa(t_pp *a, t_pp *b);
void	cmd_pb(t_pp *a, t_pp *b);
void	cmd_ra(t_pp *a);
void	cmd_rb(t_pp *b);
void	cmd_rr(t_pp *a, t_pp *b);
void	cmd_rra(t_pp *a);
void	cmd_rrb(t_pp *b);
void	cmd_rrr(t_pp *a, t_pp *b);
void	calculate_moves(t_pp *a_start, t_pp *b_start);
void	final_rotate_a(t_ss *t, t_pp *a);
t_ps	*psarr2lst(int *array, int count);
void	pslstadd_back(t_ps **lst, t_ps *new);
void	pslstadd_front(t_ps **lst, t_ps *new);
void	pslstclear(t_ps **lst);
t_ps	*pslstext(t_ps **lst, t_ps *ext);
t_ps	*pslstnew(int val);
void	push_a_with_least_moves(t_pp *a, t_pp *b);
void	push_b_all_except_min_med_max(t_ss *t, t_pp *a, t_pp *b);
void	push_swap(int argc, char **argv);
void	sort3(t_pp *a);

#endif
