/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:57:21 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 18:07:14 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Follows the behavior of memmove from libc. Copy len bytes of src into dst.
** For more info, "man memmove".
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dcpy;
	unsigned char	*scpy;
	size_t			i;

	dcpy = (unsigned char*)dst;
	scpy = (unsigned char*)src;
	if (dst <= src)
	{
		i = 0;
		while (i < len)
		{
			dcpy[i] = scpy[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			dcpy[i] = scpy[i];
		}
	}
	return (dst);
}
