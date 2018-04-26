#include "lem_in.h"

char **parser_parse_line(void)
{
	char *input;
	char **info;

	if (get_next_line(0, &input) <= 0)
		return (0);
	while (input[0] == '#' && input[1] != '#')
	{
		free(input);
		if (get_next_line(0, &input) <= 0)
			return (0);
	}
	info = ft_strsplit(input, ' ');
	free(input);
	if (!info)
		return (0);
	else if (!info[0])
	{
		parser_free(info);
		return (0);
	}
	return (info);
}

void parser_parse_nb_ants(t_data *data)
{
	long int	nb_ants;
	char		**info;
	int			i;

	if (!(info = parser_parse_line()) || (info[1]))
	{
		parser_free(info);
		error_message();
	}
	i = -1;
	while (info[0][++i])
	{
		if (!ft_isdigit(info[0][i]))
		{
			parser_free(info);
			error_message();
		}
	}
	nb_ants = ft_atoi_long(info[0]);
	parser_free(info);
	if (nb_ants > 2147483647 || nb_ants < -2147483648)
		error_message();
	data->nb_ants = nb_ants;
}

// chaque salle est une structure qui a un tableau de pointeurs vers celles auxquelles elle est liée
int parser_parse_rooms(t_data *data)
{

}

int parser_parse_tunnels(t_data *data)
{

}

void parser_free(char **info)
{
	int i;

	if (!info)
		return ;
	i = -1;
	while (info[++i])
		free(info[i]);
	free(info);
}
