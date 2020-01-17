/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 08:42:31 by ayano             #+#    #+#             */
/*   Updated: 2019/06/05 15:30:31 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function to count number of words in the string passed in ft_strsplit
*/

static int	cwrds(char const *str, char delim, int index)
{
	int			count;

	if (!(str[index]))
		return (0);
	count = 0;
	while (str[index] == delim)
		index++;
	while (str[index] != '\0' && str[index] != delim)
	{
		index++;
		count = 1;
	}
	return (count + cwrds(str, delim, index));
}

/*
** function to get the length of the mini strings split by the deliminator
*/

static int	str_len(char const *str, char delim, int index)
{
	int			len;

	len = 0;
	while (str[index] == delim)
		index++;
	while (str[index] != delim && str[index] != '\0')
	{
		index++;
		len++;
	}
	return (len);
}

/*
** splits the string into mini strings and returns them i a 2d array,
** check if string and deliminator exist, malloc to the size of number
** of words + 1, while counter less then number of words each place
** in array is set to be a mini string and then set a null terminator
** to the end of the 2d array.
*/

char		**ft_strsplit(char const *str, char c)
{
	int			i;
	int			j;
	char		**array;
	int			k;

	if (!str || !c)
		return (NULL);
	if (!(array = (char**)malloc(sizeof(*array) * (cwrds(str, c, 0) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < cwrds(str, c, 0))
	{
		k = 0;
		if (!(array[i] = ft_strnew(str_len(str, c, j))))
			return (NULL);
		while (str[j] == c)
			j++;
		while (str[j] != c && str[j] != '\0')
			array[i][k++] = str[j++];
		array[i][k] = '\0';
		i++;
	}
	array[i] = 0;
	return (array);
}
