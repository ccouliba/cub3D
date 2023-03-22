/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:57:14 by ccouliba          #+#    #+#             */
/*   Updated: 2023/03/10 01:30:58 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_elem(t_list *elem, void (*clr)())
{
	if (elem && clr)
		free(elem);
}

/*
** Free function of the entire stack
*/
void	free_stack(t_list **stack, void (*clr)())
{
	t_list	*elem;

	elem = NULL;
	if (*stack)
	{
		while (*stack)
		{
			elem = (*stack)->next;
			clr(*stack);
			*stack = elem;
		}
		*stack = NULL;
	}
}
