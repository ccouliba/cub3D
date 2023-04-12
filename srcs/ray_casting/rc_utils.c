#include "../../includes/cub3D.h"

double deg2rad(double deg)
{
    return deg * M_PI / 180.0;
}

double distance(t_mlx mlx)
{
    return (sqrt(pow(mlx.pos[0] - mlx.ray.dx, 2) + pow(mlx.pos[1] - mlx.ray.dy, 2)));
}

void increment_ray(t_ray *ray)
{
    ray->dx += ray->rayCos;
    ray->dy += ray->raySin;
}