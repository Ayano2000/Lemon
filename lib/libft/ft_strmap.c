/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:20:11 by ayano             #+#    #+#             */
/*   Updated: 2019/06/04 13:28:31 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	int		j;
	char	*nstr;

	j = 0;
	if (str == NULL)
		return (NULL);
	if (!(nstr = (char *)malloc(sizeof(char) * (ft_strlen((char *)str) + 1))))
		return (NULL);
	while (str[j] != '\0')
	{
		nstr[j] = f(str[j]);
		j++;
	}
	nstr[j] = '\0';
	return (nstr);
}
