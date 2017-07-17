/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:57:58 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/16 21:06:16 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_int(t_print *env)
{
	if (!env->pad)
		env->pad = ' ';
	env->count = ft_strlen(env->out);
	if (env->left)
	{
		ft_putstr(env->out);
		while (env->count < env->width)
		{
			ft_putchar(env->pad);
			env->count++;
		}
	}
	else
	{
		while (env->count < env->width)
		{
			ft_putchar(env->pad);
			env->count++;
		}
		ft_putstr(env->out);
	}
	return (0);
}

int	display_str(t_print *env)
{
	int		i;

	if (env->precision && env->count < env->precision)
		env->count = env->precision;
	i = 0;
	if (env->left)
	{
		while (i < env->count)
			ft_putchar(env->out[i++]);
		while (env->count < env->width)
		{
			ft_putchar(' ');
			env->count++;
		}
	}
	else
	{
		if (!env->width)
			env->width = env->precision;
		if (env->width > env->precision)
			ft_putnchar(' ', env->width - env->precision);
		while (i < env->precision)
			ft_putchar(env->out[i++]);
	}
	return (0);
}
