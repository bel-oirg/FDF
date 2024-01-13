/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:21:38 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/13 11:50:25 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pp(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (y < HEIGHT && x < WIDTH && x >= 0 && y >= 0)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static void	dda_algo(t_point s, t_point e, t_neox *neox, t_buddha v)
{
	float	x_step;
	float	y_step;
	t_point	c;
	int		max_step;

	init_p(&s, neox, v);
	init_p(&e, neox, v);
	three_dim(&s.x, &s.y, &s.z, v);
	three_dim(&e.x, &e.y, &e.z, v);
	(1) && (s.x += v.shift_x, s.y += v.shift_y);
	(1) && (e.x += v.shift_x, e.y += v.shift_y);
	c = s;
	x_step = e.x - s.x;
	y_step = e.y - s.y;
	max_step = max_v(abs_v(x_step), abs_v(y_step));
	x_step /= max_step;
	y_step /= max_step;
	while ((int)(c.x - e.x) || (int)(c.y - e.y))
	{
		my_mlx_pp(v.img, c.x, c.y, grad_c(s, c, e));
		(1) && (c.x += x_step, c.y += y_step);
	}
}

void	picasso(t_buddha *v, t_neox *neox)
{
	t_point		*s;
	t_point		*e;

	s = my_malloc(sizeof(t_point), 1);
	e = my_malloc(sizeof(t_point), 1);
	ft_bzero(v->img->addr, HEIGHT * WIDTH * (v->img->bpp / 8));
	s->y = -1;
	while (++s->y < v->rows)
	{
		s->x = -1;
		while (++s->x < v->cols)
		{
			if (s->x + 1 < v->cols)
				(1) && (e->x = s->x + 1), (e->y = s->y),
				dda_algo(*s, *e, neox, *v);
			if (s->y + 1 < v->rows)
				(1) && (e->x = s->x), (e->y = s->y + 1),
				dda_algo(*s, *e, neox, *v);
		}
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img->img, 0, 0);
}
