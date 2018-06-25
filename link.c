/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:42:32 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 22:54:39 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	link_free(t_link *links)
{
	if (!links)
		return ;
	link_free(links->next);
	free(links);
}

int		link_initialize(t_data *data, t_link **link, char **info)
{
	if (!(*link = ft_memalloc(sizeof(t_link))))
		return (0);
	(*link)->room1 = room_find(data->rooms, info[0]);
	(*link)->room2 = room_find(data->rooms, info[1]);
	(*link)->next = 0;
	(*link)->room1->nb_links++;
	(*link)->room2->nb_links++;
	return (1);
}

int		link_exists(t_link *links, char *name1, char *name2)
{
	while (links)
	{
		if ((ft_strequ(links->room1->name, name1)
			&& ft_strequ(links->room2->name, name2))
			|| (ft_strequ(links->room1->name, name2)
				&& ft_strequ(links->room2->name, name1)))
			return (1);
		links = links->next;
	}
	return (0);
}

int		link_valid(t_data *data, char **info)
{
	if (!info[0] || !info[1])
		return (0);
	else if (ft_strequ(info[0], info[1]) || !room_find(data->rooms, info[0])
			|| !room_find(data->rooms, info[1]))
		return (0);
	else if (!data->nb_links)
		return (1);
	else if (link_exists(data->links, info[0], info[1]))
		return (0);
	else
		return (1);
}

int		link_add(t_data *data, char *str)
{
	char	**info;
	t_link	*link;
	t_link	*ptr;

	data->rooms_over = 1;
	info = ft_strsplit(str, '-');
	link = 0;
	if (data->nb_commands != 2 || ft_strtablen((const char **)info) != 2
		|| !link_valid(data, info) || !link_initialize(data, &link, info))
	{
		parser_free(info);
		return (0);
	}
	if (!data->links)
		data->links = link;
	else
	{
		ptr = data->links;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = link;
	}
	parser_free(info);
	data->nb_links++;
	return (1);
}
