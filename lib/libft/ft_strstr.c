/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:40:25 by ayano             #+#    #+#             */
/*   Updated: 2019/06/03 16:54:03 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** looks for the sting needle in the string haystack and returns everything
** after, if not found return NULL, if no needle return haystack. Check if
** needle exists, while haystack is not at '\0' if needleand haystack are
** the same incriment needle and haysack.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
