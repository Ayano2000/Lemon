/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:33:34 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:33:35 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

void	draw_links(t_state *s)
{
	t_link	*link;
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	link = s->anthill->connectors;
	SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	while (link)
	{
		x1 = X(s, link->from->x);
		x2 = X(s, link->to->x);
		y1 = Y(s, link->from->y);
		y2 = Y(s, link->to->y);
		SDL_RenderDrawLine(s->renderer, x1, y1, x2, y2);
		link = link->next;
	}
}

void	draw_stats(t_state *s)
{
	stringRGBA(s->renderer, 5, 5, "Zoom: ", 255, 255, 255, 255);
	stringRGBA(s->renderer, 50, 5, ft_itoa(s->zoom), 255, 255, 255, 255);
}

void	set_sprite_position(t_state *s, SDL_Rect *r, t_ant *army)
{
	r->x = X(s, army->x) - SPRITE_W / 2;
	r->y = Y(s, army->y) - SPRITE_H;
	r->h = SPRITE_H;
	r->w = SPRITE_W;
}

void	draw_ants(t_state *s)
{
	t_ant		*army;
	SDL_Rect	r;

	army = s->anthill->colony;
	SDL_SetRenderDrawColor(s->renderer, 200, 200, 200, 255);
	stringRGBA(s->renderer, 5, 40, ft_itoa(s->frame), 255, 255, 255, 255);
	while (army)
	{
		stringRGBA(s->renderer, X(s, army->x) - 35,
			Y(s, army->y) - SPRITE_H - 10, army->name, 255, 255, 255, 255);
		set_sprite_position(s, &r, army);
		if (army->sprite)
		{
			if (s->frame % 5 == 0)
			{
				if (army->sprite && army->sprite->next)
					army->sprite = army->sprite->next;
				else
					army->sprite = s->walk_right;
			}
			SDL_RenderCopy(s->renderer, army->sprite->img, NULL, &r);
		}
		army = army->next;
	}
}

void	draw_links_list(t_state *s)
{
	int		y;
	t_link	*cur;
	char	*str;
	char	*str2;

	cur = s->anthill->connectors;
	y = 20;
	while (cur)
	{
		str = ft_strjoin(cur->from->name, " => ");
		str2 = ft_strjoin(str, cur->to->name);
		stringRGBA(s->renderer, 5, y, str2, 255, 255, 255, 255);
		free(str);
		free(str2);
		y += 10;
		cur = cur->next;
	}
}
