/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:25:54 by ayano             #+#    #+#             */
/*   Updated: 2020/01/17 03:26:33 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	check_for_no_rooms(t_data *data)
{
	bool has_rooms;

	has_rooms = false;
	while (data)
	{
		if (word_count(data->line, ' ', 0) == 3)
			has_rooms = true;
		data = data->next;
	}
	if (!has_rooms)
	{
		ft_putendl(RED "Error" RESET " : No rooms were found in input.");
		exit(1);
	}
}

int		main(void)
{
	t_anthill	*anthill;
	t_data		*data;

	data = read_stdin_to_data();
	check_for_no_rooms(data);
	anthill = build_anthill(&data);
	if (!anthill->start || !anthill->end)
		print_start_end_error();
	populate_pathlist(anthill);
	check_start_end_path(&anthill);
	if (pathcount(anthill) > 0)
	{
		display_input_and_free(data);
		create_colony(anthill);
		optimise_paths(anthill);
		create_move_list(anthill);
		print_move_list(anthill->moves);
	}
	else
		ft_putendl(RED "Error" RESET " : No valid path.");
	return (0);
}
