/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:42:48 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 22:50:05 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		node_free(t_node *node)
{
	if (!node)
		return ;
	free(node->path);
	free(node);
}

t_room		*node_state(t_node *node)
{
	return (node->path[node->path_size - 1]);
}

int			node_is_success(t_data *data, t_room *room)
{
	return (room == data->end_room);
}

t_node		*node_new(t_node *node, t_room *room)
{
	t_node *new_node;

	if (!(new_node = ft_memalloc(sizeof(t_node))))
		return (0);
	if (!node)
	{
		if (!(new_node->path = ft_memalloc(sizeof(t_room *))))
			return (0);
		new_node->path[0] = room;
		new_node->path_size = 1;
	}
	else
	{
		if (!(new_node->path = ft_memalloc(sizeof(t_room *)
								* (node->path_size + 1))))
			return (0);
		ft_memmove(new_node->path, node->path,
					sizeof(t_room *) * node->path_size);
		new_node->path[node->path_size] = room;
		new_node->path_size = node->path_size + 1;
	}
	new_node->next = 0;
	return (new_node);
}

t_node		*node_expand(t_node *node)
{
	t_room	*room;
	t_node	*queue;
	t_node	*new;
	int		i;

	room = node_state(node);
	room->expanded = 1;
	queue = 0;
	i = -1;
	while (++i < room->nb_links)
	{
		if (!(new = node_new(node, room->links[i])))
			return (0);
		queue_enqueue(&queue, new);
	}
	node_free(node);
	return (queue);
}
