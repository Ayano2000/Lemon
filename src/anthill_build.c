/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:19:36 by ayano             #+#    #+#             */
/*   Updated: 2019/09/09 14:19:42 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Skips 2 entries if ##start or ##end are found
*/

void		add_start_or_end_data(t_data **entry, t_anthill *anthill)
{
	t_data *current;

	current = *entry;
	if (ft_strcmp(current->line, "##start") == 0)
	{
		current = current->next;
		add_data_start(current->line, &anthill);
		*entry = current->next;
	}
	if (ft_strcmp(current->line, "##end") == 0)
	{
		current = current->next;
		add_data_end(current->line, &anthill);
		*entry = current->next;
	}
}

bool		command_is_needed(char *line)
{
	int strlen;

	strlen = ft_strlen(line);
	if (strlen == 5 || strlen == 7)
	{
		if (!*(line + 5) && !ft_strcmp("##end", line))
			return (true);
		if (!*(line + 7) && !ft_strcmp("##start", line))
			return (true);
	}
	return (false);
}

/*
** Read loop reads from the data structs line variable and then adds information
** to the room struct.
*/

void		read_loop(t_anthill *anthill, t_data **data)
{
	t_data	*current;
	int		link;
	int		type;

	link = 0;
	current = (*data);
	while (current)
	{
		type = check_line(current->line);
		if (type == LINK)
			link = true;
		if ((type == ROOM && link == true) || !(current->line[0]))
			print_invalid_input();
		pre_add_data(type, current->line, &anthill);
		if (type == IDENT)
		{
			if (command_is_needed(current->line))
			{
				add_start_or_end_data(&current, anthill);
				continue;
			}
		}
		current = current->next;
	}
}

/*
** Will check the line and return an int dependant on the type of line it is.
** i.e : 1 == number of ants.
**     : 2 == identifier.
**	   : 3 == room.
**     : 4 == links.
**     : 5 == comment.
**	   : 6 == error/invalid input.
*/

int			check_line(char *line)
{
	if (only_digit(line))
		return (ANT_COUNT);
	else if (line[0] == '#' && line[1] != '#')
		return (COMMENT);
	else if (line[0] == '#' && line[1] == '#')
		return (IDENT);
	else if (word_count(line, ' ', 0) == 3)
		return (ROOM);
	else if (word_count(line, '-', 0) == 2)
		return (LINK);
	else
		return (INVLD);
}

/*
** This will malloc and set the initial values to all
** the data held in the struct.
*/

t_anthill	*new_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = malloc(sizeof(t_anthill))))
		return (false);
	anthill->linear = NULL;
	anthill->start = NULL;
	anthill->end = NULL;
	anthill->connectors = NULL;
	anthill->colony = NULL;
	anthill->paths = NULL;
	anthill->room_count = 0;
	anthill->nb_ants = 0;
	anthill->moves = NULL;
	anthill->nb_paths = 0;
	return (anthill);
}
