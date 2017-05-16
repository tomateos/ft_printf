/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:12:42 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:17:55 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies function f to every char of string s.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s)
		return ;
	if (!f)
		return ;
	while (*s)
		f(s++);
}
