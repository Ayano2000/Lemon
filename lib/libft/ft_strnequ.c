/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:24:12 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 11:44:35 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *str1, char const *str2, size_t n)
{
	size_t i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (0);
	while (((str1[i] != '\0') || (str2[i] != '\0')) && (i < n))
	{
		if ((str1[i] < str2[i]) || (str1[i] > str2[i]))
			return (0);
		i++;
	}
	return (1);
}
