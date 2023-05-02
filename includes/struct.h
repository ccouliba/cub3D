/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:23:38 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 04:14:04 by ccouliba         ###   ########.fr       */
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
	int				img_width;
	int				img_height;

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
