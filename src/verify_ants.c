/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:05:05 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 17:05:06 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** This will verify the amount of ants and exit using exit(1) if there are none
** or it is incorrectly formatted or the number of ants is not given as the
** first line.
*/

void		verify_ants(char *line)
{
	int		ants;
	int		i;

	i = 0;
	ants = 0;
	if (!line)
		return ;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 1)
			i++;
		else
			break ;
	}
	ants = ft_atoi(line);
	if (ants == 0 || ants < 0)
		print_ant_error();
}

/*
** Seriousely bro, it just prints an error.
*/

void		print_ant_error(void)
{
	ft_putendl(RED "Error" RESET " : No ants given or it is badly formatted.");
	exit(1);
}
