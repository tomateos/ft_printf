/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:11:09 by tzhou             #+#    #+#             */
/*   Updated: 2017/03/13 13:32:46 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

extern char const	*g_conversion;
extern char const	*g_addr;
extern char const	*g_str;
extern char const	*g_char;
extern char const	*g_int;
extern char const	*g_float;
extern char const	*g_flags;
extern char const	*g_modifier;
extern char const	*g_detailed;
extern char const	*g_others;

int		ft_printf(const char *format, ...);

int		get_format(char *format, int count, va_list ap);
int		change_colors(char *format, int len);
int		parse_format(char *format, int len, int count, va_list ap);
int		convert_arg(char *temp, va_list ap);
int		print_addr(char *format, va_list ap);
int		print_str(char *format, va_list ap);
int		print_char(char *format, va_list ap);
int		print_int(char *format, va_list ap);
int		print_float(char *format, va_list ap);

//'+' takes priority over ' '

#endif
