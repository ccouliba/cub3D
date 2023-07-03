#include "../../includes/cub3D.h"

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
	int	*adr;
	int	j;
	int	wall_h;
	float y;
	float yIncrement;
	float texPosX;

	texPosX = (int)(mlx->tex_width * (mlx->ray.dx + mlx->ray.dy)) % mlx->tex_width;
	if (distance < 1)
	{
		wall_h = HEIGHT / 2;
		j = 0;
	}
	else
	{
		wall_h = HEIGHT / 2 / distance;
		j = HEIGHT / 2 - wall_h;
	}
	y = yIncrement = (float)wall_h * 2 / (float)mlx->tex_height;
	while (j < HEIGHT / 2 + wall_h)
	{
		adr = (int *)(mlx->addr + (j * mlx->size_line + x * (mlx->bpp / 8)));
		//dprintf(2, "y = %f\n", y);
		dprintf(2, "y = %f\n", y);
		dprintf(2, "texPosX = %d, size_line = %d\n", (int)texPosX, mlx->tex_size_line);
		dprintf(2, "bpp = %d\n", mlx->tex_bpp);
		*adr = (int *)(mlx->tex_data) + (int)(y * mlx->tex_size_line) + (int)texPosX;
		j++;
		y += yIncrement;
	}
}
		//*adr = mlx_get_color_value(mlx->mlx, ((int *)mlx->tex_data)[((int)y % (mlx->tex_height / 4)) * ((int)(mlx->ray.dx * mlx->ray.dy) % (mlx->tex_width / 4))]);
		//*adr = 1 << 23;
		//*adr = mlx_get_color_value(mlx->mlx, ((int *)mlx->tex_data)[((int)y % mlx->tex_height) * mlx->tex_width + ((int)(mlx->ray.dx + mlx->ray.dy) % mlx->tex_width)]);
