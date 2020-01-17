/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:21:01 by ayano             #+#    #+#             */
/*   Updated: 2019/09/02 15:09:26 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Checks to see if the data given for the specific room is correctly formatted.
*/

void	verify_room(char *line)
{
	char	**data;
	int		i;

	if (word_count(line, '-', 0) == 2)
		print_invalid_input();
	data = ft_strsplit(line, ' ');
	i = 0;
	if (!line || (word_count(line, ' ', 0) != 3))
		return ;
	verify_coordinates(data);
	verify_first_char(data);
	free_array(data);
}

/*
** Checks to see if the first char of the name is a "L" or a "#" as the PDF says
** it cant be.
*/

void	verify_first_char(char **data)
{
	if (data[0][0] == 'L' || data[0][0] == '#')
	{
		free_array(data);
		print_error_room();
	}
}

/*
** Check to see that the co-ordinates are only numeric values.
*/

void	verify_coordinates(char **data)
{
	int		i;

	i = 0;
	while (data[1][i] != '\0')
	{
		if (ft_isdigit(data[1][i]) == 0)
		{
			free_array(data);
			print_error_room();
		}
		i++;
	}
	i = 0;
	while (data[2][i] != '\0')
	{
		if (ft_isdigit(data[2][i]) == 0)
		{
			free_array(data);
			print_error_room();
		}
		i++;
	}
}

/*
** Frees the char ** array strsplit created.
*/

void	free_array(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/*
** Seriousely bro, it just prints an error message.
*/

void	print_error_room(void)
{
	ft_putendl(RED "Error" RESET " : Room is not formatted correctly.");
	exit(1);
}
