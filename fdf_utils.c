/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:36:52 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/05 01:36:54 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	num;
	int			signe;
	int			check;

	(1) && (i = 0, signe = 1, num = 0, check = 0);
	if (str[i] == '-' || str[i] == '+')
	{
		(str[i] == '-') && (signe = -1);
		i++;
	}
	if (!str[i])
		return (write(2, "Input Error\n", 12), my_malloc(0, 0), 0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
		check = 1;
	}
	(str[i] || !check) && (ft_error(), 0);
	return (num * signe);
}

void	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

void	my_helper(t_neox *node, char *more, char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str)
	{
		more = my_strtok_two(str, ",");
		nb = ft_atoi(more);
		node->line[i][0] = nb;
		more = my_strtok_two(NULL, ",");
		if (more)
			node->line[i][1] = ft_convert(more);
		else
			node->line[i][1] = 0;
		str = my_strtok(NULL, " \t");
		i++;
	}
}

int	my_second_helper(char *more, char *str)
{
	int	count;
	int	nb;

	nb = 0;
	count = 0;
	while (str)
	{
		more = my_strtok_two(str, ",");
		nb = ft_atoi(more);
		more = my_strtok_two(NULL, ",");
		count++;
		str = my_strtok(NULL, " \t");
	}
	return (count);
}

int	ft_parser(t_neox **neox, char **av)
{
	char	*line;
	char	*str;
	int		i;
	int		fd;
	int		count;
	char	*more;
	char	*line2;
	t_neox	*node;

	node = my_malloc(sizeof(t_neox), 1);
	fd = open(av[1], O_RDONLY);
	(fd < 0) && (write(2, "Invalid Permissions\n", 20), exit(1), 0);
	line = get_next_line(fd);
	(!line) && (close(fd), my_malloc(0, 0), 0);
	(1) && (*neox = node, more = NULL, str = NULL);
	while (line)
	{
		line2 = malloc(ft_strlen(line) + 1);
		line2 = ft_strcpy(line, line2);
		str = my_strtok(line, " \t");
		count = my_second_helper(more, str);
		node->line = my_malloc(sizeof(int **) * count, 1);
		i = 0;
		str = my_strtok(line2, " \t");
		my_helper(node, more, str);
		free(line);
		free(line2);
		line = get_next_line(fd);
		if (line)
			node->next = my_malloc(sizeof(t_neox), 1);
		node = node->next;
		if (node)
			node->next = NULL;
	}
	return (count);
}
