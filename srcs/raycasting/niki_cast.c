/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   niki_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:51:12 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 06:18:48 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <math.h>

//INITIALISER TOUT AVANT SEND_RAYS

int	hit_wall(t_game *game, int i)
{
	t_mlx	*mlx;
	char	**map;

	map = game->config.map;
	mlx = &game->img;
	if ((int)floor(mlx->ray.dy) < game->config.map_size[0]
		&& (int)floor(mlx->ray.last_y) - (int)floor(mlx->ray.dy)
		&& (int)floor(mlx->ray.dx)
		< ft_strlen(game->config.map[(int)floor(mlx->ray.dy)]))
	{
		mlx->ray.last_y = mlx->ray.dy;
		if (map[(int)floor(mlx->ray.dy)][(int)floor(mlx->ray.dx)] == '1')
			return (color_vline(mlx, i, disty(*mlx)), 1);
	}
	if ((int)floor(mlx->ray.dy) < game->config.map_size[0]
		&& (int)floor(mlx->ray.last_x) - (int)floor(mlx->ray.dx)
		&& (int)floor(mlx->ray.dx)
		< ft_strlen(game->config.map[(int)floor(mlx->ray.dy)]))
	{
		mlx->ray.last_x = mlx->ray.dx;
		if (map[(int)floor(mlx->ray.dy)][(int)floor(mlx->ray.dx)] == '1')
			return (color_vline(mlx, i, distx(*mlx)), 1);
	}
	return (0);
}

void	init_ray(t_mlx *mlx)
{
	mlx->ray.angle = mlx->angle - 30;
}

int	raycasting(t_game *game)
{
	int		i;
	t_mlx	*mlx;

	i = 0;
	mlx = &game->img;
	mlx->p_x = game->config.pos[1] + 0.5;
	mlx->p_y = game->config.pos[0] + 0.5;
	init_ray(mlx);
	while (i < WIDTH)
	{
		mlx->ray.last_x = mlx->p_x;
		mlx->ray.last_y = mlx->p_y;
		mlx->ray.dx = mlx->p_x;
		mlx->ray.dy = mlx->p_y;
		mlx->ray.raycos = cos(deg2rad(mlx->ray.angle)) / 256;
		mlx->ray.raysin = sin(deg2rad(mlx->ray.angle)) / 256;
		while (!hit_wall(game, i))
			increment_ray(&mlx->ray);
		mlx->ray.angle += 60 / (double)WIDTH;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
