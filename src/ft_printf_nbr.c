/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:50:34 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/14 21:00:39 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(t_print *env)
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
	return (display_int(env));
}

int	print_uint(t_print *env, unsigned int base)
{
	int	upper;

	upper = (env->type == 'X') ? 1 : 0;
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
	return (display_int(env));
}
