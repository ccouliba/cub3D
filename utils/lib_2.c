/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:48:14 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 02:05:54 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a_s;

	a_s = (unsigned char *)s;
	while (n-- > 0)
		*(a_s++) = 0;
}

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
			return (free_ret_1(tmp));
	}
	while (*tmp1)
	{
		if (!ft_isdigit(*tmp1))
			return (free_ret_1(tmp));
		++tmp1;
	}
	return (free_ret_0(tmp));
}
