/*
level = {s : 0}
parent = {s : None}

i = 1
frontier = [s]

while frontier:
	next = []
	for u in frontier:

		for v in u.neighbours:

			if v not in level:
				level[v] = i
				parent[v] = u
				next.append(v)

	frontier = next
	i += 1
*/

#include <lem_in.h>

typedef struct			s_lstpath
{
	struct s_lstpath 	*next;
	t_path				*path;	
}						t_lstpath;

typedef struct			s_rlist
{
	t_room				*room;
	struct s_rlist		*next;
}						t_rlist;

t_lstpath *create_path_list()
{
	t_lstpath *new;

	if (!(new = malloc(sizeof(t_lstpath))))
		return NULL;
	new->path = NULL;
	new->next = NULL;
	return new;
}

t_rlist *make_item(t_room *room)
{
	t_rlist *new;

	if (!(new = malloc(sizeof(t_rlist))))
		return NULL;
	new->next = NULL;
	new->room = room;
	return new;
}

void append_list(t_rlist **start, t_rlist *new)
{
	t_rlist *list;

	list = *start;

	if (!list)
	{
		//printf("List was empty attaching list_item with room '%s'\n", new->room->name);
		*start = new;
	}
	else
	{
		while (list->next)
			list = list->next;
		//printf("Attaching list_item with room '%s'\n", new->room->name);
		list->next = new;
	}
}

t_rlist *get_neighbours(t_room *room, t_link *links)
{
	t_rlist *start;

	start = NULL;

	while (links)
	{
		if (room == links->from)
		{
			printf("Found room '%s' in link '%s'=>'%s'\n", room->name, links->from->name, links->to->name);
			append_list(&start, make_item(links->to));
		}
		else if (room == links->to)
		{
			printf("Found room '%s' in link '%s'=>'%s'\n", room->name, links->from->name, links->to->name);
			append_list(&start, make_item(links->from));
		}
		links = links->next;
	}
	return start;
}


// void	set_levels(t_state *s)
// {
// 	t_frontier *frontier;
// 	t_frontier *next;
// 	t_frontier *neighbour;
// 	int i = 1;

// 	frontier = NULL;

// 	Iappend_roomz(&frontier, s->anthill->start);

// 	while (has_vertices(frontier))
// 	{
// 		next = NULL;
// 		while (frontier)
// 		{
// 			neighbour = get_neighbours(s->anthill->connectors, frontier);
// 			while (neighbour)
// 			{
// 				if (neighbour->room->level == -1)
// 				{
// 					neighbour->room->level = i;
// 					neighbour->room->parent = frontier->room;
// 					append_frontier(&next, neighbour);
// 				}
// 				neighbour = neighbour->next;
// 			}
// 			frontier = frontier->next;
// 		}
// 		i++;
// 		frontier = next;
// 	}
// }

typedef struct s_debug
{
	t_room *rooms;
	t_room *start;
	t_room *end;
	t_link *links;
}	t_debug;


t_link *make_link(t_room *from, t_room *to)
{
	t_link *new;

	if (!(new = malloc(sizeof(t_link))))
		return NULL;
	new->from = from;
	new->to = to;
	new->next = NULL;
	return new;
}

void append_link(t_link **start, t_link *new)
{
	t_link *link;

	link = *start;
	if (!link)
	{
		printf("t_debug->links was empty attaching link '%s'=>'%s'\n", new->from->name, new->to->name);
		*start = new;
	}
	else
	{
		while (link->next)
			link = link->next;
		printf("Attaching link '%s'=>'%s'\n", new->from->name, new->to->name);
		link->next = new;
	}
}

t_room *make_room(char *name, bool start, bool end)
{
	t_room *new;

	if (!(new = malloc(sizeof(t_room))))
		return NULL;
	new->name = ft_strdup(name);
	new->is_end = end;
	new->is_start = start;
	new->next = NULL;
	new->parent = NULL;
	new->level = -1;
	return new;
}

