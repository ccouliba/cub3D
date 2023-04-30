/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:39:03 by ccouliba          #+#    #+#             */
/*   Updated: 2023/04/30 21:11:36 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	printf_map(t_game game)
{
	int i;

	i = -1;
	printf("map = \n");
	while (++i < game.config.map_size[0])
		dprintf(2, "map[%d] = %s\n", i, game.config.map[i]);
}


static t_config	init_game(int ac, char **av)
{
	t_config	config;

	if (parser(ac, av, &config))
		exit(1);
	return (config);
}

int	exit_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
	return (exit(1), EXIT_FAILURE);
}

static int	get_key_code(int key_code, t_game *game)
{
	t_mlx		*mlx;
	double		new_x;
	double		new_y;

	mlx = &game->img;
	new_x = mlx->p_x;
	new_y = mlx->p_y;
	dprintf(2, "p_x = %f, ", mlx->p_x);
	dprintf(2, "p_y = %f\n", mlx->p_y);
	if (key_code == ROTATE_LEFT)
		mlx->angle -= 1 / 10;
	else if (key_code == ROTATE_RIGHT)	
		mlx->angle += 1 / 10;
	else if (key_code == FORWARD)
	{
		new_x = mlx->p_y + sin(deg2rad(mlx->angle) / 10);
		new_y = mlx->p_x + cos(deg2rad(mlx->angle) / 10);
	}
	else if (key_code == BACK)
	{
		new_x = mlx->p_y - sin(deg2rad(mlx->angle) / 10);
		new_y = mlx->p_x - cos(deg2rad(mlx->angle) / 10);
	}
	else if (key_code == ESC)
		return (exit_mlx(&game->img), EXIT_FAILURE);
	dprintf(2, "new_x = %f, ", new_x);
	dprintf(2, "new_y = %f\n", new_y);
	if ((int)floor(new_y) < game->config.map_size[0] && (int)floor(new_x) < ft_strlen(game->config.map[(int)floor(new_y)]))
	{
		mlx->p_x = new_x;
		mlx->p_y = new_y;
	}
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
	t_mlx	*img;
	t_game	game;

	img = &game.img;
	ft_bzero(img, sizeof(t_mlx));
	game.config = init_game(ac, av);
	//if (game.config == NULL)
	//	return (exit(1), 1);
	img->mlx = mlx_init();
	if (!img->mlx)
		return (1);
	check_win_size(WIDTH, HEIGHT);
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "cub3D");
	if (!img->win)
		return (printf("No Window\n"), 1);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	if (!img->img)
		return (printf("No Image\n"), 1);
	img->addr = (char *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_line, &img->endian);
	if (!img->addr)
		return (printf("No Address\n"), 1);
	color_line(img, 800, 100);
	printf_map(game);
	//raycasting(&game);
	mlx_key_hook(img->win, get_key_code, &img);
	//mlx_hook(img->win, 17, 0L, exit_mlx, &img);
	mlx_loop(img->mlx);
	mlx_loop_hook(img->mlx, &raycasting, &game);
	return (0);
}
