/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:23:38 by ccouliba          #+#    #+#             */
/*   Updated: 2023/10/25 18:38:00 by ccouliba         ###   ########.fr       */
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
	double	raycos;
	double	raysin;
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
	float	texpos_x;
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
	t_tex			texs[4];
	int				re_buf;
	char			*addr;
	int				**buf;
	unsigned int	ceiling;
	unsigned int	floor;
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
	char			*tex_files[4];
	char			*floor;
	char			*ceiling;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	char			**map;
}				t_config;

typedef struct s_param
{
	int		screenx;
	int		screeny;
	int		hit;
	int		side;
	int		color;
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

#endif
