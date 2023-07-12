#include "../../includes/cub3D.h"
#include <math.h>

//INITIALISER TOUT AVANT SEND_RAYS

int	hit_wall(t_game *game, int i)
{
	t_mlx			*mlx;
	char			**map;

	map = game->config.map;
	mlx = &game->img;
	if ((int)mlx->ray.dy < game->config.map_size[0] && (int)mlx->ray.last_y - (int)mlx->ray.dy &&
		(int)mlx->ray.dx < ft_strlen(game->config.map[(int)mlx->ray.dy]))
	{
		mlx->ray.last_y = mlx->ray.dy;
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1')
		{

			return (color_vline(mlx, i, disty(mlx)), 1);
		}
	}
	if ((int)mlx->ray.dy < game->config.map_size[0] && (int)mlx->ray.last_x - (int)mlx->ray.dx &&
		(int)mlx->ray.dx < ft_strlen(game->config.map[(int)mlx->ray.dy]))
	{
		mlx->ray.last_x = mlx->ray.dx;
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1')
		{
			return (color_vline(mlx, i, distx(mlx)), 1);
		}
	}
	return (0);
}

void	init_ray(t_mlx *mlx)
{
	mlx->ray.angle = mlx->angle - HALF_FOV;
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
//	dprintf(2, "new_y = %f\n", new_y - WALL_GAP);
//	dprintf(2, "new_x = %f\n", new_x - WALL_GAP);
//	dprintf(2, "1 = %d, 2 = %d, 3 = %d, 4 = %d, 5 = %d\n", new_y + WALL_GAP < game->config.map_size[0],
		new_y - WALL_GAP > 1, new_x + WALL_GAP < ft_strlen(game->config.map[(int)new_y]),
		new_x - WALL_GAP > 1, game->config.map[(int)new_y][(int)new_x] != '1');
	if (new_y + WALL_GAP < game->config.map_size[0]
		&& new_y - WALL_GAP > 1
		&& new_x + WALL_GAP < ft_strlen(game->config.map[(int)new_y])
		&& new_x - WALL_GAP > 1
		&& game->config.map[(int)new_y][(int)new_x] != '1')
	{
		mlx->p_x = new_x;
		mlx->p_y = new_y;
	}
}

bool can_move(float x, float y)
{

}

int	raycasting(t_game *game)
{
    int	i;
	t_mlx	*mlx;

	i = 0;
	mlx = &game->img;
	move(game);
	init_ray(mlx);
	color_line(mlx, 800, 100);
	dprintf(2, "==========================\n");
	while (i < WIDTH)
	{
		mlx->ray.last_x = mlx->p_x;
		mlx->ray.last_y = mlx->p_y;
		mlx->ray.dx = mlx->p_x;
		mlx->ray.dy = mlx->p_y;
		mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle)) / PRECISION;
		mlx->ray.raySin = sin(deg2rad(mlx->ray.angle)) / PRECISION;
		while (!hit_wall(game, i))
			increment_ray(&mlx->ray);
		//if (i % 100 == 0)
		//	dprintf(2, "dx = %f\ndy = %f\n", mlx->ray.dx, mlx->ray.dy);
		mlx->ray.angle += FOV / (double)WIDTH;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
