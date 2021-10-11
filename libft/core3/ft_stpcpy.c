/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:55:00 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/02 20:55:01 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stpcpy(char *dest, char const *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (dest);
}
