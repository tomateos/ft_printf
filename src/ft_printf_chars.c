/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:24:54 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/14 20:11:03 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_print *env)
{
	env->out = (char*)malloc(sizeof(char) * (2));
	env->out[0] = '%';
	env->out[1] = '\0';
	ft_putstr(env->out);
	env->count = 1;
	return (0);
}

int	print_char(t_print *env)
{
	ft_putchar((char)env->arg);
	env->count = 1;
	return (0);
}

int	print_string(t_print *env)
{
	ft_putstr((char*)env->arg);
	env->count = ft_strlen((char*)env->arg);
	return (0);
}
