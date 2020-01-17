/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:29:04 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 09:18:58 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	set_path_distances(t_anthill *hill)
{
	t_pathlist	*pathlist;
	t_path		*path;
	int			count;

	pathlist = hill->paths;
	while (pathlist)
	{
		path = pathlist->path;
		count = 0;
		while (path)
		{
			count++;
			path = path->next;
		}
		pathlist->length = count;
		pathlist = pathlist->next;
	}
}

bool	lower_distance_path_exists(t_anthill *hill, int dist)
{
	t_pathlist	*pathlist;

	pathlist = hill->paths;
	while (pathlist)
	{
		if (pathlist->length < dist)
			return (true);
		pathlist = pathlist->next;
	}
	return (false);
}

void	optimise_paths(t_anthill *hill)
{
	t_pathlist	*current;
	t_path		*current_path;

	set_path_distances(hill);
	current = hill->paths;
	while (current)
	{
		current_path = current->path;
		if (current->length - 2 > hill->nb_ants)
		{
			if (lower_distance_path_exists(hill, current->length))
				current->valid = false;
		}
		current = current->next;
	}
}

void	add_start_end_pathlist(t_anthill **anthill)
{
	t_path		*new;

	new = NULL;
	append_to_path(&new, make_path_item((*anthill)->end));
	append_to_path(&new, make_path_item((*anthill)->start));
	prepend_to_pathlist(&(*anthill)->paths, create_pathlist_item(new));
}

void	check_start_end_path(t_anthill **anthill)
{
	t_room		*start;
	t_room		*end;
	t_link		*link;

	start = (*anthill)->start;
	end = (*anthill)->end;
	link = (*anthill)->connectors;
	while (link)
	{
		if (link->from->is_end && link->to->is_start)
			return (add_start_end_pathlist(anthill));
		if (link->from->is_start && link->to->is_end)
			return (add_start_end_pathlist(anthill));
		link = link->next;
	}
}
