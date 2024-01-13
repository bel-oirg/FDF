/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:36:43 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/13 13:43:12 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_search(char *str)
{
	char	ptr[4];
	int		size;
	int		start;

	size = ft_strlen(str);
	ptr[0] = '.';
	ptr[1] = 'f';
	ptr[2] = 'd';
	ptr[3] = 'f';
	start = 4;
	while (size >= 4)
	{
		if (str[size - start] == '.')
		{
			while (start > 0 && str[size - start] == ptr[4 - start])
				start--;
			if (start == 0)
				return (1);
		}
		return (0);
	}
	return (0);
}

void	ft_check_args(int argc, char **argv)
{
	(argc != 2) && (write(2, ERR_ARGS, 23), exit(1), 0);
	(!ft_search(argv[1])) && (write(2, ERR_TYP_FILE, 23), exit(1), 0);
}
