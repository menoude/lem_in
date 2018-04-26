#include "lem_in.h"

// si on a une ligne qui deconne, on essaye de resoudre avec ce qu'on a jusque la, sinon on affiche Eroor

void error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

void initialize_data(t_data *data)
{
	data->nb_ants = 0;
	data->start_next = 0;
	data->end_next = 0;
	data->rooms = 0;
}

int main(void)
{
	t_data data;

	initialize_data(&data);
	parser_parse_nb_ants(&data);
	parser_parse_field_data(&data);
	ft_printf("nb of ants = %d\n", data.nb_ants);
}
