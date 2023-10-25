/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:24:17 by ngenadie          #+#    #+#             */
/*   Updated: 2023/10/25 18:37:25 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_load_tex(t_game *game)
{
	t_mlx		*mlx;
	t_config	*config;

	config = &game->config;
	mlx = &game->img;
	mlx->texs[0].ptr = mlx_xpm_file_to_image(mlx->mlx,
			config->tex_files[0], &mlx->texs[0].width, &mlx->texs[0].height);
	mlx->texs[0].data = mlx_get_data_addr(mlx->texs[0].ptr,
			&mlx->texs[0].bpp, &mlx->texs[0].size_line, &mlx->texs[0].endian);
	mlx->texs[1].ptr = mlx_xpm_file_to_image(mlx->mlx,
			config->tex_files[1], &mlx->texs[1].width, &mlx->texs[1].height);
	mlx->texs[1].data = mlx_get_data_addr(mlx->texs[1].ptr,
			&mlx->texs[1].bpp, &mlx->texs[1].size_line, &mlx->texs[1].endian);
	mlx->texs[2].ptr = mlx_xpm_file_to_image(mlx->mlx,
			config->tex_files[2], &mlx->texs[2].width, &mlx->texs[2].height);
	mlx->texs[2].data = mlx_get_data_addr(mlx->texs[2].ptr,
			&mlx->texs[2].bpp, &mlx->texs[2].size_line, &mlx->texs[2].endian);
	mlx->texs[3].ptr = mlx_xpm_file_to_image(mlx->mlx,
			config->tex_files[3], &mlx->texs[3].width, &mlx->texs[3].height);
	mlx->texs[3].data = mlx_get_data_addr(mlx->texs[3].ptr,
			&mlx->texs[3].bpp, &mlx->texs[3].size_line, &mlx->texs[3].endian);
	return (0);
}

int	game_init(t_game *game, t_mlx *img, int ac, char **av)
{
	ft_bzero(game, sizeof(t_game));
	game->config = init_game(ac, av);
	img->mlx = mlx_init();
	if (!img->mlx)
		return (1);
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
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(mlx));
}

void	init_ray(t_mlx *mlx)
{
		mlx->ray.last_x = mlx->p_x;
		mlx->ray.last_y = mlx->p_y;
		mlx->ray.dx = mlx->p_x;
		mlx->ray.dy = mlx->p_y;
		mlx->ray.raycos = cos(deg2rad(mlx->ray.angle)) / PRECISION;
		mlx->ray.raysin = sin(deg2rad(mlx->ray.angle)) / PRECISION;
}
