/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:14:23 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/16 17:01:01 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_length(char *parse, t_print *env, int ind)
{
	char	check;

	if (env->len)
		exit(1);
	check = 1;
	if (ft_strchr("SDOUC", env->type))
		env->len++;
	while (ft_strchr("hljz", parse[ind]) && parse[ind])
	{
		if (parse[ind] == 'h')
			(env->len > 0 || env->len < -1) ? (check = 0) : (env->len--);
		if (parse[ind] == 'l')
			(env->len < 0 || env->len > 1) ? (check = 0) : (env->len++);
		if (parse[ind] == 'j')
			(env->len != 0) ? (check = 0) : (env->len += 3);
		if (parse[ind] == 'z')
			(env->len != 0) ? (check = 0) : (env->len -= 3);
		if (!check)
			exit(1);
		ind++;
	}
	return (ind);
}

int	get_width_prec(char *parse, t_print *env, int ind)
{
	if (env->width || env->precision || env->len)
		exit(1);
	if (parse[ind] == '0')
	{
		env->pad = '0';
		ind++;
	}
	while (ft_strchr("0123456789", parse[ind]) && parse[ind])
	{
		env->width = env->width * 10 + parse[ind] - '0';
		ind++;
	}
	if (parse[ind] == '.')
	{
		ind++;
		while (ft_strchr("0123456789", parse[ind]) && parse[ind])
		{
			env->precision = env->precision * 10 + parse[ind] - '0';
			ind++;
		}
	}
	return (ind);
}

int	get_signs(char *parse, t_print *env, int ind)
{
	if (parse[ind] == '+')
		env->sign = '+';
	if (parse[ind] == '-')
		env->left = 1;
	if (parse[ind] == '#')
		env->sign = '#';
	if (parse[ind] == ' ')
		env->sign = ' ';
	return (ind + 1);
}
