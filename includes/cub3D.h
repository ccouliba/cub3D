/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:23:44 by ccouliba          #+#    #+#             */
/*   Updated: 2023/04/12 23:53:50 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "incs.h"
# include "defines.h"
# include "struct.h"
# include "gnl.h"

/******************************************************************************/
/*********************************  PARSING  **********************************/
/******************************************************************************/
int			check_file(char *av, char *extension);
int			check_flag(char **file);
int			check_config(t_config *config, char **line);
int			check_map(t_config *config, char **line);

int			parser(int ac, char **av, t_config *config);
char		**read_file(char *file_name);

int			is_directory(char *av);

int			check_extension(char *s, char *extension);
int			check_xpm_file(char *s);
int			around_zero(char **line, int i, int j);
int			occurences(char *s, int c);
void		map_size(t_config *config);

int			check_char(char *line);
int			check_walls(char *line);
int			check_spaces(char *line);
int			after_zero(char *line);
int			after_start_pos(char *line);

/******************************************************************************/
/************************************ MLX *************************************/
/******************************************************************************/
void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void		color_pixel(t_mlx *img, int *p);

void		draw(t_mlx *img);
int			looping(t_param *param, t_mlx *img, t_config *config);
void		load_texture(t_mlx *img, t_param *param);

/******************************************************************************/
/*********************************** UTILS ************************************/
/******************************************************************************/
void		print_error(char *type, int fd);
int			exit_mlx(t_mlx *mlx);

/*
** Gnl
*/
int			get_next_line(int fd, char **line);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, int start, int len);

/*
** Lib functions
*/
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);

int			ft_atoi(char *str);
int			non_alphanum(char *str);
int			check_number(char *s);
int			ft_isdigit(int c);
int			ft_strlen(char *s);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s);

void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		**ft_split(char *s, char c);
char		**free_double_p(char **s);

/*
** List functions
*/
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lst_prevlast(t_list **list);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		free_elem(t_list *elem, void (*clr)());
void		free_stack(t_list **stack, void (*clr)());

#endif
