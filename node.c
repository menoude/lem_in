#include "lem_in.h"

void		node_free(t_node *node)
{
	free(node->path);
	free(node);
}

t_room		*node_state(t_node *node)
{
	return (node->path[node->path_size - 1]);
}

int			node_is_success(t_data *data, t_node *node)
{
	return (node_state(node) == data->end_room);
}

t_node		*node_new(t_node *node, t_room *room)
{
	t_room **new_path;

	if (!node)
	{
		if (!(node = ft_memalloc(sizeof(t_node)))
			|| !(node->path = ft_memalloc(sizeof(t_room *))))
			return (0);
		node->path[0] = room;
		node->path_size = 1;
	}
	else
	{
		if (!(new_path = ft_memalloc(sizeof(t_room *) * (node->path_size + 1))))
			return (0);
		ft_memmove(node->path, new_path, sizeof(node->path));
		new_path[node->path_size++] = room;
		free(node->path);
		node->path = new_path;
	}
	return (node);
}
