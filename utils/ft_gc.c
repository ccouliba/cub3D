/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:41 by ccouliba          #+#    #+#             */
/*   Updated: 2023/04/25 20:19:07 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// cmd = (t_cmd *)push_top(&g_data.gc, sizeof(t_cmd));
// 	if (!cmd)
// 		return (gc_free(), NULL);

void	*push_top(t_gc **head, size_t data_size)
{
	t_gc	*new_node;

	new_node = (t_gc *)malloc(sizeof(t_gc));
	if (!new_node)
	{
		gc_free();
		return (NULL);
	}
	new_node->addr = (void *)malloc(data_size);
	if (!new_node->addr)
	{
		gc_free();
		free(new_node);
		return (NULL);
	}
	new_node->next = *head;
	*head = new_node;
	return (new_node->addr);
}

void	gc_free(void)
{
	t_gc	*current;

	current = g_data.gc;
	while (current != NULL)
	{
		g_data.gc = g_data.gc->next;
		free(current->addr);
		current->next = NULL;
		free(current);
		current = g_data.gc;
	}
}
