/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:55:31 by ccouliba          #+#    #+#             */
/*   Updated: 2023/03/30 00:29:05 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_config(t_config *config)
{
	config->direction = 0;
	config->position[0] = 0;
	config->position[1] = 0;
	config->map_size[0] = 0;
	config->map_size[1] = 0;
	config->north = NULL;
	config->south = NULL;
	config->west = NULL;
	config->east = NULL;
	config->floor = NULL;
	config->ceiling = NULL;
	config->map = (char **) NULL;
}

static void	get_map_position(t_config *config)
{
	int		i;
	int		j;
	char	**map;

	map = config->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				config->position[0] = i;
				config->position[1] = j;
			}
			++j;
		}
		++i;
	}
}

static int	check_arg_number(int ac)
{
	if (ac != 2)
	{
		if (ac < 2)
		{
			print_error(MISSING_ARG, 2);
			return (EXIT_FAILURE);
		}
		return (print_error(TOO_MANY, 2), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_all_config(t_config *config, char **line)
{
	if (!line || check_flag(line) || check_config(config, line))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parser(int ac, char **av, t_config *config)
{
	char		**line;

	if (!av)
		return (EXIT_FAILURE);
	if (check_arg_number(ac))
		return (EXIT_FAILURE);
	if (check_file(av[1], CUB_EXT))
		return (print_error(FILE_ERROR, 2), 1);
	line = read_file(av[1]);
	if (!line)
		return (print_error(FILE_ERROR, 2), 1);
	init_config(config);
	if (check_all_config(config, line))
		return (print_error(PARSING_ERROR, 2), 1);
	if (check_map(config, line))
		return (print_error(MAP_ERROR, 2), 1);
	get_map_position(config);
	map_size(config);
	return (/*free_double_p(line),*/ EXIT_SUCCESS);
}
