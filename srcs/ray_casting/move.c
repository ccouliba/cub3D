/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:23:58 by ngenadie          #+#    #+#             */
/*   Updated: 2023/10/24 19:48:27 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	change_pos(t_game *game, t_mlx *mlx, double new_x, double new_y)
{
	if (game->config.map[(int)(new_y - WALL_GAP)][(int)new_x] != '1'
		&& game->config.map[(int)(new_y + WALL_GAP)][(int)new_x] != '1'
		&& game->config.map[(int)new_y][(int)(new_x - WALL_GAP)] != '1'
		&& game->config.map[(int)new_y][(int)(new_x + WALL_GAP)] != '1')
	{
		game->config.map[(int)mlx->p_y][(int)mlx->p_x] = '0';
		game->config.map[(int)new_y][(int)new_x] = 'P';
		mlx->p_y = new_y;
		mlx->p_x = new_x;
	}
}

void	move2(t_game *game, t_mlx *mlx, double new_x, double new_y)
{
	if (mlx->w)
	{
		new_x = mlx->p_x + cos(deg2rad(mlx->angle)) / RUN_SP;
		new_y = mlx->p_y + sin(deg2rad(mlx->angle)) / RUN_SP;
	}
	else if (mlx->s)
	{
		new_x = mlx->p_x - cos(deg2rad(mlx->angle)) / RUN_SP;
		new_y = mlx->p_y - sin(deg2rad(mlx->angle)) / RUN_SP;
	}
	else if (mlx->a)
	{
		new_x = mlx->p_x + cos(deg2rad(mlx->angle - 90)) / SIDE_SP;
		new_y = mlx->p_y + sin(deg2rad(mlx->angle - 90)) / SIDE_SP;
	}
	else if (mlx->d)
	{
		new_x = mlx->p_x + cos(deg2rad(mlx->angle + 90)) / SIDE_SP;
		new_y = mlx->p_y + sin(deg2rad(mlx->angle + 90)) / SIDE_SP;
	}
	change_pos(game, mlx, new_x, new_y);
}

void	move(t_game *game)
{
	t_mlx	*mlx;
	double	new_x;
	double	new_y;

	mlx = &game->img;
	new_x = mlx->p_x;
	new_y = mlx->p_y;
	if (mlx->l)
	{
		mlx->angle -= ROT_SP;
		return ;
	}
	else if (mlx->r)
	{
		mlx->angle += ROT_SP;
		return ;
	}
	else
		move2(game, mlx, new_x, new_y);
}
