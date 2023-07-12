#include "../../includes/cub3D.h"

double deg2rad(double deg)
{
	return deg * M_PI / 180.0;
}

double distx(t_mlx *mlx)
{
	if (mlx->ray.rayCos < 0)
		mlx->ray.dx++;
	mlx->ray.dx = floor(mlx->ray.dx);
	float dist = sqrt(pow(mlx->p_x - mlx->ray.dx, 2) + pow(mlx->p_y - mlx->ray.dy, 2));
	float fish = cos(deg2rad(fabs(mlx->ray.angle - mlx->angle)));
	return (dist * fish);
}

double disty(t_mlx *mlx)
{
	if (mlx->ray.raySin < 0)
		mlx->ray.dy++;
	mlx->ray.dy = floor(mlx->ray.dy);
	float dist = sqrt(pow(mlx->p_x - mlx->ray.dx, 2) + pow(mlx->p_y - mlx->ray.dy, 2));
	float fish = cos(deg2rad(fabs(mlx->ray.angle - mlx->angle)));
	return (dist * fish);
}

void increment_ray(t_ray *ray)
{
	ray->dx += ray->rayCos;
	ray->dy += ray->raySin;
}
