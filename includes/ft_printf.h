/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:11:09 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/17 18:37:11 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define PRINT_CONV "sSpdDioOuUxXcCeEfFgGaAn%"

typedef struct	s_print
{
	void		*arg;
	char		type;
	int			width;
	int			precision;
	int			len;
	char		pad;
	char		sign;
	char		left;
	char		*out;
	int			count;
}				t_print;

/*
** PRINTF
*/

int				ft_printf(const char *format, ...);

/*
** Flag management
*/
int				get_length(char *parse, t_print *env, int ind);
int				get_width_prec(char *parse, t_print *env, int ind);
int				get_signs(char *parse, t_print *env, int ind);

/*
** Conversion management (non-numbers)
*/

int				print_percent(t_print *env);
int				print_char(t_print *env);
int				print_string(t_print *env);

/*
** Conversion management (numbers)
*/

int				print_int(t_print *env);
int				print_uint(t_print *env, unsigned int base);

/*
** Output management
*/

int				display_int(t_print *env);
int				display_char(t_print *env, char c);
int				display_str(t_print *env);

#endif
