/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:23:38 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/29 14:00:11 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_ray
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	last_x;
	double	last_y;
	double	rayCos;
	double	raySin;
	double	angle;
}				t_ray;

typedef struct s_mlx
{
	long			i;
	t_ray			ray;
	double			angle;
	double			p_x;
	double			p_y;
	double			pos[2];
	double			dir_x;
	double			dir_y;
	double			move_speed;
	double			rot_speed;
	bool			w;
	bool			a;
	bool			s;
	bool			d;
	bool			l;
	bool			r;
	bool			esc;
	int				last_dist;
	int				last_x;
	int				last_y;
	int				x_or_y;
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
	void			*tex_img;
	int				tex_height;
	int				tex_width;

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
	int		screenx;
	int		screeny;
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
