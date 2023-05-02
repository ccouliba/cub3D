/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:18:48 by ccouliba          #+#    #+#             */
/*   Updated: 2023/05/02 05:26:51 by ccouliba         ###   ########.fr       */
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
# define X_EVENT_KEY_PRESS	2

/*
** Define error type
*/
# define MISSING_ARG "Missing argument\n"
# define TOO_MANY "Too many arguments\n"

# define FILE_ERROR "File error\n"
# define READING_ERROR "Reading error\n"
# define PARSING_ERROR "Config error\n"
# define MAP_ERROR "Map error\n"
# define WRONG_SIZE "Cannot open window\n"
# define ANY_MLX_ERROR "MinilibX error\n"

/*
** Define sprites
*/
# define NORTH "NO "
# define SOUTH "SO "
# define WEST "WE "
# define EAST "EA "

/*
** Define valid char in map
** Define starting position letter
*/
# define VALID_CHAR " 01NSWE"
# define VALID_POS "NSWE"

/*
** Define mlx
*/
// # define OFFSET 64
# define TEXT_HEIGHT 64
# define TEXT_WIDTH 64
// # define MAP_WIDTH 32
// # define MAP_HEIGHT 32
# define WIDTH 1800
# define HEIGHT 960

#endif
