/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:20:37 by tzhou             #+#    #+#             */
/*   Updated: 2016/12/18 22:52:35 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies function f to every elem of list.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*cpy;

	cpy = lst;
	while (cpy)
	{
		f(cpy);
		cpy = cpy->next;
	}
}
