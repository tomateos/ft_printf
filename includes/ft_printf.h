/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:11:09 by tzhou             #+#    #+#             */
/*   Updated: 2017/07/13 23:11:17 by tzhou            ###   ########.fr       */
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
char			*get_length(char *parse, t_print *env);
char			*get_width_prec(char *parse, t_print *env);

/*
** Conversion management (non-numbers)
*/

int				print_percent(char *parse, t_print *env);
int				print_char(char *parse, t_print *env);
int				print_string(char *parse, t_print *env);

/*
** Conversion management (numbers)
*/

int				print_int(char *parse, t_print *env);
int				print_uint(char *parse, t_print *env);
int				print_oct(char *parse, t_print *env);
int				print_hex(char *parse, t_print *env);

/*
** Output management
*/

int				display_int(char *parse, t_print *env);

#endif
