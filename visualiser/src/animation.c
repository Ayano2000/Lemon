/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:33:21 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:33:23 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	animation_loop(t_state *state)
{
	int start;
	int time;
	int sleep_time;

	while (state->running)
	{
		start = SDL_GetTicks();
		handle_events(state);
		update_state(state);
		render_state(state);
		time = SDL_GetTicks() - start;
		if (time < 0)
			continue;
		sleep_time = 16 - time;
		if (sleep_time > 0)
			SDL_Delay(sleep_time);
		if (state->frame > 60)
			state->frame = 0;
		state->frame++;
	}
}

void	draw_path(t_state *s)
{
	t_path	*route;
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	route = s->path;
	SDL_SetRenderDrawColor(s->renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	while (route)
	{
		if (route->next)
		{
			x1 = X(s, route->room->x);
			x2 = X(s, route->next->room->x);
			y1 = Y(s, route->room->y);
			y2 = Y(s, route->next->room->y);
		}
		route = route->next;
	}
}
