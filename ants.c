/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:42:12 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 22:44:32 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ants_cleared(int *ants, int nb_ants, int path_size)
{
	int i;

	i = -1;
	while (++i < nb_ants)
	{
		if (ants[i] < path_size)
			return (0);
	}
	return (1);
}

void	ants_move(int *ants, int nb_ants)
{
	int i;

	i = -1;
	while (++i < nb_ants)
	{
		ants[i]++;
		if (ants[i] == 1)
			return ;
	}
}

void	ants_display(int *ants, int nb_ants, t_room **path, int path_size)
{
	int i;

	i = -1;
	while (++i < nb_ants)
	{
		if (ants[i] < 1)
		{
			if (i > 0)
				ft_putchar('\n');
			return ;
		}
		if (ants[i] < path_size)
			ft_printf("L%d-%s ", i + 1, path[ants[i]]->name);
	}
	ft_putchar('\n');
}

int		ants_traverse(t_data *data, t_node *path)
{
	int *ants;

	if (!(ants = ft_memalloc(sizeof(int) * data->nb_ants)))
		return (0);
	ft_bzero(ants, sizeof(int) * data->nb_ants);
	instructions_print(data->instructions);
	ft_putchar('\n');
	while (!ants_cleared(ants, data->nb_ants, path->path_size - 1))
	{
		ants_move(ants, data->nb_ants);
		ants_display(ants, data->nb_ants, path->path, path->path_size);
	}
	free(ants);
	return (1);
}
