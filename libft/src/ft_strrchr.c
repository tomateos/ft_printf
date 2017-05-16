/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 01:33:53 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 20:29:10 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Follows the behavior of strrchr from libc. Locates the last unsigned char c
** in string s. For more info, "man strrchr".
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	int		flag;
	char	*last;

	i = 0;
	len = ft_strlen(s);
	flag = 0;
	while (i <= len)
	{
		if (*s == c)
		{
			last = (char*)s;
			flag = 1;
		}
		i++;
		s++;
	}
	if (!flag)
		return (NULL);
	return (last);
}
