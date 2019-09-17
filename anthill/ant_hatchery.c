#include <lem_in.h>

void	join_colony(t_anthill **anthill, t_ant *larvae)
{
	t_ant	*nurse;
	if (!(*anthill)->colony)
		(*anthill)->colony = larvae;
	else
	{
		nurse = (*anthill)->colony;
		while (nurse->next)
			nurse = nurse->next;
		nurse->next = larvae;
	}
}

int		hatch_ant(t_anthill *anthill, char *name)
{
	t_ant *egg;

	if (!(egg = malloc(sizeof(t_ant))))
		return (0);
	egg->next = NULL;
	egg->following = NULL;
	egg->current = anthill->start;
	egg->name = ft_strdup(name);
	join_colony(&anthill, egg);
	return (1);
}