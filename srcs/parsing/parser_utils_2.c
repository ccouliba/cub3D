/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:17:11 by ccouliba          #+#    #+#             */
/*   Updated: 2023/10/25 17:16:36 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_walls(char *line)
{
	while (*line)
	{
		if (*line != '1' && *line != ' ')
			return (EXIT_FAILURE);
		++line;
	}
	return (EXIT_SUCCESS);
}

int	check_char(char *line)
{
	while (*line)
	{
		if (!*(line + 1) && !ft_strchr("01NSWE", *line))
			return (EXIT_FAILURE);
		++line;
	}
	if (line[ft_strlen(line) - 1] != '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_spaces(char *line)
{
	while (*line)
	{
		if (*line != ' ')
			break ;
		++line;
	}
	if (*line)
		if (*line != '1')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	after_zero(char *line)
{
	while (*line)
	{
		if (*line == '0')
		{
			++line;
			if (*line && !ft_strchr("01NSEW", *line))
				return (EXIT_FAILURE);
		}
		++line;
	}
	return (EXIT_SUCCESS);
}

int	after_start_pos(char *line)
{
	while (*line)
	{
		if (ft_strchr(VALID_POS, *line))
		{
			++line;
			if (*line && *line != '1' && *line != '0')
				return (EXIT_FAILURE);
		}
		++line;
	}
	return (EXIT_SUCCESS);
}
