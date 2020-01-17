/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:18:06 by ayano             #+#    #+#             */
/*   Updated: 2019/09/05 09:18:07 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Frees the linked list using the data structs.
*/

void		free_data(t_data **data)
{
	t_data	*cursor;
	t_data	*next;

	cursor = (*data);
	while (cursor)
	{
		next = cursor->next;
		free(cursor->line);
		free(cursor);
		cursor = next;
	}
	*data = NULL;
}
