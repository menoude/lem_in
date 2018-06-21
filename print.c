#include "lem_in.h"

void print_data(t_data *data)
{
	t_room *room;
	int 	i;
	t_link *link;

	ft_printf("\n----------------\n");
	ft_printf("%d ants, %d rooms\n", data->nb_ants, data->nb_rooms);
	room = data->rooms;
	ft_printf("start room: \"%s\", end room: \"%s\"\n", data->start_room ? data->start_room->name : "none",
				data->end_room ? data->end_room->name : "none");
	while (room)
	{
		ft_printf("%s (%d, %d) \n", room->name, room->x, room->y);
		ft_printf("links to: ");
		i = -1;
		while (++i < room->nb_links)
			ft_printf("%c %s", i == 0 ? 0 : ',', room->links[i]->name);
		ft_printf("\n");
		room = room->next;
	}
	ft_printf("----------------\n");
	ft_printf("%d links\n", data->nb_links);
	link = data->links;
	if (!link)
		ft_printf("no link\n");
	else
	{
		while (link)
		{
			ft_printf("%s <-> %s\n", link->room1->name, link->room2->name);
			link = link->next;
		}
	}
	ft_printf("----------------\n\n");
}

void print_queue(t_node *queue)
{
	ft_printf("queue: ");
	while (queue)
	{
		ft_printf("%s ", node_state(queue)->name);
		queue = queue->next;
	}
	ft_printf("\n");
}

void print_node(t_node *node)
{
	ft_printf("node: %s\n", node->path[node->path_size - 1]->name);
}
