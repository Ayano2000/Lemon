/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_anthill_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:42:22 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:42:29 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void		assign_room(t_anthill *ah, char *str, bool *s, bool *e)
{
	t_room	*room;
	char	**line;

	line = ft_strsplit(str, ' ');
	room = init_room_g(line[0], ft_atoi(line[1]), ft_atoi(line[2]));
	free_array(line);
	ah->start = (*s) ? room : ah->start;
	ah->end = (*e) ? room : ah->end;
	room->is_start = *s;
	if (room->is_start)
		room->level = 0;
	room->is_end = *e;
	ah->room_count++;
	if (!ah->linear)
		ah->linear = room;
	else
		append_room(ah->linear, room);
	*s = false;
	*e = false;
}

int			identify_line(char *line)
{
	int line_length;

	line_length = ft_strlen(line);
	if (ft_strstr(line, "Error"))
		return (INVLD);
	else if (line_length < 1)
		return (EMPTY);
	else if (line[0] == '#' && line[1] == '#')
		return (IDENT);
	else if (line[0] == '#' && line[1] != '#')
		return (COMMENT);
	else if (int_string(line))
		return (ANT_COUNT);
	else if (ft_strchr(line, ' ') && line[0] != 'L')
		return (ROOM);
	else if (ft_strchr(line, '-') && line[0] != 'L')
		return (LINK);
	else if (line[0] == 'L')
		return (MOVE);
	return (INVLD);
}

void		check_if_lemin_errors(char *line, bool not_identified)
{
	if (*line == '\0')
		return ;
	else if (ft_strstr(line, "Error") || not_identified)
	{
		ft_putendl(RED "Error" RESET " : Input is malformed.");
		exit(1);
	}
	else
	{
		if (not_identified)
		{
			ft_putendl(RED "Error" RESET " : Unknown error, check input.");
			exit(1);
		}
	}
}

void		read_from_stdin(t_anthill *hill, bool *next_start, bool *next_end)
{
	char		*line;
	int			line_type;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		check_if_lemin_errors(line, false);
		line_type = identify_line(line);
		if (line_type == IDENT && ft_strchr(line, 'e'))
			*next_end = true;
		else if (line_type == IDENT && ft_strchr(line, 's'))
			*next_start = true;
		else if (line_type == ROOM)
			assign_room(hill, line, next_start, next_end);
		else if (line_type == LINK)
			assign_link(hill, line);
		else if (line_type == ANT_COUNT)
			assign_ants(hill, line);
		else if (line_type == MOVE)
			assign_move(hill, line);
		else
			check_if_lemin_errors(line, true);
		free(line);
	}
}

t_anthill	*get_infos(void)
{
	t_anthill	*anthill;
	bool		next_start;
	bool		next_end;

	anthill = new_anthill();
	next_start = false;
	next_end = false;
	read_from_stdin(anthill, &next_start, &next_end);
	return (anthill);
}
