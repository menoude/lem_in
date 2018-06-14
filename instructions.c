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

void instructions_flush(t_instruction *instructions)
{
	if (!instructions)
		return ;
	ft_printf("%s\n", instructions->content);
	instructions_flush(instructions->next);
	free(instructions->content);
	free(instructions);
}
