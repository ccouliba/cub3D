/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <ngenadie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:18:48 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/19 12:59:44 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/*
** Define the cub && xpm extension
** Define the buffer_size for the read
*/
# define CUB_EXT ".cub"
# define XPM_EXT ".xpm"
# define BUFFER_SIZE 2048
# define ROT_SP 1
# define RUN_SP 10
# define SIDE_SP 100

/*
** Define keycode
*/
# define RIGHT 100
# define LEFT 97
# define FORWARD 119
# define BACK 115
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define ESC 65307

/*
** Define error type
*/
# define FILE_ERROR "File error\n"
# define READING_ERROR "Reading error\n"
# define PARSING_ERROR "Config error\n"
# define MAP_ERROR "Map error\n"
# define WRONG_SIZE "Cannot open window\n"
# define ANY_MLX_ERROR "MinilibX error\n"

# define MISSING_ARG "Missing argument\n"
# define TOO_MANY "Too many arguments\n"

/*
** Define sprites
*/
# define NORTH "NO "
# define SOUTH "SO "
# define WEST "WE "
# define EAST "EA "

/*
** Define starting position
*/
# define VALID_CHAR " 01NSWE"
# define VALID_POS "NSWE"

/*
** Define mlx
*/
# define OFFSET 64
# define TEXT_HEIGHT 32
# define TEXT_WIDTH 32
// # define MAP_WIDTH 32
// # define MAP_HEIGHT 32
# define WIDTH 640
# define HEIGHT 480
# define FOV 40
# define HALF_FOV FOV / 2
# define PRECISION 64
#endif
