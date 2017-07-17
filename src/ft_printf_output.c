/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:57:58 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/17 01:28:04 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pad_spaces(t_print *env)
{
	int	i;
	int	len;

	i = -1;
	len = env->width;
	if (!env->left && env->precision > env->count)
		len -= env->precision;
	else if (!env->left && env->count > env->precision)
		len -= env->count;
	else
		len -= env->count;
	if (!env->left)
		ft_strchr("-+ ", env->sign) ? len -= 1 : 0;
	while (++i < len)
		ft_putchar(' ');
	return (i);
}

static int	pad_zeroes(t_print *env)
{
	int	i;

	i = 0;
	ft_strchr("+- ", env->sign) ? write(1, &env->sign, 1) : 0;
	if (env->count < env->precision)
		i += env->precision - env->count;
	if (env->pad == '0' && !env->left && !env->precision)
		i += env->width - env->count;
	ft_putnchar('0', i);
	ft_putstr(env->out);
	i += ft_strlen(env->out);
	return (i);
}

int			display_int(t_print *env)
{
	int	i;

	i = 0;
	if (!env->left && env->pad != '0')
		i = pad_spaces(env);
	env->count = pad_zeroes(env);
	if (env->left)
		i = pad_spaces(env);
	ft_strchr("+- ", env->sign) ? i += 1 : 0;
	env->count += i;
	return (0);
}

int			display_str(t_print *env)
{
	int		i;

	if (env->precision && env->precision < env->count)
		env->count = env->precision;
	env->width < env->count ? (env->width = env->count) : 0;
	i = 0;
	if (env->left)
	{
		while (env->out[i] && i < env->count)
			ft_putchar(env->out[i++]);
		if (i < env->width)
			ft_putnchar(' ', env->width - i);
	}
	else
	{
		if (env->width > env->count)
			ft_putnchar(' ', env->width - env->count);
		while (env->out[i] && i < env->count)
			ft_putchar(env->out[i++]);
		env->count = env->width;
	}
	env->count = env->width;
	return (0);
}
