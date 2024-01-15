/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:07:48 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/15 13:09:28 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_c(t_buddha v, int current_p)
{
	int	color;
	int	z;

	color = v.arr_c[current_p];
	if (!color)
	{
		z = v.arr_z[current_p];
		if (z > 0)
			(color = 0xFF000F * z);
		else if (z < 0)
			(color = 0x00FF0F * -z);
		else
			(color = DEFAULT_COL);
	}
	return (color);
}

void	init_p(t_point *p, t_buddha v)
{
	int	current_point;

	current_point = (int)p->x + v.cols * (int)p->y;
	p->z = v.arr_z[current_point];
	p->color = get_c(v, current_point) * v.color_amp;
	p->x *= v.zoom;
	p->y *= v.zoom;
	p->z *= v.zoom;
}

double	get_percent(float start, float current, float end)
{
	if (start == end)
		return (1.0);
	return ((current - start) / (end - start));
}

int	get_rgb(float start, float end, double percent)
{
	return ((int)(end * percent + (1 - percent) * start));
}

int	grad_c(t_point s, t_point c, t_point e)
{
	double	percent;
	int		red;
	int		green;
	int		blue;

	if (abs_v(s.x - e.x) > abs_v(s.y - e.y))
		percent = get_percent(s.x, c.x, e.x);
	else
		percent = get_percent(s.y, c.y, e.y);
	red = get_rgb((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
	green = get_rgb((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
	blue = get_rgb((s.color) & 0xFF, (e.color) & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
