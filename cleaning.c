/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:17:11 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/10 11:07:44 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_error(void)
{
	write(2, "Invalid file Input !!\n", ft_strlen("Invalid file Input !!\n"));
	my_malloc(0, 0);
}
