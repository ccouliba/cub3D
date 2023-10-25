/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:08:17 by ngenadie          #+#    #+#             */
/*   Updated: 2023/10/25 21:40:56 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	color_line(t_mlx *mlx, int y, int distance)
{
	int	*adr;
	int	i;
	int	j;

	(void)distance;
	(void)y;
	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		while (i < WIDTH)
		{
			adr = (int *)(mlx->addr + (j
						* mlx->size_line + i * (mlx->bpp / 8)));
			if (j < HEIGHT / 2)
				*adr = mlx->floor;
			else
				*adr = mlx->ceiling;
			i++;
		}
		i = 0;
		j++;
	}
}

void	color_vline(t_mlx *mlx, int x, double distance, t_tex tex)
{
	int		*adr;
	int		j;
	float	wall_h;
	float	y;
	float	yincrement;

	tex.texposx = (int)((tex.width * (mlx->ray.dx + mlx->ray.dy))) % tex.width;
	wall_h = HALF_HEIGHT / distance;
	j = HALF_HEIGHT - wall_h;
	yincrement = tex.height / (wall_h * 2);
	y = 0;
	if (j < 0)
	{
		j = 0;
		y = (tex.height - (tex.height * HEIGHT) / (2 * wall_h)) / 2;
		yincrement = (tex.height * (HEIGHT / ((2 * wall_h)))) / HEIGHT;
	}
	while (j < HEIGHT && j < HALF_HEIGHT + wall_h - 2)
	{
		adr = (int *)(mlx->addr + (j * mlx->size_line + x * (mlx->bpp / 8)));
		*adr = *((int *)tex.data + (int)(((int)y
						* (tex.size_line / (tex.bpp / 8)) + (int)tex.texposx)));
		j++;
		y += yincrement;
	}
}
