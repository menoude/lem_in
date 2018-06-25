/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:42:44 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 22:53:34 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_message(void)
{
	ft_printf("ERROR\n");
	exit(1);
}

int		main(void)
{
	t_data	data;
	t_node	*path;

	data_initialize(&data);
	parser_parse_nb_ants(&data);
	parser_parse_field_data(&data);
	path = 0;
	if (!graph_new(&data) || !(path = solver_solve(&data))
		|| !ants_traverse(&data, path))
	{
		node_free(path);
		data_free(&data);
		error_message();
	}
	node_free(path);
	data_free(&data);
	return (0);
}
