/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:32:16 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:32:17 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

t_path		*append_path_here(t_path *path, t_room *room)
{
	t_path *p;
	t_path *cur;

	p = malloc(sizeof(t_path));
	p->next = NULL;
	p->room = room;
	if (!path)
		path = p;
	else
	{
		cur = path;
		while (cur->next)
			cur = cur->next;
		cur->next = p;
	}
	return (path);
}

bool		visited(t_path *path, t_room *room)
{
	t_path *cursor;

	cursor = path;
	while (cursor)
	{
		if (cursor->room == room)
			return (true);
		cursor = cursor->next;
	}
	return (false);
}

void		move(t_path **callback, t_path *path, t_room *from, t_room *to)
{
	int i;

	i = 0;
	if (from)
		append_path_here(path, from);
	if (to && to->is_end)
		*callback = path;
	if (*callback)
		return ;
	while (i < to->link_count)
	{
		if (!(visited(path, to->links[i])))
			move(callback, path, to, to->links[i]);
		i++;
	}
}

t_movelist	*make_movelist_item(t_moves *moves)
{
	t_movelist *new;

	if (!(new = malloc(sizeof(t_movelist))))
		return (NULL);
	new->next = NULL;
	new->active = false;
	new->complete = false;
	new->moves = moves;
	return (new);
}

void		append_to_movelist(t_movelist **start, t_movelist *new)
{
	t_movelist *mvlist;

	mvlist = *start;
	if (!mvlist)
		*start = new;
	else
	{
		while (mvlist->next)
			mvlist = mvlist->next;
		mvlist->next = new;
	}
}
