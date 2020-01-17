/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:26:47 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:26:49 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** This will create the anthills first node and then add nodes for each room.
*/

t_anthill	*build_anthill(t_data **data)
{
	t_anthill	*anthill;

	anthill = new_anthill();
	read_loop(anthill, data);
	if (anthill->nb_ants <= 0)
		print_ant_error();
	return (anthill);
}
