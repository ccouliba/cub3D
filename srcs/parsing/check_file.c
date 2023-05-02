/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:16:50 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 01:50:40 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_directory(char *av)
{
	int	fd;

	if (av)
	{
		fd = open(av, O_DIRECTORY);
		if (fd != -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	there_is_path(char *av)
{
	if (ft_strchr(av, '/'))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static char	*relative_path(char *av)
{
	char	*tmp;
	char	**split;

	if (!av)
		return (NULL);
	split = ft_split(av, '/');
	if (!split)
		return (NULL);
	tmp = NULL;
	if (split[1])
	{
		tmp = ft_strdup(split[1]);
		if (!tmp)
			return (free_double_p(split), NULL);
		return (free_double_p(split), tmp);
	}
	if (tmp)
		free(tmp);
	return (free_double_p(split), av);
}

static int	is_hidden_file(char *av)
{
	char	*tmp;

	tmp = NULL;
	if (there_is_path(av))
	{
		tmp = relative_path(av);
		if (!tmp)
			return (EXIT_FAILURE);
		if (*tmp == '.' && ft_strlen(tmp) == 4)
			return (free(tmp), EXIT_FAILURE);
		free(tmp);
	}
	return (EXIT_SUCCESS);
}

/*
** 0 if the extension is .cub
** 1 if it is a dir or hidden file
*/
int	check_file(char *av, char *extension)
{
	int		dot;
	char	*ext;

	ext = NULL;
	dot = ft_strlen(av) - 4;
	if (av[dot])
	{
		ext = &(av[dot]);
		if (ext && *ext && *av != '.' && !ft_strcmp(ext, extension))
		{
			if (is_directory(av))
				return (EXIT_FAILURE);
		}
		else
			return (EXIT_FAILURE);
		if (is_hidden_file(av))
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
