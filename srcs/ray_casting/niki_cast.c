#include "../../includes/cub3D.h"

//INITIALISER TOUT AVANT SEND_RAYS

double deg2rad(double deg) {
    return deg * M_PI / 180.0;
}

void increment_ray(t_ray *ray)
{
    ray->dx += ray->rayCos;
    ray->dy += ray->raySin;
}

double distance(t_mlx mlx)
{
    return (sqrt(pow(mlx.pos[0] - mlx.ray.x, 2) + pow(mlx.pos[1] - mlx.ray.y, 2)));
}

int raycastig(t_mlx mlx)
{
    int i;

    i = 0;
    while (i < WIDTH)
    {
        printf("ray_x = %f\n", mlx.ray.x);
        printf("ray_y = %f\n", mlx.ray.y);
        if (check_wall(mlx.ray))
        {
            draw_line(i, distance(mlx));
        }
        increment_ray(&mlx.ray);
        i++;
    }
}