/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:23:38 by ccouliba          #+#    #+#             */
/*   Updated: 2023/04/12 15:21:59 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_ray
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	rayCos;
	double	raySin;
	double	angle;
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
	// int				*texture[4];
	int				re_buf;
	char			*addr;
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

typedef struct s_param
{
	int		hit;
	int		side;
	int		color;
	// int		texture;
	// int		text_num;
	int		line_height;
	int		map[2];
	int		text[2];
	int		step[2];
	int		draw[2];
	double	cam;
	double	wall;
	double	perp_wall_dist;
	double	delta[2];
	double	raydir[2];
	double	side_dist[2];
}				t_param;

typedef struct s_game
{
	t_mlx			img;
	t_param			param;
	t_config		config;
}				t_game;

typedef int(*t_getter[5])(t_config *, char *);

#endif
