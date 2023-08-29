#include "../../headers/cub3d.h"

void    color_line(t_mlx *mlx, int y, int distance)
{
	int	*adr;
	int	i;
	int j;

	(void)distance;
	(void)y;
	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		while (i < WIDTH)
		{
			adr = (int *)(mlx->addr + (j * mlx->size_line + i * (mlx->bpp / 8)));
			if (j < HEIGHT / 2)
				*adr = 1 << 7 | 1 << 14;
			else
				*adr = 1 << 14;
			i++;
		}
		i = 0;
		j++;
	}
}

void	color_vline(t_mlx *mlx, int x, double distance)
{
	int		*adr;
	int		j;
	float	wall_h;
	float	y;
	float	yIncrement;
	float	texPosX;
 
	texPosX = (int)((mlx->tex.width * (mlx->ray.dx + mlx->ray.dy))) % mlx->tex.width;
	wall_h = HALF_HEIGHT / distance;
	j = HALF_HEIGHT - wall_h;
	yIncrement = mlx->tex.height / (wall_h * 2);
	y = 0;
	if (j < 0)
	{
		j = 0;
		y = (mlx->tex.height - (mlx->tex.height * HEIGHT) / (2 * wall_h)) / 2;
		yIncrement = (mlx->tex.height * (HEIGHT / ((2 * wall_h)))) / HEIGHT;
	}
	while (j < HEIGHT && j < HALF_HEIGHT + wall_h)
	{
		adr = (int *)(mlx->addr + (j * mlx->size_line + x * (mlx->bpp / 8)));
		*adr = *((int *)mlx->tex_data + (int)(((int)y * (mlx->tex_size_line / (mlx->tex_bpp / 8)) + (int)texPosX)));
		j++;
		y += yIncrement;
	}
}