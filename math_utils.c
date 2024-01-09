/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:44:24 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/09 03:38:16 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	diff(int x1, int x2)
{
	return (x2 - x1);
}

int	max_v(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	abs_v(int val)
{
	return (max_v(val, -val));
}
