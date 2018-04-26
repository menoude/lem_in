#include "lem_in.h"

int parser_nb_ants(t_data *data)
{
	int		nb_ants;

	if (!(info[0] && !info[1]) || !(data_nb_ants = ft_atoi(info[0])))
	{
		parser_free(info);
		return (0);
	}
}

// chaque salle est une structure qui a un tableau de pointeurs vers celles auxquelles elle est liée
int parser_rooms(t_data *data)
{


	if
}

void parser_free(char **info)
{
	int i;

	i = -1;
	while (info[++i])
		free(info[i]);
	free(info);
}

char **parser_parse_line()
{
	char *input;
	char **info;

	if (get_next_line(0, &input) <= 0)
		return (0);
	info = ft_strsplit(input, ' ');
	free(input);
	if (!info || !info[0])

		return (0);

}
