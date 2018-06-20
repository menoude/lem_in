#include "lem_in.h"

void error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

int main(void)
{
	t_data	data;

	data_initialize(&data);
	parser_parse_nb_ants(&data);
	ft_printf("a\n");
	parser_parse_field_data(&data);
	ft_printf("b\n");
	if (!graph_new(&data) || !solver_solve(&data))
	{
		ft_printf("c\n");
		data_free(&data);
		error_message();
	}
	ft_printf("d\n");
	instructions_print(data.instructions);

	print_data(&data);
	ft_printf("e\n");

	data_free(&data);
	return (0);
}
