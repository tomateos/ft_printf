/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:30:39 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:13:05 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates memory of size and initialize memory to zero.
*/

void	*ft_memalloc(size_t size)
{
	char	*output;
	size_t	i;

	output = (char*)malloc(size);
	if (!output)
		return (NULL);
	i = 0;
	while (i < size)
	{
		output[i] = 0;
		i++;
	}
	return ((void*)output);
}
