#include "lem_in.h"

void		queue_free(t_node *queue)
{
	if (!queue)
		return ;
	queue_free(queue->next);
	node_free(queue);
}

void		queue_enqueue(t_node **queue, t_node *node)
{
	t_node *ptr;

	if (!*queue)
	{
		*queue = node;
		return ;
	}
	ptr = *queue;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = node;
}

t_node		*queue_dequeue(t_node **queue)
{
	t_node *node;

	if (!(*queue))
		return (0);
	node = *queue;
	*queue = (*queue)->next;
	return (node);
}
