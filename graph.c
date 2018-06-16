#include "lem_in.h"

int graph_allocate_room_space(t_data *data)
{
	t_room	*ptr;
	int		i;

	ptr = data->rooms;
	while (ptr)
	{
		if (!(ptr->links = ft_memalloc(sizeof(t_room *) * ptr->nb_links)))
			return (0);
		i = -1;
		while (++i < ptr->nb_links)
			ptr->links[i] = 0;
		ptr = ptr->next;
	}
	return (1);
}

void graph_join_rooms(t_data *data)
{
	t_link *link;
	t_room *room1;
	t_room *room2;
	int		i;

	link = data->links;
	while (link)
	{
		room1 = finder_find_room(data->rooms, link->name1);
		room2 = finder_find_room(data->rooms, link->name2);
		i = 0;
		while (room1->links[i])
			i++;
		room1->links[i] = room2;
		i = 0;
		while (room2->links[i])
			i++;
		room2->links[i] = room1;
		link = link->next;
	}
}

int graph_create(t_data *data)
{
	if (!graph_allocate_room_space(data))
		return (0);
	graph_join_rooms(data);
	return (1);
}
