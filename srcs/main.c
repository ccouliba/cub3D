/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:39:03 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 02:37:22 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	init_game(int ac, char **av)
{
	t_config	config;

	if (parser(ac, av, &config))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	exit_game(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
	return (exit(1), EXIT_FAILURE);
}

static int	get_key_code(int key_code, t_mlx *mlx)
{
	if (key_code == ESC)
		return (exit_game(mlx), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	check_win_size(int width, int height)
{
	if (!width || !height)
		print_error(WRONG_SIZE, 2);
	if (width < 1000 || width > INT_MAX || height < 480 || height > INT_MAX)
		print_error(WRONG_SIZE, 2);
	else
		return ;
}

int	main(int ac, char **av)
{
	t_mlx		img;

	if (init_game(ac, av))
		return (1);
	img.mlx = mlx_init();
	if (!img.mlx)
		return (1);
	check_win_size(WIDTH, HEIGHT);
	img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "cub3D");
	if (!img.win)
		return (1);
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	if (!img.img)
		return (1);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp,
			&img.size_line, &img.endian);
	if (!img.addr)
		return (EXIT_FAILURE);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_key_hook(img.win, get_key_code, &img);
	mlx_hook(img.win, 17, 0L, exit_game, &img);
	mlx_loop(img.mlx);
	return (0);
}
