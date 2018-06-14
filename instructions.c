#include "lem_in.h"

int instructions_add(t_data *data, char *input)
{
	t_instruction *ptr;
	t_instruction *new_instruct;

	if (!(new_instruct = ft_memalloc(sizeof(t_instruction))))
		return (0);
	new_instruct->content = ft_strdup(input);
	new_instruct->next = 0;
	if (!data->instructions)
		data->instructions = new_instruct;
	else
	{
		ptr = data->instructions;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_instruct;
	}
	return (1);
}

void instructions_flush(t_data *data)
{
	t_instruction *instruct;
	t_instruction *instruct_next;

	instruct_next = data->instructions;
	while (instruct_next)
	{
		instruct = instruct_next;
		instruct_next = instruct->next;
		ft_printf("%s\n", instruct->content);
		free(instruct);
	}
}
