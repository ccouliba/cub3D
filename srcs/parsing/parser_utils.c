/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:29:22 by ccouliba          #+#    #+#             */
/*   Updated: 2023/02/16 05:35:12 by ccouliba         ###   ########.fr       */
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
	if (!line[i + 1] || !line[i + 1][j - 1] || !ft_strchr("01NSWE", line[i + 1][j - 1]))
		return (EXIT_FAILURE);
	if (!line[i + 1] || !line[i + 1][j] || !ft_strchr("01NSWE", line[i + 1][j]))
		return (EXIT_FAILURE);
	if (!line[i + 1] || !line[i + 1][j + 1] || !ft_strchr("01NSWE", line[i + 1][j + 1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	around_char(char **line, int i, int j)
{
	char	*charset;

	if (line[i][j] == ' ')
		charset = "1 ";
	else
		charset = "01NSWE";

	if (!line[i][j - 1] || !ft_strchr("01NSWE", line[i][j - 1]))
		return (EXIT_FAILURE);
	if (!line[i - 1][j - 1] || !ft_strchr("01NSWE", line[i - 1][j - 1]))
		return (EXIT_FAILURE);
	if (!line[i - 1][j] || !ft_strchr("01NSWE", line[i - 1][j]))
		return (EXIT_FAILURE);
	if (!line[i - 1][j + 1] || !ft_strchr("01NSWE", line[i - 1][j + 1]))
		return (EXIT_FAILURE);
	if (!line[i + 1] || !line[i + 1][j - 1] || !ft_strchr("01NSWE", line[i + 1][j - 1]))
		return (EXIT_FAILURE);
	if (!line[i + 1] || !line[i + 1][j] || !ft_strchr("01NSWE", line[i + 1][j]))
		return (EXIT_FAILURE);
	if (!line[i + 1] || !line[i + 1][j + 1] || !ft_strchr("01NSWE", line[i + 1][j + 1]))
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

void	map_size(t_config *config)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(config->map[i]);
	++i;
	while (config->map[i])
	{
		if (*config->map[i])
			if (ft_strlen(config->map[i]) >= ft_strlen(config->map[i - 1]))
				config->map_size[1] = ft_strlen(config->map[i]);
		++i;
	}
	config->map_size[0] = i;
}
