/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:43:44 by ccouliba          #+#    #+#             */
/*   Updated: 2023/04/13 18:24:58 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// void	init_mlx(t_mlx *img)
// {
// 	img->bpp = 0;
// 	img->size_line = 0;
// 	img->endian = 0;
// 	img->re_buf = 0;
// 	img->addr = 0;
// 	img->mlx = 0;
// 	img->win = 0;
// 	img->img = 0;
// }

// void	init_param(t_param *param, int *position)
// {
// 	param->hit = 0;
// 	param->side = 0;
// 	// param->texture
// 	param->text_num = 0;
// 	param->line_height = 0;
// 	param->map[0] = 0;
// 	param->map[1] = 0;
// 	param->text[0] = 0;
// 	param->text[1] = 0;
// 	param->step[0] = 0;
// 	param->step[1] = 0;
// 	param->draw[0] = 0;
// 	param->draw[1] = 0;

// 	param->pos[0] = (double)position[0];
// 	param->pos[1] = (double)position[1];
// 	param->dir_x = 0;
// 	param->dir_y = 0;
// 	param->plane_x = 0;
// 	param->plane_y = 0.66;
// 	param->move_speed = 0;
// 	param->rot_speed = 0;
// 	// param->texture[4];

// 	param->cam = 0.0;
// 	param->	wall = 0.0;
// 	param->perp_wall_dist = 0.0;
// 	param->delta[0] = 0.0;
// 	param->delta[1] = 0.0;
// 	param->raydir[0] = 0.0;
// 	param->raydir[1] = 0.0;
// 	param->side_dist[0] = 0.0;
// 	param->side_dist[1] = 0.0;
// }

// void	putpixel(t_mlx *img, int x, int y, int color)
// {
// 	void	*dst;

// 	dst = (int *)(img->addr + (y * img->size_line + x * (img->bpp / 8)));
// 	*(unsigned int *)dst = color;
// }

// void	color_pixel(t_mlx *img, int *p)
// {
// 	int	i;
// 	int	j;

// 	(void)p;
// 	i = 0;
// 	j = 0;
// 	while (i < WIDTH)
// 	{
// 		j = 0;
// 		while (j < HEIGHT)
// 		{
// 			putpixel(img, i, j, 1 << 15);
// 			++j;
// 		}
// 		++i;
// 	}
// }

void    color_pixel(t_mlx *mlx, int *distance)
{
	char *adr;
	int	i;
	int	j;

	// (void)y;
	// (void)x;
	(void)distance;
	i = 0;
	j = 0;
	adr = malloc(sizeof(unsigned int ));
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			adr = (int *)(mlx->addr + (j * mlx->size_line + i * (mlx->bpp / 8)));
			if (!*adr)
				return ;
			*adr = 1 << 15;
			j++;
		}
		i++;
    }
}
