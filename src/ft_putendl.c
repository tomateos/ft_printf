/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:56:06 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:44:00 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes string s followed by a new line to standard output.
*/

void	ft_putendl(char const *s)
{
	if (!s)
	{
		write(1, "\n", 1);
		return ;
	}
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}
