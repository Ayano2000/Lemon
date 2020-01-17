/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_pathing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:27:55 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:27:56 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_path	*new_path_node(t_room *room)
{
	t_path *path;

	if (!(path = malloc(sizeof(t_path))))
		return (NULL);
	path->next = NULL;
	path->room = room;
	return (path);
}

void	append_path(t_path **start, t_room *room)
{
	t_path *head;

	if (*start)
	{
		head = *start;
		while (head->next)
			head = head->next;
		head->next = new_path_node(room);
	}
	else
		*start = new_path_node(room);
}

void	destroy_unusable_path(t_path *path)
{
	t_path *previous;

	if (!path)
		return ;
	while (path->next)
	{
		previous = path;
		path = path->next;
		free(previous);
	}
}

t_path	*get_shortest_path(t_anthill *a, t_room *end_room)
{
	t_path *path;

	path = NULL;
	while (end_room->parent)
	{
		append_path(&path, end_room);
		end_room = end_room->parent;
	}
	if (!end_room->is_start)
	{
		destroy_unusable_path(path);
		return (NULL);
	}
	append_path(&path, a->start);
	return (path);
}
