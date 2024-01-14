/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:44:24 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/14 12:25:54 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_v(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_v(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	abs_v(int val)
{
	return (max_v(val, -val));
}
