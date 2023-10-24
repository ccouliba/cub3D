/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:24:17 by ngenadie          #+#    #+#             */
/*   Updated: 2023/10/24 18:24:19 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_mlx(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(mlx));
}

void	init_ray(t_mlx *mlx)
{
		mlx->ray.last_x = mlx->p_x;
		mlx->ray.last_y = mlx->p_y;
		mlx->ray.dx = mlx->p_x;
		mlx->ray.dy = mlx->p_y;
		mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle)) / PRECISION;
		mlx->ray.raySin = sin(deg2rad(mlx->ray.angle)) / PRECISION;
}
