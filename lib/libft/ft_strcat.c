/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:22:54 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 15:13:39 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** adds str2 to the end of str1
*/

char	*ft_strcat(char *str1, const char *str2)
{
	size_t i;
	size_t c;

	c = 0;
	i = ft_strlen(str1);
	while (str2[c] != '\0')
	{
		str1[i] = str2[c];
		c++;
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
