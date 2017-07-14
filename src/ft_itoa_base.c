/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:41:11 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/13 22:56:03 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a string that represents int n in base 10 as int n in base base.
** Base should be between 2 and 16.
*/

static int	get_nbr_len(uintmax_t value, unsigned int base)
{
	int len;

	len = 1;
	while (value >= base)
	{
		len++;
		value = value / base;
	}
	return (len);
}

static char	get_digit(uintmax_t value, unsigned int base, int upper)
{
	int		digit;
	char	c;

	digit = (value % base);
	if (digit >= 0 && digit < 10)
		c = digit + '0';
	else
	{
		if (upper)
			c = digit + 'A' - 10;
		else
			c = digit + 'a' - 10;
	}
	return (c);
}

char		*ft_itoa_base(uintmax_t value, unsigned int base, int upper)
{
	int		len;
	char	*nbr;

	len = get_nbr_len(value, base);
	nbr = (char*)malloc(sizeof(char) * (len + 1));
	nbr[len--] = 0;
	while (value >= base)
	{
		nbr[len--] = get_digit(value, base, upper);
		value = value / base;
	}
	nbr[len] = get_digit(value, base, upper);
	return (nbr);
}
