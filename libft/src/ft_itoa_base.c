/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:41:11 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 23:03:20 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a string that represents int n in base 10 as int n in base base.
** Base must be between 2 and 36. If base is not 10, treat n as unsigned.
*/

static int	get_nbr_len(int value, int base, int neg)
{
	int len;

	len = 0;
	if (neg && base == 10)
		len++;
	while (value >= base || value <= -base)
	{
		len++;
		value = value / base;
	}
	len++;
	return (len);
}

static char	get_digit(int value, int base, int neg)
{
	int		digit;
	int		sign;
	char	c;

	sign = 1;
	if (neg)
		sign = -1;
	digit = (value % base) * sign;
	if (digit >= 0 && digit < 10)
		c = digit + 48;
	else
		c = digit + 55;
	return (c);
}

char		*ft_itoa_base(int value, int base)
{
	int		neg;
	int		len;
	char	*nbr;

	neg = 0;
	if (value < 0)
		neg = 1;
	len = get_nbr_len(value, base, neg);
	nbr = (char*)malloc(sizeof(char) * (len + 1));
	nbr[len--] = 0;
	while ((value >= base && !neg) || (value <= -base && neg))
	{
		nbr[len--] = get_digit(value, base, neg);
		value = value / base;
	}
	nbr[len] = get_digit(value, base, neg);
	if (len && base == 10)
		nbr[0] = '-';
	return (nbr);
}
