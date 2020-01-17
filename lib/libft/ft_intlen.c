/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 09:29:08 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 12:45:39 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** gives youthe length of the number passed
*/

int		ft_intlen(int n)
{
	int		c;

	c = 0;
	if (n == INTMIN)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		c++;
	}
	while (n >= 10)
	{
		c++;
		n = n / 10;
	}
	if (n >= 0)
		c++;
	return (c);
}
