/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:32:02 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:32:03 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	handle_zoom(t_state *s)
{
	if (s->event.wheel.y > 0)
	{
		s->offset_x -= s->event.motion.x;
		s->offset_y -= s->event.motion.y;
		s->zoom++;
	}
	else if (s->event.wheel.y < 0)
	{
		s->offset_x -= s->event.motion.x;
		s->offset_y -= s->event.motion.y;
		s->zoom--;
	}
}

void	handle_events(t_state *s)
{
	while (SDL_PollEvent(&s->event))
	{
		if (s->event.type == SDL_QUIT)
			s->running = false;
		if (s->event.type == SDL_MOUSEWHEEL)
			handle_zoom(s);
		if (s->event.type == SDL_MOUSEBUTTONDOWN)
			if (s->event.button.button == SDL_BUTTON_LEFT)
				s->click = true;
		if (s->click)
		{
			if (s->event.type == SDL_MOUSEMOTION)
			{
				s->offset_x += s->event.motion.xrel;
				s->offset_y += s->event.motion.yrel;
			}
		}
		if (s->event.type == SDL_MOUSEBUTTONUP)
			s->click = false;
	}
}
