/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:30:36 by ayano             #+#    #+#             */
/*   Updated: 2019/06/04 13:50:08 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** joins two strings and adds a null terminator to the end, copy string 1 to
** string 3, then copy string 2 and add a null beforereturning string 3.
*/

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	len;
	int		i;
	int		j;
	char	*str3;

	i = 0;
	j = 0;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len = ft_strlen((char *)str1) + ft_strlen((char *)str2);
	if (!(str3 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str1[i])
	{
		str3[i] = str1[i];
		i++;
	}
	while (str2[j])
		str3[i++] = str2[j++];
	str3[i] = '\0';
	return (str3);
}
