/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:27:42 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 17:57:45 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Follows the behavior of memcmp from libc. Compares n bytes of s1 against s2.
** For more info, "man memcmp".
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cp1;
	unsigned char	*cp2;
	size_t			i;

	i = 0;
	cp1 = (unsigned char*)s1;
	cp2 = (unsigned char*)s2;
	while (i < n)
	{
		if (cp1[i] != cp2[i])
			return (cp1[i] - cp2[i]);
		i++;
	}
	return (0);
}
