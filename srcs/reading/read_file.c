/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:18:43 by ccouliba          #+#    #+#             */
/*   Updated: 2023/10/27 20:29:47 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Read the file with GNL
** Then split it at '\n' and return a *str for each line
*/

void	*line_to_list(t_list *list, char *line)
{
	void	*tmp;
	t_list	*new;

	tmp = (void *)ft_strdup(line);
	if (!tmp)
		return (NULL);
	new = ft_lstnew((void *)tmp);
	if (!new)
		return (NULL);
	free(tmp);
	ft_lstadd_back(&list, ft_lstnew((void *) tmp));
	return ((void *)list);
}

static void	*get_line(int fd)
{
	int		res;
	char	*line;
	t_list	*tmp;
	t_list	*list;

	res = 1;
	line = NULL;
	list = NULL;
	while (res == 1)
	{
		res = get_next_line(fd, &line);
		tmp = ft_lstnew((void *)line);
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&list, tmp);
	}
	return ((void *)list);
}

char	**ft_malloc_double_p(t_list *token)
{
	int		i;
	char	*tmp;
	char	**param;

	if (!token)
		return ((char **) NULL);
	param = (char **)malloc((sizeof(char *) * (ft_lstsize(token) + 1)));
	if (!param)
		return ((char **) NULL);
	i = 0;
	while (token)
	{
		tmp = token->val;
		param[i] = ft_strdup(tmp);
		if (!param[i])
			return (free_double_p(param), (char **) NULL);
		token = token->next;
		++i;
	}
	param[i] = 0;
	return (param);
}

char	**read_file(char *av)
{
	int		fd;
	char	**line;
	t_list	*tmp;

	if (!av)
		return (NULL);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp = get_line(fd);
	if (!tmp)
		return (NULL);
	line = ft_malloc_double_p(tmp);
	if (!line || !*line)
		return (NULL);
	free_stack(&tmp, free);
	close(fd);
	return (line);
}
