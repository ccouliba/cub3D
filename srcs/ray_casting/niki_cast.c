#include "../../includes/cub3D.h"

//INITIALISER TOUT AVANT SEND_RAYS

void init_ray(t_mlx *mlx)
{
    mlx->ray.angle = mlx->angle - 30; 
}

int raycasting(t_mlx *mlx)
{
    int i;

    i = 0;
    init_ray(mlx);
    while (i < WIDTH)
    {
        mlx->ray.dx = mlx->pos[0];
        mlx->ray.dy = mlx->pos[1];
        mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle) / 64);
        mlx->ray.raySin = sin(deg2rad(mlx->ray.angle) / 64);
        while (mlx->ray.dx < 90)
            increment_ray(&mlx->ray);
        color_line(mlx, i, 0, distance(*mlx) * cos(deg2rad(mlx->ray.angle - mlx->angle)));
        if (i % 10 == 0)
            printf("distance2 = %f\n", distance(*mlx) * cos(deg2rad(mlx->ray.angle - mlx->angle)));
        mlx->ray.angle += 60 / (double)WIDTH;
        i++;
    }
    return (0);
}