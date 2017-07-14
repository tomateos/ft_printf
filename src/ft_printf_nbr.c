/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:50:34 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/13 23:13:41 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(char *parse, t_print *env)
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
	return (display_int(parse, env));
}

int	print_uint(char *parse, t_print *env)
{
	if (env->len == -3)
		env->out = ft_itoa_base((size_t)env->arg, 10, 0);
	if (env->len == -2)
		env->out = ft_itoa_base((unsigned char)env->arg, 10, 0);
	if (env->len == -1)
		env->out = ft_itoa_base((unsigned short)env->arg, 10, 0);
	if (env->len == 0)
		env->out = ft_itoa_base((unsigned int)env->arg, 10, 0);
	if (env->len == 1)
		env->out = ft_itoa_base((unsigned long)env->arg, 10, 0);
	if (env->len == 2)
		env->out = ft_itoa_base((unsigned long long)env->arg, 10, 0);
	if (env->len == 3)
		env->out = ft_itoa_base((uintmax_t)env->arg, 10, 0);
	return (display_int(parse, env));
}

int	print_oct(char *parse, t_print *env)
{
	if (env->len == -3)
		env->out = ft_itoa_base((size_t)env->arg, 8, 0);
	if (env->len == -2)
		env->out = ft_itoa_base((unsigned char)env->arg, 8, 0);
	if (env->len == -1)
		env->out = ft_itoa_base((unsigned short)env->arg, 8, 0);
	if (env->len == 0)
		env->out = ft_itoa_base((unsigned int)env->arg, 8, 0);
	if (env->len == 1)
		env->out = ft_itoa_base((unsigned long)env->arg, 8, 0);
	if (env->len == 2)
		env->out = ft_itoa_base((unsigned long long)env->arg, 8, 0);
	if (env->len == 3)
		env->out = ft_itoa_base((uintmax_t)env->arg, 8, 0);
	return (display_int(parse, env));
}

int	print_hex(char *parse, t_print *env)
{
	int	upper;

	env->type == 'X' ? upper = 1 : 0;
	if (env->len == -3)
		env->out = ft_itoa_base((size_t)env->arg, 16, upper);
	if (env->len == -2)
		env->out = ft_itoa_base((unsigned char)env->arg, 16, upper);
	if (env->len == -1)
		env->out = ft_itoa_base((unsigned short)env->arg, 16, upper);
	if (env->len == 0)
		env->out = ft_itoa_base((unsigned int)env->arg, 16, upper);
	if (env->len == 1)
		env->out = ft_itoa_base((unsigned long)env->arg, 16, upper);
	if (env->len == 2)
		env->out = ft_itoa_base((unsigned long long)env->arg, 16, upper);
	if (env->len == 3)
		env->out = ft_itoa_base((uintmax_t)env->arg, 16, upper);
	return (display_int(parse, env));
}
