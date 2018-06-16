#include "lem_in.h"

t_room *finder_find_room(t_room *rooms, char *name)
{
	while (rooms)
	{
		if (ft_strequ(rooms->name, name))
			return (rooms);
		rooms = rooms->next;
	}
	return (0);
}
