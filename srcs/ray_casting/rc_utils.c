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
	float dist = sqrt(pow(mlx.p_x - floor(mlx.ray.dx), 2) + pow(mlx.p_y - (mlx.ray.dy), 2));
	float fish = cos(deg2rad((mlx.ray.angle - mlx.angle)));
	if (i % 25 == 0)
	{
		dprintf(2, "anlge_diff = %f, ", mlx.angle - mlx.ray.angle);
		dprintf(2, "dist XX = %f, x = %f, p_x = %f, y = %f, py_= %f\n", dist * fish, mlx.p_x, floor(mlx.ray.dx), mlx.ray.dy, mlx.p_y);
		//dprintf(2, "angle = %f\n", mlx.ray.angle);
		//dprintf(2, "fish = %f\n", fish);
	}
	i++;
	return (dist * fish);
//	return (cos(deg2rad((mlx.ray.angle - mlx.angle) / 2)) * sqrt(pow(mlx.p_x - (int)floor(mlx.ray.dx), 2) + pow(mlx.p_y - mlx.ray.dy, 2)));
}

double disty(t_mlx mlx)
{
	static int i = 0;
	if (mlx.ray.raySin < 0)
		mlx.ray.dy++;
	float dist = sqrt(pow(mlx.p_x - mlx.ray.dx, 2) + pow(mlx.p_y - floor(mlx.ray.dy), 2));
	float fish = cos(deg2rad((mlx.ray.angle - mlx.angle)));
	if (i % 25 == 0)
	{
		dprintf(2, "anlge_diff = %f, ", mlx.angle - mlx.ray.angle);
		dprintf(2, "dist YY = %f, x = %f, p_x = %f, y = %f, py_= %f\n", dist * fish, mlx.p_x, (mlx.ray.dx), floor(mlx.ray.dy), mlx.p_y);
		//dprintf(2, "angle = %f\n", mlx.ray.angle);
		//dprintf(2, "fish = %f\n", fish);
	}
	i++;
	return (dist * fish);
//	return (cos(deg2rad((mlx.ray.angle - mlx.angle) / 2)) * sqrt(pow(mlx.p_x - mlx.ray.dx, 2) + pow(mlx.p_y - (int)floor(mlx.ray.dy), 2)));
}

void increment_ray(t_ray *ray)
{
    ray->dx += ray->rayCos;
    ray->dy += ray->raySin;
}
