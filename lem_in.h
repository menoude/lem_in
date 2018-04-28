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
	int		nb_links;
	t_room	*links;
	int		full;
	int		start;
	int		end;
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
	int		starting;
	int		ending;
};

void error_message(void);

char	**parser_parse_line(void);
void	parser_parse_nb_ants(t_data *data);
void	parser_free(char **info);
void	parser_parse_field_data(t_data *data);

int		room_valid(t_data *data, char **info);
int room_initiliaze(t_data *data, t_room *room, char **info);
int		room_add(t_data *data, char **info);
void	room_free(t_room *rooms);

void link_free(t_link *links);
int link_add(t_data *data, char *link);

#endif

// mettre le header dans ft_isnumber dans la libft
