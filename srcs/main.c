/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:39:03 by ccouliba          #+#    #+#             */
/*   Updated: 2023/08/28 13:51:28 by ngenadie         ###   ########.fr       */
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

int	ft_load_tex(t_game game)
{
	t_mlx	*mlx;
	t_config *config;

	config = &game.config;
	mlx = &game.img;
	mlx->n_img = mlx_xpm_file_to_image(game->img->mlx, config.north, &img->tex_width, &img->tex_height);
}

int	main(int ac, char **av)
{
	t_mlx	*img;
	t_game	game;

	img = &game.img;
	ft_bzero(&game, sizeof(t_game));
	game.config = init_game(ac, av);
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
	mlx_get_screen_size(img->mlx, &game.param.screenx, &game.param.screeny);
	img->tex_img = mlx_xpm_file_to_image(img->mlx, "textures/bricksx64.xpm", &img->tex_width, &img->tex_height);
	img->tex_data = mlx_get_data_addr(img->tex_img, &img->tex_bpp, &img->tex_size_line, &img->tex_endian);
	dprintf(2, "tex_width = %d, tex_height = %d\n", img->tex_width, img->tex_height);
	img->p_x = game.config.pos[1] + 0.5;
	img->p_y = game.config.pos[0] + 0.5;
	//mlx_hook(img->win, 17, 0L, exit_mlx, &img);
	mlx_loop_hook(img->mlx, &raycasting, &game);
	mlx_hook(img->win, 2, 1L << 0, &press_key, img);
	mlx_hook(img->win, 3, 1L << 1, &release_key, img);
	mlx_loop(img->mlx);
	return (0);
}

//	dprintf(2, "SCREEN SIZE X = %d, SCREEN SIZE Y = %d\n", game.param.screenx, game.param.screeny);
	//dprintf(2, "bpp = %d, size_line = %d\n", img->bpp, img->size_line);
	//for (int i = 0; i < img->tex_width / 4; i++)
	//{
	//	for (int j = 0; j < img->tex_height / 4; j++)
	//	{
	//		printf("tex[%d][%d] = %d\n", i, j, ((int *)img->tex_img)[i * j]);	
	//		printf("tex[%d][%d] = %p\n", i, j, ((int *)img->tex_img) + i * j);	
	//	}
	//}
