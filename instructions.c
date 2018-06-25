/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:42:29 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 22:47:34 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		instructions_add(t_data *data, char *input)
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

void	instructions_print(t_instruction *instructions)
{
	while (instructions)
	{
		ft_printf("%s\n", instructions->content);
		instructions = instructions->next;
	}
}

void	instructions_free(t_instruction *instructions)
{
	t_instruction *ptr;

	if (!(ptr = instructions))
		return ;
	while (ptr)
	{
		instructions = instructions->next;
		free(ptr->content);
		free(ptr);
		ptr = instructions;
	}
}
