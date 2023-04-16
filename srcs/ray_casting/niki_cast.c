#include "../../includes/cub3D.h"

//INITIALISER TOUT AVANT SEND_RAYS

int	hit_wall(t_game *game, int i)
{
	t_mlx	*mlx;
	char	**map;

	map = game->config.map;
	mlx = &game->img;
	printf("diffy = %d\n", (int)(mlx->p_y - (int)mlx->ray.dy));
	printf("diffx = %d\n", (int)(mlx->p_x - (int)mlx->ray.dx));
	if ((int)(mlx->p_y - (int)mlx->ray.dy))
		if (map[(int)mlx->ray.dx][(int)mlx->ray.dy] == 1 &&
			map[(int)mlx->ray.dx + 1][(int)mlx->ray.dy] == 1)
		{
			color_vline(mlx, i, disty(*mlx));
			return (1);
		}
	if ((int)(mlx->p_x - (int)mlx->ray.dx))
	{
		printf("mlx->ray.dx = %d, mlx->ray.y = %d\n", (int)mlx->ray.dx, (int)mlx->ray.dy);
		if (map[(int)mlx->ray.dx][(int)mlx->ray.dy] == 1 &&
			map[(int)mlx->ray.dx][(int)mlx->ray.dy + 1] == 1)
		{
			color_vline(mlx, i, distx(*mlx));
			return (1);
		}
	}	
	return (0);
}

void	init_ray(t_mlx *mlx)
{
	mlx->ray.angle = mlx->angle - 50; 
}

int	raycasting(t_game *game)
{
    int	i;
	t_mlx	*mlx;
	i = 0;

	mlx = &game->img;
	init_ray(mlx);
	while (i < WIDTH)
	{
		mlx->ray.dx = mlx->pos[0];
		mlx->ray.dy = mlx->pos[1];
		mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle) / 64);
		mlx->ray.raySin = sin(deg2rad(mlx->ray.angle) / 64);
		while (!hit_wall(game, i))
			increment_ray(&mlx->ray);
		if (i % 50 == 0)
			printf("dx = %d\ndy = %f\n", (int)mlx->ray.dx, mlx->ray.dy);
		mlx->ray.angle += 100 / (double)WIDTH;
		i++;
	}
	return (0);
}
