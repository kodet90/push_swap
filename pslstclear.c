/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslstclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:11:27 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/09 23:26:02 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pslstclear(t_ps **lst)
{
	t_ps	*last;
	t_ps	*temp;

	if (!*lst)
		return ;
	last = (*lst)->prev;
	while ((*lst) != last)
	{
		temp = (*lst)->next;
		*lst = ft_free(*lst);
		*lst = temp;
	}
	*lst = ft_free(*lst);
}
