/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:39:03 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/20 18:30:12 by ngenadie         ###   ########.fr       */
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
	t_mlx		*mlx;

	mlx = ptr;
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
	printf_map(game);
	dprintf(2, "screen width = %d, screen height = %d", )
	img->p_x = game.config.pos[1] + 0.5;
	img->p_y = game.config.pos[0] + 0.5;
	//raycasting(&game);
	//mlx_hook(img->win, 17, 0L, exit_mlx, &img);
	mlx_loop_hook(img->mlx, &raycasting, &game);
	mlx_hook(img->win, 2, 1L << 0, &press_key, img);
	mlx_hook(img->win, 3, 1L << 1, &release_key, img);
	mlx_loop(img->mlx);
	return (0);
}
