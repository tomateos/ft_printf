/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:58:28 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:41:47 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes int n to standard output.
*/

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 0 && n < 10)
		digit = n + 48;
	else if (n >= 10)
	{
		digit = n % 10 + 48;
		ft_putnbr(n / 10);
	}
	else
	{
		ft_putchar('-');
		if (n <= -10)
			ft_putnbr((n / 10) * -1);
		digit = (n % 10) * -1 + 48;
	}
	ft_putchar(digit);
}
