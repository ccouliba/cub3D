/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:43:44 by ccouliba          #+#    #+#             */
/*   Updated: 2023/03/30 06:12:04 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// char	**malloc_map(char **line, int size)
// {
// 	int		i;
// 	char	**map;

// 	map = malloc(sizeof(char *) * (size + 1));
// 	if (!map)
// 		return ((char **) NULL);
// 	i = 0;
// 	while (line[i])
// 	{
// 		map[i] = ft_strdup(line[i]);
// 		if (!map[i])
// 			return (free_double_p(map));
// 		++i;
// 	}
// 	map[i] = 0;
// 	return (map);
// }

void	init_mlx(t_mlx *img)
{
	img->bpp = 0;
	img->size_line = 0;
	img->endian = 0;
	img->re_buf = 0;
	img->addr = 0;
	img->mlx = 0;
	img->win = 0;
	img->img = 0;
}

void	init_param(t_param *param, int *position)
{
	param->hit = 0;
	param->side = 0;
	param->color = 0;
	// param->texture
	param->text_num = 0;
	param->line_height = 0;
	param->map[0] = 0;
	param->map[1] = 0;
	param->text[0] = 0;
	param->text[1] = 0;
	param->step[0] = 0;
	param->step[1] = 0;
	param->draw[0] = 0;
	param->draw[1] = 0;

	param->pos[0] = (double)position[0];
	param->pos[1] = (double)position[1];
	param->dir_x = 0;
	param->dir_y = 0;
	param->plane_x = 0;
	param->plane_y = 0.66;
	param->move_speed = 0;
	param->rot_speed = 0;
	// param->texture[4];
	
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

// void	my_mlx_pixel_put(t_mlx *img, int x, int y, int color)
// {
// 	void	*dst;

// 	dst = (int *)(img->addr + (y * img->size_line + x * (img->bpp / 8)));
// 	*(unsigned int *)dst = color;
// }

static void	drawer(t_mlx *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			printf("Drawer : (int)img->buf[2][1] : [%d]\n", (int)img->buf[2][1]);
			img->addr[y * WIDTH + x] = img->buf[y][x];
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	printf("END OF LOOP\n");
}

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

static void	init_ray(t_param *param, int x)
{
	param->cam = 2 * x / (double)WIDTH - 1;
	param->raydir[0] = param->dir_x + param->plane_x * param->cam;
	param->raydir[1] = param->dir_y + param->plane_y * param->cam;
	param->map[0] = (int)param->pos[0];
	param->map[1] = (int)param->pos[1];
}

static void	get_step(t_param *param)
{
	if (param->raydir[0] == 0)
		param->delta[0] = 1e30;
	else
		param->delta[0] = fabs(1 / param->raydir[0]);
	if (param->raydir[1] == 0)
		param->delta[1] = 1e30;
	else
		param->delta[1] = fabs(1 / param->raydir[1]);
	// param->delta[0] = fabs(1 / param->raydir[0]);
	// param->delta[1] = fabs(1 / param->raydir[1]);
	printf("get_step : param->delta[0] : [%.2f]\n", param->delta[0]);
	printf("get_step : param->delta[1] : [%.2f]\n", param->delta[1]);
	if (param->raydir[0] < 0)
	{
		param->step[0] = -1;
		param->side_dist[0] = (param->pos[0] - param->map[0]) * param->delta[0];
	}
	else
	{
		param->step[0] = 1;
		param->side_dist[0] = (param->map[0] + 1.0 - param->pos[0])
			* param->delta[0];
	}
	if (param->raydir[1] < 0)
	{
		param->step[1] = -1;
		param->side_dist[1] = (param->pos[1] - param->map[1]) * param->delta[1];
	}
	else
	{
		param->step[1] = 1;
		param->side_dist[1] = (param->map[1] + 1.0 - param->pos[1])
			* param->delta[1];
	}
	printf("param->pos[0] : [%d]\n", (int)param->pos[0]);
	printf("param->pos[1] : [%d]\n", (int)param->pos[1]);
}

static void	handle_hits(t_param *param, t_config *config)
{
	(void)config;
	// printf("Step1\n");
	param->hit = 0;
	while (param->hit == 0)
	{
		if (param->side_dist[0] < param->side_dist[1])
		{
			param->side_dist[0] += param->delta[0];
			param->map[0] += param->step[0];
			param->side = 0;
		}
		else
		{
			param->side_dist[1] += param->delta[1];
			param->map[1] += param->step[1];
			param->side = 1;
		}
		// printf("param->map[0] : [%d]\n", param->map[0]);
		printf("Handle_hits : config->map[param->map[0]][param->map[1]] : [%c]\n", config->map[param->map[0]][param->map[1]]);
		if (config->map[param->map[0]][param->map[1]] > 0)
			param->hit = 1;
		printf("Handle_hits : param->hit : [%d]\n", param->hit);
	}
	printf("\n");
	// printf("Handle_hits : config->map[param->map[0]][param->map[1]] : [%c]\n", config->map[param->map[0]][param->map[1]]);
}

/*
** for fish eye
*/
// static void	set_perp_wall(t_param *param)
// {
// 	if (param->side == 0)
// 		param->perp_wall_dist = param->side_dist[0] - param->delta[0];
// 	else
// 		param->perp_wall_dist = param->side_dist[1] - param->delta[1];
// 	printf("set_perp_wall : param->perp_wall_dist : [%.2f]\n", param->perp_wall_dist);
// 	printf("set_perp_wall : param->side_dist[1] : [%.2f]\n", param->side_dist[0]);
// 	printf("set_perp_wall : param->side_dist[1] : [%.2f]\n", param->side_dist[1]);
// 	printf("set_perp_wall : param->delta[1] : [%.2f]\n", param->delta[0]);
// 	printf("set_perp_wall : param->delta[1] : [%.2f]\n", param->delta[1]);
// 	printf("set_perp_wall : param->map[1] - param->pos[1] : [%d]\n", (int)(param->map[1] - param->pos[1]));
// }

