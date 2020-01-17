/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_movelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:27:17 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:27:18 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	create_move_list(t_anthill *anthill)
{
	t_pathlist	*pathlist;
	t_path		*path;
	t_ant		*ant;

	while (!ants_are_free(anthill))
	{
		pathlist = anthill->paths;
		while (pathlist && pathlist->valid)
		{
			path = pathlist->path;
			while (!path->room->is_start)
			{
				if ((ant = ant_here(anthill->colony, path->next->room)))
				{
					ant->current = path->room;
					append_move(&anthill->moves, move_ant(ant, path->room));
				}
				path = path->next;
			}
			pathlist = pathlist->next;
		}
		append_move(&anthill->moves, move_ant(NULL, NULL));
	}
}

/*
** Checks to see if all the ants are free, ie all the ants are in the next room.
*/

bool	ants_are_free(t_anthill *anthill)
{
	t_ant *ant;

	ant = anthill->colony;
	while (ant)
	{
		if (ant->current != anthill->end)
			return (false);
		ant = ant->next;
	}
	return (true);
}

/*
** Puts the ant in the first room in the pathlist that is not the start room.
*/

t_ant	*ant_here(t_ant *colony, t_room *room)
{
	t_ant *ant;

	ant = colony;
	while (ant)
	{
		if (ant->current == room)
			return (ant);
		ant = ant->next;
	}
	return (NULL);
}
