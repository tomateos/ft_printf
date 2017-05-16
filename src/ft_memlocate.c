/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlocate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 23:33:17 by tzhou             #+#    #+#             */
/*   Updated: 2017/01/25 22:03:56 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the index of the first char c within the first n bytes of s.
** If c is not found, n is returned.
*/

size_t	ft_memlocate(const void *s, int c, size_t n)
{
	unsigned char	*copy;
	unsigned char	test;
	size_t			i;

	test = (unsigned char)c;
	copy = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (copy[i] == test)
			return (i);
		i++;
	}
	return (n);
}
