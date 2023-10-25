/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:08:25 by ngenadie          #+#    #+#             */
/*   Updated: 2023/10/25 18:37:25 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_ray_dir(double x, double y, double angle, char **map)
{
	if (angle < 180)
	{
		if (map[(int)(y + 0.2)][(int)x] == '0')
			return (1);
	}
	if (angle > 180)
	{
		if (map[(int)(y - 0.2)][(int)x] == '0')
			return (0);
	}
	if (map[(int)y][(int)(x + 0.2)] == '0')
		return (2);
	return (3);
}

double	deg2rad(double deg)
{
	return (deg * M_PI / 180.0);
}

double	distx(t_mlx *mlx)
{
	float	dist;
	float	fish;

	if (mlx->ray.raycos < 0)
		mlx->ray.dx++;
	mlx->ray.dx = floor(mlx->ray.dx);
	dist = sqrt(pow(mlx->p_x - mlx->ray.dx, 2)
			+ pow(mlx->p_y - mlx->ray.dy, 2));
	fish = cos(deg2rad(fabs(mlx->ray.angle - mlx->angle)));
	return (dist * fish);
}

double	disty(t_mlx *mlx)
{
	float	dist;
	float	fish;

	if (mlx->ray.raysin < 0)
		mlx->ray.dy++;
	mlx->ray.dy = floor(mlx->ray.dy);
	dist = sqrt(pow(mlx->p_x - mlx->ray.dx, 2)
			+ pow(mlx->p_y - mlx->ray.dy, 2));
	fish = cos(deg2rad(fabs(mlx->ray.angle - mlx->angle)));
	return (dist * fish);
}

void	increment_ray(t_ray *ray)
{
	ray->dx += ray->raycos;
	ray->dy += ray->raysin;
}
