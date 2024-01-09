/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:45:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/09 03:36:54 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (key == 13)
		v->z_teta += 0.1;
	if (key == 2)
		v->x_teta += 0.1;
	if (key == 6)
		v->y_teta += 0.1;
	mlx_clear_window(v->mlx, v->win);
	picasso(v, v->neox);
	return (0);
}
