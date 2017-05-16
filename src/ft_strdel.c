/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:39:49 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:16:51 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes the address of a string, frees the string and sets the pointer to NULL.
*/

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	if (*as)
		free(*as);
	*as = NULL;
}
