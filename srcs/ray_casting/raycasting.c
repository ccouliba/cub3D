/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:43:44 by ccouliba          #+#    #+#             */
/*   Updated: 2023/04/02 19:12:52 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_mlx(t_mlx *img)
{
	img->angle = -30;
	img->pos[0] = 0;
	img->pos[1] = 0;
	img->dir_x = 0;
	img->dir_y = 0;
	img->plane_x = 0;
	img->plane_y = 0;
	img->move_speed = 0;
	img->rot_speed = 0;
	img->bpp = 0;
	img->size_line = 0;
	img->endian = 0;
	// img->texture[4];
	img->re_buf = 0;
	img->addr = 0;
	img->mlx = 0;
	img->win = 0;
	img->img = 0;
}

void	init_param(t_param *param)
{
	param->hit = 0;
	param->side = 0;
	param->color = 0;
	// param->texture
	// param->text_num = 0;
	param->line_height = 0;
	param->map[0] = 0;
	param->map[1] = 0;
	param->text[0] = 0;
	param->text[1] = 0;
	param->step[0] = 0;
	param->step[1] = 0;
	param->draw[0] = 0;
	param->draw[1] = 0;
	param->cam = 0.0;
	param->	wall = 0.0;
	param->perp_wall_dist = 0.0;
	param->delta[0] = 0.0;
	param->delta[1] = 0.0;
	param->raydir[0] = 0.0;
	param->raydir[1] = 0.0;
	param->side_dist[0] = 0.0;
	param->side_dist[1] = 0.0;
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	void	*dst;

	dst = (int *)(data->addr + (y * data->size_line + x * (data->bpp / 8)));
	*(unsigned int *)dst = color;
}

// static void	drawer(t_mlx *img)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			img->addr[y * WIDTH + x] = img->buf[y][x];
// 			++x;
// 		}
// 		++y;
// 	}
// 	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
// }

static void	init_buffer(t_mlx *img)
{
	int	i;
	int	j;

	i = 0;
	if (img->re_buf == 1)
	{
		while (i < HEIGHT)
		{
			j = 0;
			while (j < WIDTH)
			{
				img->buf[i][j] = 0;
				++j;
			}
			++i;
		}
		img->re_buf = 0;
	}
}

static void	ray_direction(t_game *game, int x)
{
	t_mlx	img;
	t_param	param;

	img = game->img;
	param = game->param;
	param.cam = 2 * x / (double)WIDTH - 1;
	param.raydir[0] = img.dir_x + img.plane_x * param.cam;
	param.raydir[1] = img.dir_y + img.plane_y * param.cam;
}

static void	initial_position(t_game *game)
{
	t_mlx	img;
	t_param	param;

	img = game->img;
	param = game->param;
	param.map[0] = img.pos[0];
	param.map[1] = img.pos[1];
}

static void	get_step(t_game *game)
{
	t_mlx	img;
	t_param	param;

	img = game->img;
	param = game->param;
	param.delta[0] = sqrt(1 + (param.raydir[1] * param.raydir[1])
			/ (param.raydir[0] * param.raydir[0]));
	param.delta[1] = sqrt(1 + (param.raydir[0] * param.raydir[0])
			/ (param.raydir[1] * param.raydir[1]));
	if (param.raydir[0] < 0)
	{
		param.step[0] = -1;
		param.side_dist[0] = (img.pos[0] - param.map[0]) * param.delta[0];
	}
	else
	{
		param.step[0] = 1;
		param.side_dist[0] = (param.map[0] + 1.0 - img.pos[0]) * param.delta[0];
	}
	if (param.raydir[1] < 0)
	{
		param.step[1] = -1;
		param.side_dist[1] = (img.pos[1] - param.map[1]) * param.delta[1];
	}
	else
	{
		param.step[1] = 1;
		param.side_dist[1] = (param.map[1] + 1.0 - img.pos[1]) * param.delta[1];
	}
}

static void	handle_hits(t_game *game)
{
	t_mlx		img;
	t_param		param;

	img = game->img;
	param = game->param;
	param.hit = 0;
	// param.side = 0;
	while (param.hit == 0)
	{
		if (param.side_dist[0] < param.side_dist[1])
		{
			param.side_dist[0] += param.delta[0];
			param.map[0] += param.step[0];
			param.side = 0;
		}
		else
		{
			param.side_dist[1] += param.delta[1];
			param.map[1] += param.step[1];
			param.side = 1;
		}
		if (game->config.map[param.map[0]][param.map[1]] > 0)
			param.hit = 1;
	}
}

static void	dist_n_height(t_game *game)
{
	t_mlx		img;
	t_param		param;

	img = game->img;
	param = game->param;
	param.line_height = (int)(HEIGHT / param.perp_wall_dist);
	param.draw[0] = -param.line_height / 2 + HEIGHT / 2;
	param.draw[1] = param.line_height / 2 + HEIGHT / 2;
	if (param.side == 0)
		param.perp_wall_dist = (param.map[0] - img.pos[0]
				+ (1 - param.step[0]) / 2) / param.raydir[0];
	else
		param.perp_wall_dist = (param.map[1] - img.pos[1]
				+ (1 - param.step[1]) / 2) / param.raydir[1];
	if (param.draw[0] < 0)
		param.draw[0] = 0;
	if (param.draw[1] >= HEIGHT)
		param.draw[1] = HEIGHT - 1;
	// param.text_num = game.config->map[param.map[0]][param.map[1]];

	if (param.side == 0)
		param.wall = img.pos[1] + param.perp_wall_dist * param.raydir[1];
	else
		param.wall = img.pos[0] + param.perp_wall_dist * param.raydir[0];
	param.wall -= floor(param.wall);

	// param.text[0] = (int)(param.wall * (double)TEXT_WIDTH);

	// if (param.side == 0 && param.raydir[0] > 0)
	// 	param.text[0] = TEXT_WIDTH - param.text[0] - 1;
	// if (param.side == 1 && param.raydir[1] < 0)
	// 	param.text[0] = TEXT_WIDTH - param.text[0] - 1;
}

/*
** Cast the texture coordinate to integer, and mask with (TEXT_HEIGHT - 1)
** In case of overflow
*/
// void	texturing(t_game *game, int x)
// {
// 	int			i;
// 	double		step;
// 	double		text_pos;
// 	t_mlx		img;
// 	t_param		param;

// 	img = game->img;
// 	param = game->param;

// 	step = 1.0 * TEXT_HEIGHT / param.line_height;
// 	text_pos = (param.draw[0] - HEIGHT / 2 + param.line_height / 2) * step;
// 	i = param.draw[0];
// 	while (i < param.draw[1])
// 	{
// 		param.text[1] = (int)text_pos & (TEXT_HEIGHT - 1);
// 		text_pos += step;
// 		param.color = img.texture[param.text_num][TEXT_HEIGHT * param.text[1] + param.text[0]];

// 		if (param.side == 1)
// 			param.color = (param.color >> 1) & 8355711;
// 		img.buf[i][x] = param.color;
// 		img.re_buf = 1;
// 		++i;
// 	}
// }

static void	calculator(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		ray_direction(game, i);
		initial_position(game);
		get_step(game);
		handle_hits(game);
		dist_n_height(game);
		// texturing(game, i);
		++i;
	}
}

void	looping(t_game *game)
{
	init_mlx(&game->img);
	init_param(&game->param);
	init_buffer(&game->img);
	calculator(game);
	// drawer(&game->img);
}
