/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:36:43 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/05 01:36:46 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen_line(char *str)
{
	int		count;
	char	*line;

	line = my_strtok(str, " ");
	count = 0;
	if (!line)
		return (0);
	while (line)
	{
		if (ft_atoi(line) >= 0 || ft_atoi(line) <= 0)
			count++;
		line = my_strtok(NULL, " ");
	}
	return (count);
}

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
