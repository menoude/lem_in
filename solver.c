#include "lem_in.h"

// en vrai il faut checker avec le set qu'on retourne pas en arriere
// et
t_node *solver_solve(t_data *data)
{
	t_node *queue;
	t_node *node;
	t_node *expanded_node;

	if (data->nb_rooms < 2 || !data->nb_links
		|| !(node = node_new(0, data->start_room)))
		return (0);
	queue = 0;
	queue_enqueue(&queue, node);
	while (1)
	{
		if (!(node = queue_dequeue(&queue)))
			return (0);
		if (node_is_success(data, node))
			return (node);
		expanded_node = node_expand(node);
		queue_enqueue(&queue, expanded_node);
		node_free(node);
	}
	return (node);
}
