#include "../../includes/cub3D.h"
#include <math.h>

//INITIALISER TOUT AVANT SEND_RAYS

int	hit_wall(t_game *game, int i)
{
	t_mlx	*mlx;
	char	**map;

	map = game->config.map;
	mlx = &game->img;
	if ((int)mlx->ray.dy < game->config.map_size[0] && (int)mlx->ray.last_y - (int)mlx->ray.dy &&
		(int)mlx->ray.dx < ft_strlen(game->config.map[(int)mlx->ray.dy]))
	{
		mlx->ray.last_y = mlx->ray.dy;
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1')
			return (color_vline(mlx, i, disty(*mlx)), 1);
	}
	if ((int)mlx->ray.dy < game->config.map_size[0] && (int)mlx->ray.last_x - (int)mlx->ray.dx &&
		(int)mlx->ray.dx < ft_strlen(game->config.map[(int)mlx->ray.dy]))
	{
		mlx->ray.last_x = mlx->ray.dx;
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1')
			return (color_vline(mlx, i, distx(*mlx)), 1);
	}
	return (0);
}

void	init_ray(t_mlx *mlx)
{
	mlx->ray.angle = mlx->angle - 40;
}

void	move(t_game *game)
{
	t_mlx *mlx;
	double	new_x;
	double	new_y;

	mlx = &game->img;
	new_x = mlx->p_x;
	new_y = mlx->p_y;
	if (mlx->l)
	{
		mlx->angle -= ROT_SP;
		return ;
	}
	else if (mlx->r)
	{
		mlx->angle += ROT_SP;
		return ;
	}	
	else if (mlx->w)
	{
		new_x = mlx->p_x + cos(deg2rad(mlx->angle)) / RUN_SP;
		new_y = mlx->p_y + sin(deg2rad(mlx->angle)) / RUN_SP;
	}
	else if (mlx->s)
	{
		new_x = mlx->p_x - cos(deg2rad(mlx->angle)) / RUN_SP;
		new_y = mlx->p_y - sin(deg2rad(mlx->angle)) / RUN_SP;
	}
	else if (mlx->a)
	{
		new_x = mlx->p_x + cos(deg2rad(mlx->angle - 90)) / SIDE_SP;
		new_y = mlx->p_y + sin(deg2rad(mlx->angle - 90)) / SIDE_SP;
	}
	else if (mlx->d)
	{
		new_x = mlx->p_x + cos(deg2rad(mlx->angle + 90)) / SIDE_SP;
		new_y = mlx->p_y + sin(deg2rad(mlx->angle + 90)) / SIDE_SP;
	}
	if ((int)floor(new_y) < game->config.map_size[0]
		&& (int)floor(new_x) < ft_strlen(game->config.map[(int)floor(new_y)])
		&& game->config.map[(int)floor(new_y)][(int)floor(new_x)] != '1')
	{
		mlx->p_x = new_x;
		mlx->p_y = new_y;
	}
}

int	raycasting(t_game *game)
{
	static int j = 0;
    int	i;
	t_mlx	*mlx;
	i = 0;

	mlx = &game->img;
	move(game);
	//if (j % 200 == 0)
	//{
	//	dprintf(2, "p_x = %f\n", (double)mlx->p_x);
	//	dprintf(2, "p_y = %f\n", (double)mlx->p_y);
	//}
	j++;
	init_ray(mlx);
	color_line(mlx, 800, 100);
	while (i < WIDTH)
	{
		mlx->ray.last_x = mlx->p_x;
		mlx->ray.last_y = mlx->p_y;
		mlx->ray.dx = mlx->p_x;
		mlx->ray.dy = mlx->p_y;
		mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle)) / 64;
		mlx->ray.raySin = sin(deg2rad(mlx->ray.angle)) / 64;
		while (!hit_wall(game, i))
			increment_ray(&mlx->ray);
		//if (i % 100 == 0)
		//	dprintf(2, "dx = %f\ndy = %f\n", mlx->ray.dx, mlx->ray.dy);
		mlx->ray.angle += 80 / (double)WIDTH;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
