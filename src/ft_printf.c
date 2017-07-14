/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 21:09:56 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/14 00:19:31 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		clear_env(t_print *env)
{
	free(env->out);
	free(env);
}

static int	choose_conv(char *parse, t_print *env)
{
	env->type == '%' ? print_percent(parse, env) : 0;
	ft_strchr("cC", env->type) ? print_char(parse, env) : 0;
	ft_strchr("sS", env->type) ? print_string(parse, env) : 0;
	ft_strchr("idD", env->type) ? print_int(parse, env) : 0;
	ft_strchr("oO", env->type) ? print_oct(parse, env) : 0;
	ft_strchr("uU", env->type) ? print_uint(parse, env) : 0;
	ft_strchr("pxX", env->type) ? print_hex(parse, env) : 0;
	if (ft_strchr("eEfFgGaAn", env->type))
		exit(1);
	return (env->count);
}

static int	parse_format(char *parse, va_list ap, char type)
{
	t_print	*env;
	int		i;
	int		count;

	if (!(env = (t_print*)malloc(sizeof(t_print))))
		exit(1);
	ft_bzero((void*)env, sizeof(t_print));
	env->type = type;
	if (env->type != '%')
		env->arg = va_arg(ap, void*);
	i = 0;
	while (!ft_strchr(PRINT_CONV, parse[i]))
	{
		if (ft_strchr(".0123456789", parse[i]))
			i = get_width_prec(parse, env, i);
		else if (ft_strchr("hljz", parse[i]))
			i = get_length(parse, env, i);
		else
			i++;
	}
	if (!env->pad)
		env->pad = ' ';
	count = choose_conv(parse, env);
	clear_env(env);
	return (count);
}

static int	get_format(const char **format, va_list ap)
{
	int		i;
	char	*tmp;
	char	*parse;
	int		count;

	i = 1;
	tmp = (char*)*format;
	while (!ft_strchr(PRINT_CONV, tmp[i]))
	{
		if (!tmp[i])
			exit(1);
		i++;
	}
	if (!(parse = ft_strndup(&tmp[1], i + 1)))
		exit(1);
	count = parse_format(parse, ap, tmp[i]);
	while (i-- > 0)
		++*format;
	free(parse);
	return (count);
}

int			ft_printf(const char *format, ...)
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