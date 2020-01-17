/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_hatchery.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 04:26:13 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 04:26:15 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

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

int		hatch_ant(t_anthill *anthill, char *name)
{
	t_ant *egg;

	if (!(egg = malloc(sizeof(t_ant))))
		return (0);
	egg->next = NULL;
	egg->following = NULL;
	egg->current = anthill->start;
	egg->name = name;
	join_colony(&anthill, egg);
	return (1);
}

void	create_colony(t_anthill *anthill)
{
	int i;

	i = 0;
	while (i < anthill->nb_ants)
		hatch_ant(anthill, ft_itoa(++i));
}
