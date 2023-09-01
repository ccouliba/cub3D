/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:23:38 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 06:17:12 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_ray
{
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			last_x;
	double			last_y;
	double			raycos;
	double			raysin;
	double			angle;
}				t_ray;

typedef struct s_mlx
{
	t_ray			ray;
	double			width;
	double			lenght;
	double			angle;
	double			p_x;
	double			p_y;
	double			pos[2];
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	int				bpp;
	int				size_line;
	int				endian;
	int				re_buf;
	char			*addr;
	int				**buf;
	void			*mlx;
	void			*win;
	void			*img;
}				t_mlx;

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
	int				pos[2];
	int				map_size[2];
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			*ceiling;
	char			**map;
}				t_config;

typedef struct s_game
{
	t_mlx			img;
	t_config		config;
}				t_game;

typedef struct s_list
{
	void			*val;
	struct s_list	*next;
}				t_list;

typedef struct s_cgf
{
	int				(*f)();
	char			*msg;
}				t_cfg;

// typedef int(*t_cfg[3])(t_config *, char **);

#endif
