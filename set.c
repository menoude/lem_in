#include "lem_in.h"

int

void set_add(t_room **set, t_room *room)
{
	t_room *ptr;

	if (!*set)
	{
		*set = room;
		return ;
	}
	ptr = *set;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = room;
}

int set_contains(t_room *room)
{

}
