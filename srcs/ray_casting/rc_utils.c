#include "../../includes/cub3D.h"

double deg2rad(double deg)
{
	return deg * M_PI / 180.0;
}

double distance(t_mlx mlx)
{
	return (pow(mlx.pos[0] - (int)mlx.ray.dx, 2) + pow(mlx.pos[1] - mlx.ray.dy, 2));
}

double distx(t_mlx mlx)
{
	return (pow(mlx.pos[0] - (int)mlx.ray.dx, 2) + pow(mlx.pos[1] - mlx.ray.dy, 2));
}

double disty(t_mlx mlx)
{
	return (pow(mlx.pos[0] - mlx.ray.dx, 2) + pow(mlx.pos[1] - (int)mlx.ray.dy, 2));
}

void increment_ray(t_ray *ray)
{
    ray->dx += ray->rayCos;
    ray->dy += ray->raySin;
}
