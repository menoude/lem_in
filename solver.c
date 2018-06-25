/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:43:38 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 22:52:27 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*solver_solve(t_data *data)
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
			queue_enqueue(&queue, node_expand(node));
		else
			node_free(node);
	}
}
