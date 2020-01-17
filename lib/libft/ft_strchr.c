/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:23:59 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 15:16:25 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** looks for x in the string
*/

char	*ft_strchr(const char *str, int to_find)
{
	size_t	i;

	i = 0;
	while (i < (ft_strlen(str)) && str[i] != to_find)
		i++;
	if (str[i] != to_find)
		return (NULL);
	else
		return ((char *)&str[i]);
}
