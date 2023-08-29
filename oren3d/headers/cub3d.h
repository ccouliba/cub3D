#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "draw.h"


# define ROTATE_LEFT		124
# define ROTATE_RIGHT		123
# define FORWARD			13
# define BACK				1
# define LEFT				0
# define RIGHT				2
# define BUFFER_SIZE		500
# define ESC				53
# define ROT_SP 1
# define RUN_SP 10
# define SIDE_SP 100

# define WIDTH 640
# define HEIGHT 480
# define HALF_WIDTH WIDTH / 2
# define HALF_HEIGHT HEIGHT / 2
# define FOV 40
# define HALF_FOV FOV / 2
# define PRECISION 64
# define WALL_GAP 0.2

typedef struct s_param
{
	t_i_point	screen;
	t_i_point	map;
	t_i_point	text;
	t_i_point	step;
	t_i_point	draw;
	t_point		delta;
	t_point		raydir;
	t_point		side_dist;
	int			hit;
	int			side;
	int			color;
	int			line_height;
	double		cam;
	double		wall;
	double		perp_wall_dist;
}				t_param;

typedef struct s_config
{
	int				direction;
	t_i_point		pos;
	t_i_point		map_size;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			*ceiling;
	char			**map;
}				t_config;

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
	t_point			p;
	t_point			pos;
	t_point			dir;
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
	t_i_point		last;
	int				x_or_y;
	int				bpp;
	int				size_line;
	int				endian;
	int				re_buf;
	char			*addr;
	int				**buf;
	void			*mlx;
	void			*win;
	void			*img;
	void			*tex_img;
	void			*tex_data;
	int				tex_bpp;
	int				tex_size_line;
	int				tex_endian;
	t_i_size		tex;

}				t_mlx;

typedef struct s_data {
	t_mlx		mlx;
	t_param		param;
	t_config	config;
} t_data;

int close_hook(t_data *data);
int key_hook(int keycode, t_data *data);
int	raycasting(t_data *data);
void    color_line(t_mlx *mlx, int y, int distance);
void	color_vline(t_mlx *mlx, int x, double distance);
double deg2rad(double deg);
double distx(t_mlx *mlx);
double disty(t_mlx *mlx);
void increment_ray(t_ray *ray);
# endif