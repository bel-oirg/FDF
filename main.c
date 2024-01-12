/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:37:23 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/12 11:21:51 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_centred(t_buddha *v)
{
	int	x;
	int	y;
	int	diff_x;
	int	diff_y;

	x = v->cols;
	y = v->rows;
	v->zoom = (min_v(WIDTH / x, HEIGHT / y) * 0.6 + 1);
	diff_x = WIDTH - x * v->zoom;
	diff_y = HEIGHT - y * v->zoom;
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
	v->x_teta = -0.366;
	v->y_teta = -0.236;
	v->z_teta = 0;
	v->color_amp = 1;
	zoom_centred(v);
	v->m->is_pressed = 0;
}

int	main(int ac, char **argv)
{
	t_buddha	*v;

	v = my_malloc(sizeof(t_buddha), 1);
	v->m = my_malloc(sizeof(t_mouse), 1);
	v->img = my_malloc(sizeof(t_img), 1);
	ft_check_args(ac, argv);
	parser(&(v->neox), argv);
	init_v(v, argv[1]);
	picasso(v, v->neox);
	mlx_hook(v->win, 2, 2, key_hook, v);
	mlx_hook(v->win, 4, 2, mouse_clicked, v);
	mlx_hook(v->win, 6, 2, mouse_move, v);
	mlx_hook(v->win, 5, 2, mouse_release, v);
	mlx_hook(v->win, 17, 2, destroy_fdf, v);
	mlx_loop(v->mlx);
}
