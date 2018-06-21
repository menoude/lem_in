#include "lem_in.h"

void error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

int main(void)
{
	t_data	data;
	t_node *path;

	data_initialize(&data);
	parser_parse_nb_ants(&data);
	parser_parse_field_data(&data);
	path = 0;
	if (!graph_new(&data) || !(path = solver_solve(&data))
		|| !ants_traverse(&data, path))
	{
		data_free(&data);
		error_message();
	}
	data_free(&data);
	return (0);
}
