/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:54:00 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:54:00 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

t_moves		*make_move(t_ant *ant, t_room *to)
{
	t_moves *move;

	if (!(move = malloc(sizeof(t_moves))))
		return (NULL);
	move->next = NULL;
	move->to = to;
	move->ant = ant;
	return (move);
}

t_ant		*ant_by_name(t_ant *ants, char *name)
{
	while (ants)
	{
		if (!(ft_strcmp(ants->name, name)))
			return (ants);
		ants = ants->next;
	}
	return (NULL);
}

t_moves		*deserialise_move(t_anthill *anthill, char *line)
{
	char	*ptr;
	t_ant	*ant;
	t_room	*room;

	line++;
	ptr = ft_strchr(line, '-');
	*ptr = 0;
	ant = ant_by_name(anthill->colony, line);
	room = get(anthill->linear, (ptr + 1));
	*ptr = '-';
	return (make_move(ant, room));
}

void		append_move(t_moves **start, t_moves *new)
{
	t_moves *moves;

	moves = *start;
	if (!moves)
		*start = new;
	else
	{
		while (moves->next)
			moves = moves->next;
		moves->next = new;
	}
}

void		place_ants_on_start(t_state *s)
{
	t_ant *ant;

	ant = s->anthill->colony;
	while (ant)
	{
		ant->x = s->anthill->start->x;
		ant->y = s->anthill->start->y;
		ant->sprite = s->walk_static_r;
		ant->current = s->anthill->start;
		ant = ant->next;
	}
}
