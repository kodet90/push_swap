/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psarr2lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:03:29 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/09 23:09:44 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*psarr2lst(int *array, int count)
{
	t_ps	*list;
	t_ps	*lst;

	lst = NULL;
	while (count-- > 0)
	{
		list = pslstnew(array[count]);
		pslstadd_front(&lst, list);
	}
	return (lst);
}
