#include <visualiser.h>

bool fbetween(double n, double min, double max)
{
	if (n >= min && n <= max)
		return true;
	return false;
}

int calc_x(t_state *state, double value)
{
	return (state->zoom * value / 2 + state->offset_x) ;
}

int calc_y(t_state *state, double value)
{
	return (state->zoom * value / 2 + state->offset_y);
}

void change_zoom(t_state *s, int z)
{
	if (s->zoom > 1 && z < 0)
		s->zoom--;
	if (z > 0)
		s->zoom++;
	if (s->zoom < 0)
		s->zoom = 0;
}