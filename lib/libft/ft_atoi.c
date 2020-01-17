/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:09:34 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 12:42:27 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** coverts the string pointed to int representation.
*/

int		ft_atoi(const char *str)
{
	int				i;
	int				nbr;
	int				neg;

	i = 0;
	nbr = 0;
	neg = 1;
	while ((str[i] == '\n' || str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
				|| str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * neg);
}
