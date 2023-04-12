#include "../../includes/cub3D.h"

void    color_line(t_mlx *mlx, int x, int y, int distance)
{
	int	*adr;
	int	i;
	int	j;

	(void)y;
	(void)x;
	(void)distance;
	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			adr = (int *)(mlx->addr + (j * mlx->size_line + i * (mlx->bpp / 8)));
			*adr = 1 << 15;
			j++;
		}
		i++;
    }
}
