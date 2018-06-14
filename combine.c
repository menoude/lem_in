#include "lem_in.h"

void combine_rooms_with_links(t_data *data)
{
	t_link *link_ptr;
	t_room *room_ptr;

	link_ptr = data->links;
	while (link_ptr)
	{
		room_ptr = finder_find_room(link_ptr->name1);
		if (!room_ptr->links)
			room_ptr->links = finder_find_room(link_ptr->name2);
		else
		{
			while (room)
		}
		link_ptr = link_ptr->next;
	}
	link_free(data->links);
	data->links = 0;
}

// comprendre comment les rooms communiquent entre elles et quelle forme ont
// les liens. Pas oublier qu'il faut qu'ils soient bi-directionnels
