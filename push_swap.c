/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:34:41 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 13:45:58 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	args_to_array(t_ss *t, int argc, char **argv)
{
	int		i;
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	t->count = ft_count_strings(args);
	t->array = ft_malloc(sizeof(int) * t->count);
	i = -1;
	while (++i < t->count)
		if (ft_satoi(args[i], &t->array[i]) < 0)
			ft_exit("Error\nInvalid int\n");
	if (argc == 2)
		args = ft_free_strings(args);
	if (!ft_arrisunq(t->array, t->count))
		ft_exit("Error\nDuplicates found\n");
	if (ft_arrissrt(t->array, t->count))
		return (-1);
	t->sorted = ft_arrbbl(ft_arrdup(t->array, t->count), t->count);
	t->min = t->sorted[0];
	t->med = t->sorted[t->count / 2];
	t->max = t->sorted[t->count - 1];
	t->sorted = ft_free(t->sorted);
	return (0);
}

void	push_swap(int argc, char **argv)
{
	t_ss	t;
	t_pp	a;
	t_pp	b;

	if (!args_to_array(&t, argc, argv))
	{
		a.count = t.count;
		a.l = psarr2lst(t.array, t.count);
		b.count = 0;
		b.l = NULL;
		push_b_all_except_min_med_max(&t, &a, &b);
		sort3(&a);
		while (b.count)
		{
			calculate_moves(&a, &b);
			push_a_with_least_moves(&a, &b);
		}
		final_rotate_a(&t, &a);
		pslstclear(&a.l);
		pslstclear(&b.l);
	}
	t.array = ft_free(t.array);
}
