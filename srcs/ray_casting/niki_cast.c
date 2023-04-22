#include "../../includes/cub3D.h"

//INITIALISER TOUT AVANT SEND_RAYS

int	hit_wall(t_game *game, int i)
{
	t_mlx	*mlx;
	char	**map;

	map = game->config.map;
	mlx = &game->img;

	dprintf(2, "---------------------------\n");
	dprintf(2, "x = %f, y = %f\n", mlx->ray.dx, mlx->ray.dy);
	if ((int)(mlx->p_y - (int)mlx->ray.dy))
	{
		dprintf(2, " map[%d][%d] = %c\n", (int)mlx->ray.dy, (int)mlx->ray.dx, map[(int)mlx->ray.dy][(int)mlx->ray.dx]);
		dprintf(2, "+map[%d][%d] = %c\n", (int)mlx->ray.dy, (int)mlx->ray.dx + 1, map[(int)mlx->ray.dy][(int)mlx->ray.dx + 1]);
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1' &&
			map[(int)mlx->ray.dy][(int)mlx->ray.dx + 1] == '1')
			return (color_vline(mlx, i, disty(*mlx)), 1);
	}
	if ((int)(mlx->p_x - (int)mlx->ray.dx))
	{
		dprintf(2, " map[%d][%d] = %c\n", (int)mlx->ray.dy, (int)mlx->ray.dx, map[(int)mlx->ray.dy][(int)mlx->ray.dx]);
		dprintf(2, "+map[%d][%d] = %c\n", (int)mlx->ray.dy + 1, (int)mlx->ray.dx, map[(int)mlx->ray.dy + 1][(int)mlx->ray.dx]);
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1' &&
			map[(int)mlx->ray.dy + 1][(int)mlx->ray.dx] == '1')
			return (color_vline(mlx, i, distx(*mlx)), 1);
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
	mlx->p_x = game->config.pos[1];
	mlx->p_y = game->config.pos[0];
	printf("map size1 = %d\n", game->config.map_size[1]);
	printf("map size0 = %d\n", game->config.map_size[0]);
	printf("GAME_addr = %p\n", game->img.addr);
	init_ray(mlx);
	dprintf(2, "posx = %f. posy = %f\n", mlx->p_x, mlx->p_y);
	while (i < WIDTH)
	{
		mlx->ray.dx = mlx->p_x;
		mlx->ray.dy = mlx->p_y;
		mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle) / 64);
		mlx->ray.raySin = sin(deg2rad(mlx->ray.angle) / 64);
		while (!hit_wall(game, i))
			increment_ray(&mlx->ray);
		if (i % 50 == 0)
			dprintf(1, "dx = %d\ndy = %f\n", (int)mlx->ray.dx, mlx->ray.dy);
		mlx->ray.angle += 100 / (double)WIDTH;
		i++;
	}
	return (0);
}
