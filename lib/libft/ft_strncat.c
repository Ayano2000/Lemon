/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:32:09 by ayano             #+#    #+#             */
/*   Updated: 2019/05/22 15:31:31 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	c;

	c = 0;
	i = ft_strlen(str1);
	while (str2[c] != '\0' && c < n)
	{
		str1[i] = str2[c];
		i++;
		c++;
	}
	str1[i] = '\0';
	return (str1);
}
