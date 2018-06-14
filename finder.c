#include "lem_in.h"

t_room *finder_find_room(t_room *rooms, char *name)
{
	t_room *ptr;

	ptr = data->rooms;
	while (ptr)
	{
		if (ft_strequ(ptr->name), name))
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}
