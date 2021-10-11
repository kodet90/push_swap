/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:38:33 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 15:38:36 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_pslst_is_sorted_bonus(t_pp *a)
{
	int	i;

	i = 0;
	while (i < a->count - 1)
	{
		if (a->l->val > a->l->next->val)
			return (-1);
		a->l = a->l->next;
		i++;
	}
	a->l = a->l->next;
	return (0);
}

static void	args_to_array(t_ss *t, int argc, char **argv)
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
}

void	push_swap(int argc, char **argv)
{
	t_ss	t;
	t_pp	a;
	t_pp	b;

	args_to_array(&t, argc, argv);
	a.count = t.count;
	a.l = psarr2lst(t.array, t.count);
	t.array = ft_free(t.array);
	b.count = 0;
	b.l = NULL;
	parse_cmds_bonus(&a, &b);
	if (check_pslst_is_sorted_bonus(&a) < 0 || b.count != 0 || b.l != NULL)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	pslstclear(&a.l);
	pslstclear(&b.l);
}
