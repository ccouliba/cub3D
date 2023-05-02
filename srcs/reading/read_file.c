/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:18:43 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/01 23:47:35 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Read the file with GNL
** Then split it at '\n' and return a *str for each line
*/

/*
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
	ft_lstadd_back(&list, new);
	return (free(tmp), (void *)list);
}
*/

static void	*line_to_list(int fd, int (*rd)())
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
		res = rd(fd, &line);
		tmp = ft_lstnew((void *)line);
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&list, tmp);
	}
	return ((void *)list);
}

char	**malloc_2_ptr(t_list *token, void *(*_mllc)())
{
	int		i;
	int		size;
	char	*tmp;
	char	**param;

	size = ft_lstsize(token);
	param = (char **)malloc((sizeof(char *) * (size + 1)));
	if (!param)
		return ((char **) NULL);
	i = 0;
	while (token)
	{
		tmp = token->val;
		param[i] = (char *)_mllc(tmp);
		if (!param[i])
			return (free_double_p(param));
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
	tmp = line_to_list(fd, get_next_line);
	if (!tmp)
		return (NULL);
	line = malloc_2_ptr(tmp, (void *)ft_strdup);
	if (!line)
		return (NULL);
	free_list(&tmp, free);
	return (close(fd), line);
}
