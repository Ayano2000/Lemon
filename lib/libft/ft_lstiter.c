/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:16:30 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 12:58:03 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** iterates through the list and applies the function f to it
*/

void	ft_lstiter(t_list *list, void (*f)(t_list *elem))
{
	while (list)
	{
		f(list);
		list = list->next;
	}
}
