#include "lem_in.h"

void	room_free(t_room *rooms)
{
	if (!rooms)
		return ;
	room_free(rooms->next);
	free(rooms->name);
	free(rooms);
}

// check qu'on en soit pas deja aux liens, que la room est au bon format
// qu'elle n'existe pas encore en termes de coordonnees, puis la crée
int		room_add(t_data *data, char **info)
{
	t_room *room;
	t_room *ptr;

	if (data->rooms_over || !ft_isnumber(info[1]) || !ft_isnumber(info[2])
		|| (data->starting && data->ending) || !(room = ft_memalloc(sizeof(t_room))))
		return (0);
	room->name = ft_strdup(info[0]);
	room->nb_links = 0;
	room->full = 0;
	room->start = data->starting ? 1 : 0;
	room->end = data->ending ? 1 : 0;
	room->next = 0;
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
