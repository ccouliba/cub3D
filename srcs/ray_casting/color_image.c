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
	y = yIncrement = wall_h / mlx->tex_height;
	//dprintf(2, "y = %f, y mod = %d\n", y ,((int)y % (mlx->tex_height / 4)));
	while (j < HEIGHT / 2 + wall_h)
	{
		adr = (int *)(mlx->addr + (j * mlx->size_line + x * (mlx->bpp / 8)));
		*adr = ((int *)mlx->tex_img)[((int)y % (mlx->tex_height / 4)) * ((int)(mlx->ray.dx + mlx->ray.dy) % (mlx->tex_width / 4))];
		//dprintf(2, "y = %d, x = %d\n", (j % (mlx->tex_height / 4)), ((int)(mlx->ray.dx + mlx->ray.dy) % (mlx->tex_width / 4)));



		//printf(2, "y = %f, y mod = %d\n", y, ((int)y % (mlx->tex_height / 4)));
		//*adr = 1 << 23;
		j++;
		y += yIncrement;
		//dprintf(2, "*adr = %d\n", *adr);
	}
}
