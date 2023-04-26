#include "../../includes/cub3D.h"

double deg2rad(double deg)
{
	return deg * M_PI / 180.0;
}

double distx(t_mlx mlx)
{
	static int i = 0;

	if (mlx.ray.rayCos < 0)
		mlx.ray.dx++;
	if (i % 10 == 0)
	{
		dprintf(2, "DISTtri x = %f, ", cos(deg2rad(mlx.ray.angle - mlx.angle)) * sqrt(pow(mlx.p_x - (int)mlx.ray.dx, 2) + pow(mlx.p_y - mlx.ray.dy, 2)));
		dprintf(2, "DIST x = %f, ", sqrt(pow(mlx.p_x - (int)mlx.ray.dx, 2) + pow(mlx.p_y - mlx.ray.dy, 2)));
		dprintf(2, "diff_y = %f, ", mlx.ray.dy - mlx.p_y);
		dprintf(2, "diff_x = %f\n", (int)mlx.ray.dx - mlx.p_x);
	}
	i++;
	return (cos(deg2rad(mlx.ray.angle - mlx.angle)) * sqrt(pow(mlx.p_x - (int)mlx.ray.dx, 2) + pow(mlx.p_y - mlx.ray.dy, 2)));
}

double disty(t_mlx mlx)
{
	static int i = 0;

	if (mlx.ray.raySin < 0)
		mlx.ray.dy++;
	if (i % 10 == 0)
	{
		dprintf(2, "DISTtri y = %f, ", cos(deg2rad(mlx.ray.angle - mlx.angle)) * sqrt(pow(mlx.p_x - mlx.ray.dx, 2) + pow(mlx.p_y - (int)mlx.ray.dy, 2)));
		dprintf(2, "DIST y = %f, ", sqrt(pow(mlx.p_x - mlx.ray.dx, 2) + pow(mlx.p_y - (int)mlx.ray.dy, 2)));
		dprintf(2, "ray.dy = %d, mlx.p_y = %f\n", (int)mlx.ray.dy, mlx.p_y);
		dprintf(2, "diff_y = %f, ", (int)mlx.ray.dy - mlx.p_y);
		dprintf(2, "diff_x = %f\n", mlx.ray.dx - mlx.p_x);
	}
	i++;	
	return (cos(deg2rad(mlx.ray.angle - mlx.angle)) * sqrt(pow(mlx.p_x - mlx.ray.dx, 2) + pow(mlx.p_y - (int)mlx.ray.dy, 2)));
}

void increment_ray(t_ray *ray)
{
    ray->dx += ray->rayCos;
    ray->dy += ray->raySin;
}
