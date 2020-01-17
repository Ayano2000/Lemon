/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 09:01:15 by ayano             #+#    #+#             */
/*   Updated: 2019/09/12 09:01:16 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define NORMAL 0
# define START 1
# define END 2
# define ANT_COUNT 1
# define IDENT 2
# define ROOM 3
# define LINK 4
# define COMMENT 5
# define INVLD 6
# define RESET "\033[00m"
# define RED "\033[31m"
# include <stdbool.h>
# include <stdlib.h>
# include <libft.h>

typedef struct			s_room
{
	struct s_room		*next;
	struct s_room		**links;
	struct s_room		*parent;
	int					level;
	int					link_count;
	bool				in_path;
	double				x;
	double				y;
	char				*name;
	bool				is_start;
	bool				is_end;
	bool				occupied;
}						t_room;

typedef struct			s_link
{
	t_room				*to;
	t_room				*from;
	struct s_link		*next;
}						t_link;

typedef struct			s_ant
{
	char				*name;
	struct s_path		*path;
	t_room				*current;
	t_room				*following;
	bool				is_moving;
	double				gradient;
	double				distance;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_path
{
	t_room				*room;
	t_ant				*ants;
	int					index;
	struct s_path		*next;
	struct s_path		*prev;
}						t_path;

typedef struct			s_pathlist
{
	t_path				*path;
	int					length;
	bool				valid;
	struct s_pathlist	*next;
}						t_pathlist;

typedef struct			s_data
{
	char				*line;
	struct s_data		*next;
}						t_data;

typedef struct			s_moves
{
	struct s_moves		*next;
	t_ant				*ant;
	t_room				*room;
}						t_moves;

typedef struct			s_fifo
{
	struct s_fifo		*next;
	t_room				*room;
}						t_fifo;

typedef struct			s_anthill
{
	t_room				*linear;
	t_room				*start;
	t_room				*end;
	t_link				*connectors;
	t_ant				*colony;
	t_pathlist			*paths;
	t_moves				*moves;
	int					room_count;
	int					nb_ants;
	int					nb_paths;
}						t_anthill;

bool					only_digit(char *line);
bool					ants_are_free(t_anthill *anthill);
int						pathcount(t_anthill *hill);
int						hatch_ant(t_anthill *anthill, char *name);
int						check_line(char *line);
int						verify_start_and_end(char *line);
int						word_count(char *str, char delim, int index);
t_ant					*ant_here(t_ant *colony, t_room *room);
t_anthill				*build_anthill(t_data **data);
t_anthill				*build_anthill(t_data **data);
t_anthill				*new_anthill(void);
t_data					*new_data_node(void);
t_data					*read_stdin_to_data();
t_link					*make_link(t_room *from, t_room *to);
t_pathlist				*create_pathlist_item(t_path *path_start);
t_moves					*move_ant(t_ant *ant, t_room *room);
t_path					*get_shortest_path(t_anthill *a, t_room *end_room);
t_path					*make_path_item(t_room *room);
t_room					*init_room(void);
t_room					*find_room_by_name(t_anthill **anthill, char *name);
t_room					*fifo_pop(t_fifo **stack);
void					prepend_to_path(t_path **start, t_path *item);
void					append_link(t_link **start, t_link *new);
void					append_data_node(t_data **data, char *line);
void					append_to_path(t_path **start, t_path *item);
void					optimise_paths(t_anthill *anthill);
void					check_start_end_path(t_anthill **anthill);
void					create_move_list(t_anthill *anthill);
void					print_move_list(t_moves *moves);
void					append_move(t_moves **start, t_moves *new);
void					create_colony(t_anthill *anthill);
void					add_data_end(char *line, t_anthill **anthill);
void					add_data_start(char *line, t_anthill **anthill);
void					pre_add_data(int type, char *line, t_anthill **anthill);
void					verify_ants(char *line);
void					verify_coordinates(char **data);
void					verify_first_char(char **data);
void					verify_links(char *line, t_anthill **anthill);
void					verify_room(char *line);
void					add_start_data(char *line, t_anthill **anthill);
void					add_end_data(char *line, t_anthill **anthill);
void					display_ants(t_anthill **anthill);
void					display_rooms(t_anthill **anthill);
void					display_input_and_free(t_data *data);
void					prepend_to_pathlist(t_pathlist **s, t_pathlist *new);
void					graph_traverse(t_anthill *a);
void					set_path_distances(t_anthill *hill);
void					polarize_room_parents(t_anthill *a);
void					populate_pathlist(t_anthill *a);
void					read_loop(t_anthill *anthill, t_data **data);
void					new_room(int rtype, char *line, t_anthill **anthill);
void					append_room_linear(t_room **entry_point, t_room *new);
void					link_rooms(t_anthill *anthill, char *line);
void					print_allocation_fail(void);
void					print_ant_error(void);
void					print_error_link(void);
void					print_invalid_input(void);
void					print_error_room(void);
void					print_start_end_error(void);
void					free_array(char **str);
void					free_data(t_data **data);
void					fifo_push(t_fifo **stack, t_room *room);

#endif
