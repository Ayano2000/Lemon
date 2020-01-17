/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:27:26 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:27:51 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

bool	direct_link(t_link *link)
{
	if (link->from->is_start && link->to->is_end)
		return (true);
	if (link->from->is_end && link->to->is_start)
		return (true);
	return (false);
}

t_room	*valid_neighbour(t_room *node, t_link *link)
{
	if (link->to == node && !link->from->parent && !link->from->is_start)
	{
		link->from->parent = node;
		return (link->from);
	}
	if (link->from == node && !link->to->parent && !link->to->is_start)
	{
		link->to->parent = node;
		return (link->to);
	}
	return (NULL);
}

t_room	*get_room_neighbour(t_room *node, t_link *link)
{
	t_room	*next;

	while (link)
	{
		if (direct_link(link))
		{
			link = link->next;
			continue;
		}
		if ((next = valid_neighbour(node, link)))
		{
			return (next);
		}
		link = link->next;
	}
	return (NULL);
}

void	graph_traverse(t_anthill *a)
{
	t_fifo	*queue;
	t_room	*node;
	t_room	*neighbour;

	polarize_room_parents(a);
	queue = NULL;
	fifo_push(&queue, a->start);
	while ((node = fifo_pop(&queue)))
		while ((neighbour = get_room_neighbour(node, a->connectors)))
			fifo_push(&queue, neighbour);
}
