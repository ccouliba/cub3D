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

	//dprintf(2, "Distance = %f\n", distance);
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
	//printf("HEIGHT/2 = %d, distance = %f\n", HEIGHT / 2, distance);
	//printf("wall_h = %d\nj = %d\n", wall_h, HEIGHT / 2 - wall_h);
	//dprintf(2, "min = %p, max = %p\n", mlx->addr, mlx->addr + (WIDTH * mlx->size_line + HEIGHT * (mlx->bpp / 8)));
	//dprintf(2, "adr = %p\n", mlx->addr + (j * mlx->size_line + x * (mlx->bpp / 8)));
	while (j < HEIGHT / 2 + wall_h)
	{
		//printf("%d %d\n", x, j);
		//fflush(stdout);
		//printf("addr = %p\n", mlx->addr);
		//printf("j.. * ..x = %d\n", (j * mlx->size_line + x * (mlx->bpp / 8)));
		adr = (int *)(mlx->addr + (j * mlx->size_line + x * (mlx->bpp / 8)));
		*adr = 1 << 23;
		j++;
	}
}