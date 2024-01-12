/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:07:48 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/12 16:52:14 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_c(int x, int y, t_neox *neox)
{
	int	color;
	int	default_col;
	int	z;

	if (x < 0 || y < 0 || !neox)
		return (-1);
	default_col = 0x000FF7;
	while (y-- && neox)
		neox = neox->next;
	z = neox->line[x][0];
	color = neox->line[x][1];
	if (!color)
		(z > 0) && (color = 0xFF000F * z),
		(z < 0) && (color = 0x00FF0F * -z),
		(!z) && (color = default_col);
	return (color);
}

void	init_p(t_point *p, t_neox *neox, t_buddha v)
{
	p->z = get_z(p->x, p->y, neox);
	p->color = get_c(p->x, p->y, neox) * v.color_amp;
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
