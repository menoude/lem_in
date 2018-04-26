#include "lem_in.h"

void room_free(t_room *rooms)
{
	if (!rooms)
		return ;
	room_free(rooms->next);
	free(rooms->name);
	free(rooms);
}

// check qu'on en soit pas deja aux liens, que la room est au bon format, qu'elle n'existe pas encore en termes de coordonnees, puis la crée
int room_add()
{
	return (1);
}
