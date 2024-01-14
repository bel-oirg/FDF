/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:49:23 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/14 12:23:32 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_cols(char *file_name)
{
	int		fd;
	int		index;
	char	*line;
	char	**splitted;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	splitted = ft_split(line, ' ');
	free(line);
	line = NULL;
	index = 0;
	while (splitted[index])
		index++;
	f_matrix(splitted);
	close(fd);
	return (index);
}

int	get_rows(char *file_name)
{
	int		fd;
	int		line_count;
	char	*line;

	line_count = 0;
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_count++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (line_count);
}
