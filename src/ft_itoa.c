/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:05:11 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:38:19 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a string that represents the int n.
*/

static int	get_nbr_len(int n, int base, int neg)
{
	int len;

	len = 0;
	if (neg)
		len++;
	while (n >= base || n <= -base)
	{
		len++;
		n = n / base;
	}
	len++;
	return (len);
}

static char	get_digit(int n, int base, int neg)
{
	int		digit;
	char	c;

	if (neg)
		digit = (n % base) * -1;
	else
		digit = n % base;
	c = digit + 48;
	return (c);
}

char		*ft_itoa(int n)
{
	int		len;
	int		base;
	int		neg;
	char	*output;

	base = 10;
	neg = 0;
	if (n < 0)
		neg = 1;
	len = get_nbr_len(n, base, neg);
	output = (char*)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	output[len--] = 0;
	if (neg)
		output[0] = '-';
	while (n >= base || n <= -base)
	{
		output[len--] = get_digit(n, base, neg);
		n = n / base;
	}
	output[len] = get_digit(n, base, neg);
	if (len && base == 10)
		output[0] = '-';
	return (output);
}
