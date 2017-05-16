/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:14:57 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:50:37 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes the address of a list. For every link, free its contents using del,
** free the link, and set the link's pointer to NULL.
*/

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*copy;

	copy = *alst;
	if (copy->next)
		ft_lstdel(&(copy->next), del);
	del(copy->content, copy->content_size);
	if (copy)
		free(copy);
	*alst = NULL;
}
