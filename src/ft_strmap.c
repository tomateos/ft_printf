/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:18:51 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:21:25 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a string created by the application of f to every char in string s.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	ind;
	unsigned int	len;
	char			*output;

	if (!s)
		return (0);
	len = ft_strlen(s);
	output = (char*)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	ind = 0;
	while (ind < len)
	{
		output[ind] = f(s[ind]);
		ind++;
	}
	output[ind] = 0;
	return (output);
}
