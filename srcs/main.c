/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:39:03 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/03 19:17:24 by ngenadie         ###   ########.fr       */
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

static int	get_key_code(int key_code, void *ptr)
{
	t_mlx		*mlx;
	t_game		*game;
	double		new_x;
	double		new_y;

	game = (t_game *)ptr;
	mlx = &game->img;
	new_x = mlx->p_x;
	new_y = mlx->p_y;
	if (key_code == ROTATE_LEFT)
	{
		dprintf(2, "ANGLE CHANGE LEFT = %f\n", mlx->angle);
		mlx->angle -= 0.1;
		dprintf(2, "ANGLE CHANGE LEFT = %f\n", mlx->angle);
	}
	else if (key_code == ROTATE_RIGHT)	
	{
		dprintf(2, "ANGLE CHANGE RIGHT = %f\n", mlx->angle);
		mlx->angle += 0.1 ;
		dprintf(2, "ANGLE CHANGE RIGHT = %f\n", mlx->angle);
	}
	else if (key_code == FORWARD)
	{
		new_x = mlx->p_x + cos(deg2rad(mlx->angle)) / RUN_SP;
		new_y = mlx->p_y + sin(deg2rad(mlx->angle)) / RUN_SP;
	}
	else if (key_code == BACK)
	{
		new_x = mlx->p_x - cos(deg2rad(mlx->angle)) / RUN_SP;
		new_y = mlx->p_y - sin(deg2rad(mlx->angle)) / RUN_SP;
	}
	else if (key_code == ESC)
		return (exit_mlx(&game->img), EXIT_FAILURE);		
	if ((int)floor(new_y) < game->config.map_size[0] 
		&& (int)floor(new_x) < ft_strlen(game->config.map[(int)floor(new_y)])
		&& game->config.map[(int)floor(new_y)][(int)floor(new_x)] != '1')
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
	img->p_x = game.config.pos[1] + 0.5;
	img->p_y = game.config.pos[0] + 0.5;
	//raycasting(&game);
	//mlx_hook(img->win, 17, 0L, exit_mlx, &img);
	mlx_loop_hook(img->mlx, &raycasting, &game);
	mlx_hook(img->win, 2, 1L << 0, get_key_code, &game);
	mlx_loop(img->mlx);
	return (0);
}
