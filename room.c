#include "lem_in.h"

void	room_free(t_room *rooms)
{
	if (!rooms)
		return ;
	room_free(rooms->next);
	free(rooms->name);
	free(rooms);
}

int		room_valid(t_data *data, char **info)
{
	t_room *ptr;
	long int x;
	long int y;

	if ((data->starting && data->ending) ||
		!ft_isnumber(info[1]) || !ft_isnumber(info[2]))
		return (0);
	x = ft_atoi_long(info[1]);
	y = ft_atoi_long(info[2]);
	if (x > 2147483647 || y > 2147483647 || x < 0 || y < 0)
		return (0);
	if (!data->rooms)
		return (1);
	ptr = data->rooms;
	while (ptr->next)
	{
		if (ft_strequ(info[0], ptr->name) || (x == ptr->x && y == ptr->y))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int room_initiliaze(t_data *data, t_room *room, char **info)
{
	if (!(room = ft_memalloc(sizeof(t_room))))
		return (0);
	room->name = ft_strdup(info[0]);
	room->x = ft_atoi(info[1]);
	room->y = ft_atoi(info[2]);
	room->nb_links = 0;
	room->full = 0;
	room->start = data->starting ? 1 : 0;
	room->end = data->ending ? 1 : 0;
	room->next = 0;
	return (1);
}
// check qu'on en soit pas deja aux liens, que la room est au bon format
// qu'elle n'existe pas encore en termes de coordonnees, puis la crée
int		room_add(t_data *data, char **info)
{
	t_room *room;
	t_room *ptr;

	room = 0;
	if (!room_valid(data, info) || !room_initiliaze(data, room, info))
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
	data->starting = 0;
	data->ending = 0;
	data->nb_rooms++;
	return (1);
}