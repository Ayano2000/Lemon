/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 04:25:32 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 04:25:33 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
**	Create a new room link item.
**
**	int rtype :: Distinguish between start (1), end (2), or normal (0)
**	room types
**	char *line     :: will be split to get name, x, and y values
**	t_anthill      :: The anthill struct whose lineat will get the new room.
*/

void	new_room(int rtype, char *line, t_anthill **anthill)
{
	t_room	*new;
	t_room	*current;
	char	**data;

	new = init_room();
	current = (*anthill)->linear;
	data = NULL;
	if (rtype == START || rtype == END)
	{
		new->is_end = (rtype == END) ? true : false;
		new->is_start = (rtype == START) ? true : false;
	}
	else
	{
		data = ft_strsplit(line, ' ');
		new->name = ft_strdup(data[0]);
		new->x = ft_atod(data[1]);
		new->y = ft_atod(data[2]);
		free_array(data);
	}
	append_room_linear(&(*anthill)->linear, new);
}

/*
** initializes the rooms values and mallocs the struct.
*/

t_room	*init_room(void)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->next = NULL;
	new->link_count = 0;
	new->name = NULL;
	new->is_end = 0;
	new->is_start = 0;
	new->x = 0;
	new->y = 0;
	new->level = 0;
	new->in_path = false;
	new->occupied = false;
	new->links = NULL;
	return (new);
}

/*
**	Append a newly created room onto the end of the room linked list.
**
**	t_room *entry_point :: usually the first room ever created
**	t_room *new :: A pointer to the newly created room
*/

void	append_room_linear(t_room **entry_point, t_room *new)
{
	t_room		*current;

	current = (*entry_point);
	if (current == NULL)
	{
		(*entry_point) = new;
		return ;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
	}
	current->next = new;
}

t_room	*find_room_by_name(t_anthill **anthill, char *name)
{
	t_room *cursor;

	cursor = (*anthill)->linear;
	while (cursor)
	{
		if ((ft_strequ(name, cursor->name)) == 1)
		{
			return (cursor);
		}
		cursor = cursor->next;
	}
	return (NULL);
}
