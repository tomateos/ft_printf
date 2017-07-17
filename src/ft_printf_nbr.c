/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:50:34 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/16 22:39:52 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fix_flags(t_print *env)
{
	int		ind;
	char	*line;

	ind = 0;
	if (env->out[0] == '-')
	{
		env->sign = '-';
		ind = 1;
	}
	if (ft_strchr("+- ", env->sign))
	{
		if (!(line = ft_strdup(&env->out[ind])))
			exit(1);
		free(env->out);
		env->out = line;
	}
}

int			print_int(t_print *env)
{
	if (env->len == -3)
		env->out = ft_itoa((size_t)env->arg);
	if (env->len == -2)
		env->out = ft_itoa((signed char)env->arg);
	if (env->len == -1)
		env->out = ft_itoa((short)env->arg);
	if (env->len == 0)
		env->out = ft_itoa((int)env->arg);
	if (env->len == 1)
		env->out = ft_itoa((long)env->arg);
	if (env->len == 2)
		env->out = ft_itoa((long long)env->arg);
	if (env->len == 3)
		env->out = ft_itoa((intmax_t)env->arg);
	fix_flags(env);
	env->count = ft_strlen(env->out);
	return (display_int(env));
}

static int	fix_uflags(t_print *env)
{
	char	*line;

	line = 0;
	if (ft_strchr("oO", env->type) && env->out[0] != '0')
		if (!(line = ft_strjoin("0", env->out)))
			exit(1);
	if (ft_strchr("px", env->type))
		if (!(line = ft_strjoin("0x", env->out)))
			exit(1);
	if (ft_strchr("X", env->type))
		if (!(line = ft_strjoin("0X", env->out)))
			exit(1);
	if (line)
	{
		free(env->out);
		env->out = line;
	}
	return (0);
}

int			print_uint(t_print *env, unsigned int base)
{
	int	upper;

	upper = (env->type == 'X') ? 1 : 0;
	env->type == 'p' ? (env->len = 3) : 0;
	if (env->len == -3)
		env->out = ft_itoa_base((size_t)env->arg, base, upper);
	if (env->len == -2)
		env->out = ft_itoa_base((unsigned char)env->arg, base, upper);
	if (env->len == -1)
		env->out = ft_itoa_base((unsigned short)env->arg, base, upper);
	if (env->len == 0)
		env->out = ft_itoa_base((unsigned int)env->arg, base, upper);
	if (env->len == 1)
		env->out = ft_itoa_base((unsigned long)env->arg, base, upper);
	if (env->len == 2)
		env->out = ft_itoa_base((unsigned long long)env->arg, base, upper);
	if (env->len == 3)
		env->out = ft_itoa_base((uintmax_t)env->arg, base, upper);
	env->sign == '#' || env->type == 'p' ? fix_uflags(env) : 0;
	env->count = ft_strlen(env->out);
	return (display_int(env));
}
