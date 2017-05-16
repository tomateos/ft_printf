/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 01:46:43 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 20:15:06 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Follows the behavior of strlcat from libc. Attempts to append src to dst and
** returns attempted cat length (up to size). For more info, "man strlcat".
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = dlen;
	j = 0;
	if (size < dlen)
		return (slen + size);
	while (i < size - 1 && j < slen)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (slen + dlen);
}
