/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 03:06:44 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 05:10:06 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	after_zero(char *line)
{
	while (*line)
	{
		if (*line == '0')
		{
			++line;
			if (*line && !ft_strchr("01NSEO", *line))
				return (EXIT_FAILURE);
		}
		++line;
	}
	return (EXIT_SUCCESS);
}

int	around_zero(char **line, int i, int j)
{
	if (!line[i][j - 1] || !ft_strchr("01NSWE", line[i][j - 1]))
		return (EXIT_FAILURE);
	if (!line[i - 1][j - 1] || !ft_strchr("01NSWE", line[i - 1][j - 1]))
		return (EXIT_FAILURE);
	if (!line[i - 1][j] || !ft_strchr("01NSWE", line[i - 1][j]))
		return (EXIT_FAILURE);
	if (!line[i - 1][j + 1] || !ft_strchr("01NSWE", line[i - 1][j + 1]))
		return (EXIT_FAILURE);
	if (!line[i + 1] || !line[i + 1][j - 1]
		|| !ft_strchr("01NSWE", line[i + 1][j - 1]))
		return (EXIT_FAILURE);
	if (!line[i + 1] || !line[i + 1][j] || !ft_strchr("01NSWE", line[i + 1][j]))
		return (EXIT_FAILURE);
	if (!line[i + 1] || !line[i + 1][j + 1]
		|| !ft_strchr("01NSWE", line[i + 1][j + 1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	map_size(t_config *config)
{
	int		i;
	char	**map;

	i = 1;
	map = config->map;
	if (!map)
		return ;
	while (map[i])
	{
		if (*map[i])
			if (ft_strlen(map[i]) >= ft_strlen(map[i - 1]))
				config->map_size[1] = ft_strlen(map[i]);
		++i;
	}
	config->map_size[0] = i;
}
