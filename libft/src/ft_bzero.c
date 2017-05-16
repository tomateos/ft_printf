/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:25:33 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 12:20:13 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Follows the behavior of bzero from libc. Writes n zeroed bytes into string s.
** For more info, "man bzero".
*/

void	ft_bzero(void *s, size_t n)
{
	char	*temp;
	size_t	i;

	if (n > 0)
	{
		i = 0;
		temp = (char*)s;
		while (i < n)
			temp[i++] = 0;
	}
}
