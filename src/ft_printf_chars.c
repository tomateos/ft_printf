/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:24:54 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/13 21:11:16 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(char *parse, t_print *env)
{
	env->out = (char*)malloc(sizeof(char) * (2));
	env->out[0] = '%';
	env->out[1] = '\0';
	env->count = 1;
	if (parse)
		env->type = 0;
	return (0);
}

int	print_char(char *parse, t_print *env)
{
	ft_putchar((char)env->arg);
	env->count = 1;
	if (parse)
		env->type = 0;
	return (0);
}

int	print_string(char *parse, t_print *env)
{
	ft_putstr((char*)env->arg);
	env->count = ft_strlen((char*)env->arg);
	if (parse)
		env->type = 0;
	return (0);
}
