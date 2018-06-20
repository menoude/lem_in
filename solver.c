#include "lem_in.h"

// en vrai il faut checker avec le set qu'on retourne pas en arriere
// et
t_node *solver_solve(t_data *data)
{
	t_node *queue;
	t_node *node;
	t_node *expanded_node;

	ft_printf("f\n");
	if (data->nb_rooms < 2 || !data->nb_links
		|| !(node = node_new(0, data->start_room)))
		return (0);
	queue = 0;
	ft_printf("g\n");
	queue_enqueue(&queue, node);
	ft_printf("h\n");
	print_queue(queue);
	while (1)
	{
		if (!(node = queue_dequeue(&queue)))
			return (0);
		print_queue(queue);
		ft_printf("i\n");
		if (node_is_success(data, node))
			return (node);
		ft_printf("j\n");
		expanded_node = node_expand(node);
		print_queue(expanded_node);
		queue_enqueue(&queue, expanded_node);
		print_queue(queue);
		ft_printf("k\n");
		node_free(node);
	}
	return (node);
}
