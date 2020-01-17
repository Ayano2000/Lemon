/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:16:50 by ayano             #+#    #+#             */
/*   Updated: 2019/09/02 14:56:23 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** checks to see that it has both a from room and a to room and that they both
** exist.
*/

void		verify_links(char *line, t_anthill **anthill)
{
	char		**data;
	t_room		*from;
	t_room		*to;

	if (!line || (word_count(line, '-', 0) != 2))
		print_error_link();
	data = ft_strsplit(line, '-');
	from = find_room_by_name(anthill, data[0]);
	to = find_room_by_name(anthill, data[1]);
	if (!to || !from)
		print_error_link();
	free_array(data);
}

/*
** Seriousely bro, it just prints an error message.
*/

void		print_error_link(void)
{
	ft_putendl(RED "Error" RESET " : Link is not formatted correctly.");
	exit(1);
}
