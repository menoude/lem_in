#include "lem_in.h"

// en vrai il faut checker avec le set qu'on retourne pas en arriere
// et
t_node *solver_solve(t_data *data)
{
	t_node *queue;
	t_node *node;
	t_node *expanded_node;

	ft_printf("entered solver\n");
	if (data->nb_rooms < 2 || !data->nb_links
		|| !(node = node_new(0, data->start_room)))
		return (0);
	queue = 0;
	queue_enqueue(&queue, node);
	ft_printf("before loop in solver\n");
	print_queue(queue);
	while (1)
	{
		ft_printf("loop cycle\n");
		print_queue(queue);
		ft_printf("dequeue\n");
		if (!(node = queue_dequeue(&queue)))
			return (0);
		print_queue(queue);
		print_node(node);
		if (node_is_success(data, node))
		{
			ft_printf("reached end room %s\n", node_state(node)->name);
			return (node);
		}
		ft_printf("node is not success\n");
		print_queue(expanded_node);
		if (node_state(node)->nb_links)
		{
			expanded_node = node_expand(node);
			ft_printf("expanded node --> ");
			queue_enqueue(&queue, expanded_node);
		}
		print_queue(queue);
		node_free(node);
	}
	return (node);
}
