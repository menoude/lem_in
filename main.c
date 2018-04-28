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
	data->rooms_over = 0;
	data->links = 0;
}

int main(void)
{
	t_data data;

	initialize_data(&data);
	parser_parse_nb_ants(&data);
	parser_parse_field_data(&data);
	// check que deux rooms ont pas le meme nom ou les memes coordonnées...
	ft_printf("nb of ants = %d\n", data.nb_ants);
	room_free(data.rooms);
}
