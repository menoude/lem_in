#include "lem_in.h"

int graph_allocate_room_space(t_room *rooms)
{
	int		i;

	while (rooms)
	{
		if (!(rooms->links = ft_memalloc(sizeof(t_room *) * rooms->nb_links)))
			return (0);
		i = -1;
		while (++i < rooms->nb_links)
			rooms->links[i] = 0;
		rooms = rooms->next;
	}
	return (1);
}

void graph_join_rooms(t_link *links)
{
	t_room *room1;
	t_room *room2;
	int i;
	int j;

	while (links)
	{
		room1 = links->room1;
		room2 = links->room2;
		i = room1->links_count;
		j = room2->links_count;
		room1->links[i] = room2;
		room2->links[j] = room1;
		room1->links_count++;
		room2->links_count++;
		links = links->next;
	}
}

int graph_new(t_data *data)
{
	if (!graph_allocate_room_space(data->rooms))
		return (0);
	graph_join_rooms(data->links);
	return (1);
}
