/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:52:19 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/18 16:13:31 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_centred(t_buddha *v)
{
	int	diff_x;
	int	diff_y;

	v->zoom = min_v(WIDTH / v->cols, HEIGHT / v->rows) * 0.6 + 1;
	diff_x = WIDTH - v->cols * v->zoom;
	diff_y = HEIGHT - v->rows * v->zoom;
	v->shift_x = diff_x / 2;
	v->shift_y = diff_y / 2;
}

void	init_v(t_buddha *v, char *file_name)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "BUDDHA X NEOX - FDF");
	v->img->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->img->addr = mlx_get_data_addr(v->img->img, &v->img->bpp,
			&v->img->line_len, &v->img->endian);
	v->rows = get_rows(file_name);
	v->cols = get_cols(file_name);
	v->all_bpp = HEIGHT * WIDTH * (v->img->bpp / 8);
	v->x_teta = -0.366;
	v->y_teta = -0.236;
	v->z_teta = 0;
	v->color_amp = 1;
	zoom_centred(v);
	v->m->is_pressed = 0;
}
