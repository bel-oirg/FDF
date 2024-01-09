/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:07:48 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/09 03:38:49 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_c(int x, int y, t_neox *neox)
{
	int	color;
	int	default_col;

	if (x < 0 || y < 0 || !neox)
		return (-1);
	default_col = 0x00f297;
	while (y-- && neox)
		neox = neox->next;
	color = neox->line[x][1];
	if (neox->line[x][0])
		(!color) && (color = 0x0000FF);
	else
		color = 0x00FFFF;
	return (color);
}

void	init_p(t_point *p, t_neox *neox, t_buddha v)
{
	p->z = get_z(p->x, p->y, neox);
	p->color = get_c(p->x, p->y, neox);
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
