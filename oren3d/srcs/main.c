#include "../headers/cub3d.h"

int close_hook(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	exit(0);
	return 0;
}

int key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_hook(data);
	return 0;
}

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
void init_game_variables(t_data *data)
{
	data->config.map_size.x = 10;
	data->config.map_size.y = 10;
	data->mlx.ray.last_y = 0;
	data->mlx.ray.last_x = 0;
	data->mlx.ray.dx = 0;
	data->mlx.ray.dy = 0;
	data->config.map = (char **)malloc((MAP_HEIGHT + 1) * sizeof(char *));
	data->config.map[0] = "1111111111";
	data->config.map[1] = "1000000001";
	data->config.map[2] = "1000000001";
	data->config.map[3] = "1000000001";
	data->config.map[4] = "1000000001";
	data->config.map[5] = "1000000001";
	data->config.map[6] = "1000000001";
	data->config.map[7] = "1000000001";
	data->config.map[8] = "1000000001";
	data->config.map[9] = "1111111111";
	data->config.map[10] = 0;
	data->config.direction = 0;
	data->config.pos.x = 2;
	data->config.pos.y = 2;
	data->mlx.a = 0;
	data->mlx.d = 0;
	data->mlx.i = 0;
	data->mlx.l = 0;
	data->mlx.p.x = 0;
	data->mlx.p.y = 0;
	data->mlx.r = 0;
	data->mlx.s = 0;
	data->mlx.w = 0;
	data->mlx.x_or_y = 0;
	data->mlx.esc = 0;
	data->mlx.rot_speed = 0;
	data->mlx.angle = 0;
	data->mlx.ray.angle = 0;

	
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

int main()
{
	t_data data;

	init_game_variables(&data);

	data.mlx.mlx = mlx_init();
	if (!data.mlx.mlx)
		return (1);
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "");
	if (!data.mlx.win)
		return (1);
	data.mlx.img = mlx_new_image(data.mlx.mlx, WIDTH, HEIGHT);
	if (!data.mlx.img)
		return (1);
	data.mlx.addr = mlx_get_data_addr(data.mlx.img, &data.mlx.bpp,
			&data.mlx.size_line, &data.mlx.endian);
	if (!data.mlx.addr)
		return (1);

	// uploade d'une texture pour tester le code
	data.mlx.tex_img = mlx_xpm_file_to_image(data.mlx.mlx, "assets/textures/bricksx64.xpm", &data.mlx.tex.width, &data.mlx.tex.height);
	data.mlx.tex_data = mlx_get_data_addr(data.mlx.tex_img, &data.mlx.tex_bpp, &data.mlx.tex_size_line, &data.mlx.tex_endian);
	mlx_loop_hook(data.mlx.mlx, &raycasting, &data);
	mlx_hook(data.mlx.win, 17, 0L, close_hook, &data);
	mlx_hook(data.mlx.win, 2, 1L << 0, &press_key, &data.mlx);
	mlx_hook(data.mlx.win, 3, 1L << 1, &release_key, &data.mlx);
	mlx_loop(data.mlx.mlx);
	return 0;
}