/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:08:42 by ayano             #+#    #+#             */
/*   Updated: 2019/06/04 14:27:33 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_white_space(char const *str)
{
	int		c;

	c = 0;
	while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n')
		c++;
	return (c);
}

char		*ft_strtrim(char const *str)
{
	char	*nstr;
	int		i;
	int		l;
	int		x;

	i = 0;
	x = 0;
	if (str == NULL)
		return (NULL);
	if ((int)ft_strlen(str) == 0)
		return ((char*)str);
	l = (int)ft_strlen(str) - 1;
	i = ft_is_white_space(str);
	if (str[i] == '\0')
		return (ft_strdup(""));
	while (str[l] == '\t' || str[l] == '\n' || str[l] == ' ')
		l--;
	if (l < 0)
		l = 0;
	if (!(nstr = (char *)malloc(sizeof(char) * (l - i) + 2)))
		return (NULL);
	while (i <= l)
		nstr[x++] = str[i++];
	nstr[x] = '\0';
	return (nstr);
}
