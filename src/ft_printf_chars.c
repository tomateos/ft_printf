/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:24:54 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/16 21:07:01 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_print *env)
{
	if (!(env->out = (char*)malloc(sizeof(char) * (2))))
		exit(1);
	env->out[0] = '%';
	env->out[1] = '\0';
	ft_putstr(env->out);
	env->count = 1;
	return (display_str(env));
}

int	print_char(t_print *env)
{
	if (!(env->out = (char*)malloc(sizeof(char) * (2))))
		exit(1);
	env->out[0] = (char)env->arg;
	env->out[1] = '\0';
	ft_putstr(env->out);
	env->count = 1;
	return (display_str(env));
}

int	print_string(t_print *env)
{
	if (env->arg)
	{
		if (!(env->out = ft_strdup((char*)env->arg)))
			exit(1);
	}
	else
	{
		if (!(env->out = ft_strdup("(null)")))
			exit(1);
	}
	env->count = ft_strlen(env->out);
	return (display_str(env));
}
