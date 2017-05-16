/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:42:06 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 19:56:33 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Follows the behavior of strncat from libc. Appends up to n bytes of s2 to the
** end of s1. For more info, "man strncat".
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (j < n && s2[j])
		s1[i++] = s2[j++];
	s1[i] = 0;
	return (s1);
}
