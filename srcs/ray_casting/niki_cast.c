#include "../../includes/cub3D.h"

//INITIALISER TOUT AVANT SEND_RAYS

void	init_ray(t_mlx *mlx)
{
	mlx->ray.angle = mlx->angle - 50; 
}

int	raycasting(t_mlx *mlx)
{
    int	i;

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
		if (i % 50 == 0)
		{
			printf("dx = %f\ndy = %f\n", mlx->ray.dx, mlx->ray.dy);
			printf("angle = %f, i = %d ---- distance2 = %f\n", mlx->ray.angle, i, distance(*mlx));
		}
		mlx->ray.angle += 100 / (double)WIDTH;
		i++;
	}
	return (0);
}
