/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:49:12 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/09 03:58:19 by bel-oirg         ###   ########.fr       */
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
	node->line = my_malloc(sizeof(int **) * cols, 1);
	index = -1;
	while (p[++index])
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

	node = my_malloc(sizeof(t_neox), 1);
	fd = open(argv[1], O_RDONLY);
	(fd < 0) && (write(2, "Invalid Permissions\n", 20), exit(1), 0);
	*neox = node;
	line = get_next_line(fd);
	cols = get_cols_l(line);
	while (line)
	{
		parse_line(line, cols, node);
		line = get_next_line(fd);
		node->next = NULL;
		if (!line)
			break ;
		node->next = my_malloc(sizeof(t_neox), 1);
		node = node->next;
	}
	close(fd);
}
