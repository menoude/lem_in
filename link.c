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


int link_initialize(t_data *data, t_link *link, char **info)
{
	if (!(link = ft_memalloc(sizeof(t_link))))
		return (0);
	link->name1 = ft_strdup(info[0]);
	link->name2 = ft_strdup(info[1]);
	link->next = 0;
	return (1);
}

// checker que les deux noms existent et que le link n'a pas deja ete defini
// sauf si c'est le premier link
int link_valid(t_data *data, char **info)
{
	t_link *ptr;

	if (!data->links)
		return (1);
	ptr = data->links;
	while (ptr->next)
	{
	}
	return (1);
}

// termine le parsing des rooms, split le buffer autour de '-'
// //////////
// check qu'il fait bien 2 elements et que les noms de salles sont valides !!!!!!!!!!!!!!
// /////////
//

int link_add(t_data *data, char *str)
{
	char	**info;
	t_link	*link;
	t_link	*ptr;

	data->rooms_over = 1;
	info = ft_strsplit(str, '-');
	if (ft_strtablen((const char **)info) != 2 || !link_valid(data, info)
		|| !link_initialize(data, link, info))
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
	return (1);
}
