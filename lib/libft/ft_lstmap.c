/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:33:52 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 15:31:23 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates a list lst and applies the function f to each link to
** create a “fresh” list using malloc, resulting from the successive
** applications of f. If the allocation fails, the function
** returns NULL.
*/

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *new;
	t_list *start;

	temp = f(list);
	if (!(new = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	start = new;
	list = list->next;
	while (list != NULL)
	{
		temp = f(list);
		if (!(new->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		new = new->next;
		list = list->next;
	}
	return (start);
}
