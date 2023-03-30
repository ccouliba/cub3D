/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:23:38 by ccouliba          #+#    #+#             */
/*   Updated: 2023/03/30 22:35:02 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx
{
	int				bpp;
	int				size_line;
	int				endian;
	int				re_buf;
	int				*addr;
	int				**buf;
	void			*mlx;
	void			*win;
	void			*img;

}				t_mlx;

typedef struct s_list
{
	void			*val;
	struct s_list	*next;
}				t_list;

typedef struct s_flag
{
	int				north;
	int				south;
	int				west;
	int				east;
	int				floor;
	int				ceiling;
}				t_flag;

typedef struct s_config
{
	int				direction;
	int				position[2];
	int				map_size[2];
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			*ceiling;
	char			**map;
}				t_config;

typedef struct s_param
{
	// int		texture;
	int				hit;
	int				side;
	int				text_num;
	int				line_height;
	int				map[2];
	int				text[2];
	int				step[2];
	int				draw[2];
	int				texture[3][TEXT_WIDTH * TEXT_HEIGHT];
	double			pos[2];
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	double			cam;
	double			wall;
	double			perp_wall_dist;
	double			delta[2];
	double			raydir[2];
	double			side_dist[2];
}				t_param;

typedef struct s_game
{
	t_mlx			img;
	t_param			param;
	t_config		config;
}				t_game;

typedef int(*t_getter[5])(t_config *, char *);

#endif
