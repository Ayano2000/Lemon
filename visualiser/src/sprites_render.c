/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 04:24:50 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 04:24:54 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	assign_sprite(t_state *s, t_ant *ant)
{
	if (ant->degrees > 90.0 && ant->degrees < 270.0)
		ant->sprite = s->walk_left;
	else
		ant->sprite = s->walk_right;
}
