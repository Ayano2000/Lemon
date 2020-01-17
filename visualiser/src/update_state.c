/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:33:28 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:33:29 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

void	update_ant_position(t_ant *ant)
{
	double gradient;
	double diff_x;
	double diff_y;

	diff_y = (ant->following->y - ant->current->y);
	diff_x = (ant->following->x - ant->current->x);
	if (diff_x == 0)
	{
		if (diff_y < 0)
			ant->y -= (0.05 * 0.6);
		else
			ant->y += (0.05 * 0.6);
		return ;
	}
	gradient = diff_y / diff_x;
	if (ant->degrees >= 90.0 && ant->degrees <= 270)
	{
		ant->x -= (0.05 * 0.6);
		ant->y -= gradient * 0.05 * 0.6;
	}
	else
	{
		ant->x += (0.05 * 0.6);
		ant->y += gradient * 0.05 * 0.6;
	}
}
