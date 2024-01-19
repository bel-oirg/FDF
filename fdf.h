/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:11:04 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/18 16:14:04 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH	1920
# define HEIGHT	1080

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define BUFFER_SIZE 2147479540

# define DEFAULT_COL 0x070FFF

# define ERR_EMP_FILE 	"[-] Empty File\n"
# define ERR_MAP 		"[-] Incorrect MAP\n"
# define ERR_TYP_FILE 	"[-] Invalid File Type\n"
# define ERR_ARGS 		"[-] Invalid Arguments\n"
# define ERR_COL		"[-] Invalid Color Code\n"
# define ERR_PER 		"[-] Invalid Permissions\n"

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

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_buddha
{
	int		rows;
	int		cols;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		color_amp;
	int		*arr_z;
	int		*arr_c;
	int		all_bpp;
	double	x_teta;
	double	y_teta;
	double	z_teta;
	t_point	*s;
	t_point	*e;
	void	*mlx;
	void	*win;
	t_neox	*neox;
	t_mouse	*m;
	t_img	*img;
}	t_buddha;

void	*my_malloc(size_t size, int mode);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);

void	ft_check_args(int ac, char **av);
char	*get_next_line(int fd);
char	**ft_split(char *str, char c);

//next line
void	free_out(char *out_free);
char	*ft_strjoin(char *s1, char *s2);
int		have_n(char	*temp);
char	*print_line(char **temp);
char	*get_next_line(int fd);

//parser_fdf
void	parser(t_neox **neox, char **argv);

//gradient
int		grad_c(t_point s, t_point c, t_point e);
void	init_p(t_point *p, t_buddha v);

//ft_convert
int		ft_convert(char *str);

//algo_utils
int		get_rows(char *file_name);
int		get_cols(char *file_name);

//cleaning
void	f_matrix(char **str);
int		destroy_fdf(t_buddha *v);

//three_dim
void	three_dim(float *x, float *y, float *z, t_buddha v);

//math_utils
int		abs_v(int val);
int		max_v(int a, int b);
int		min_v(int a, int b);

//algo
void	picasso(t_buddha *v);

//init_v
void	init_v(t_buddha *v, char *file_name);

#endif
