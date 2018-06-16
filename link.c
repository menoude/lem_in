#include "lem_in.h"

void link_free(t_link *links)
{
	if (!links)
		return ;
	link_free(links->next);
	free(links->name1);
	free(links->name2);
	free(links);
}

int link_initialize(t_data *data, t_link **link, char **info)
{
	t_room *room1;
	t_room *room2;

	if (!(*link = ft_memalloc(sizeof(t_link))))
		return (0);
	(*link)->name1 = ft_strdup(info[0]);
	(*link)->name2 = ft_strdup(info[1]);
	(*link)->next = 0;
	room1 = finder_find_room(data->rooms, (*link)->name1);
	room1->nb_links++;
	room2 = finder_find_room(data->rooms, (*link)->name2);
	room2->nb_links++;
	return (1);
}

int link_exists(t_data *data, char *name1, char *name2)
{
	t_link *ptr;

	ptr = data->links;
	while (ptr)
	{
		if ((ft_strequ(ptr->name1, name1) && ft_strequ(ptr->name2, name2))
			|| (ft_strequ(ptr->name1, name2) && ft_strequ(ptr->name2, name1)))
		return (1);
		ptr = ptr->next;
	}
	return (0);
}

// check que le premier element et le deuxieme sont pas vides
// si c'est le premier link c'est bon
// checker que les deux noms existent
// checker la liste des links et verifier qu'un identique n'existe pas deja
// renvoyer 1
int link_valid(t_data *data, char **info)
{
	if (!info[0] || !info[1])
		return (0);
	else if (!room_exists(data, info[0]) || !room_exists(data, info[1])
			|| ft_strequ(info[0], info[1]))
		return (0);
	else if (!data->nb_links)
		return (1);
	else if (link_exists(data, info[0], info[1]))
		return (0);
	else
		return (1);
}

// termine le parsing des rooms, split le buffer autour de '-'
int link_add(t_data *data, char *str)
{
	char	**info;
	t_link	*link;
	t_link	*ptr;

	data->rooms_over = 1;
	info = ft_strsplit(str, '-');
	link = 0;
	if (data->nb_commands != 2 || ft_strtablen((const char **)info) != 2 || !link_valid(data, info)
		|| !link_initialize(data, &link, info))
	{
		parser_free(info);
		return (0);
	}
	if (!data->links)
		data->links = link;
	else
	{
		ptr = data->links;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = link;
	}
	parser_free(info);
	data->nb_links++;
	return (1);
}
