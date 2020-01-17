/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_add_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:55:30 by ayano             #+#    #+#             */
/*   Updated: 2019/08/27 08:55:31 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		add_room(char *line, t_anthill **anthill)
{
	verify_room(line);
	new_room(0, line, anthill);
	(*anthill)->room_count++;
}

/*
** This will take the data we have and then pass it to the appropriate function
** that will add the data to the linear, start or end structs.
**     : 1 == number of ants.
**     : 2 == identifier. (1 == start, 2 == end)
**	   : 3 == room.
**     : 4 == links.
**     : 5 == comment.
**	   : 6 == error/invalid input.
*/

void		pre_add_data(int type, char *line, t_anthill **anthill)
{
	if (type == 1)
	{
		verify_ants(line);
		(*anthill)->nb_ants = ft_atoi(line);
	}
	if (type == 2)
	{
		if (verify_start_and_end(line) == 1)
			new_room(START, line, anthill);
		else if (verify_start_and_end(line) == 2)
			new_room(END, line, anthill);
		else
			return ;
	}
	if (type == 3)
		add_room(line, anthill);
	if (type == 4)
	{
		verify_links(line, anthill);
		link_rooms(*anthill, line);
	}
	if (type == 5)
		return ;
	if (type == 6)
		print_invalid_input();
}

/*
** Seriously bro, its just and error message..
*/

void		print_invalid_input(void)
{
	ft_putendl(RED "Error" RESET " : Invalid Input.");
	exit(1);
}
