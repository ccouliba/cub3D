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
	float diff;
	float y;
	float yIncrement;
	float texPosX;
 
	texPosX = (int)((mlx->tex_width * (mlx->ray.dx + mlx->ray.dy))) % mlx->tex_width;
	wall_h = HALF_HEIGHT / distance;
	j = HALF_HEIGHT - wall_h;
	yIncrement = (wall_h);
	y = 0;
	if (j < 0)
	{
		j = 0;
		if (wall_h > HEIGHT)
		{
			dprintf(2, "HEIGHT = %d, wall_h = %d\n", HEIGHT, wall_h);
			diff = HEIGHT / (float)wall_h;
			dprintf(2, "diff = HEIGHT / wall_h = %f\n", diff);
			y = mlx->tex_height * (diff / 2);
			dprintf(2, "y = %d\n", y);
		}
		//y = diff * mlx->tex_height;
		//yIncrement = z
		//y = 
	}
	while (j < HEIGHT && j < HEIGHT / 2 + wall_h)
	{
		adr = (int *)(mlx->addr + (j * mlx->size_line + x * (mlx->bpp / 8)));
		*adr = *((int *)mlx->tex_data + (int)(((int)y * (mlx->tex_size_line / (mlx->tex_bpp / 8)) + (int)texPosX)));
		j++;
		y += yIncrement;
	}
} 
	// yIncrement = (float)(wall_h * 2) / mlx->tex_height;
		// dprintf(2, "y = %f\n", y);
		// y = (int)y % mlx->tex_height;
		//*adr = 1 << 23;
		//dprintf(2, "y = %d, x = %d|", (int)y, (int)texPosX);
		//dprintf(2, "y = %d, x = %d\n", y, texPosX);
		//*adr = (int *)(mlx->tex_data) + ((int)(y * mlx->tex_size_line) + (int)texPosX / mlx->tex_bpp);
		//*adr = 1 << 23;
//	dprintf(2, "yIncrement = %f\n", yIncrement);
	//dprintf(2, "\n-------------------------------------------------------\n");
	//dprintf(2, "size_line / bpp = %d\n", mlx->tex_size_line / mlx->tex_bpp);
	//dprintf(2, "wall_h * 2 = %d, yIncrement = %f\n", wall_h * 2, yIncrement);
