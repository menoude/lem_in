#include "lem_in.h"

// si on a une ligne qui deconne, on essaye de resoudre avec ce qu'on a jusque la, sinon on affiche Error

void error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

void initialize_data(t_data *data)
{
	data->nb_ants = 0;
	data->starting = 0;
	data->ending = 0;
	data->rooms = 0;
	data->nb_rooms = 0;
	data->rooms_over = 0;
	data->links = 0;
	data->nb_links = 0;
}

void print_rooms(t_data *data)
{
	t_room *ptr;

	ft_printf("----------------\n");
	ptr = data->rooms;
	if (!ptr)
	{
		ft_printf("no room\n");
		return ;
	}
	while (ptr)
	{
		ft_printf("name = %s, x = %d, y = %d\n", ptr->name, ptr->x, ptr->y);
		ft_printf("start = %d, end = %d\n", ptr->start, ptr->end);
		ptr = ptr->next;
	}
}

int main(void)
{
	t_data data;

	initialize_data(&data);
	parser_parse_nb_ants(&data);
	parser_parse_field_data(&data);
	ft_printf("---------------------\nnb of ants = %d, rooms = %d and links %d\n", data.nb_ants, data.nb_rooms, data.nb_links);
	print_rooms(&data);
	// print_links(&data);
	room_free(data.rooms);
	return (0);
}
// pas encore commit les modifs !
// euh les doubles noms ca marche ou pas ?
