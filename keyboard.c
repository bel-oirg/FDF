/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:45:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/16 18:25:56 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	parralel(t_buddha *v)
{
	v->x_teta = 0;
	v->y_teta = 0;
	v->z_teta = 0;
	return (1);
}

static int	isometric(t_buddha *v)
{
	v->x_teta = -0.366;
	v->y_teta = -0.236;
	v->z_teta = 0;
	return (1);
}

int	key_hook(int key, t_buddha *v)
{
	(key == 126) && (v->shift_y += 30);
	(key == 125) && (v->shift_y -= 30);
	(key == 124) && (v->shift_x -= 30);
	(key == 123) && (v->shift_x += 30);
	(key == 8) && (v->color_amp += 5);
	(key == 9) && (v->color_amp -= 5);
	(key == 34) && (isometric(v));
	(key == 35) && (parralel(v));
	(key == 53) && (destroy_fdf(v));
	picasso(v);
	return (0);
}
