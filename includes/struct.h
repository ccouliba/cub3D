/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:23:38 by ccouliba          #+#    #+#             */
/*   Updated: 2023/10/24 17:46:59 by ngenadie         ###   ########.fr       */
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

typedef struct s_texture
{
	int		endian;
	int		bpp;
	int		size_line;
	int		width;
	int		height;
	int		len;
	char	*name;
	void	*ptr;
	void	*data;
	float	texPosX;
}				t_tex;

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
	char			xy;
	int				bpp;
	int				size_line;
	int				endian;
	t_tex			texs[4]; /*norht, south, west, east*/
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
	char			*tex_files[4]; /*order: north, south, east, west*/
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

//typedef int(*t_getter[5])(t_config *, char *);

#endif
