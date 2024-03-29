/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:56:54 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 23:00:58 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include "./libft/includes/libft.h"

typedef struct s_data			t_data;
typedef struct s_room			t_room;
typedef struct s_link			t_link;
typedef struct s_instruction	t_instruction;
typedef struct s_node			t_node;

struct	s_room
{
	char	*name;
	int		x;
	int		y;
	t_room	**links;
	int		nb_links;
	int		links_count;
	int		ants;
	int		expanded;
	t_room	*next;
};

struct	s_link
{
	t_room	*room1;
	t_room	*room2;
	t_link	*next;
};

struct	s_instruction
{
	char			*content;
	t_instruction	*next;
};

struct	s_node
{
	t_room	**path;
	int		path_size;
	t_node	*next;
};

struct	s_data
{
	t_instruction	*instructions;
	int				nb_ants;
	t_room			*rooms;
	int				nb_rooms;
	int				rooms_over;
	t_link			*links;
	int				nb_links;
	int				start_announced;
	int				end_announced;
	int				nb_commands;
	t_room			*start_room;
	t_room			*end_room;
	t_node			*queue;
};

void	print_queue(t_node *queue);
void	print_node(t_node *node);

void	error_message(void);

void	data_initialize(t_data *data);
void	data_free(t_data *data);

char	**parser_parse_line(t_data *data);
void	parser_parse_nb_ants(t_data *data);
void	parser_free(char **info);
void	parser_parse_field_data(t_data *data);

int		room_valid(t_data *data, char **info);
t_room	*room_find(t_room *rooms, char *name);
int		room_initialize(t_room **room, char **info);
int		room_add(t_data *data, char **info);
void	room_free(t_room *rooms);

void	link_free(t_link *links);
int		link_add(t_data *data, char *link);
int		link_initialize(t_data *data, t_link **link, char **info);
int		link_exists(t_link *links, char *name1, char *name2);

t_node	*solver_solve(t_data *data);

int		instructions_add(t_data *data, char *input);
void	instructions_print(t_instruction *instructions);
void	instructions_free(t_instruction *instructions);

int		graph_allocate_room_space(t_room *rooms);
void	graph_join_rooms(t_link *links);
int		graph_new(t_data *data);

void	node_free(t_node *node);
t_room	*node_state(t_node *node);
int		node_is_success(t_data *data, t_room *room);
t_node	*node_new(t_node *node, t_room *room);
t_node	*node_expand(t_node *node);

void	queue_free(t_node *queue);
void	queue_enqueue(t_node **queue, t_node *node);
t_node	*queue_dequeue(t_node **queue);

int		ants_cleared(int *ants, int nb_ants, int path_size);
void	ants_move(int *ants, int nb_ants);
void	ants_display(int *ants, int nb_ants, t_room **path, int path_size);
int		ants_traverse(t_data *data, t_node *path);

#endif
