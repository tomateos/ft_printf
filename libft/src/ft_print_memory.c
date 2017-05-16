/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 23:09:00 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 23:09:06 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prints the hex and char values of size bytes of memory at pointer addr. If
** char value is not printable, print ".".
*/

static void	ft_puthex(unsigned char c)
{
	unsigned char	print;

	if (c >= 0 && c < 10)
		print = c + 48;
	if (c >= 10 && c < 16)
		print = c + 87;
	write(1, &print, 1);
}

static void	print_hex(unsigned char *array, size_t i)
{
	size_t			j;
	size_t			k;
	unsigned char	c;

	j = i % 4 + 1;
	k = 2 * (4 - j);
	while (j > 0)
	{
		j--;
		c = array[i - j];
		ft_puthex(c / 16);
		ft_puthex(c % 16);
		if (j % 2 == 0)
			write(1, " ", 1);
	}
	while (k > 0)
	{
		k--;
		write(1, " ", 1);
		if (k % 4 == 3)
			write(1, " ", 1);
	}
}

static void	print_chars(unsigned char *array, size_t i)
{
	size_t			j;
	unsigned char	c;

	j = i % 16 + 1;
	while (j > 0)
	{
		j--;
		c = array[i - j];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
	}
	write(1, "\n", 1);
}

void		ft_print_memory(const void *addr, size_t size)
{
	unsigned char	*temp;
	size_t			i;
	unsigned int	spaces;

	temp = (unsigned char*)addr;
	i = 0;
	while (i < size)
	{
		if (i % 4 == 3)
			print_hex(temp, i);
		if (i % 16 == 15)
			print_chars(temp, i);
		i++;
	}
	i--;
	if (i % 4 != 3)
		print_hex(temp, i);
	spaces = (i / 4 + 1) % 4;
	ft_putnchar(' ', spaces * 10 + 1);
	if (i % 16 != 15)
		print_chars(temp, i);
}
