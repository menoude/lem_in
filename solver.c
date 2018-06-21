#include "lem_in.h"

t_node *solver_solve(t_data *data)
{
	t_node *queue;
	t_node *node;
	t_room *room;

	if (data->nb_rooms < 2 || !data->nb_links
		|| !(node = node_new(0, data->start_room)))
		return (0);
	queue = 0;
	queue_enqueue(&queue, node);
	while (1)
	{
		if (!(node = queue_dequeue(&queue)))
			return (0);
		room = node_state(node);
		if (node_is_success(data, room))
		{
			queue_free(queue);
			return (node);
		}
		if (!room->expanded && room->nb_links)
		{
			room->expanded = 1;
			queue_enqueue(&queue, node_expand(node));
		}
	}
}
