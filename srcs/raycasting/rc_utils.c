/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 05:57:24 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 06:19:15 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	deg2rad(double deg)
{
	return (deg * M_PI / 180.0);
}

double	distx(t_mlx mlx)
{
	static int	i = 0;

	if (mlx.ray.raycos < 0)
		mlx.ray.dx++;
	if (i % 10 == 0)
	{
		//dprintf(2, "DISTtri x = %f, ", cos(deg2rad(mlx.ray.angle - mlx.angle)) * sqrt(pow(mlx.p_x - (int)mlx.ray.dx, 2) + pow(mlx.p_y - mlx.ray.dy, 2)));
		//dprintf(2, "DIST x = %f, ", sqrt(pow(mlx.p_x - (int)mlx.ray.dx, 2) + pow(mlx.p_y - mlx.ray.dy, 2)));
		//dprintf(2, "diff_y = %f, ", mlx.ray.dy - mlx.p_y);
		//dprintf(2, "diff_x = %f\n", (int)mlx.ray.dx - mlx.p_x);
	}
	i++;
	return (cos(deg2rad(mlx.ray.angle - mlx.angle))
		* sqrt(pow(mlx.p_x - (int)floor(mlx.ray.dx), 2) 
			+ pow(mlx.p_y - mlx.ray.dy, 2)));
}

double	disty(t_mlx mlx)
{
	static int	i = 0;

	if (mlx.ray.raysin < 0)
		mlx.ray.dy++;
	i++;
	return (cos(deg2rad(mlx.ray.angle - mlx.angle))
		* sqrt(pow(mlx.p_x - mlx.ray.dx, 2)
			+ pow(mlx.p_y - (int)floor(mlx.ray.dy), 2)));
}

void	increment_ray(t_ray *ray)
{
	ray->dx += ray->raycos;
	ray->dy += ray->raysin;
}
