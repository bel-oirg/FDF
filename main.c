/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:37:23 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/07 09:32:35 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pp(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

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

void	rot_x(float *x, float *y, float *z, double angle)
{
	int	y0;
	int	z0;
	(void)*x;

	y0 = *y;
	z0 = *z;
	*y = y0 * cos(angle) + *z * sin(angle);
	*z = -y0 * sin(angle) + *z * cos(angle);
}

void	rot_y(float *x, float *y, float *z, double angle)
{
	int	x0;
	int	z0;
	(void)*y;

	x0 = *x;
	z0 = *z;
	*x = x0 * cos(angle) + *z * sin(angle);
	*z = -x0 * sin(angle) + *z * cos(angle);
}

void	rot_z(float *x, float *y, float *z, double angle)
{
	int	x0;
	int	y0;
	(void)*z;

	x0 = *x;
	y0 = *y;
	*x = x0 * cos(angle) - y0 * sin(angle);
	*y = x0 * sin(angle) + y0 * cos(angle);
}

void	iso(float *x, float *y, float *z, t_buddha v)
{
	int x0;
	int	y0;

	x0 = *x;
	y0 = *y;
	*x = (x0 - y0) * cos(v.angle);
	*y = (x0 + y0) * sin(v.angle) - *z;
}
void	three_dim(float *x, float *y, float *z, t_buddha v)
{
	rot_x(x, y, z, v.x_teta);
	rot_y(x, y, z, v.y_teta);
	rot_z(x, y, z, v.z_teta);
}
float	get_z(int x, int y, t_neox *neox)
{
	if (x < 0 || y < 0 || !neox)
		return (-1);
	while (y-- && neox)
		neox = neox->next;
	printf("this is x %d\n\n", x);
	return ((float) neox->line[x][0]);
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
	if (neox->line[x][0])
		(!color) && (color = 0x0000FF);
	else
		color = 0xFFFFFF;
	return (color);
}
double	get_percent(float start, float current, float end)
{
	if (start == end)
		return (1.0);
	return ((current - start) / (end - start));
}

int	get_rgb(float start, float end, double percent)
{
	return ((int) (end * percent + (1 - percent) * start));
}
int grad_c(t_point s, t_point c, t_point e, t_neox *neox)
{
	double percent;
	int	red;
	int	green;
	int	blue;
	(void)neox;

	// c.color = get_c(c.x, c.y, neox);
	// if (c.color == e.color)
	// 	return (c.color);
	if (abs_v(s.x - e.x) > abs_v(s.y - e.y))
		percent = get_percent(s.x, c.x, e.x);
	else
		percent = get_percent(s.y, c.y, e.y);
	red = get_rgb((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
	green = get_rgb((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
	blue = get_rgb((s.color) & 0xFF, (e.color) & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

void	init_p(t_point *p, t_neox *neox, t_buddha v)
{
	p->z = get_z(p->x, p->y, neox);
	p->color = get_c(p->x, p->y, neox);
	p->x *= v.zoom;
	p->y *= v.zoom;
	p->z *= v.zoom;
}
void bresenham_algo(t_point s, t_point e, t_neox *neox, t_buddha v)
{
	t_point	c;
	float	x_step;
	float	y_step;
	int		max_step;

	// iso(&x, &y, &z, v), iso(&x1, &y1, &z1, v);
	init_p(&s, neox, v);
	init_p(&e, neox, v);

	three_dim(&s.x, &s.y, &s.z, v), three_dim(&e.x, &e.y, &e.z, v);
	//centered
	(s.x += v.shift_x, s.y += v.shift_y);
	(e.x += v.shift_x, e.y += v.shift_y);
	//algo
	c = s; //for color
	(x_step = e.x - s.x, y_step = e.y - s.y);
	max_step = max_v(abs_v(x_step), abs_v(y_step));
	(x_step /= max_step, y_step /= max_step);
	while((int) (c.x - e.x) || (int) (c.y - e.y))
	{
		my_mlx_pp(v.img, c.x, c.y, grad_c(s, c, e, neox));
		(c.x += x_step , c.y += y_step);
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
	free(splitted); ////free each array
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
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, HEIGHT, WIDTH, "BUDDHA X NEOX - FDF");
	v->img->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->img->addr = mlx_get_data_addr(v->img->img, &v->img->bpp,
	&v->img->line_len, &v->img->endian);
	v->cols = get_cols(file_name);
	v->rows = get_rows(file_name);
	v->angle = 0.523599;
	v->x_teta = 0;
	v->y_teta = 0;
	v->z_teta = 0;
	v->zoom = 25;
	v->shift_x = 300;
	v->shift_y = 300;
	v->m->is_pressed = 0;
}

void	picasso(t_buddha *v, t_neox *neox)
{
	t_point		*s;
	t_point		*e;
	
	s = malloc(sizeof(t_point));
	e = malloc(sizeof(t_point));
	s->y = -1;
	while (++s->y < v->rows)
	{
		s->x = -1;
		while(++s->x < v->cols)
		{
			if (s->x + 1 < v->cols)
				e->x = s->x + 1,
					e->y = s->y,
						bresenham_algo(*s, *e, neox, *v);
			if (s->y + 1 < v->rows)
			{
				(e->x = s->x), (e->y = s->y + 1);
				bresenham_algo(*s, *e, neox, *v);
			}
		}
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img->img, 0 ,0);
}

int	key_hook(int key, t_buddha *v)
{
	if (key == 126)
		v->shift_y += 30;
	if (key == 125)
		if (v->shift_y > 30)
			v->shift_y -= 30;
			
	if (key == 124)
		if (v->shift_x > 30)
			v->shift_x -= 30;
	if (key == 123)
		v->shift_x += 30;
		
	if (key == 116)
		v->angle += 0.1;
	if (key == 121)
		v->angle -= 0.1;

	if (key == 13) //w
		v->z_teta += 0.1;
	if (key == 2) //d
		v->x_teta += 0.1;
	if (key == 6) //z
		v->y_teta += 0.1;
	printf("key %d\n", key);
	mlx_clear_window(v->mlx, v->win);
	picasso(v, v->neox);
	return (0);
}

int	mouse_release(int mouse_hook, int x, int y, t_buddha *v)
{
	(void)mouse_hook;
	(void)x;
	(void)y;
	v->m->is_pressed = 0;
	printf("released clicked %d:%d  -- %d\n", x, y, v->m->is_pressed);
	return (0);
}

int	mouse_clicked(int mouse_hook, int x, int y, t_buddha *v)
{
	(void)x;
	(void)y;
	if (mouse_hook == 1)
		v->m->is_pressed = 1;
	//ZOOOM
	if (mouse_hook == 4)
		v->zoom += 2;
	if (mouse_hook == 5)
		if (v->zoom > 2)
			v->zoom -= 2;

	printf("mouse clicked %d:%d  -- %d\n", x, y, v->m->is_pressed);
	mlx_clear_window(v->mlx, v->win);
	picasso(v, v->neox);
	return (0);
}

int	mouse_move(int x, int y, t_buddha *v)
{
	v->m->x0 = v->m->x;  //v->m->x == ???? in the first time;
	v->m->y0 = v->m->y;
	v->m->x = x;
	v->m->y = y;
	if (v->m->is_pressed)
	{
		v->y_teta += (x - v->m->x0) * 0.002;
		v->x_teta += (y - v->m->y0) * 0.002;
		mlx_clear_window(v->mlx, v->win);
		picasso(v, v->neox);
	}
	printf("mouse moved %d:%d\n", x, y);
	return (0);
}



int	main (int ac, char **av)
{
	t_buddha	*v;

	v = malloc(sizeof(t_buddha));
	v->m = malloc(sizeof(t_mouse));
	v->img = malloc(sizeof(t_img));
	ft_check_args(ac, av), ft_parser(&(v->neox), av);
	init_v(v, av[1]);
	
	picasso(v, v->neox);

	mlx_hook(v->win, 2, 2, key_hook, v);
	
	mlx_hook(v->win, 4, 2, mouse_clicked, v);
	mlx_hook(v->win, 6, 2, mouse_move, v);
	mlx_hook(v->win, 5, 2, mouse_release, v);
	mlx_loop(v->mlx);
	my_malloc(0, 2);
}
