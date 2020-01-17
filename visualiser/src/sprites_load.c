/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:56:30 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:56:30 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	load_sprites_right(t_state *s)
{
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle01.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle02.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle03.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle04.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle05.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle06.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle07.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle08.png"));
	append_sprite(&s->walk_static_r, make_sprite(s, "./img/walkr_cycle01.png"));
}

void	load_sprites_left(t_state *s)
{
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle01.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle02.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle03.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle04.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle05.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle06.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle07.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle08.png"));
	append_sprite(&s->walk_static_l, make_sprite(s, "./img/walkl_cycle01.png"));
}

void	load_walk_static(t_state *s)
{
	s->walkl_static = IMG_LoadTexture(s->renderer, "./img/walkl_cycle01.png");
	s->walkr_static = IMG_LoadTexture(s->renderer, "./img/walkr_cycle01.png");
}

void	load_background(t_state *s)
{
	s->background = IMG_LoadTexture(s->renderer, "./img/background.png");
}

void	load_all_images(t_state *s)
{
	load_sprites_right(s);
	load_sprites_left(s);
	load_background(s);
	loop_sprites(s->walk_left);
	loop_sprites(s->walk_right);
	loop_sprites(s->walk_static_r);
	loop_sprites(s->walk_static_l);
}
