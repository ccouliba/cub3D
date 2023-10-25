/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:48:14 by ccouliba          #+#    #+#             */
/*   Updated: 2023/10/25 16:06:49 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*(str++) - '0') * sign;
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a_s;

	a_s = (unsigned char *)s;
	while (n-- > 0)
		*(a_s++) = 0;
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int	check_number(char *s)
{
	char	*tmp1;
	char	**tmp;

	tmp1 = NULL;
	tmp = ft_split(s, ' ');
	if (!tmp)
		return (EXIT_FAILURE);
	if (tmp[0])
	{
		tmp1 = tmp[0];
		if (tmp[1])
			return (EXIT_FAILURE);
	}
	while (*tmp1)
	{
		if (!ft_isdigit(*tmp1))
			return (EXIT_FAILURE);
		++tmp1;
	}
	return (EXIT_SUCCESS);
}

unsigned int	get_config_color(char *s)
{
	char			**tmp;
	unsigned int	rgb_color;

	rgb_color = 0;
	if (occurences(s, ',') != 2)
		return (EXIT_FAILURE);
	tmp = ft_split(s, ',');
	if (!tmp)
		return (free_double_p(tmp), EXIT_FAILURE);
	rgb_color = (ft_atoi(tmp[0]) << 16) | (ft_atoi(tmp[1]) << 8)
		| ft_atoi(tmp[2]);
	return (free_double_p(tmp), rgb_color);
}
