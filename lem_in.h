#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdlib.h>
#include "./libft/includes/libft.h"

typedef struct s_data t_data;
typedef struct s_room t_room;
typedef struct s_link t_link;

struct s_room
{
	char	*name;
	int		x;
	int		y;
	t_room	*links;
	int		ants;
	t_room	*next;
};

struct s_link
{
		char *name1;
		char *name2;
		t_link *next;
};

struct s_data
{
	int		nb_ants;
	t_room	*rooms;
	int		nb_rooms;
	int		rooms_over;
	t_link	*links;
	int		nb_links;
	int		start_announced;
	int		end_announced;
	t_room	*start_room;
	t_room	*end_room;
};

////////////
void print_data(t_data *data);
/////////////

void error_message(void);

char	**parser_parse_line(void);
void	parser_parse_nb_ants(t_data *data);
void	parser_free(char **info);
void	parser_parse_field_data(t_data *data);

int		room_valid(t_data *data, char **info);
int		room_exists(t_data *data, char *name);
int		room_initiliaze(t_room **room, char **info);
int		room_add(t_data *data, char **info);
void	room_free(t_room *rooms);

void	link_free(t_link *links);
int		link_add(t_data *data, char *link);
int		link_initialize(t_link **link, char **info);
int		link_exists(t_data *data, char *name1, char *name2);


#endif

// mettre le header dans ft_isnumber dans la libft
