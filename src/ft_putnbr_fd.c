/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:18:27 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:44:42 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes int n to file descriptor fd.
*/

void	ft_putnbr_fd(int n, int fd)
{
	char digit;

	if (n >= 0 && n < 10)
		digit = n + 48;
	else if (n >= 10)
	{
		digit = n % 10 + 48;
		ft_putnbr_fd(n / 10, fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		if (n <= -10)
			ft_putnbr_fd((n / 10) * -1, fd);
		digit = (n % 10) * -1 + 48;
	}
	ft_putchar_fd(digit, fd);
}
