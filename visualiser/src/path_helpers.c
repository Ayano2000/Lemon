/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:31:46 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:31:47 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

t_path		*make_path_item(t_room *room)
{
	t_path *new;

	if (!(new = malloc(sizeof(t_path))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->room = room;
	return (new);
}

void		append_to_path(t_path **start, t_path *item)
{
	t_path *path;

	path = *start;
	if (!path)
		*start = item;
	else
	{
		while (path->next)
			path = path->next;
		path->next = item;
		item->prev = path;
	}
}

t_pathlist	*create_pathlist_item(t_path *path_start)
{
	t_pathlist *new;

	if (!path_start)
		return (NULL);
	if (!(new = malloc(sizeof(t_pathlist))))
		return (NULL);
	new->path = path_start;
	new->next = NULL;
	return (new);
}

t_room		*get(t_room *start, char *name)
{
	while (start)
	{
		if (!(ft_strcmp(start->name, name)))
			return (start);
		start = start->next;
	}
	return (NULL);
}

void		prepend_to_pathlist(t_pathlist **start, t_pathlist *new)
{
	t_pathlist *list;

	list = *start;
	if (!list)
		*start = new;
	else
	{
		new->next = list;
		*start = new;
	}
}
