/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:57:58 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/17 13:10:03 by tzhou            ###   ########.fr       */
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

static int	pad_zeroes(t_print *env, int zeroes)
{
	char	*line;
	int		size;
	int		ind;

	size = ft_strlen(env->out) + zeroes;
	ft_strchr("+- ", env->sign) ? size += 1 : 0;
	if (!(line = (char*)malloc(sizeof(char) * (size + 1))))
		exit(1);
	ft_bzero(line, size + 1);
	ind = 0;
	ft_strchr("+- ", env->sign) ? (line[ind++] = env->sign) : 0;
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

	size = ft_strlen(env->out);
	ft_strchr("+- ", env->sign) ? size += 1 : 0;
	zeroes = 0;
	env->width < env->precision ? (env->width = env->precision) : 0;
	env->width < size ? (env->width = size) : 0;
	if (!env->left && env->pad == '0')
		zeroes = env->width - size;
	else
	{
		ft_strchr("+- ", env->sign) ? size -= 1 : 0;
		size < env->precision ? zeroes = env->precision - size : 0;
	}
	pad_zeroes(env, zeroes);
	size = env->width - env->count;
	if (size > 0)
		pad_spaces(env, size);
	ft_putstr(env->out);
	env->count = ft_strlen(env->out);
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
