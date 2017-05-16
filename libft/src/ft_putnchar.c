/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:36:33 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:39:48 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes char c to standard output n times.
*/

void	ft_putnchar(char c, int n)
{
	while (--n > 0)
		ft_putchar(c);
}
