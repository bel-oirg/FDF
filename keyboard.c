/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:45:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/10 11:06:21 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_fdf(t_buddha *v)
{
	mlx_destroy_image(v->mlx, v->img->addr);
	mlx_destroy_window(v->mlx, v->win);
	my_malloc(0, 2);
	exit(0);
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
	if (key == 53)
		destroy_fdf(v);
	mlx_clear_window(v->mlx, v->win);
	picasso(v, v->neox);
	return (0);
}
