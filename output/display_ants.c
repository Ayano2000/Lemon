/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:32:04 by ayano             #+#    #+#             */
/*   Updated: 2019/09/04 12:32:06 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Displays the number of ants
** MIGHT NOT NEED.
*/

void	display_ants(t_anthill **anthill)
{
	ft_putnbr((*anthill)->nb_ants);
	ft_putchar('\n');
}
