/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:44:44 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 14:44:47 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** This function will get the amount of words by deliminating by spaces.
**
** str : line variable read by get_next_line.
** delim : will always be a " ", used to seperate room number and
** 		   x & y co-orsinates.
** index : will always be 0 but needs to be passed so function has an
**		   exit condition.
*/

int		word_count(char *str, char delim, int index)
{
	int			count;

	if (!(str[index]))
		return (0);
	count = 0;
	while (str[index] == delim)
		index++;
	while (str[index] != '\0' && str[index] != delim)
	{
		index++;
		count = 1;
	}
	return (count + word_count(str, delim, index));
}
