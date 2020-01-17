/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 04:25:26 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 04:25:27 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

t_anthill	*new_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = malloc(sizeof(t_anthill))))
		return (false);
	anthill->room_count = 0;
	anthill->linear = NULL;
	anthill->colony = NULL;
	anthill->start = NULL;
	anthill->paths = NULL;
	anthill->nb_ants = 0;
	anthill->movelist = NULL;
	anthill->connectors = NULL;
	anthill->end = NULL;
	return (anthill);
}
