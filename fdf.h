/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:36:58 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/07 08:57:44 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT	900
# define WIDTH	900

# include <stdio.h>
#include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_neox
{
	int				(*line)[2];
	struct s_neox	*next;
}	t_neox;

typedef struct s_data
{
	void			*data;
	struct s_data	*next;
}	t_data;

typedef struct s_mouse
{
	int	x;
	int	y;
	int	x0;
	int	y0;
	int	is_pressed;
}	t_mouse;

typedef	struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef	struct s_buddha
{
	int		rows;
	int		cols;
	int		zoom;
	int		shift_x;
	int		shift_y;
	double	x_teta;
	double	y_teta;
	double	z_teta;
	double	angle;
	void	*mlx;
	void	*win;
	t_neox	*neox;
	t_mouse *m;
	t_img	*img;
}	t_buddha;

void	ft_error();
int		ft_isdigit(int c);
int		ft_strlen_line(char *str);
int		ft_search(char *str);
int		ft_convert(char *str);
void	*my_malloc(size_t size, int mode);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);
char	*my_strtok(char *src, char *delim);
char	*my_strtok_two(char *src, char *delim);
void	ft_check_args(int ac, char **av);
int		ft_parser(t_neox **neox, char **av);
char	*my_strcpy(char *s1, char *s2, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_all(int fd, char *str);
char	*get_next_line(int fd);
int		find_line(char *str);
char	*get_the_line(char *str);
char	*get_the_rest(char *str, size_t size);
int		ft_str_line(char *str);
char	**ft_split(char *str, char c);

#endif
