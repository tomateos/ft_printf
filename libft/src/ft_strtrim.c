/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:02:38 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:36:02 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a copy of string s with leading and trailing whitespaces removed.
*/

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int	get_space(const char *s, int i, int len)
{
	int sign;
	int	count;

	count = 0;
	sign = 1;
	if (i)
		sign = -1;
	while (i >= 0 && i <= len)
	{
		if (!is_whitespace(s[i]))
		{
			return (count);
		}
		count++;
		i += sign;
	}
	return (count);
}

static char	*get_trim(char const *s, int lead, int end, int len)
{
	char	*trim;
	int		i;
	int		j;
	int		size;

	size = len - lead - end;
	if (size < 0)
		size = 0;
	trim = (char*)malloc(sizeof(char) * (size + 1));
	if (!trim)
		return (NULL);
	i = 0;
	j = 0;
	while (j < size)
	{
		if (i >= lead && i <= len - end)
			trim[j++] = s[i];
		i++;
	}
	trim[j] = 0;
	return (trim);
}

char		*ft_strtrim(char const *s)
{
	int		lead;
	int		end;
	int		len;
	char	*trim;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	lead = get_space(s, 0, len);
	end = get_space(s, len - 1, len);
	trim = get_trim(s, lead, end, len);
	return (trim);
}
