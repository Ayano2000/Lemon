#ifndef LEM_IN_H
# define LEM_IN_H
# define NORMAL 0
# define START 1
# define END 2

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
# define RESET "\033[00m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define WHITE "\033[37m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define PURPLE "\033[35m"

typedef int roomtype;

/*
typedef struct			s_img
{
	SDL_Texture 		*img;
	struct s_img		*next;

}						t_img;
*/
typedef struct		s_room
{
	struct s_room 	*next;
	struct s_room	**links;
	struct s_room	*parent;
	int				level;
	int				link_count;
	double			x;
	double			y;
	int				index;
	char			*name;
	bool			is_start;
	bool			is_end;
	
}					t_room;

typedef struct		s_link
{
	t_room			*to;
	t_room			*from;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	t_room			*room;
	int				index;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;

typedef struct			s_ant
{
	double				x;
	double				y;
	char 				*name;
	t_path				*path;
	t_room				*current;
	t_room				*following;
	// t_img				*sprite;
	bool				is_moving;
	double				gradient;
	double				distance;
	struct s_ant		*next;
}						t_ant;

typedef struct 			s_pathlist
{
	t_path				*path;
	int					length;
	struct s_pathlist	*next;
}						t_pathlist;

typedef struct			s_anthill
{
	t_room				*linear;
	t_room				*start;
	t_room				*end;
	t_link				*connectors;
	t_ant				*colony;
	t_pathlist				*paths;
	int					room_count;
	int					nb_ants;
}						t_anthill;

typedef struct			s_data
{
	char				*line;
	struct s_data		*next;
}						t_data;

typedef struct			s_roomlist
{
	t_room				*room;
	struct s_roomlist	*next;
}						t_roomlist;

/*
** Debug 
*/
void				db_print_linear(t_anthill *anthill);

/*
** Anthill prototypes
*/
t_anthill			*build_anthill(t_data **data);
t_anthill			*init_anthill(void);
void				read_loop(t_anthill *anthill, t_data **data);

/*
** Room prototypes
*/
void				new_room(roomtype rtype, char *line, t_anthill **anthill);
void				append_room_linear(t_room **entry_point, t_room *new);
void				init_roomlink_max(t_anthill **anthill);
t_room				*find_room_by_name(t_anthill **anthill, char *name);
void				link_rooms(t_anthill *anthill, char *line);
t_room				*init_room(void);
void				reset_rooms(t_anthill **anthill);

/*
** Error prints.
*/
void				print_allocation_fail(void);
void				print_ant_error(void);
void				print_error_link(void);
void				print_invalid_input(void);
void				print_error_room(void);
void				print_start_end_error(void);

/*
** (Leaks). Freeing prototypes.
*/
void				free_array(char **str);
void				free_data(t_data **data);

/*
** Preflight prototypes.
*/
int					check_line(char *line);
int					get_nb_rooms(void);
int					only_digit(char *line);
int					verify_start_and_end(char *line);
int					word_count(char *str, char delim, int index);
void				add_data_end(char *line, t_anthill **anthill);
void				add_data_start(char *line, t_anthill **anthill);
void				pre_add_data(int type, char *line, t_anthill **anthill);
void				verify_ants(char *line);
void				verify_coordinates(char **data);
void				verify_first_char(char **data);
void				verify_links(char *line, t_anthill **anthill);
void				verify_room(char *line);
void				index_rooms(t_anthill **anthill);
void				add_start_data(char *line, t_anthill **anthill);
void				add_end_data(char *line, t_anthill **anthill);

/*
** Pathing prototypes.
*/
int					check_end_route_head(t_anthill **anthill);
int					create_map(t_anthill **anthill);
bool				set_levels(t_anthill *anthill);
t_path				*map_path(t_room *end);

/*
** Output prototypes.
*/
void				display_ants(t_anthill **anthill);
void				display_output(t_anthill **anthill);
void				display_rooms(t_anthill **anthill);
void				display_links(t_anthill **anthill);
void				display_input(t_data **data);

/*
** Data prototypes.
*/
t_data				*init_data(void);
void				read_into_data(t_data **data);
void				add_data_node(t_data **data, char *line);

/*
** links.
*/
t_link  		    *init_link(void);
t_link 				*make_link(t_room *from, t_room *to);
void 				append_link(t_link **start, t_link *new);
void				assign_link(t_anthill *ah, char *str);

/*
** Roomlist prototypes.
*/
t_roomlist			*init_roomlist(void);
t_roomlist			*make_item(t_room *room);
t_roomlist			*get_neighbours(t_room *room, t_link *links);
void				append_list(t_roomlist **start, t_roomlist *new);
bool				room_in_pathlist(t_pathlist *pathlist, t_room *room);
void				append_to_path(t_path **start, t_path *item);
bool				append_to_pathlist(t_pathlist **start, t_pathlist *item);
t_pathlist			*create_pathlist_item(t_path *path_start);


t_path *make_path_item(t_room *room);

#endif