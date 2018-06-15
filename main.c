#include "lem_in.h"

void error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

void data_initialize(t_data *data)
{
	data->nb_ants = 0;
	data->start_announced = 0;
	data->end_announced = 0;
	data->rooms = 0;
	data->nb_rooms = 0;
	data->rooms_over = 0;
	data->links = 0;
	data->nb_links = 0;
	data->start_room = 0;
	data->end_room = 0;
}

void print_data(t_data *data)
{
	t_room *ptr;
	t_link *ptr2;

	ft_printf("\n----------------\n");
	ft_printf("nb of ants = %d\n", data->nb_ants);
	ft_printf("----------------\n");
	ft_printf("nb of rooms = %d\n", data->nb_rooms);
	ptr = data->rooms;
	if (!ptr)
	{
		ft_printf("no room\n");
		return ;
	}
	else
		ft_printf("start: \"%s\", end: \"%s\"\n", data->start_room ? data->start_room->name : "none",
												data->end_room ? data->end_room->name : "none");
	while (ptr)
	{
		ft_printf("%s (%d, %d) \n", ptr->name, ptr->x, ptr->y);
		ptr = ptr->next;
	}
	ft_printf("----------------\n");
	ft_printf("nb of links = %d\n", data->nb_links);
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

// Error si on peut pas résoudre avec les infos qu'on a déjà
int main(void)
{
	t_data data;

	data_initialize(&data);
	parser_parse_nb_ants(&data);
	parser_parse_field_data(&data);

	print_data(&data);
	room_free(data.rooms);
	return (0);
}
