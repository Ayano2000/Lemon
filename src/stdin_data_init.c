/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:00:32 by ayano             #+#    #+#             */
/*   Updated: 2019/09/04 13:00:33 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Mallocs the data struct and sets all the variables to NULL
*/

t_data		*new_data_node(void)
{
	t_data	*new;

	if (!(new = malloc(sizeof(t_data))))
		return (false);
	new->line = NULL;
	new->next = NULL;
	return (new);
}

/*
** uses get_next_line and set the line variable in data to be the same as the
** line variable in the data struct
*/

t_data		*read_stdin_to_data(void)
{
	char	*line;
	t_data	*data;

	data = NULL;
	while (get_next_line(0, &line) > 0)
	{
		append_data_node(&data, line);
		free(line);
	}
	return (data);
}

/*
** Adds a data node to the end of the current linked list using the data struct
*/

void		append_data_node(t_data **data, char *line)
{
	t_data	*current;
	t_data	*new;

	new = new_data_node();
	new->line = ft_strdup(line);
	current = (*data);
	if (!current)
		*data = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}