void	Iappend_room(t_room **start, t_room *new)
{
	t_room *room;

	room = *start;

	if (!room)
	{
		printf("t_debug->rooms was empty, attaching room '%s'\n", new->name);
		*start = new;
	}
	else
	{
		while (room->next)
			room = room->next;
		printf("Room '%s' attached to '%s'\n", new->name, room->name);
		room->next = new;
	}
}


t_room *get(t_room *start, char *name)
{
	while (start)
	{
		if (!(ft_strcmp(start->name, name)))
			return start;
		start = start->next;
	}
	return NULL;
}


bool set_levels(t_state *s)
{
	int i = 1;

	t_rlist *frontier = NULL;

	s->anthill->start->level = 0;

	append_list(&frontier, make_item(s->anthill->start));

	t_rlist *next;
	t_rlist *neighbour;

	while (frontier)
	{
		next = NULL;
		while (frontier)
		{
			neighbour = get_neighbours(frontier->room, s->anthill->connectors);
			while (neighbour)
			{
				if (neighbour->room->level == -1)
				{
					neighbour->room->level = i;
					neighbour->room->parent = frontier->room;
					append_list(&next, make_item(neighbour->room));
				}
				neighbour = neighbour->next;
			}
			frontier = frontier->next;
		}
		i++;
		frontier = next;
	}
	return true;
}



int	main_debug()
{
	t_debug *s;

	s = malloc(sizeof(t_debug));

	s->rooms = NULL;
	s->links = NULL;
	s->start = NULL;
	s->end = NULL;

	if (!s)
		return 1;

	Iappend_room(&s->rooms, make_room("Start", true, false));
	Iappend_room(&s->rooms, make_room("One", false, false));
	Iappend_room(&s->rooms, make_room("Two", false, false));
	Iappend_room(&s->rooms, make_room("Three", false, false));
	Iappend_room(&s->rooms, make_room("Four", false, false));
	Iappend_room(&s->rooms, make_room("Five", false, false));
	Iappend_room(&s->rooms, make_room("Six", false, false));
	Iappend_room(&s->rooms, make_room("Seven", false, false));
	Iappend_room(&s->rooms, make_room("Eight", false, false));
	Iappend_room(&s->rooms, make_room("End", false, false));


	append_link(&s->links, make_link(get(s->rooms, "Start"), get(s->rooms, "One")));
	append_link(&s->links, make_link(get(s->rooms, "Start"), get(s->rooms, "Two")));
	append_link(&s->links, make_link(get(s->rooms, "Start"), get(s->rooms, "Three")));
	append_link(&s->links, make_link(get(s->rooms, "Start"), get(s->rooms, "Four")));
	append_link(&s->links, make_link(get(s->rooms, "Four"),  get(s->rooms, "Five")));

	append_link(&s->links, make_link(get(s->rooms, "Four"),  get(s->rooms, "Six")));
	append_link(&s->links, make_link(get(s->rooms, "Four"),  get(s->rooms, "Seven")));
	append_link(&s->links, make_link(get(s->rooms, "Seven"),  get(s->rooms, "Eight")));
	append_link(&s->links, make_link(get(s->rooms, "Eight"),  get(s->rooms, "End")));


	s->end =   get(s->rooms, "End");
	s->start = get(s->rooms, "Start");

	
	

	int i = 1;

	t_rlist *frontier = NULL;

	(get(s->rooms, "Start"))->level = 0;


	append_list(&frontier, make_item(s->start));


	t_rlist *next;
	t_rlist *neighbour;

	while (frontier)
	{
		next = NULL;
		while (frontier)
		{
			neighbour = get_neighbours(frontier->room, s->links);
			while (neighbour)
			{
				if (neighbour->room->level == -1)
				{
					neighbour->room->level = i;
					neighbour->room->parent = frontier->room;
					append_list(&next, make_item(neighbour->room));
				}
				neighbour = neighbour->next;
			}
			frontier = frontier->next;
		}
		i++;
		frontier = next;
	}

	t_room *c = s->end;

	while (c)
	{
		printf("name : %s ,level %d\n", c->name, c->level);
		c = c->parent;
	}

	return 1;
}