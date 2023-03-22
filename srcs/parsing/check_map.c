/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:37:28 by ccouliba          #+#    #+#             */
/*   Updated: 2023/03/17 04:53:36 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	get_map_beginning(char **line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i][0])
			++count;
		if (count == 6)
			break ;
		++i;
	}
	return (i + 1);
}

static char	**get_map(char **line)
{
	int		i;
	int		first_line;
	char	**map;

	if (!line)// || !*line)
		return (NULL);
	i = get_map_beginning(line);
	if (!line[i] || *line[i])
		return (NULL);
	while (line[i])
	{
		if (*line[i])
			break ;
		++i;
	}
	first_line = i;
	map = NULL;
	if (line[first_line] && *line[first_line])
		map = &line[first_line];
	return (map);
}

static int	start_pos(t_config *config, char *line)
{
	int		i;
	int		flag;
	char	*str;

	i = 0;
	flag = 0;
	str = NULL;
	while (line[i])
	{
		str = ft_strchr(VALID_POS, line[i++]);
		if (str)
		{
			config->direction = (int)(*str);
			++flag;
		}
	}
	if (flag == 1)
		return (1);
	if (flag > 1)
		return (flag);
	return (EXIT_SUCCESS);
}

static int	check_around_zero(char **line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] == '0')
				if (around_zero(line, i, j))
					return (EXIT_FAILURE);
			++j;
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

/*
** get map first
*/
int	check_map(t_config *config, char **line)
{
	int			i;
	int			res;
	char		**map;

	i = 0;
	res = 0;
	map = get_map(line);
	if (!map)
		return (EXIT_FAILURE);
	config->map = map;
	if (check_walls(map[i]))
		return (EXIT_FAILURE);
	++i;
	while (map[i])
	{
		if (*map[i] && (check_char(map[i]) || check_spaces(map[i])))
			return (EXIT_FAILURE);
		res += start_pos(config, map[i]);
		if (after_start_pos(map[i]) || after_zero(map[i]))
			return (EXIT_FAILURE);
		++i;
	}
	if (res != 1 || check_around_zero(config->map) || check_walls(map[i - 1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
