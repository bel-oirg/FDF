/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:49:12 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/12 10:31:13 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *str)
{
	long int	num;
	int			i;
	int			sign;
	int			checker;

	if (!str)
		return (0);
	(1) && (i = 0, sign = 1, num = 0, checker = 0);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i++] - 48);
		checker = 1;
	}
	if (str[i] || !checker)
		write(1, "Invalid Content\n", ft_strlen("Invalid Content\n"));
	return (num * sign);
}

int	get_cols_l(char *line)
{
	int		index;
	char	**splitted;

	splitted = ft_split(line, ' ');
	index = 0;
	while (splitted[index])
		index++;
	f_matrix(splitted);
	return (index);
}

void	parse_line(char *line, int cols, t_neox *node)
{
	char	**mini_p;
	char	**p;
	int		index;

	p = ft_split(line, ' ');
	node->line = my_malloc(sizeof(int *) * cols, 1);
	index = -1;
	while (p[++index] && cols--)
	{
		mini_p = ft_split(p[index], ',');
		(node)->line[index][0] = ft_atoi(mini_p[0]);
		if (ft_convert(mini_p[1]))
			(node)->line[index][1] = ft_convert(mini_p[1]);
		else
			(node)->line[index][1] = 0;
		f_matrix(mini_p);
	}
	f_matrix(p);
}

void	parser(t_neox **neox, char **argv)
{
	t_neox	*node;
	char	*line;
	int		fd;
	int		cols;

	fd = open(argv[1], O_RDONLY);
	(fd < 0) && (write(2, "Invalid Permissions\n", 21), exit(1), 0);
	line = get_next_line(fd);
	(!line) && (close(fd), write(2, "Empty File\n", 12), exit(1), 0);
	node = my_malloc(sizeof(t_neox), 1);
	*neox = node;
	while (line)
	{
		cols = get_cols_l(line);
		parse_line(line, cols, node);
		free(line);
		line = get_next_line(fd);
		node->next = NULL;
		if (!line)
			break ;
		node->next = my_malloc(sizeof(t_neox), 1);
		node->next->line = NULL;
		node = node->next;
	}
	close(fd);
}
