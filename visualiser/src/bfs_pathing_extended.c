/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_pathing_extended.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:32:38 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:32:40 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

t_pathlist	*new_path_list(t_path *path)
{
	t_pathlist *pathlist;

	if (!(pathlist = malloc(sizeof(t_pathlist))))
		return (NULL);
	pathlist->next = NULL;
	pathlist->valid = true;
	pathlist->path = path;
	return (pathlist);
}

void		append_pathlist_item(t_anthill *a, t_path *path)
{
	t_pathlist *head;

	head = a->paths;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new_path_list(path);
	}
	else
		a->paths = new_path_list(path);
}

void		populate_pathlist(t_anthill *a)
{
	t_path *path;

	graph_traverse(a);
	while ((path = get_shortest_path(a, a->end)))
	{
		append_pathlist_item(a, path);
		graph_traverse(a);
	}
}

int			pathcount(t_anthill *hill)
{
	t_pathlist	*paths;
	int			count;

	paths = hill->paths;
	count = 0;
	while (paths)
	{
		if (paths->valid)
			count++;
		paths = paths->next;
	}
	return (count);
}
