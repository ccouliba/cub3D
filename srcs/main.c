/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:39:03 by ccouliba          #+#    #+#             */
/*   Updated: 2023/10/27 20:17:57 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_config	init_game(int ac, char **av)
{
	t_config	config;

	if (parser(ac, av, &config))
		exit(1);
	return (config);
}

int	exit_mlx(t_game *game)
{
	int		i;
	t_mlx	*mlx;

	i = 0;
	mlx = &game->img;
	while (i < 4)
	{
		mlx_destroy_image(mlx->mlx, mlx->texs[i].ptr);
		if (game->config.tex_files[i])
			free(game->config.tex_files[i]);
		++i;
	}
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
	free_double_p(game->config.line);
	return (exit(1), EXIT_FAILURE);
}

static int	release_key(int key_code, void *ptr)
{
	t_mlx		*mlx;

	mlx = ptr;
	if (key_code == ROTATE_LEFT)
		mlx->l = 0;
	else if (key_code == ROTATE_RIGHT)
		mlx->r = 0;
	else if (key_code == FORWARD)
		mlx->w = 0;
	else if (key_code == BACK)
		mlx->s = 0;
	else if (key_code == LEFT)
		mlx->a = 0;
	if (key_code == RIGHT)
		mlx->d = 0;
	return (1);
}

static int	press_key(int key_code, void *ptr)
{
	t_game		*game;
	t_mlx		*mlx;

	game = ptr;
	mlx = &game->img;
	if (key_code == ROTATE_LEFT)
		mlx->l = 1;
	else if (key_code == ROTATE_RIGHT)
		mlx->r = 1;
	else if (key_code == FORWARD)
		mlx->w = 1;
	else if (key_code == BACK)
		mlx->s = 1;
	else if (key_code == LEFT)
		mlx->a = 1;
	if (key_code == RIGHT)
		mlx->d = 1;
	else if (key_code == ESC)
	{
		exit_mlx(game);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_mlx	*img;
	t_game	game;

	img = &game.img;
	if (game_init(&game, img, ac, av))
		return (1);
	mlx_get_screen_size(img->mlx, &game.param.screenx, &game.param.screeny);
	img->p_x = game.config.pos[1] + 0.5;
	img->p_y = game.config.pos[0] + 0.5;
	ft_load_tex(&game);
	player_direction(game, img);
	img->ceiling = game.config.ceiling_color;
	img->floor = game.config.floor_color;
	mlx_loop_hook(img->mlx, &raycasting, &game);
	mlx_hook(img->win, 2, 1L << 0, &press_key, &game);
	mlx_hook(img->win, 3, 1L << 1, &release_key, img);
	mlx_hook(img->win, 17, 0L, exit_mlx, &game);
	mlx_loop(img->mlx);
	return (0);
}
