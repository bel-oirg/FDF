/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:06:44 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/13 14:06:10 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_release(int mouse_hook, int x, int y, t_buddha *v)
{
	(void)mouse_hook;
	(void)x;
	(void)y;
	v->m->is_pressed = 0;
	return (0);
}

int	mouse_clicked(int mouse_hook, int x, int y, t_buddha *v)
{
	(void)x;
	(void)y;
	if (mouse_hook == 1)
		v->m->is_pressed = 1;
	if (mouse_hook == 4)
		v->zoom += 1;
	if (mouse_hook == 5)
		if (v->zoom > 1)
			v->zoom -= 1;
	picasso(v);
	return (0);
}

int	mouse_move(int x, int y, t_buddha *v)
{
	v->m->x0 = v->m->x;
	v->m->y0 = v->m->y;
	v->m->x = x;
	v->m->y = y;
	if (v->m->is_pressed)
	{
		v->y_teta += (x - v->m->x0) * 0.002;
		v->x_teta += (y - v->m->y0) * 0.002;
		picasso(v);
	}
	return (0);
}
