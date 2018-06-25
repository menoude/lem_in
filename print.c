/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:43:17 by meyami            #+#    #+#             */
/*   Updated: 2018/06/25 22:56:36 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_queue(t_node *queue)
{
	ft_printf("\nqueue: \n");
	while (queue)
	{
		print_node(queue);
		queue = queue->next;
	}
	ft_printf("end of queue\n");
}

void	print_node(t_node *node)
{
	int i;

	i = -1;
	ft_printf("node: ");
	while (++i < node->path_size)
	{
		if (node->path[i])
			ft_printf("%s - ", node->path[i]->name);
	}
	ft_printf("\n");
}
