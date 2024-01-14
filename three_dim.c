/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:40:50 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/14 12:20:48 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(float *y, float *z, double angle)
{
	int	y0;

	y0 = *y;
	*y = y0 * cos(angle) + *z * sin(angle);
	*z = -y0 * sin(angle) + *z * cos(angle);
}

void	rot_y(float *x, float *z, double angle)
{
	int	x0;

	x0 = *x;
	*x = x0 * cos(angle) + *z * sin(angle);
	*z = -x0 * sin(angle) + *z * cos(angle);
}

void	rot_z(float *x, float *y, double angle)
{
	int		x0;
	int		y0;

	x0 = *x;
	y0 = *y;
	*x = x0 * cos(angle) - y0 * sin(angle);
	*y = x0 * sin(angle) + y0 * cos(angle);
}

void	three_dim(float *x, float *y, float *z, t_buddha v)
{
	rot_x(y, z, v.x_teta);
	rot_y(x, z, v.y_teta);
	rot_z(x, y, v.z_teta);
}
