#include "../../includes/cub3D.h"
#include <math.h>

//INITIALISER TOUT AVANT SEND_RAYS

int	hit_wall(t_game *game, int i)
{
	t_mlx	*mlx;
	char	**map;

	map = game->config.map;
	mlx = &game->img;
	//if (i % 50 == 0)
	//	dprintf(2, "i = %d\n", i);
	//dprintf(2, "---------------------------\n");
	//dprintf(2, "x = %f, y = %f\n", mlx->ray.dx, mlx->ray.dy);
	if ((int)floor(mlx->ray.dy) < game->config.map_size[0] && (int)floor(mlx->ray.last_y) - (int)floor(mlx->ray.dy) &&
		(int)floor(mlx->ray.dx) < ft_strlen(game->config.map[(int)floor(mlx->ray.dy)]))
	{
		//dprintf(2, "Last_y = %d, d_y = %d\n", (int)last_y, (int)mlx->ray.dy);
		mlx->ray.last_y = mlx->ray.dy;
		if (map[(int)floor(mlx->ray.dy)][(int)floor(mlx->ray.dx)] == '1')
		{
			//if (i % 25 == 0)
			//	dprintf(2, " map[%d][%d] = %c\n", (int)mlx->ray.dy, (int)mlx->ray.dx, map[(int)mlx->ray.dy][(int)mlx->ray.dx]);		
			return (color_vline(mlx, i, disty(*mlx)), 1);
		}
	}
	if ((int)floor(mlx->ray.dy) < game->config.map_size[0] && (int)floor(mlx->ray.last_x) - (int)floor(mlx->ray.dx) &&
		(int)floor(mlx->ray.dx) < ft_strlen(game->config.map[(int)floor(mlx->ray.dy)]))
	{
		//dprintf(2, "Last_x = %d, d_x = %d\n", (int)last_x, (int)mlx->ray.dx);
		mlx->ray.last_x = mlx->ray.dx;
		if (map[(int)floor(mlx->ray.dy)][(int)floor(mlx->ray.dx)] == '1')
		{
			//if (i % 25 == 0)
			//	dprintf(2, " map[%d][%d] = %c\n", (int)mlx->ray.dy, (int)mlx->ray.dx, map[(int)mlx->ray.dy][(int)mlx->ray.dx]);		
			return (color_vline(mlx, i, distx(*mlx)), 1);
		}
	}
	return (0);
}

void	init_ray(t_mlx *mlx)
{
	mlx->ray.angle = mlx->angle - 30;
}

int	raycasting(t_game *game)
{
	static int j = 0;
    int	i;
	t_mlx	*mlx;
	i = 0;

	mlx = &game->img;
	if (j % 200 == 0)
	{
		dprintf(2, "p_x = %f\n", (double)mlx->p_x);
		dprintf(2, "p_y = %f\n", (double)mlx->p_y);
	}
	j++;
	init_ray(mlx);
	color_line(mlx, 800, 100);
	while (i < WIDTH)
	{
		mlx->ray.last_x = mlx->p_x;
		mlx->ray.last_y = mlx->p_y;
		mlx->ray.dx = mlx->p_x;
		mlx->ray.dy = mlx->p_y;
		mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle)) / 256;
		mlx->ray.raySin = sin(deg2rad(mlx->ray.angle)) / 256;
		while (!hit_wall(game, i))
			increment_ray(&mlx->ray);
		//if (i % 100 == 0)
		//	dprintf(2, "dx = %f\ndy = %f\n", mlx->ray.dx, mlx->ray.dy);
		mlx->ray.angle += 60 / (double)WIDTH;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}