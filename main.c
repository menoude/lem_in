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
	parser_parse_field_data(&data);
	if (!solver_solve(&data))
	{
		data_free(&data);
		error_message();
	}
	instructions_print(data.instructions);

	print_data(&data);

	data_free(&data);
	return (0);
}
