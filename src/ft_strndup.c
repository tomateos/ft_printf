/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:27:42 by tzhou             #+#    #+#             */
/*   Updated: 2017/01/25 22:08:28 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Follows the behavior of strndup from libc. Allocates and copies the first n
** chars of s1. For more info, "man strndup".
*/

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	if (!(s2 = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
