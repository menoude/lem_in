#include "lem_in.h"

// si on a une ligne qui deconne, on essaye de resoudre avec ce qu'on a jusque la, sinon on affiche Eroor

void error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

int main(void)
{
	t_data data;

	parser_parse_nb_ants(&data);
	parser_parse_rooms()
	ft_printf("nb of ants = %d\n", data.nb_ants);
}
