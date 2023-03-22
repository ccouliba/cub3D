/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:07:00 by ccouliba          #+#    #+#             */
/*   Updated: 2023/03/10 12:50:34 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
		write(fd, s, ft_strlen(s));
}

void	print_error(char *type, int fd)
{
	ft_putstr_fd("[\033[5;31m!\033[0;m]", fd);
	ft_putstr_fd(" cub3D", fd);
	ft_putstr_fd(" : ", fd);
	ft_putstr_fd(type, fd);
	return ;
}
