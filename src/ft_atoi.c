/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:42:28 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 21:00:24 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Follows the behavior of atoi from libc. Converts string str into an int.
** For more info, "man atoi".
*/

static int	is_white_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	long	nbr;
	long	sign;

	nbr = 0;
	sign = 1;
	while (is_white_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		nbr = nbr * 10 + *(str++) - '0';
	return (nbr * sign);
}
