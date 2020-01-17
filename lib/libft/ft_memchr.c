/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:03:38 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 14:11:34 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** find the first occurance of c, returns a pointer to the byte c is at or
** null if no c is found.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s1;

	i = 0;
	s1 = (const char *)s;
	while (n--)
	{
		if (s1[i] == (char)c)
			return ((void *)&s1[i]);
		i++;
	}
	return (NULL);
}
