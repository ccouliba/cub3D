/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:07:36 by ccouliba          #+#    #+#             */
/*   Updated: 2023/04/26 19:05:49 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_gc	*_garbage(void)
{
	static t_gc	*gc = NULL;

	if (!gc)
	{
		gc = (t_gc *)malloc(sizeof(t_gc));
		if (!gc)
			return (gc_free(), NULL);
	}
	return (gc);
}

/*
** split = (char **)push_top(&g_data.gc, sizeof(char *) * (i + 1));
*/
void	*push_top(t_gc **head, size_t data_size)
{
	t_gc	*new_node;

	// new_node = (t_gc *)malloc(sizeof(t_gc));
	// if (!new_node)
	// {
	// 	gc_free();
	// 	return (NULL);
	// }
	new_node = _garbage();
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
	t_gc	*gc;
	t_gc	*current;

	current = _garbage();
	gc = current;
	while (current != NULL)
	{
		gc = gc->next;
		free(current->addr);
		current->next = NULL;
		free(current);
		current = gc;
	}
}
