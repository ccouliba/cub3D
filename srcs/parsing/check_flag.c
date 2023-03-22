/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:00:17 by ccouliba          #+#    #+#             */
/*   Updated: 2023/03/22 21:49:11 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_flag(t_flag *flag)
{
	flag->north = 0;
	flag->south = 0;
	flag->west = 0;
	flag->east = 0;
	flag->floor = 0;
	flag->ceiling = 0;
}

static void	get_flag_line(t_flag *flag, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		++flag->north;
	else if (!ft_strncmp(line, SOUTH, 2))
		++flag->south;
	else if (!ft_strncmp(line, WEST, 2))
		++flag->west;
	else if (!ft_strncmp(line, EAST, 2))
		++flag->east;
	else if (*line && *line == 'F')
		++flag->floor;
	else if (*line && *line == 'C')
		++flag->ceiling;
}

static int	check_flag_value(t_flag *flag)
{
	if (flag->north != 1 || flag->south != 1)
		return (EXIT_FAILURE);
	else if (flag->west != 1 || flag->east != 1)
		return (EXIT_FAILURE);
	else if (flag->floor != 1 || flag->ceiling != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_flag(char **file)
{
	t_flag	flag;

	init_flag(&flag);
	while (*file)
	{
		get_flag_line(&flag, *file);
		// printf("*file : [%s]\nfloor = [%d]\nceiling = [%d]\n", *file, flag.floor, flag.ceiling);
		++file;
	}
	if (check_flag_value(&flag))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
