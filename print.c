#include "lem_in.h"

void print_data(t_data *data)
{
	t_room *ptr;
	t_link *ptr2;

	ft_printf("\n----------------\n");
	ft_printf("%d ants\n", data->nb_ants);
	ft_printf("----------------\n");
	ft_printf("%d rooms\n", data->nb_rooms);
	ptr = data->rooms;
	if (!ptr)
	{
		ft_printf("no room\n");
		return ;
	}
	else
		ft_printf("start room: \"%s\", end room: \"%s\"\n", data->start_room ? data->start_room->name : "none",
												data->end_room ? data->end_room->name : "none");
	while (ptr)
	{
		ft_printf("%s (%d, %d) \n", ptr->name, ptr->x, ptr->y);
		ptr = ptr->next;
	}
	ft_printf("----------------\n");
	ft_printf("%d links\n", data->nb_links);
	ptr2 = data->links;
	if (!ptr2)
		ft_printf("no link\n");
	else
	{
		while (ptr2)
		{
			ft_printf("%s <-> %s\n", ptr2->name1, ptr2->name2);
			ptr2 = ptr2->next;
		}
	}
	ft_printf("----------------\n\n");
}
