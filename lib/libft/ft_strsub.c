/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:04:18 by ayano             #+#    #+#             */
/*   Updated: 2019/05/27 16:06:27 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*substr;

	j = 0;
	if (str == NULL)
		return (NULL);
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (j < len && str[start] != '\0')
	{
		substr[j] = str[start];
		j++;
		start++;
	}
	substr[j] = '\0';
	return (substr);
}
