/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:50:41 by ccouliba          #+#    #+#             */
/*   Updated: 2023/03/09 21:17:26 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (s1 && s1[++i] != '\0')
		tab[i] = s1[i];
	while (s2 && s2[++j] != '\0')
		tab[i + j] = s2[j];
	free(s1);
	tab[i + j] = '\0';
	return (tab);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*sub;

	// if (!s)
	// 	return (NULL);
	sub = malloc(sizeof(char) * (len - start + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s && s[start] && start < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
