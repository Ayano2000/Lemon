/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 04:25:38 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 04:25:40 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
**	Glens function idk what it does, pretty sure its useless.
**	it replaces the above function which does nothing :D
*/

t_link	*make_link(t_room *from, t_room *to)
{
	t_link *new;

	if (!(new = malloc(sizeof(t_link))))
		return (NULL);
	new->from = from;
	new->to = to;
	new->next = NULL;
	return (new);
}

/*
** adds the node new to the end of the linked list start.
*/

void	append_link(t_link **start, t_link *new)
{
	t_link *link;

	link = *start;
	if (!link)
		*start = new;
	else
	{
		while (link->next)
			link = link->next;
		link->next = new;
	}
}

/*
**	Link one room to another, i.e append a pointer onto *from->links array
*/

void	link_rooms(t_anthill *anthill, char *line)
{
	t_room	*from;
	t_room	*to;
	char	**data;

	data = ft_strsplit(line, '-');
	from = find_room_by_name(&anthill, data[0]);
	to = find_room_by_name(&anthill, data[1]);
	append_link(&anthill->connectors, make_link(from, to));
	free_array(data);
}

/*
** Seriousely bro, it just prints an error message.
*/

void	print_allocation_fail(void)
{
	ft_putendl(RED "Error" RESET " : Allocation Failed.");
	exit(1);
}
