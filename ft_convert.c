/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:37:04 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/15 13:09:50 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_convert(char *str)
{
	int	num;
	int	i;

	if (ft_strlen(str) < 2)
		return (0);
	i = 1;
	num = 0;
	while (str && str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 16 + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			num = num * 16 + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = num * 16 + str[i] - 'A' + 10;
		else
			(1) && write(2, ERR_COL, 24), my_malloc(0, 0);
	}
	return (num);
}
