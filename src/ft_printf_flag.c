/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:14:23 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/13 23:04:02 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_length(char *parse, t_print *env)
{
	char	check;

	if (env->len)
		exit(1);
	check = 1;
	if (ft_strchr("SDOUC", env->type))
		env->len++;
	while (ft_strchr("hljz", *parse) && *parse)
	{
		if (*parse == 'h')
			(env->len > 0 || env->len < -1) ? (check = 0) : (env->len--);
		if (*parse == 'l')
			(env->len < 0 || env->len > 1) ? (check = 0) : (env->len++);
		if (*parse == 'j')
			(env->len != 0) ? (check = 0) : (env->len += 3);
		if (*parse == 'z')
			(env->len != 0) ? (check = 0) : (env->len -= 3);
		if (!check)
			exit(1);
		parse++;
	}
	return (parse);
}

char	*get_width_prec(char *parse, t_print *env)
{
	if (env->width || env->precision || env->len)
		exit(1);
	if (*parse == '0')
	{
		env->pad = '0';
		parse++;
	}
	while (ft_strchr("0123456789", *parse) && *parse)
	{
		env->width = env->width * 10 + *parse - '0';
		parse++;
	}
	if (*parse == '.')
	{
		parse++;
		while (ft_strchr("0123456789", *parse) && *parse)
		{
			env->precision = env->precision * 10 + *parse - '0';
			parse++;
		}
	}
	return (parse);
}
