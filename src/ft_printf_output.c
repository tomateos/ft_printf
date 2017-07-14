/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:57:58 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/14 00:02:20 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_int(char *parse, t_print *env)
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
	if (*parse)
		env->sign = 0;
	return (0);
}
