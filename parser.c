#include "lem_in.h"

int parser_nb_ants(t_data *data)
{
	char	*input;
	char	*info;
	int		nb_ants;

	if (get_next_line(0, &input) <= 0)
		return (0);
	info = ft_strsplit(input, ' ');
	if (!(info[0] && !info[1]) || !(data_nb_ants = ft_atoi(info[0])))
	{
		free(input);
		parser_free(info);
		return (0);
	}
}