void	set_param_draw(t_param *param, int line_height)
{
	param->line_height = (int)(HEIGHT / param->perp_wall_dist);
	param->draw[0] = -line_height / 2 + HEIGHT / 2;
	if (param->draw[0] < 0)
		param->draw[0] = 0;
	param->draw[1] = line_height / 2 + HEIGHT / 2;
	if (param->draw[1] >= HEIGHT)
		param->draw[1] = HEIGHT - 1;
	printf("set_param_draw : param->draw[0] : [%d]\n", param->draw[0]);
	printf("set_param_draw : param->draw[1] : [%d]\n\n", param->draw[1]);
}

static void	height_to_draw(t_param *param, t_config *config)
{
	printf("Height_to_draw\n");
	// set_perp_wall(param);
	set_param_draw(param, param->line_height);
	if (config->map[param->map[0]][param->map[1]])
	{
		if (config->map[param->map[0]][param->map[1]] == 0)
			param->color = 0;
		else if (config->map[param->map[0]][param->map[1]] == 1)
			param->color = 255;
		printf("Height_to_draw : param->color : [%d]\n", param->color);

		if (param->side == 1)
			param->color = param->color / 2;
		// here draw vertical line to draw[0] to draw[1];
	}
	printf("\n");
}

static void	texture_calc(t_param *param, t_config *config)
{
	printf("Texture_calc\n\n");
	// printf("Texture_calc : param->wall : [%.2f]\n\n", param->wall);
	param->text_num = config->map[param->map[0]][param->map[1]] - 1;
	if (param->side == 0)
		param->wall = param->pos[1] + param->perp_wall_dist * param->raydir[1];
	else
		param->wall = param->pos[0] + param->perp_wall_dist * param->raydir[0];
	// printf("\tparam->wall : [%f]\n", (float)param->wall);
	param->wall -= floor(param->wall);
}

void	texturing(t_param *param, t_mlx *img, int x)
{
	int			i;
	double		step;
	double		text_pos;

	printf("Texturing_0\n");
	step = 1.0 * TEXT_HEIGHT / param->line_height;
	text_pos = (param->draw[0] - HEIGHT / 2 + param->line_height / 2) * step;
	param->text[0] = (int)(param->wall * (double)TEXT_WIDTH);
	if (param->side == 0 && param->raydir[0] > 0)
		param->text[0] = TEXT_WIDTH - param->text[0] - 1;
	if (param->side == 1 && param->raydir[1] < 0)
		param->text[1] = TEXT_WIDTH - param->text[0] - 1;
	i = param->draw[0];
	// printf("\ti : [%d]\n", i);(int)
	while (i < param->draw[1])
	{
		param->text[1] = (int)text_pos & (TEXT_HEIGHT - 1);
		text_pos += step;
		param->color = param->texture[param->text_num]
		[TEXT_WIDTH * param->text[1] + param->text[0]];
		if (param->side == 1)
			param->color = (param->color >> 1) & 8355711;
		img->buf[i][x] = param->color;
		printf("\timg->buf[i][x] : [%d]\n", img->buf[i][x]);
		++i;
	}
	printf("\n");
}

static void	calculator(t_param *param, t_mlx *img, t_config *config)
{
	int	i;

	i = 0;
	init_buffer(img);
	printf("Calculator : param->color : [%d]\n\n", param->color);
	while (i < WIDTH)
	{
		init_ray(param, i);
		get_step(param);
		handle_hits(param, config);
		height_to_draw(param, config);
		texture_calc(param, config);
		// printf("tbefore texturing fct\n");
		texturing(param, img, i);
		++i;
	}
	// printf("\n");
}

void	looping(t_param *param, t_mlx *img, t_config *config)
{
	init_mlx(img);
	init_param(param, config->position);
	calculator(param, img, config);
	drawer(img);
}

void	generate_texture(t_param *param)
{
	int	i;
	int	j;
	int	xorcolor;
	int	ycolor;
	int	xycolor;

	i = 0;
	while (i < TEXT_WIDTH)
	{
		j = 0;
		while (j < TEXT_HEIGHT)
		{
			xorcolor = (i * 256 / TEXT_WIDTH) ^ (j * 256 / TEXT_HEIGHT);
			ycolor = j * 256 / TEXT_HEIGHT;
			xycolor = j * 128 / TEXT_HEIGHT + i * 128 / TEXT_WIDTH;
			param->texture[0][TEXT_WIDTH * j + i] = 65536 * 254 * (i != j && i != TEXT_WIDTH - j); //flat red texture with black cross
			param->texture[1][TEXT_WIDTH * j + i] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			param->texture[2][TEXT_WIDTH * j + i] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			// param->texture[3][TEXT_WIDTH * j + i] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			// param->texture[4][TEXT_WIDTH * j + i] = 256 * xorcolor; //xor green
			// param->texture[5][TEXT_WIDTH * j + i] = 65536 * 192 * (i % 16 && j % 16); //red bricks
			// param->texture[6][TEXT_WIDTH * j + i] = 65536 * ycolor; //red gradient
			// param->texture[7][TEXT_WIDTH * j + i] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
			++j;
		}
		++i;
	}
}
