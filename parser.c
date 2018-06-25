/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:50:12 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 22:55:19 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**parser_parse_line(t_data *data)
{
	char *input;
	char **info;

	if (get_next_line(0, &input) <= 0 || !instructions_add(data, input))
		return (0);
	while (input[0] == '#' && !ft_strequ(input, "##start")
			&& !ft_strequ(input, "##end"))
	{
		free(input);
		return (parser_parse_line(data));
	}
	info = ft_strsplit(input, ' ');
	free(input);
	if (!info || !info[0])
	{
		parser_free(info);
		return (0);
	}
	return (info);
}

void	parser_free(char **info)
{
	int i;

	if (!info)
		return ;
	i = -1;
	while (info[++i])
		free(info[i]);
	free(info);
}

void	parser_parse_nb_ants(t_data *data)
{
	long int	nb_ants;
	char		**info;

	if (!(info = parser_parse_line(data)) || (info[1]) || !ft_isnumber(info[0]))
	{
		parser_free(info);
		error_message();
	}
	nb_ants = ft_atoi_long(info[0]);
	parser_free(info);
	if (nb_ants > 2147483647 || nb_ants < 1)
		error_message();
	data->nb_ants = (int)nb_ants;
}

int		parser_manage_commands(t_data *data, char *info)
{
	if (info[0] != '#' || info[1] != '#' || data->rooms_over
		|| data->start_announced || data->end_announced
		|| data->nb_commands >= 2)
		return (0);
	else if (ft_strequ(info, "##start") && !data->start_room)
	{
		data->start_announced = 1;
		data->nb_commands++;
		return (1);
	}
	else if (ft_strequ(info, "##end") && !data->end_room)
	{
		data->end_announced = 1;
		data->nb_commands++;
		return (1);
	}
	else
		return (0);
}

void	parser_parse_field_data(t_data *data)
{
	char	**info;
	int		len;

	while ((info = parser_parse_line(data)))
	{
		if ((len = ft_strtablen((const char **)info)) != 1 && len != 3)
		{
			parser_free(info);
			return ;
		}
		else if ((len == 3 && !room_add(data, info))
				|| (len == 1 && !(parser_manage_commands(data, info[0])
								|| link_add(data, info[0]))))
		{
			parser_free(info);
			return ;
		}
		parser_free(info);
	}
}
