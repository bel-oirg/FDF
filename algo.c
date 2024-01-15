/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:21:38 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/15 15:52:37 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pp(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (y < HEIGHT && x < WIDTH && x >= 0 && y >= 0)
	{
		dst = img->addr + (y * img->line_len + x * 4);
		*(unsigned int *)dst = color;
	}
}

static void	dda_algo(t_point s, t_point e, t_buddha v)
{
	float	x_step;
	float	y_step;
	t_point	c;
	int		max_step;

	init_p(&s, v);
	init_p(&e, v);
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
		c.x += x_step;
		c.y += y_step;
	}
}

void	picasso(t_buddha *v)
{
	mlx_destroy_image(v->mlx, v->img->img);
	v->img->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->s->y = -1;
	while (++v->s->y < v->rows)
	{
		v->s->x = -1;
		while (++v->s->x < v->cols)
		{
			if (v->s->x + 1 < v->cols)
				(1) && (v->e->x = v->s->x + 1), (v->e->y = v->s->y),
				dda_algo(*(v->s), *(v->e), *v);
			if (v->s->y + 1 < v->rows)
				(1) && (v->e->x = v->s->x), (v->e->y = v->s->y + 1),
				dda_algo(*(v->s), *(v->e), *v);
		}
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img->img, 0, 0);
}
