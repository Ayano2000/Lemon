/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:38:22 by ayano             #+#    #+#             */
/*   Updated: 2019/05/23 14:24:54 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	size_t i;

	i = ft_strlen(str);
	while (i > 0 && str[i] != to_find)
		i--;
	if (str[i] != to_find)
		return (NULL);
	else
		return ((char *)&str[i]);
}
