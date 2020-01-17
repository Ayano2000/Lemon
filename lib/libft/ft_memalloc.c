/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:36:02 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 15:29:27 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates memory to size of the size passed to function
** and sets each byte to '\0'
*/

void	*ft_memalloc(size_t size)
{
	char	*mem;
	int		i;

	i = 0;
	mem = (void *)malloc(size * sizeof(size_t));
	if (mem == NULL)
		return (NULL);
	else
		ft_memset(mem, '\0', size);
	return (mem);
}
