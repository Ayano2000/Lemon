/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:44:46 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:44:46 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

void	join_colony(t_anthill **anthill, t_ant *larvae)
{
	t_ant	*nurse;

	if (!(*anthill)->colony)
		(*anthill)->colony = larvae;
	else
	{
		nurse = (*anthill)->colony;
		while (nurse->next)
			nurse = nurse->next;
		nurse->next = larvae;
	}
}

int		hatch_ant(t_anthill *anthill, int x, int y, char *name)
{
	t_ant *egg;

	if (!(egg = malloc(sizeof(t_ant))))
		return (0);
	egg->x = x;
	egg->y = y;
	egg->is_moving = false;
	egg->path = NULL;
	egg->next = NULL;
	egg->following = NULL;
	egg->current = NULL;
	egg->degrees = 0;
	egg->gradient = 0;
	egg->name = ft_strdup(name);
	join_colony(&anthill, egg);
	return (1);
}
