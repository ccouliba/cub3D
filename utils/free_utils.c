/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:57:14 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 01:56:15 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	free_ret_0(char **s)
{
	if (s)
		free_double_p(s);
	return (EXIT_SUCCESS);
}

int	free_ret_1(char **s)
{
	if (s)
		free_double_p(s);
	return (EXIT_FAILURE);
}

void	free_node(t_list *elem, void (*clr)())
{
	if (elem && clr)
	{
		free(elem->val);
		free(elem);
	}
}

/*
** Free function of the entire stack
*/
void	free_list(t_list **stack, void (*clr)())
{
	t_list	*elem;

	elem = NULL;
	if (*stack)
	{
		while (*stack)
		{
			elem = (*stack)->next;
			free_node(*stack, clr);
			*stack = elem;
		}
		*stack = NULL;
	}
}
