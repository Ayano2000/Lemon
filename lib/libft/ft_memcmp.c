/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:07:47 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 14:16:23 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares two byte strings an returns the difference if there is one or 0
** if there is no difference
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = ((unsigned char *)s1);
	str2 = ((unsigned char *)s2);
	if (s1 == s2 || n == 0)
		return (0);
	while (n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (n)
			i++;
		n--;
	}
	return (0);
}
