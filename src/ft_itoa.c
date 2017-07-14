/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:05:11 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/13 23:41:21 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a string that represents the int n.
*/

static int	get_nbr_len(intmax_t n, int sign)
{
	int len;

	len = 1;
	if (sign < 0)
		len++;
	while (n >= 10 || n <= -10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(intmax_t n)
{
	int		sign;
	int		len;
	char	*output;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = get_nbr_len(n, sign);
	output = (char*)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	output[len--] = 0;
	if (n < 0)
		output[0] = '-';
	while (n >= 10 || n <= -10)
	{
		output[len--] = sign * (n % 10) + '0';
		n = n / 10;
	}
	output[len--] = sign * n + '0';
	return (output);
}
