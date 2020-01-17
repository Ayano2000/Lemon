/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:07:07 by ayano             #+#    #+#             */
/*   Updated: 2019/06/03 16:43:02 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** applies function passed as f to the string str.
*/

void	ft_striter(char *str, void (*f)(char *))
{
	if (str == NULL || f == NULL)
		return ;
	while (str != NULL && *str)
		f(str++);
}
