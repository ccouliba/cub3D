#include "../../includes/cub3D.h"

//INITIALISER TOUT AVANT SEND_RAYS

double deg2rad(double deg) {
    return deg * M_PI / 180.0;
}

void init_ray(t_mlx *mlx)
{
    static int  angle = -30;

    if (angle == 30)
        angle = -30;
    else
        angle++;
    mlx->ray.x = mlx->pos[0];
    mlx->ray.y = mlx->pos[1];
    mlx->ray.dx = mlx->ray.x;
    mlx->ray.dy = mlx->ray.y;
    mlx->ray.angle = mlx->angle - angle;
    mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle) / 64);
    mlx->ray.raySin = sin(deg2rad(mlx->ray.angle) / 64);
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

int raycasting(t_mlx mlx)
{
    int i;

    i = 0;
    while (i < 10)
    {
        init_ray(&mlx);
        //if (check_wall(mlx.ray))
        //{
        //    draw_line(i, distance(mlx));
        //}make
        printf("Ray_number: %d\n", i);
        for (int j = 0; j < 30; j++)
        {
            increment_ray(&mlx.ray);
            printf("ray_x = %f\n", mlx.ray.dx);
            printf("ray_y = %f\n", mlx.ray.dy);
        }
        i++;
    }
    return (0);
}