/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:28:40 by ayano             #+#    #+#             */
/*   Updated: 2020/01/17 03:28:25 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Displays all the data we have read in if there are no errors
*/

void		display_input_and_free(t_data *data)
{
	t_data	*current;
	t_data	*previous;

	current = data;
	while (current)
	{
		ft_putendl(current->line);
		previous = current;
		current = current->next;
		if (previous)
		{
			free(previous->line);
			free(previous);
		}
	}
	ft_putendl("");
}
