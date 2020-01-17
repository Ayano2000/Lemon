/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:42:56 by ayano             #+#    #+#             */
/*   Updated: 2019/06/03 16:45:41 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** check for minimum int value, check for input being negative, if it is write
** negative sign and multiply input by -1. recursively call putnbr until number
** is less than or equal to 10 then write the last digit.
*/

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = n * -1;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
		}
		ft_putchar((n % 10) + '0');
	}
}
