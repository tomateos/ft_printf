/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:57:03 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:47:10 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a link containing content and content_size with next set to NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*lst;
	unsigned char	*temp;
	size_t			i;

	lst = (t_list*)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	temp = (unsigned char*)content;
	if (!temp)
		content_size = 0;
	lst->content_size = content_size;
	lst->content = (void*)malloc(sizeof(content_size));
	if (!lst->content)
		return (NULL);
	i = 0;
	while (i < content_size)
	{
		((unsigned char*)lst->content)[i] = temp[i];
		i++;
	}
	if (!temp)
		lst->content = NULL;
	lst->next = NULL;
	return (lst);
}
