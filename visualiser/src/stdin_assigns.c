/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_assigns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:32:09 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:32:10 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	assign_ants(t_anthill *anthill, char *str)
{
	int i;

	anthill->nb_ants = ft_atoi(str);
	i = 0;
	while (i < anthill->nb_ants)
	{
		hatch_ant(anthill, 0, 0, ft_itoa(i + 1));
		i++;
	}
}

void	assign_link(t_anthill *ah, char *str)
{
	char	**line;
	t_room	*from;
	t_room	*to;
	t_link	*link;
	t_link	*cursor;

	line = ft_strsplit(str, '-');
	from = get_room(ah, line[0]);
	to = get_room(ah, line[1]);
	if (!(link = malloc(sizeof(t_link))))
		exit(1);
	link->to = to;
	link->from = from;
	link->next = NULL;
	cursor = ah->connectors;
	if (!cursor)
		ah->connectors = link;
	else
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = link;
	}
}

void	assign_move(t_anthill *anthill, char *str)
{
	char	**line;
	int		i;
	t_moves	*moves;

	moves = NULL;
	line = ft_strsplit(str, ' ');
	i = 0;
	while (line[i])
		append_move(&moves, deserialise_move(anthill, line[i++]));
	append_to_movelist(&anthill->movelist, make_movelist_item(moves));
	free_array(line);
}
