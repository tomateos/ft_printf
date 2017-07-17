/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:57:58 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/16 21:15:40 by tzhou            ###   ########.fr       */
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
		if (i < env->width)
			ft_putnchar(' ', env->width - i);
		env->count = i;
	}
	else
	{
		if (!env->width)
			env->width = env->count;
		if (env->width > env->count)
			ft_putnchar(' ', env->width - env->count);
		while (i < env->count)
			ft_putchar(env->out[i++]);
		env->count = env->width;
	}
	return (0);
}
