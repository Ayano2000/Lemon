#include "visualiser.h"

t_state *init_state()
{
	t_state *state;

	state = malloc(sizeof(t_state));

	state->window = NULL;
	state->renderer = NULL;
	state->running = false;
	state->width = 0;
	state->height = 0;
	state->frame = 0;
	state->path = NULL;
	state->paths = NULL;
	state->click = false;
	state->rect = malloc(sizeof(SDL_Rect));
	state->zoom = ZOOM_DEFAULT;
	state->offset_x = 0;
	state->offset_y = 0;
	state->walk_left = NULL;
	state->walk_right = NULL;
	state->room_sprite = NULL;

	return state;
}

void	update_state(t_state *s)
{
	t_ant *army;

	update_current_move(s);
	army = s->anthill->colony;
	while (army)
	{
		if (army->following)
			update_ant_position(army);
		army = army->next;
	}
}

void	render_state(t_state *s)
{
	SDL_RenderClear(s->renderer);
	SDL_RenderCopy(s->renderer, s->background, NULL, NULL);

	
	//draw_parents(s);

	// Draw links
	draw_links(s);
	draw_paths(s);
	draw_nodes(s);

	// Draw Stats
	draw_stats(s);

	
	// Draw ants
	draw_ants(s);


	//SDL_RenderFillRect(s->renderer, s->rect);
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 255);
	// SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 255);
	
	SDL_RenderPresent(s->renderer);
}