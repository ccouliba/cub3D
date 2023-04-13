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

void	color_vline(t_mlx *mlx, int x, int distance)
{
	int	*adr;
	int	j;

	(void)distance;
	j = 0;
	while (j < HEIGHT)
	{
		adr = (int *)(mlx->addr + (j * mlx->size_line + x * (mlx->bpp / 8)));
		*adr = 1 << 15;
		j++;
	}
}
