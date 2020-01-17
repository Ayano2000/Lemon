/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:15:39 by ayano             #+#    #+#             */
/*   Updated: 2019/06/04 13:34:12 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	j;
	char			*nstr;

	j = 0;
	if (str == NULL)
		return (NULL);
	if (!(nstr = (char *)malloc(sizeof(char) * (ft_strlen((char *)str) + 1))))
		return (NULL);
	while (str[j] != '\0')
	{
		nstr[j] = (f)(j, str[j]);
		j++;
	}
	nstr[j] = '\0';
	return (nstr);
}
