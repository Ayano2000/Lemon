/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:31:25 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:31:26 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	render_paths(t_state *s, t_path *path)
{
	double x1;
	double x2;
	double y1;
	double y2;

	x1 = X(s, path->room->x);
	y1 = Y(s, path->room->y);
	x2 = X(s, path->next->room->x);
	y2 = Y(s, path->next->room->y);
	SDL_RenderDrawLine(s->renderer, x1, y1, x2, y2);
}

void	draw_paths(t_state *s)
{
	t_pathlist	*list;
	t_path		*path;

	list = s->paths;
	SDL_SetRenderDrawColor(s->renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	while (list)
	{
		path = list->path;
		while (path && path->next)
		{
			render_paths(s, path);
			path = path->next;
		}
		list = list->next;
	}
}
