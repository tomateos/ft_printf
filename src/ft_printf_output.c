/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:57:58 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/17 18:35:48 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pad_spaces(t_print *env, int size)
{
	char	*line;
	char	*space;

	if (!(space = (char*)malloc(sizeof(char) * (size + 1))))
		exit(1);
	space[size] = '\0';
	ft_memset(space, ' ', size);
	if (env->left)
	{
		if (!(line = ft_strjoin(env->out, space)))
			exit(1);
	}
	else
	{
		if (!(line = ft_strjoin(space, env->out)))
			exit(1);
	}
	free(space);
	free(env->out);
	env->out = line;
	return (0);
}

static int	pad_zeroes(t_print *env, int zeroes, int sign)
{
	char	*line;
	int		size;
	int		ind;

	if (zeroes < 0)
		zeroes = 0;
	size = ft_strlen(env->out) + zeroes + sign;
	if (!(line = (char*)malloc(sizeof(char) * (size + 1))))
		exit(1);
	ft_bzero(line, size + 1);
	ind = 0;
	sign ? (line[ind++] = env->sign) : 0;
	ft_memset(&line[ind], '0', zeroes);
	ft_strcat(line, env->out);
	free(env->out);
	env->out = line;
	env->count = ft_strlen(env->out);
	return (0);
}

int			display_int(t_print *env)
{
	int		zeroes;
	int		size;
	int		sign;

	sign = (env->sign && ft_strchr("+- ", env->sign)) ? 1 : 0;
	size = ft_strlen(env->out);
	if (!env->left && env->width > size && env->pad == '0')
	{
		if (env->precision)
			zeroes = env->precision - size - sign;
		else
			zeroes = env->width - size - sign;
	}
	else
		zeroes = env->precision - size;
	pad_zeroes(env, zeroes, sign);
	size = env->width - env->count;
	if (size > 0)
		pad_spaces(env, size);
	ft_putstr(env->out);
	env->count = ft_strlen(env->out);
	return (0);
}

int			display_char(t_print *env, char c)
{
	int		size;

	size = env->width - env->count;
	if (size > 0)
		pad_spaces(env, size);
	if (env->left)
		ft_putchar(c);
	ft_putstr(env->out);
	if (!env->left)
		ft_putchar(c);
	env->count = ft_strlen(env->out) + 1;
	return (0);
}

int			display_str(t_print *env)
{
	char	*line;
	int		size;

	if (env->precision && env->precision < env->count)
	{
		if (!(line = ft_strndup(env->out, env->precision)))
			exit(1);
		free(env->out);
		env->out = line;
		env->count = ft_strlen(env->out);
	}
	size = env->width - env->count;
	if (size > 0)
		pad_spaces(env, size);
	ft_putstr(env->out);
	env->count = ft_strlen(env->out);
	return (0);
}
