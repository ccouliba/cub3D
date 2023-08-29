#include "../../headers/cub3d.h"

//INITIALISER TOUT AVANT SEND_RAYS

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int	hit_wall(t_data *data, int i)
{
	t_mlx			*mlx;
	char			**map;

	map = data->config.map;
	mlx = &data->mlx;
	/*printf("mlx->ray.dy %f\n", mlx->ray.dy);
	printf("mlx->ray.dx %f\n", mlx->ray.dx);
	printf("data->config.map[(int)mlx->ray.dy] %s\n", data->config.map[(int)mlx->ray.dy]);
	printf("mlx->ray.last_y %f\n", mlx->ray.last_y);
//	exit(0);*/
	if ((int)mlx->ray.dy < data->config.map_size.x && (int)mlx->ray.last_y - (int)mlx->ray.dy &&
		(int)mlx->ray.dx < ft_strlen(data->config.map[(int)mlx->ray.dy]))
	{
		mlx->ray.last_y = mlx->ray.dy;
		if (map[(int)mlx->ray.dy][(int)mlx->ray.dx] == '1')
		{

			return (color_vline(mlx, i, disty(mlx)), 1);
		}
	}
	if ((int)mlx->ray.dy < data->config.map_size.x && (int)mlx->ray.last_x - (int)mlx->ray.dx &&
		(int)mlx->ray.dx < ft_strlen(data->config.map[(int)mlx->ray.dy]))
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

void	move(t_data *data)
{
	t_mlx	*mlx;
	double	new_x;
	double	new_y;

	mlx = &data->mlx;
	new_x = mlx->p.x;
	new_y = mlx->p.y;
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
		new_x = mlx->p.x + cos(deg2rad(mlx->angle)) / RUN_SP;
		new_y = mlx->p.y + sin(deg2rad(mlx->angle)) / RUN_SP;
	}
	else if (mlx->s)
	{
		new_x = mlx->p.x - cos(deg2rad(mlx->angle)) / RUN_SP;
		new_y = mlx->p.y - sin(deg2rad(mlx->angle)) / RUN_SP;
	}
	else if (mlx->a)
	{
		new_x = mlx->p.x + cos(deg2rad(mlx->angle - 90)) / SIDE_SP;
		new_y = mlx->p.y + sin(deg2rad(mlx->angle - 90)) / SIDE_SP;
	}
	else if (mlx->d)
	{
		new_x = mlx->p.x + cos(deg2rad(mlx->angle + 90)) / SIDE_SP;
		new_y = mlx->p.y + sin(deg2rad(mlx->angle + 90)) / SIDE_SP;
	}
	if (data->config.map[(int)(new_y - WALL_GAP)][(int)new_x] != '1'
		&& data->config.map[(int)(new_y + WALL_GAP)][(int)new_x] != '1'
		&& data->config.map[(int)new_y][(int)(new_x - WALL_GAP)] != '1'
		&& data->config.map[(int)new_y][(int)(new_x + WALL_GAP)] != '1'
		&& data->config.map[(int)new_y][(int)new_x] != '1')
	{
		mlx->p.x = new_x;
		mlx->p.y = new_y;
	}
}

int	raycasting(t_data *data)
{
    int	i;
	t_mlx	*mlx;

	i = 0;
	mlx = &data->mlx;
	move(data);
	init_ray(mlx);
	color_line(mlx, 800, 100);
	while (i < WIDTH)
	{
		mlx->ray.last_x = mlx->p.x;
		mlx->ray.last_y = mlx->p.y;
		mlx->ray.dx = mlx->p.x;
		mlx->ray.dy = mlx->p.y;
		mlx->ray.rayCos = cos(deg2rad(mlx->ray.angle)) / PRECISION;
		mlx->ray.raySin = sin(deg2rad(mlx->ray.angle)) / PRECISION;
		while (!hit_wall(data, i))
			increment_ray(&mlx->ray);
		mlx->ray.angle += FOV / (double)WIDTH;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}