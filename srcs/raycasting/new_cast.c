/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:51:07 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 05:57:11 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	raycasting(t_mlx *mlx)
{
	int	i;

	i = 0;
	init_ray(mlx);
	while (i < WIDTH)
	{
		mlx->ray.dx = mlx->pos[0];
		mlx->ray.dy = mlx->pos[1];
		j = 0;
		while (j < 100)
		{
			increment_ray(&mlx->ray);
			++j;
		}
		mlx->ray.angle += 60 / (double)1800;
		i++;
	}
	return (0);
}
