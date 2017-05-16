/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:07:33 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:49:08 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes the address of a link, frees its contents using del, frees the link,
** and sets the link's pointer to NULL.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*copy;

	copy = *alst;
	del(copy->content, copy->content_size);
	if (copy)
		free(copy);
	*alst = NULL;
}
