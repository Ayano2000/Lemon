/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 03:33:13 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 03:33:15 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

bool	int_string(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
