/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:58:29 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/03 02:52:40 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	word_counter(char const *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			counter++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counter);
}

static void	free_malloc(char **split, int k)
{
	while (k >= 0)
	{
		free(split[k]);
		split[k--] = NULL;
	}
	free(split);
	split = NULL;
}

static char	*char_counter(char const *s, char c)
{
	char		*str;
	int			counter;
	int			index;

	counter = 0;
	index = 0;
	while (s[counter] != c && s[counter])
		counter++;
	str = (char *)malloc(sizeof(char) * (counter + 1));
	if (!str)
		return (NULL);
	while (counter--)
	{
		str[index] = s[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	int		k;
	int		w_count;

	if (!s)
		return (NULL);
	w_count = word_counter(s, c);
	split = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!split)
		return (NULL);
	k = -1;
	while (++k < w_count)
	{
		while (*s == c && c)
			s++;
		split[k] = char_counter(s, c);
		if (!split[k])
		{
			free_malloc(split, k);
			return (NULL);
		}
		s += ft_strlen(split[k]);
	}
	split[k] = NULL;
	return (split);
}
