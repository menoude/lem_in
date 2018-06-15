#include "lem_in.h"

void data_initialize(t_data *data)
{
	data->instructions = 0;
	data->nb_ants = 0;
	data->start_announced = 0;
	data->end_announced = 0;
	data->nb_commands = 0;
	data->rooms = 0;
	data->nb_rooms = 0;
	data->rooms_over = 0;
	data->links = 0;
	data->nb_links = 0;
	data->start_room = 0;
	data->end_room = 0;
}

void data_free(t_data *data)
{
	instructions_free(data->instructions);
	room_free(data->rooms);
	link_free(data->links);
}
