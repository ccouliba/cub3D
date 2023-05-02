/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:18:59 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 02:05:17 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*a_s;

	if (!s)
		return (NULL);
	a_s = (char *)s;
	while (*a_s && *a_s != c)
		a_s++;
	if (*a_s == c)
		return (a_s);
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a_s1;
	unsigned char	*a_s2;

	a_s1 = (unsigned char *)s1;
	a_s2 = (unsigned char *)s2;
	i = 0;
	while (a_s1[i] && a_s2[i] && a_s1[i] == a_s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (a_s1[i] - a_s2[i]);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;

	if (!s)
		return (NULL);
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}
