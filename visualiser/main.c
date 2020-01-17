/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:37:01 by gwasserf          #+#    #+#             */
/*   Updated: 2020/01/17 01:37:09 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

int	main(void)
{
	t_state *state;

	state = init_state();
	state->anthill = get_infos();
	SDL_Init(SDL_INIT_EVERYTHING);
	state->window = SDL_CreateWindow("Lem-in",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 960,
		SDL_WINDOW_SHOWN);
	state->renderer = SDL_CreateRenderer(state->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	state->running = true;
	SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, 255);
	SDL_RenderClear(state->renderer);
	SDL_RenderPresent(state->renderer);
	populate_pathlist(state->anthill);
	optimise_paths(state->anthill);
	state->paths = state->anthill->paths;
	load_all_images(state);
	place_ants_on_start(state);
	state->anthill->movelist->active = true;
	animation_loop(state);
}
