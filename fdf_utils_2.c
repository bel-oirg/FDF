/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:36:43 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/10 11:29:44 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_search(char *str)
{
	char	ptr[4];
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	ptr[0] = '.';
	ptr[1] = 'f';
	ptr[2] = 'd';
	ptr[3] = 'f';
	while (str[i])
	{
		if (str[i] == '.')
		{
			j = i;
			while (str[j] && str[j] == ptr[k])
				(j++) && (k++);
			if (k == 4 && !str[j])
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_check_args(int ac, char **av)
{
	(ac != 2) && (write(2, "Invalid Arguments", 18), exit(1), 0);
	(!ft_search(av[1])) && (write(2, "Invalid file type\n", 18), exit(1), 0);
}
