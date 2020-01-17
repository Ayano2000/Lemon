/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 04:25:20 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 04:25:21 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	set_ant_end_position(t_state *s, t_moves *moves)
{
	moves->ant->x = moves->to->x;
	moves->ant->y = moves->to->y;
	moves->ant->current = moves->ant->following;
	moves->ant->following = NULL;
	moves->ant->is_moving = false;
	if (moves->ant->degrees > 90.0 && moves->ant->degrees < 270.0)
		moves->ant->sprite = s->walk_static_l;
	else
		moves->ant->sprite = s->walk_static_r;
}

int		set_active_movelist(t_state *s, t_moves *moves)
{
	int moving;

	moving = 0;
	while (moves)
	{
		if (!moves->ant->following)
		{
			moves->ant->following = moves->to;
			moves->ant->degrees = get_ant_angle(moves->ant);
			assign_sprite(s, moves->ant);
		}
		moving++;
		if (ant_reached_dest(moves->ant))
		{
			set_ant_end_position(s, moves);
			moving--;
		}
		moves = moves->next;
	}
	return (moving);
}
