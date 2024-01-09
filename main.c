/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:37:23 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/09 03:38:35 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_v(t_buddha *v, char *file_name)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, HEIGHT, WIDTH, "BUDDHA X NEOX - FDF");
	v->img->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->img->addr = mlx_get_data_addr(v->img->img, &v->img->bpp,
			&v->img->line_len, &v->img->endian);
	v->cols = get_cols(file_name);
	v->rows = get_rows(file_name);
	v->angle = 0.523599;
	v->x_teta = 0;
	v->y_teta = 0;
	v->z_teta = 0;
	v->zoom = 25;
	v->shift_x = 300;
	v->shift_y = 300;
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
	mlx_loop(v->mlx);
	my_malloc(0, 2);
}
