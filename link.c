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

// attention links est pas initialisé dans chaque room, par contre ya une variable nb_links !
// d'ailleurs ptet qu'elle sert a rien et qu'on peut juste parcourir la liste des links si jamais j'utilise une liste
// les links sont juste un tableau de pointeurs vers d'autres rooms
int link_add(t_data *data, char *str)
{
	char	**info;
	t_link	*link;
	t_link	*ptr;

	data->rooms_over = 1;
	info = ft_strsplit(str, '-');
	if (ft_strtablen((const char **)info) != 2 || !ft_isnumber(info[0]) || !ft_isnumber(info[1])
		|| !(link = ft_memalloc(sizeof(t_link))))
	{
		parser_free(info);
		return (0);
	}
	link->name1 = ft_strdup(info[0]);
	link->name2 = ft_strdup(info[1]);
	link->next = 0;
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
