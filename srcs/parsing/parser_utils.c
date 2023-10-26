/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:29:22 by ccouliba          #+#    #+#             */
/*   Updated: 2023/10/26 16:12:11 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_extension(char *s, char *extension)
{
	if (ft_strcmp(s, extension))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_xpm_file(char *s)
{
	int		fd;
	int		index;
	char	*ext;

	index = ft_strlen(s) - 4;
	if (s[index])
	{
		ext = &(s[index]);
		if (!ext || (check_extension(ext, XPM_EXT) || is_directory(ext)))
			return (EXIT_FAILURE);
	}
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	close(fd);
	fd = open(s, O_DIRECTORY);
	if (fd != -1)
		return (EXIT_FAILURE);
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

int	occurences(char *s, int c)
{
	int	flag;

	flag = 0;
	while (*s)
	{
		if (*s == c)
			++flag;
		++s;
	}
	return (flag);
}

void	lines_length(t_config *config)
{
	int		i;
	char	**map;

	i = 0;
	map = config->map;
	++i;
	while (map[i])
	{
		if (*map[i])
			if (ft_strlen(map[i]) > ft_strlen(map[i - 1]))
				config->map_size[1] = ft_strlen(map[i]);
		++i;
	}
	config->map_size[0] = i;
}
