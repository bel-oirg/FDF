/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:37:23 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/16 18:36:09 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	stack_arr(t_buddha v)
{
	int	index;
	int	cols;
	int	x;

	cols = v.cols;
	index = -1;
	while (v.neox)
	{
		x = -1;
		while (++x < cols)
		{
			v.arr_z[++index] = v.neox->line[x][0];
			if (v.arr_z[index] > 100)
				v.arr_z[index] = 100;
			if (v.arr_z[index] < -100)
				v.arr_z[index] = -100;
			v.arr_c[index] = v.neox->line[x][1];
		}
		v.neox = v.neox->next;
	}
}

int	key_hook_man(int key, t_buddha *v)
{
	(key == 53) && (destroy_fdf(v));
	return (0);
}

int	main(int ac, char **argv)
{
	t_buddha	*v;
	t_point		*s;
	t_point		*e;

	s = NULL;
	e = NULL;
	ft_check_args(ac, argv);
	v = my_malloc(sizeof(t_buddha), 1);
	v->m = my_malloc(sizeof(t_mouse), 1);
	v->img = my_malloc(sizeof(t_img), 1);
	parser(&(v->neox), argv);
	init_v(v, argv[1]);
	v->arr_z = my_malloc(sizeof(int) * v->rows * v->cols, 1);
	v->arr_c = my_malloc(sizeof(int) * v->rows * v->cols, 1);
	stack_arr(*v);
	v->s = my_malloc(sizeof(t_point), 1);
	v->e = my_malloc(sizeof(t_point), 1);
	picasso(v);
	mlx_hook(v->win, 2, 2, key_hook_man, v);
	mlx_hook(v->win, 17, 2, destroy_fdf, v);
	mlx_loop(v->mlx);
}
