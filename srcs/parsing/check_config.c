/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:35:57 by ccouliba          #+#    #+#             */
/*   Updated: 2023/03/30 00:24:58 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	check_surface_file(char *s)
{
	int		i;
	int		res;
	char	**tmp;

	if (occurences(s, ',') != 2)
		return (EXIT_FAILURE);
	tmp = ft_split(s, ',');
	if (!tmp)
		return (EXIT_FAILURE);
	if (!tmp[0] || !tmp[1] || !tmp[2] || tmp[3])
		return (free_double_p(tmp), EXIT_FAILURE);
	i = 0;
	while (tmp[i])
	{
		if (check_number(tmp[i]))
			return (free_double_p(tmp), EXIT_FAILURE);
		res = ft_atoi(tmp[i]);
		if (res < 0 || res > 255)
			return (free_double_p(tmp), EXIT_FAILURE);
		++i;
	}
	return (free_double_p(tmp), EXIT_SUCCESS);
}

static int	get_surface_config(t_config *config, char *line)
{
	char	*tmp;

	if (*line == 'F' || *line == 'C')
	{
		if (*(line + 1) && *(line + 1) != ' ')
			return (EXIT_FAILURE);
		tmp = ft_strchr(line, ' ');
		if (!tmp)
			return (EXIT_FAILURE);
		if (!ft_strncmp(line, "F", 1))
		{
			config->floor = tmp;
			if (check_surface_file(config->floor))
				return (EXIT_FAILURE);
		}
		else if (!ft_strncmp(line, "C", 1))
		{
			config->ceiling = tmp;
			if (check_surface_file(config->ceiling))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	get_direction_config(t_config *config, char *line, char *file)
{
	if (!ft_strncmp(line, NORTH, 2))
		config->north = file;
	else if (!ft_strncmp(line, SOUTH, 2))
		config->south = file;
	else if (!ft_strncmp(line, WEST, 2))
		config->west = file;
	else if (!ft_strncmp(line, EAST, 2))
		config->east = file;
	else if (*line == 'F' || *line == 'C')
	{
		if (get_surface_config(config, line))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_config_line(t_config *config, char *line)
{
	char	**s;

	if (!ft_strchr("NSWEFC", *line))
		return (EXIT_FAILURE);
	if (ft_strchr("NSWE", *line))
	{
		s = ft_split(line, ' ');
		if (s[0] && ft_strlen(s[0]) != 2)
			return (free_double_p(s), EXIT_FAILURE);
		if (!s || !s[1] || s[2] || check_xpm_file(s[1]))
			return (free_double_p(s), EXIT_FAILURE);
		if (get_direction_config(config, line, s[1]))
			return (free_double_p(s), EXIT_FAILURE);
		free_double_p(s);
	}
	else if (*line == 'F' || *line == 'C')
	{
		if (get_surface_config(config, line))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_config(t_config *config, char **line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (*line[i])
		{
			if (check_config_line(config, line[i]))
				return (EXIT_FAILURE);
			++count;
		}
		if (count == 6)
			break ;
		++i;
	}
	return (EXIT_SUCCESS);
}
