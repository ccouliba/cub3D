#include "../../includes/cub3D.h"

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
        printf("----------------------------------\n");
        printf("Ray_number: %d\n", i);
        printf("raycos: %f\n", mlx->ray.rayCos);
        printf("raysin: %f\n", mlx->ray.raySin);
        printf("angle: %f\n\n", mlx->ray.angle);
        //if (check_wall(mlx.ray))
        //{
        //    draw_line(i, distance(mlx));
        //}make
        for (int j = 0; j < 100; j++)
        {
            increment_ray(&mlx->ray);
            printf("ray_x = %f\n", mlx->ray.dx);
            printf("ray_y = %f\n", mlx->ray.dy);
        }
        printf("angle: %f\n", mlx->ray.angle);
        mlx->ray.angle += 60 / (double)1800;
        printf("angle: %f\n", mlx->ray.angle);
        i++;
    }
    return (0);
}