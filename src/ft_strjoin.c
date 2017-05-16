/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:47:58 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:35:16 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a string that results from concatenating string s1 and string s2.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*out;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	out = (char*)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (*s1)
		out[i++] = *(s1++);
	while (*s2)
		out[i++] = *(s2++);
	out[i] = 0;
	return (out);
}
