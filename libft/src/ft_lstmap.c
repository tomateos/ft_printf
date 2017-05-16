/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:22:30 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:53:39 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a list created by the application of f to every elem of list.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!tmp)
		return (NULL);
	ret = tmp;
	while ((lst = lst->next))
	{
		tmp->next = f(lst);
		if (!tmp->next)
		{
			free(ret);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (ret);
}
