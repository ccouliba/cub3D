#include "../../includes/cub3D.h"
#include <math.h>

int	hit_wall(t_game *game, int i)
{
	t_mlx			*mlx;
	char			**map;
	int				direction;
	int				ret;

	map = game->config.map;
	mlx = &game->img;

	ret = 0;
	if ((int)mlx->ray.dy < game->config.map_size[0] && (int)mlx->ray.last_x - (int)mlx->ray.dx &&
		(int)mlx->ray.dx < ft_strlen(game->config.map[(int)mlx->ray.dy]))
	{
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1')
		{
			ret = 1;
			if (mlx->ray.dx > mlx->p_x && map[(int)mlx->ray.dy][(int)mlx->ray.dx - 1] != '1') /*west*/
				return (color_vline(mlx, i, distx(mlx), mlx->texs[2]), 1);
			if (mlx->ray.dx < mlx->p_x && map[(int)mlx->ray.dy][(int)mlx->ray.dx + 1] != '1') /*east*/
				return (color_vline(mlx, i, distx(mlx), mlx->texs[3]), 1);
		}
	}
	if ((int)mlx->ray.dy < game->config.map_size[0] && (int)mlx->ray.last_y - (int)mlx->ray.dy &&
		(int)mlx->ray.dx < ft_strlen(game->config.map[(int)mlx->ray.dy]))
	{
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1')
		{
			ret = 1;
			if (mlx->ray.dy > mlx->p_y && map[(int)mlx->ray.dy - 1][(int)mlx->ray.dx] != '1') /*north*/
				return (color_vline(mlx, i, disty(mlx), mlx->texs[0]), 1);
			if (mlx->ray.dy < mlx->p_y && map[(int)mlx->ray.dy + 1][(int)mlx->ray.dx] != '1') /*south*/
				return (color_vline(mlx, i, disty(mlx), mlx->texs[1]), 1);
		}
	}
	mlx->ray.last_y = mlx->ray.dy;
	mlx->ray.last_x = mlx->ray.dx;
	return (ret);
}



void	init_ray(t_mlx *mlx)
{
		mlx->ray.last_x = mlx->p_x;
		mlx->ray.last_y = mlx->p_y;
		mlx->ray.dx = mlx->p_x;
		mlx->ray.dy = mlx->p_y;
		mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle)) / PRECISION;
		mlx->ray.raySin = sin(deg2rad(mlx->ray.angle)) / PRECISION;
}

void	change_pos(t_game *game, t_mlx *mlx, double new_x, double new_y)
{
	if (game->config.map[(int)(new_y - WALL_GAP)][(int)new_x] != '1'
		&& game->config.map[(int)(new_y + WALL_GAP)][(int)new_x] != '1'
		&& game->config.map[(int)new_y][(int)(new_x - WALL_GAP)] != '1'
		&& game->config.map[(int)new_y][(int)(new_x + WALL_GAP)] != '1')
	{
		game->config.map[(int)mlx->p_y][(int)mlx->p_x] = '0';
		game->config.map[(int)new_y][(int)new_x] = 'P';
		mlx->p_y = new_y;
		mlx->p_x = new_x;
	}
}

void	move2(t_game *game, t_mlx *mlx, double new_x, double new_y)
{
	if (mlx->w)
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
	change_pos(game, mlx, new_x, new_y);
}

void	move(t_game *game)
{
	t_mlx	*mlx;
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

	else
		move2(game, mlx, new_x, new_y);
}

int	raycasting(t_game *game)
{
    int	i;
	t_mlx	*mlx;

	i = 0;
	mlx = &game->img;
	move(game);
	mlx->ray.angle = mlx->angle - HALF_FOV;
	color_line(mlx, 800, 100);
	dprintf(2, "==========================\n");
	while (i < WIDTH)
	{
		init_ray(mlx);
		while (!hit_wall(game, i))
			increment_ray(&mlx->ray);
		mlx->ray.angle += FOV / (double)WIDTH;
		if (mlx->ray.angle > 360)
			mlx->ray.angle -= 360;
		if (mlx->ray.angle < 0)
			mlx->ray.angle += 360;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
