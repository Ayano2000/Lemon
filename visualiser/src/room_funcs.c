/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:55:11 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:55:11 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	append_room(t_room *entry_point, t_room *new)
{
	t_room		*current;

	current = entry_point;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_room	*init_room_g(char *name, int x, int y)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->next = NULL;
	new->link_count = 0;
	new->name = ft_strdup(name);
	new->level = -1;
	new->parent = NULL;
	new->is_end = 0;
	new->is_start = 0;
	new->x = x;
	new->y = y;
	new->links = NULL;
	return (new);
}

t_room	*get_room(t_anthill *anthill, char *name)
{
	t_room *cursor;

	cursor = anthill->linear;
	while (cursor)
	{
		if (!(ft_strcmp(name, cursor->name)))
		{
			return (cursor);
		}
		cursor = cursor->next;
	}
	return (NULL);
}
