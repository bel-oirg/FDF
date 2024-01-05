/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:37:23 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/05 01:37:25 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	diff(int x1, int x2)
{
	return (x2 - x1);
}

int	max_v(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	abs_v(int val)
{
	return (max_v(val, -val));
}

void	three_dim(float *x, float *y, int z, double angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}


int	get_z(int x, int y, t_neox *neox)
{
	if (x < 0 || y < 0 || !neox)
		return (-1);
	while (y-- && neox)
		neox = neox->next;
	return (neox->line[x][0]);
}

int	get_c(int x, int y, t_neox *neox)
{
	int color;
	int default_col;
	
	if (x < 0 || y < 0 || !neox)
		return (-1);
	default_col = 0x00f297;
	while (y-- && neox)
		neox = neox->next;
	color = neox->line[x][1];
	if (!color)
		color = default_col;
	return (color);
}

void bresenham_algo(float x, float y, float x1, float y1, t_neox *neox, t_buddha v)
{
	float	x_step;
	float	y_step;
	int		max_step;
	int		color;

	color = get_c(x, y, neox);
	three_dim(&x, &y, get_z(x, y, neox), v.angle);
	three_dim(&x1, &y1, get_z(x1, y1, neox), v.angle);
	//zoom
	(x *= v.zoom, y *= v.zoom);
	(x1 *= v.zoom, y1 *= v.zoom);
	//centered
	(x += v.shift_x, y += v.shift_y);
	(x1 += v.shift_x, y1 += v.shift_y);
	//algo
	(x_step = x1 - x, y_step = y1 - y);
	max_step = max_v(abs_v(x_step), abs_v(y_step));
	(x_step /= max_step, y_step /= max_step);
	while((int) (x - x1) || (int) (y - y1))
	{
		mlx_pixel_put(v.mlx, v.win, x, y, color);
		(x += x_step , y += y_step);
	}
}

int	get_cols(char *file_name)
{
	int		fd;
	int		index;
	char	*line;
	char	**splitted;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	splitted = ft_split(line, ' ');
	free(line);
	line = NULL;
	index = 0;
	while (splitted[index])
		index++;
	free(splitted);
	splitted = NULL;
	close(fd);
	return (index);
}

int	get_rows(char *file_name)
{
	int		fd;
	int		line_count;
	char	*line;
	
	line_count = 0;
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_count++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (line_count);
}

void	init_v(t_buddha *v, char *file_name)
{
	v->cols = get_cols(file_name);
	v->rows = get_rows(file_name);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, 900, 900, "BUDDHA X NEOX - FDF");
	v->zoom = 25;
	v->shift_x = 300;
	v->shift_y = 300;
	v->angle = 0.8;
}

void	picasso(t_buddha v, t_neox *neox)
{
	int			x;
	int			y;
	
	y = -1;
	while (++y < v.rows)
	{
		x = -1;
		while(++x < v.cols)
		{
			if (x + 1 < v.cols)
				bresenham_algo(x, y, x + 1, y, neox, v);
			if (y + 1 < v.rows)
				bresenham_algo(x, y, x, y + 1, neox, v);
		}
	}
}

int	key_hook(int keycode, t_buddha *v)
{
	if (keycode == 126)
		v->shift_y += 30;
	if (keycode == 125)
		if (v->shift_y > 30)
			v->shift_y -= 30;
	if (keycode == 124)
		if (v->shift_x > 30)
			v->shift_x -= 30;
	if (keycode == 123)
		v->shift_x += 30;
	if (keycode == 116)
		v->angle += 0.1;
	if (keycode == 121)
		v->angle -= 0.1;
	mlx_clear_window(v->mlx, v->win);
	picasso(*v, v->neox);
	return (0);
}

int mouse_hook(int mouse_hook, int x, int y, t_buddha *v)
{
	printf("%d:%d \n", x, y);
	if (mouse_hook == 4)
		if (v->zoom > 10)
			v->zoom -= 10;
	if (mouse_hook == 5)
			v->zoom += 10;
	mlx_clear_window(v->mlx, v->win);
	picasso(*v, v->neox);
	return (0);
}

int	main (int ac, char **av)
{
	t_buddha	v;

	ft_check_args(ac, av);
	ft_parser(&(v.neox), av);
	init_v(&v, av[1]);
	
	picasso(v, v.neox);
	mlx_mouse_hook(v.win, mouse_hook, &v);
	mlx_key_hook(v.win, key_hook, &v);
	
	mlx_loop(v.mlx);
	my_malloc(0, 2);
}
