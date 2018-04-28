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
		return (parser_parse_line());
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
	if (!ft_isnumber(info[0]))
	{
		parser_free(info);
		error_message();
	}
	nb_ants = ft_atoi_long(info[0]);
	parser_free(info);
	if (nb_ants > 2147483647 || nb_ants < -2147483648 || !nb_ants)
		error_message();
	data->nb_ants = (int)nb_ants;
}

void parser_parse_field_data(t_data *data)
{
	char **info;
	int len;

	while ((info = parser_parse_line()))
	{
		if (!(len = ft_strtablen((const char **)info)) || len == 2 || len > 3)
		{
			parser_free(info);
			return ;
		}
		else if (len == 1 && ft_strequ(info[0], "##start"))
			data->starting = 1;
		else if (len == 1 && ft_strequ(info[0], "##end"))
			data->ending = 1;
		else if ((len == 3 && !room_add(data, info))
				|| (len == 1 && !link_add(data, info[0])))
		{
			parser_free(info);
			return ;
		}
		parser_free(info);
	}
}
