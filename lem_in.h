#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdlib.h>
#include "./libft/includes/libft.h"

typedef struct s_data t_data;
typedef struct s_room t_room;

struct s_room
{
	char	*name;
	int		nb_links;
	t_room	*links;
	int		full;
};

struct s_data
{
	int		nb_ants;
	t_room	*rooms;
	int		start_next;
	int		end_next;
};

void error_message(void);

char	**parser_parse_line(void);
void	parser_parse_nb_ants(t_data *data);
void	parser_free(char **info);
void	parser_parse_field_data(t_data *data);


#endif

// mettre le header dans ft_isnumber dans la libft
