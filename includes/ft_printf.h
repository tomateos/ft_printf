/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:11:09 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/10 22:28:35 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_conv
{
	void		*arg;
	char		type;
	int			width;
	int			precision;
	int			length;
	char		pad;
	char		sign;
	char		*out;
	int			count;
}				t_conv;

char			*g_conv;
char			*g_int;
char			*g_float;
char			*g_flag;

int				ft_printf(const char *format, ...);

#endif
