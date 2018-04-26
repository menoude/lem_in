#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdlib.h>
#include "./libft/includes/libft.h"

typedef struct s_data t_data;

struct s_data
{
	int nb_ants;
};

void error_message(void);

char	**parser_parse_line(void);
void	parser_nb_ants(t_data *data);
void	parser_free(char **info);

#endif
