/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:57:18 by tzhou             #+#    #+#             */
/*   Updated: 2017/01/24 19:34:20 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*store_next_line(char *temp, char *last)
{
	char	*out;
	int		cut;

	if (ft_strchr(temp, '\n'))
	{
		cut = ft_strlocate(temp, '\n');
		if (!(out = ft_strndup(temp, cut)))
			return (NULL);
		ft_bzero(last, BUFF_SIZE + 1);
		ft_strcpy(last, ft_strchr(temp, '\n') + 1);
	}
	else
	{
		if (!(out = ft_strdup(temp)))
			return (NULL);
		ft_bzero(last, BUFF_SIZE + 1);
	}
	return (out);
}

static int	read_next_line(const int fd, char **temp)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*copy;
	int			flag;

	flag = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		flag = 1;
		if (!(copy = ft_strjoin(*temp, buff)))
			return (-1);
		free(*temp);
		if (!(*temp = ft_strdup(copy)))
			return (-1);
		free(copy);
		if (ft_strchr(*temp, '\n'))
			break ;
	}
	return ((ret < 0 || !flag) ? ret : 1);
}

static char	*get_last_line(char *last)
{
	char	*temp;

	if (!last)
	{
		if (!(temp = ft_strnew(1)))
			return (NULL);
	}
	else
	{
		if (!(temp = ft_strdup(last)))
			return (NULL);
		ft_bzero(last, BUFF_SIZE + 1);
	}
	return (temp);
}

int			get_next_line(const int fd, char **line)
{
	static char	last[BUFF_SIZE + 1];
	char		empty[1];
	int			ret;
	char		*temp;

	if (fd < 0 || !line || read(fd, empty, 0) < 0)
		return (-1);
	if (!(temp = get_last_line(last)))
		return (-1);
	ret = 1;
	if (!ft_strchr(temp, '\n'))
	{
		if ((ret = read_next_line(fd, &temp)) < 0)
			return (-1);
	}
	if (!(*line = store_next_line(temp, last)))
		return (-1);
	free(temp);
	if (ret == 0 && ft_strlen(*line) < 1)
		return (0);
	return (1);
}
