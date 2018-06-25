/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:51:48 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 22:55:34 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_free(t_room *rooms)
{
	if (!rooms)
		return ;
	room_free(rooms->next);
	free(rooms->name);
	free(rooms->links);
	free(rooms);
}

t_room	*room_find(t_room *rooms, char *name)
{
	while (rooms)
	{
		if (ft_strequ(rooms->name, name))
			return (rooms);
		rooms = rooms->next;
	}
	return (0);
}

int		room_initialize(t_room **room, char **info)
{
	if (!(*room = ft_memalloc(sizeof(t_room))))
		return (0);
	(*room)->name = ft_strdup(info[0]);
	(*room)->x = ft_atoi(info[1]);
	(*room)->y = ft_atoi(info[2]);
	(*room)->links = 0;
	(*room)->nb_links = 0;
	(*room)->links_count = 0;
	(*room)->ants = 0;
	(*room)->expanded = 0;
	(*room)->next = 0;
	return (1);
}

int		room_valid(t_data *data, char **info)
{
	t_room		*ptr;
	long int	x;
	long int	y;

	if (info[0][0] == 'L' || !ft_isnumber(info[1]) || !ft_isnumber(info[2]))
		return (0);
	x = ft_atoi_long(info[1]);
	y = ft_atoi_long(info[2]);
	if (x > 2147483647 || y > 2147483647 || x < 0 || y < 0)
		return (0);
	if (!data->rooms)
		return (1);
	ptr = data->rooms;
	while (ptr)
	{
		if (ft_strequ(info[0], ptr->name) || (x == ptr->x && y == ptr->y))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int		room_add(t_data *data, char **info)
{
	t_room *room;
	t_room *ptr;

	if (data->rooms_over || !room_valid(data, info)
		|| !room_initialize(&room, info))
		return (0);
	if (!data->rooms)
		data->rooms = room;
	else
	{
		ptr = data->rooms;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = room;
	}
	if (data->start_announced)
		data->start_room = room;
	else if (data->end_announced)
		data->end_room = room;
	data->start_announced = 0;
	data->end_announced = 0;
	data->nb_rooms++;
	return (1);
}
