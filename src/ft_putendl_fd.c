/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:04:16 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:43:42 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes string s followed by a new line to file descriptor fd.
*/

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
	{
		write(fd, "\n", 1);
		return ;
	}
	while (*s)
		ft_putchar_fd(*(s++), fd);
	write(fd, "\n", 1);
}
