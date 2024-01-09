/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:37:13 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/09 03:59:42 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *str, int len)
{
	char	*array;
	int		count;

	if (!str || !len)
		return (NULL);
	count = -1;
	array = (char *)malloc((len + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (++count < len)
		array[count] = str[count];
	array[count] = '\0';
	return (array);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*array;

	i = 0;
	if (!s1 || !s2)
	{
		if (s1)
			return (ft_strdup(s1, ft_strlen(s1)));
		else if (s2)
			return (ft_strdup(s2, ft_strlen(s2)));
		else
			return (NULL);
	}
	array = (char *)malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!array)
		return (free_out(s1), NULL);
	len = 0;
	while (s1[i])
		array[len++] = s1[i++];
	i = 0;
	while (s2[i])
		array[len++] = s2[i++];
	array[len] = '\0';
	return (free_out(s1), array);
}

int	have_n(char	*temp)
{
	int		i;

	if (!temp)
		return (0);
	i = -1;
	while (temp[++i])
		if (temp[i] == 10)
			return (1);
	return (0);
}

char	*print_line(char **temp)
{
	int		n_pos;
	int		fdf;
	char	*return_line;
	char	*str;

	if (!*temp)
		return (NULL);
	str = *temp;
	n_pos = 0;
	fdf = 0;
	while (str[n_pos] && str[n_pos] != 10)
		n_pos++;
	if (str[n_pos] == 10)
		fdf++;
	return_line = ft_strdup(str, n_pos);
	*temp = ft_strdup(str + n_pos + fdf, ft_strlen(str + n_pos + fdf));
	return (free_out(str), return_line);
}
