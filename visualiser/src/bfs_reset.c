/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:32:22 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:32:33 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	reset_all_room_parents(t_anthill *a)
{
	t_room *room;

	room = a->linear;
	while (room)
	{
		room->parent = NULL;
		room = room->next;
	}
}

void	polarize_room_parents(t_anthill *a)
{
	t_pathlist	*pathlist;
	t_path		*path;

	reset_all_room_parents(a);
	pathlist = a->paths;
	while (pathlist)
	{
		path = pathlist->path;
		while (path)
		{
			path->room->parent = a->start;
			path = path->next;
		}
		pathlist = pathlist->next;
	}
	a->end->parent = NULL;
	a->start->parent = NULL;
}
