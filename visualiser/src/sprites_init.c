/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 04:01:32 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 04:01:36 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

t_img	*make_sprite(t_state *s, char *filename)
{
	t_img *new;

	if (!(new = malloc(sizeof(t_img))))
		return (NULL);
	new->img = IMG_LoadTexture(s->renderer, filename);
	new->next = NULL;
	return (new);
}

void	append_sprite(t_img **start, t_img *new)
{
	t_img *sprite;

	sprite = *start;
	if (!sprite)
		*start = new;
	else
	{
		while (sprite->next)
			sprite = sprite->next;
		sprite->next = new;
	}
}

void	loop_sprites(t_img *start)
{
	t_img *cursor;

	cursor = start;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = start;
}
