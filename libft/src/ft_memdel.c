/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:32:30 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:14:43 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes the address of memory, frees the memory and sets the pointer to NULL.
*/

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	if (!*ap)
		return ;
	if (*ap)
		free(*ap);
	*ap = NULL;
}
