/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   niki_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:42:14 by ngenadie          #+#    #+#             */
/*   Updated: 2023/10/25 17:10:05 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <math.h>

int	hit_wall2(t_game *game, int i, int ret)
{
	t_mlx			*mlx;
	char			**map;

	map = game->config.map;
	mlx = &game->img;
	mlx->ceiling = game->config.ceiling_color;
	mlx->floor = game->config.floor_color;
	if ((int)mlx->ray.dy < game->config.map_size[0]
		&& (int)mlx->ray.last_y - (int)mlx->ray.dy
		&& (int)mlx->ray.dx < ft_strlen(game->config.map[(int)mlx->ray.dy]))
	{
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1')
		{
			ret = 1;
			if (mlx->ray.dy > mlx->p_y
				&& map[(int)mlx->ray.dy - 1][(int)mlx->ray.dx] != '1')
				return (color_vline(mlx, i, disty(mlx), mlx->texs[0]), 1);
			if (mlx->ray.dy < mlx->p_y
				&& map[(int)mlx->ray.dy + 1][(int)mlx->ray.dx] != '1')
				return (color_vline(mlx, i, disty(mlx), mlx->texs[1]), 1);
		}
	}
	mlx->ray.last_y = mlx->ray.dy;
	mlx->ray.last_x = mlx->ray.dx;
	return (ret);
}

int	hit_wall(t_game *game, int i)
{
	t_mlx			*mlx;
	char			**map;
	int				ret;

	map = game->config.map;
	mlx = &game->img;
	mlx->ceiling = game->config.ceiling_color;
	mlx->floor = game->config.floor_color;
	ret = 0;
	if ((int)mlx->ray.dy < game->config.map_size[0]
		&& (int)mlx->ray.last_x - (int)mlx->ray.dx
		&& (int)mlx->ray.dx < ft_strlen(game->config.map[(int)mlx->ray.dy]))
	{
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1')
		{
			ret = 1;
			if (mlx->ray.dx > mlx->p_x
				&& map[(int)mlx->ray.dy][(int)mlx->ray.dx - 1] != '1')
				return (color_vline(mlx, i, distx(mlx), mlx->texs[2]), 1);
			if (mlx->ray.dx < mlx->p_x
				&& map[(int)mlx->ray.dy][(int)mlx->ray.dx + 1] != '1')
				return (color_vline(mlx, i, distx(mlx), mlx->texs[3]), 1);
		}
	}
	return (hit_wall2(game, i, ret));
}

void	player_direction(t_game game, t_mlx *mlx)
{
	if (game.config.direction == 'W')
		mlx->angle = 180;
	if (game.config.direction == 'N')
		mlx->angle = 270;
	if (game.config.direction == 'S')
		mlx->angle = 90;
}

int	raycasting(t_game *game)
{
	int		i;
	t_mlx	*mlx;

	i = 0;
	mlx = &game->img;
	move(game);
	//printf("direction = %c\n", game->config.direction);
	//printf("angle = %f\n", mlx->angle);
	mlx->ray.angle = mlx->angle - HALF_FOV;
	color_line(mlx, 800, 100);
	dprintf(2, "==========================\n");
	while (i < WIDTH)
	{
		init_ray(mlx);
		while (!hit_wall(game, i))
			increment_ray(&mlx->ray);
		mlx->ray.angle += FOV / (double)WIDTH;
		if (mlx->ray.angle > 360)
			mlx->ray.angle -= 360;
		if (mlx->ray.angle < 0)
			mlx->ray.angle += 360;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
