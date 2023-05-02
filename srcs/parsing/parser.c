/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:55:31 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 05:22:23 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_config(t_config *config)
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

static void	map_position(t_config *config)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = config->map;
	if (!map)
		return ;
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
			print_error(MISSING_ARG, 2);
		else
			print_error(TOO_MANY, 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	_all_config(t_config *config, char **line)
{
	int		i;
	int		ret;
	t_cfg	cfg[3];

	i = -1;
	_cfg(cfg);
	ret = -1;
	while (++i < 3)
	{
		ret = cfg[i].f(config, line);
		if (ret)
			return (print_error(cfg[i].msg, 2), ret);
	}
	return (EXIT_SUCCESS);
}

int	parser(int ac, char **av, t_config *config)
{
	char		**line;

	if (!av || check_arg_number(ac))
		return (EXIT_FAILURE);
	if (check_file(av[1], CUB_EXT))
		return (print_error(FILE_ERROR, 2), 1);
	line = read_file(av[1]);
	if (!line)
		return (print_error(FILE_ERROR, 2), 1);
	init_config(config);
	if (!line || _all_config(config, line))
		return (free_ret_1(line));
	map_size(config);
	map_position(config);
	return (free_ret_0(line));
}
