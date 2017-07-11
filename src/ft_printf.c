/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 21:09:56 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/10 22:30:25 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		store_env(char *parse, t_conv *env, void *arg, char type)
{
	ft_putstr(parse);
	env->arg = arg;
	env->type = type;
	return (0);
}

int		parse_format(char *parse, va_list ap)
{
	t_conv	*env;
	int		i;
	void	*arg;

	if (!(env = (t_conv*)malloc(sizeof(t_conv))))
		exit(1);
	ft_bzero((void*)env, sizeof(t_conv));
	i = 0;
	while (!ft_strchr(g_conv, parse[i]))
		i++;
	if (parse[i] != '%')
		arg = va_arg(ap, void*);
	else
		arg = NULL;
	return (store_env(parse, env, arg, parse[i]));
}

int		get_format(const char **format, va_list ap)
{
	int			i;
	char		*tmp;
	char		*parse;
	int			count;

	i = 1;
	tmp = (char*)*format;
	while (!ft_strchr(g_conv, tmp[i]))
	{
		if (!tmp[i])
			exit(1);
		i++;
	}
	if (!(parse = ft_strndup(&tmp[1], i + 1)))
		exit(1);
	while (i-- > 0)
		++*format;
	count = parse_format(parse, ap);
	free(parse);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	int		out;
	va_list	ap;

	va_start(ap, format);
	out = 0;
	while (*format)
	{
		if (*format == '%')
			out += get_format(&format, ap);
		else
			out += (int)write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (out);
}
