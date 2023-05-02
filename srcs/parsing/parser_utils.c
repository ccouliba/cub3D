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

void	_cfg(t_cfg *cfg)
{
	cfg[0].f = check_flag;
	cfg[0].msg = PARSING_ERROR;
	cfg[1].f = check_config;
	cfg[1].msg = PARSING_ERROR;
	cfg[2].f = check_map;
	cfg[2].msg = MAP_ERROR;
}
