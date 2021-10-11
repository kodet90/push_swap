/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslstext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:37:22 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 13:37:23 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*pslstext(t_ps **lst, t_ps *ext)
{
	if (!ext)
		return (ext);
	if (*lst == ext)
	{
		if ((*lst)->next == ext)
			*lst = NULL;
		else
			*lst = (*lst)->next;
	}
	ext->prev->next = ext->next;
	ext->next->prev = ext->prev;
	ext->prev = NULL;
	ext->next = NULL;
	return (ext);
}
