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
    printf("WIDTH = %d, HEIGHT = %d\n", WIDTH, HEIGHT);
    init_ray(mlx);
    while (i < WIDTH)
    {
        mlx->ray.dx = mlx->pos[0];
        mlx->ray.dy = mlx->pos[1];
        mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle) / 64);
        mlx->ray.raySin = sin(deg2rad(mlx->ray.angle) / 64);
        while (mlx->ray.dx < 90)
            increment_ray(&mlx->ray);
        printf("ray_x = %f\n", mlx->ray.dx);
        printf("ray_y = %f\n", mlx->ray.dy);
        printf("distance = %f\n", distance(*mlx));
        printf("angle = %f\n", mlx->ray.angle);
        mlx->ray.angle += 60 / (double)1800;
        i++;
    }
    return (0);
}