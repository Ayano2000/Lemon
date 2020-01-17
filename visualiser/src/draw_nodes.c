/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:31:13 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:31:15 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	draw_defined_node(t_state *s, t_room *room)
{
	if (room->is_start)
	{
		stringRGBA(s->renderer, X(s, room->x) + 5,
			Y(s, room->y) - 24, "START", 255, 255, 255, 255);
		filledCircleRGBA(s->renderer, X(s, room->x),
			Y(s, room->y), 10, RGBA_RED);
	}
	else if (room->is_end)
	{
		stringRGBA(s->renderer, X(s, room->x) + 5,
			Y(s, room->y) - 24, "END", 255, 255, 255, 255);
		filledCircleRGBA(s->renderer, X(s, room->x),
			Y(s, room->y), 10, RGBA_GREEN);
	}
	else
	{
		stringRGBA(s->renderer, X(s, room->x) + 5,
			Y(s, room->y) - 24, room->name, 255, 255, 255, 255);
		filledCircleRGBA(s->renderer, X(s, room->x),
			Y(s, room->y), 7, RGBA_WHITE);
	}
}

void	draw_nodes(t_state *s)
{
	t_room *room;

	room = s->anthill->linear;
	SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	while (room)
	{
		draw_defined_node(s, room);
		room = room->next;
	}
}
