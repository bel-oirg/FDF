/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:17:11 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/18 16:17:21 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_fdf(t_buddha *v)
{
	mlx_destroy_window(v->mlx, v->win);
	my_malloc(0, 2);
	exit(0);
}

void	f_matrix(char **str)
{
	int	index;

	if (!str || !*str)
		return ;
	index = -1;
	while (str[++index])
	{
		free(str[index]);
		str[index] = NULL;
	}
	free(str);
	str = NULL;
}
