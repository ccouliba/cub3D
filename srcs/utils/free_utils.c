/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:57:14 by ccouliba          #+#    #+#             */
/*   Updated: 2023/10/27 20:30:22 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
			clr((*stack)->val);
			clr(*stack);
			*stack = elem;
		}
		*stack = NULL;
	}
}

void	init_texture(t_config *config)
{
	int	i;

	i = 0;
	while (i < 4)
		config->tex_files[i++] = 0;
}

void	free_textures(t_config *config)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (config->tex_files && config->tex_files[i])
			free(config->tex_files[i]);
		++i;
	}
}
