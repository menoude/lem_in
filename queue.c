/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:43:20 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 22:51:44 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
