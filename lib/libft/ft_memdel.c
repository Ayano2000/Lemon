/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:21:40 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 14:21:23 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** frees the memory using the free function
*/

void	ft_memdel(void **to_free)
{
	if (to_free == NULL)
		return ;
	else
	{
		free(*to_free);
		*to_free = NULL;
	}
}
