/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:32:14 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 12:50:41 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function to check if int being passed is a negativei.
*/

static int		ft_isneg(int nb)
{
	int		x;

	x = 0;
	if (nb < 0)
		x = 1;
	return (x);
}

/*
** function to check if int passed is the min int value.
*/

static char		*check_min(char *minint)
{
	int		i;
	char	*min;

	i = 0;
	min = ft_strnew(11);
	while (i < 11)
	{
		min[i] = minint[i];
		i++;
	}
	return (min);
}

/*
** check for input being zero, check negative, fill array from back so
** we dont need to use a string reverse. then adds a negative sign if
** applicable
*/

char			*ft_itoa(int n)
{
	int		len;
	char	*ret;
	int		neg;

	neg = ft_isneg(n);
	len = ft_intlen(n);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	if (n == -2147483648)
		return (check_min(MININT));
	if (neg == 1)
		n = n * -1;
	while (len > 0)
	{
		ret[--len] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg == 1)
		ret[0] = '-';
	return (ret);
}
