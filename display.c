#include "lem_in.h"

int displayer_display(t_data *data, t_node *path)
{
	int *ants;
	int i;

	if (!(ants = ft_memalloc(sizeof(int) * data->nb_ants)))
		return (0);
	ft_memset(ants, -1, sizeof(int) * data->nb_ants));
	instructions_print(data->instructions);
	i = -1;
	while (++i < path[])
	free(ants);
}
